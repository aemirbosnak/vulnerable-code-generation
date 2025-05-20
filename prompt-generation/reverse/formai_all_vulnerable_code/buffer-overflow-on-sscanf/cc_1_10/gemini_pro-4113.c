//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/queue.h>
#include <net/ethernet.h>
#include <netinet/udp.h>
#include <netdb.h>
#include <pcap.h>
#include <net/if.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>

#define ETH_HDRLEN 14

struct firewall_rule {
    uint32_t src_ip;
    uint32_t dst_ip;
    uint16_t src_port;
    uint16_t dst_port;
    uint8_t protocol;
    uint8_t action;
};

struct firewall_state {
    pcap_t *handle;
    struct firewall_rule *rules;
    int num_rules;
};

static void firewall_init(struct firewall_state *fw, char *interface) {
    char errbuf[PCAP_ERRBUF_SIZE];
    fw->handle = pcap_open_live(interface, BUFSIZ, 1, 1000, errbuf);
    if (fw->handle == NULL) {
        fprintf(stderr, "Error opening interface: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }
}

static void firewall_cleanup(struct firewall_state *fw) {
    pcap_close(fw->handle);
}

static int firewall_process_packet(struct firewall_state *fw, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ethhdr *eth = (struct ethhdr *)packet;
    int i;

    if (ntohs(eth->h_proto) != ETH_P_IP) {
        return 0;
    }

    const struct iphdr *ip = (struct iphdr *)(packet + ETH_HDRLEN);
    const struct tcphdr *tcp = (struct tcphdr *)((const u_char *)ip + (ip->ihl * 4));
    const struct udphdr *udp = (struct udphdr *)((const u_char *)ip + (ip->ihl * 4));

    for (i = 0; i < fw->num_rules; i++) {
        struct firewall_rule *rule = &fw->rules[i];

        if ((rule->src_ip == 0 || rule->src_ip == ip->saddr) &&
            (rule->dst_ip == 0 || rule->dst_ip == ip->daddr) &&
            (rule->src_port == 0 || rule->src_port == ntohs(tcp->source)) &&
            (rule->dst_port == 0 || rule->dst_port == ntohs(tcp->dest)) &&
            (rule->protocol == 0 || rule->protocol == ip->protocol)) {
            if (rule->action == 0) {
                return 1;
            } else {
                return -1;
            }
        }
    }

    return 0;
}

static void firewall_loop(struct firewall_state *fw) {
    while (1) {
        struct pcap_pkthdr header;
        const u_char *packet;

        int ret = pcap_next_ex(fw->handle, &header, &packet);
        if (ret == -1) {
            fprintf(stderr, "Error reading packet: %s\n", pcap_geterr(fw->handle));
            break;
        } else if (ret == -2) {
            continue;
        }

        int action = firewall_process_packet(fw, &header, packet);
        if (action == 1) {
            fprintf(stdout, "Packet allowed\n");
        } else if (action == -1) {
            fprintf(stdout, "Packet blocked\n");
        }
    }
}

static void firewall_usage(char *argv[]) {
    fprintf(stderr, "Usage: %s <interface> <rules_file>\n", argv[0]);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        firewall_usage(argv);
    }

    struct firewall_state fw;
    firewall_init(&fw, argv[1]);

    FILE *rules_file = fopen(argv[2], "r");
    if (rules_file == NULL) {
        perror("Error opening rules file");
        firewall_cleanup(&fw);
        exit(EXIT_FAILURE);
    }

    char line[1024];
    int num_rules = 0;
    while (fgets(line, sizeof(line), rules_file)) {
        struct firewall_rule rule;
        memset(&rule, 0, sizeof(rule));

        int ret = sscanf(line, "%u %u %hu %hu %hhu %hhu", &rule.src_ip, &rule.dst_ip, &rule.src_port, &rule.dst_port, &rule.protocol, &rule.action);
        if (ret != 6) {
            fprintf(stderr, "Error parsing rule: %s\n", line);
            continue;
        }

        num_rules++;
    }

    fclose(rules_file);

    fw.rules = malloc(sizeof(struct firewall_rule) * num_rules);
    if (fw.rules == NULL) {
        perror("Error allocating memory for rules");
        firewall_cleanup(&fw);
        exit(EXIT_FAILURE);
    }

    FILE *rules_file2 = fopen(argv[2], "r");
    if (rules_file2 == NULL) {
        perror("Error opening rules file");
        firewall_cleanup(&fw);
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (fgets(line, sizeof(line), rules_file2)) {
        struct firewall_rule rule;
        memset(&rule, 0, sizeof(rule));

        int ret = sscanf(line, "%u %u %hu %hu %hhu %hhu", &rule.src_ip, &rule.dst_ip, &rule.src_port, &rule.dst_port, &rule.protocol, &rule.action);
        if (ret != 6) {
            fprintf(stderr, "Error parsing rule: %s\n", line);
            continue;
        }

        fw.rules[i] = rule;
        i++;
    }

    fclose(rules_file2);

    fw.num_rules = num_rules;

    firewall_loop(&fw);

    firewall_cleanup(&fw);

    return EXIT_SUCCESS;
}