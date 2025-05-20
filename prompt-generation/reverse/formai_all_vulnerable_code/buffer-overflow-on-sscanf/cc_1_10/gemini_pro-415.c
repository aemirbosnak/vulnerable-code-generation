//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_RULES 100
#define MAX_RULE_SIZE 100

struct rule {
    char src_ip[16];
    char dst_ip[16];
    int src_port;
    int dst_port;
    int protocol;
    char action[10];
};

struct firewall {
    struct rule rules[MAX_RULES];
    int num_rules;
};

int load_rules(struct firewall *fw, char *filename) {
    FILE *fp;
    char line[MAX_RULE_SIZE];
    int i = 0;

    if ((fp = fopen(filename, "r")) == NULL) {
        perror("fopen");
        return -1;
    }

    while (fgets(line, MAX_RULE_SIZE, fp) != NULL) {
        if (line[0] == '#') {
            continue;
        }

        sscanf(line, "%s %s %d %d %d %s", fw->rules[i].src_ip, fw->rules[i].dst_ip, &fw->rules[i].src_port, &fw->rules[i].dst_port, &fw->rules[i].protocol, fw->rules[i].action);

        i++;
    }

    fw->num_rules = i;

    fclose(fp);

    return 0;
}

int check_rule(struct rule *rule, char *src_ip, char *dst_ip, int src_port, int dst_port, int protocol) {
    if (strcmp(rule->src_ip, src_ip) != 0) {
        return 0;
    }

    if (strcmp(rule->dst_ip, dst_ip) != 0) {
        return 0;
    }

    if (rule->src_port != src_port) {
        return 0;
    }

    if (rule->dst_port != dst_port) {
        return 0;
    }

    if (rule->protocol != protocol) {
        return 0;
    }

    return 1;
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <rules file> <src IP> <dst IP> <src port> <dst port> <protocol>\n", argv[0]);
        return -1;
    }

    struct firewall fw;
    if (load_rules(&fw, argv[1]) != 0) {
        perror("load_rules");
        return -1;
    }

    int src_port = atoi(argv[4]);
    int dst_port = atoi(argv[5]);
    int protocol = atoi(argv[6]);

    int i;
    for (i = 0; i < fw.num_rules; i++) {
        if (check_rule(&fw.rules[i], argv[2], argv[3], src_port, dst_port, protocol)) {
            printf("Packet allowed by rule %d.\n", i);
            return 0;
        }
    }

    printf("Packet blocked.\n");

    return 0;
}