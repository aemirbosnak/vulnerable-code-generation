//FormAI DATASET v1.0 Category: Firewall ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

#define MAX_RULES 1000

struct Rule {
    uint32_t src_ip;
    uint32_t dst_ip;
    uint16_t src_port;
    uint16_t dst_port;
    uint8_t proto;
    uint8_t action; 
};

int allow_all = 0;
struct Rule rules[MAX_RULES];
int num_rules = 0;

void add_rule(uint32_t s_ip, uint32_t d_ip, uint16_t s_port, uint16_t d_port, uint8_t proto, uint8_t action) {
    if (num_rules >= MAX_RULES) {
        printf("Maximum number of rules reached\n");
        return;
    }
    rules[num_rules].src_ip = s_ip;
    rules[num_rules].dst_ip = d_ip;
    rules[num_rules].src_port = s_port;
    rules[num_rules].dst_port = d_port;
    rules[num_rules].proto = proto;
    rules[num_rules].action = action;
    num_rules++;
}

int match_rule(uint32_t s_ip, uint32_t d_ip, uint16_t s_port, uint16_t d_port, uint8_t proto) {
    if (allow_all) {
        return 1;
    }
    for (int i = 0; i < num_rules; i++) {
        if (rules[i].src_ip == 0 || rules[i].src_ip == s_ip) {
            if (rules[i].dst_ip == 0 || rules[i].dst_ip == d_ip) {
                if (rules[i].src_port == 0 || rules[i].src_port == s_port) {
                    if (rules[i].dst_port == 0 || rules[i].dst_port == d_port) {
                        if (rules[i].proto == 0 || rules[i].proto == proto) {
                            return rules[i].action;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

void print_rule(struct Rule rule) {
    printf("%d.%d.%d.%d:%d -> %d.%d.%d.%d:%d %s %s\n",
           (rule.src_ip >> 24) & 0xFF, (rule.src_ip >> 16) & 0xFF, (rule.src_ip >> 8) & 0xFF, rule.src_ip & 0xFF, ntohs(rule.src_port),
           (rule.dst_ip >> 24) & 0xFF, (rule.dst_ip >> 16) & 0xFF, (rule.dst_ip >> 8) & 0xFF, rule.dst_ip & 0xFF, ntohs(rule.dst_port),
           rule.proto == IPPROTO_TCP ? "TCP" : "UDP",
           rule.action == 1 ? "allow" : "deny");
}

void print_rules() {
    printf("Rules:\n");
    if (allow_all) {
        printf("Allow all\n");
    } else {
        for (int i = 0; i < num_rules; i++) {
            print_rule(rules[i]);
        }
    }
}

void parse_rule(char *rule_str) {
    char *tokens[6];
    for (int i = 0; i < 6; i++) {
        tokens[i] = strtok(i == 0 ? rule_str : NULL, " ");
        if (tokens[i] == NULL) {
            printf("Invalid rule format: %s\n", rule_str);
            return;
        }
    }
    uint32_t s_ip = 0, d_ip = 0;
    uint16_t s_port = 0, d_port = 0;
    uint8_t proto = 0, action = 0;
    if (strcmp(tokens[0], "any") != 0) {
        if (inet_pton(AF_INET, tokens[0], &s_ip) != 1) {
            printf("Invalid source IP: %s\n", tokens[0]);
            return;
        }
    }
    if (strcmp(tokens[1], "any") != 0) {
        if (inet_pton(AF_INET, tokens[1], &d_ip) != 1) {
            printf("Invalid destination IP: %s\n", tokens[1]);
            return;
        }
    }
    if (strcmp(tokens[2], "any") != 0) {
        if (sscanf(tokens[2], "%hu", &s_port) != 1) {
            printf("Invalid source port: %s\n", tokens[2]);
            return;
        }
    }
    if (strcmp(tokens[3], "any") != 0) {
        if (sscanf(tokens[3], "%hu", &d_port) != 1) {
            printf("Invalid destination port: %s\n", tokens[3]);
            return;
        }
    }
    if (strcmp(tokens[4], "tcp") == 0) {
        proto = IPPROTO_TCP;
    } else if (strcmp(tokens[4], "udp") == 0) {
        proto = IPPROTO_UDP;
    } else if (strcmp(tokens[4], "any") != 0) {
        printf("Invalid protocol: %s\n", tokens[4]);
        return;
    }
    if (strcmp(tokens[5], "allow") == 0) {
        action = 1;
    } else if (strcmp(tokens[5], "deny") == 0) {
        action = 0;
    } else {
        printf("Invalid action: %s\n", tokens[5]);
        return;
    }
    add_rule(s_ip, d_ip, s_port, d_port, proto, action);
}

int main() {
    int sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock_raw < 0) {
        perror("Could not create socket");
        return -1;
    }
    int opt = 1;
    setsockopt(sock_raw, IPPROTO_IP, IP_HDRINCL, &opt, sizeof(opt));
    printf("Firewall started\n");
    while (1) {
        char rule_str[100];
        fgets(rule_str, sizeof(rule_str), stdin);
        if (rule_str[strlen(rule_str) - 1] == '\n') {
            rule_str[strlen(rule_str) - 1] = '\0';
        }
        if (strcmp(rule_str, "rules") == 0) {
            print_rules();
        } else if (strcmp(rule_str, "allow all") == 0) {
            allow_all = 1;
            printf("Enabled allow all\n");
        } else if (strcmp(rule_str, "deny all") == 0) {
            allow_all = 0;
            printf("Disabled allow all\n");
        } else {
            parse_rule(rule_str);
        }
    }
    close(sock_raw);
    return 0;
}