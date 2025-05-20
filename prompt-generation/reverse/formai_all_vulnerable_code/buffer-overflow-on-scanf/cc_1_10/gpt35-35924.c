//FormAI DATASET v1.0 Category: Firewall ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 10
#define MAX_IPLEN 16

struct Rule {
    char sourceIP[MAX_IPLEN];
    char destIP[MAX_IPLEN];
    int port;
    char protocol[5];
};

void add_rule(struct Rule **rules, int *num_rules) {
    char src_ip[MAX_IPLEN], dest_ip[MAX_IPLEN], protocol[5];
    int port;
    printf("Enter source IP address: ");
    scanf("%s", src_ip);
    printf("Enter destination IP address: ");
    scanf("%s", dest_ip);
    printf("Enter destination port: ");
    scanf("%d", &port);
    printf("Enter protocol (TCP/UDP): ");
    scanf("%s", protocol);
    if (*num_rules >= MAX_RULES) {
        printf("Maximum number of rules reached!\n");
        return;
    }
    struct Rule *new_rule = (struct Rule *)malloc(sizeof(struct Rule));
    strcpy(new_rule->sourceIP, src_ip);
    strcpy(new_rule->destIP, dest_ip);
    new_rule->port = port;
    strcpy(new_rule->protocol, protocol);
    rules[*num_rules] = new_rule;
    (*num_rules)++;
}

void print_rules(struct Rule **rules, int num_rules) {
    printf("Source IP\tDest IP\t\tPort\tProtocol\n");
    for (int i = 0; i < num_rules; i++) {
        struct Rule *r = rules[i];
        printf("%s\t%s\t%d\t%s\n", r->sourceIP, r->destIP, r->port, r->protocol);
    }
}

int check_rule(struct Rule **rules, int num_rules, char *src_ip, char *dest_ip, int port, char *protocol) {
    for (int i = 0; i < num_rules; i++) {
        struct Rule *r = rules[i];
        if (strcmp(r->sourceIP, src_ip) == 0 && strcmp(r->destIP, dest_ip) == 0 && r->port == port && strcmp(r->protocol, protocol) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    struct Rule *rules[MAX_RULES];
    int num_rules = 0;
    while (1) {
        printf("\nEnter option:\na) Add rule\nb) Print rules\nc) Check rule\nd) Exit\n");
        char option;
        scanf(" %c", &option);
        switch (option) {
            case 'a':
                add_rule(rules, &num_rules);
                break;

            case 'b':
                print_rules(rules, num_rules);
                break;

            case 'c': {
                char src_ip[MAX_IPLEN], dest_ip[MAX_IPLEN], protocol[5];
                int port;
                printf("Enter source IP address: ");
                scanf("%s", src_ip);
                printf("Enter destination IP address: ");
                scanf("%s", dest_ip);
                printf("Enter destination port: ");
                scanf("%d", &port);
                printf("Enter protocol (TCP/UDP): ");
                scanf("%s", protocol);
                int result = check_rule(rules, num_rules, src_ip, dest_ip, port, protocol);
                if (result == 1) {
                    printf("Rule exists!\n");
                } else {
                    printf("Rule does not exist!\n");
                }
                break;
            }
            case 'd':
                printf("Exiting...");
                exit(0);

            default:
                printf("Invalid option!\n");
        }
    }
}