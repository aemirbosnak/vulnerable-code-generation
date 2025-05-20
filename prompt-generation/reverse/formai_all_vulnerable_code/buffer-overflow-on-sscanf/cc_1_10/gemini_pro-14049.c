//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <net/if.h>

#define MAX_RULES 100
#define MAX_RULE_SIZE 1024

typedef struct rule_t {
    char source_ip[16];
    char destination_ip[16];
    int source_port;
    int destination_port;
    char protocol[16];
    int action;
} rule_t;

rule_t rules[MAX_RULES];
int num_rules = 0;

int load_firewall_rules() {
    FILE *fp;
    char buf[MAX_RULE_SIZE];
    int i;

    fp = fopen("firewall.conf", "r");
    if (fp == NULL) {
        return -1;
    }

    while (fgets(buf, MAX_RULE_SIZE, fp) != NULL) {
        if (num_rules >= MAX_RULES) {
            fclose(fp);
            return -1;
        }

        sscanf(buf, "%s %s %d %d %s %d", rules[num_rules].source_ip, rules[num_rules].destination_ip, &rules[num_rules].source_port, &rules[num_rules].destination_port, rules[num_rules].protocol, &rules[num_rules].action);
        num_rules++;
    }

    fclose(fp);
    return 0;
}

int apply_firewall_rules() {
    struct sockaddr_in sin;
    int sockfd, i;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
    if (sockfd < 0) {
        return -1;
    }

    for (i = 0; i < num_rules; i++) {
        memset(&sin, 0, sizeof(struct sockaddr_in));
        sin.sin_family = AF_INET;
        sin.sin_addr.s_addr = inet_addr(rules[i].destination_ip);

        if (setsockopt(sockfd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &sin, sizeof(struct sockaddr_in)) < 0) {
            close(sockfd);
            return -1;
        }
    }

    close(sockfd);
    return 0;
}

int main() {
    if (load_firewall_rules() < 0) {
        printf("Error loading firewall rules\n");
        return -1;
    }

    if (apply_firewall_rules() < 0) {
        printf("Error applying firewall rules\n");
        return -1;
    }

    printf("Firewall rules applied successfully\n");
    return 0;
}