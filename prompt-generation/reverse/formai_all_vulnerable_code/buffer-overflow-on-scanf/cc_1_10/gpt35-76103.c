//FormAI DATASET v1.0 Category: Firewall ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct firewall_rule {
    char source_ip[16];
    char dest_ip[16];
    int source_port;
    int dest_port;
    char protocol[4];
    int allow; // 1 for allowing traffic, 0 for blocking traffic
};

void read_rule(struct firewall_rule* rule) {
    printf("Enter the source IP: ");
    scanf("%s", rule->source_ip);

    printf("Enter the destination IP: ");
    scanf("%s", rule->dest_ip);

    printf("Enter the source port: ");
    scanf("%d", &rule->source_port);

    printf("Enter the destination port: ");
    scanf("%d", &rule->dest_port);

    printf("Enter the protocol (TCP or UDP): ");
    scanf("%s", rule->protocol);

    printf("Enter 1 to allow traffic or 0 to block traffic: ");
    scanf("%d", &rule->allow);
}

void print_rule(struct firewall_rule rule) {
    printf("Source IP: %s\n", rule.source_ip);
    printf("Dest IP: %s\n", rule.dest_ip);
    printf("Source Port: %d\n", rule.source_port);
    printf("Dest Port: %d\n", rule.dest_port);
    printf("Protocol: %s\n", rule.protocol);
    printf("Allow: %d\n", rule.allow);
}

int main() {
    int rule_count;
    printf("Enter the number of firewall rules: ");
    scanf("%d", &rule_count);

    struct firewall_rule* rules = malloc(rule_count * sizeof(struct firewall_rule));

    printf("Enter the firewall rules:\n");
    for (int i = 0; i < rule_count; i++) {
        read_rule(&rules[i]);
    }

    printf("\nFirewall Rules:\n");
    for (int i = 0; i < rule_count; i++) {
        printf("Rule %d:\n", i+1);
        print_rule(rules[i]);
    }

    free(rules);

    return 0;
}