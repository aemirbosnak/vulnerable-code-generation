//Falcon-180B DATASET v1.0 Category: Firewall ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_RULE_LENGTH 80

typedef struct {
    char source_ip[16];
    char dest_ip[16];
    char protocol[10];
    int source_port;
    int dest_port;
    int action;
} rule_t;

void add_rule(rule_t rules[], int num_rules) {
    printf("Enter the source IP address: ");
    scanf("%s", rules[num_rules].source_ip);

    printf("Enter the destination IP address: ");
    scanf("%s", rules[num_rules].dest_ip);

    printf("Enter the protocol (TCP/UDP): ");
    scanf("%s", rules[num_rules].protocol);

    printf("Enter the source port: ");
    scanf("%d", &rules[num_rules].source_port);

    printf("Enter the destination port: ");
    scanf("%d", &rules[num_rules].dest_port);

    printf("Enter the action (allow/deny): ");
    scanf("%d", &rules[num_rules].action);

    num_rules++;
}

void print_rules(rule_t rules[], int num_rules) {
    printf("Firewall Rules:\n");
    for(int i=0; i<num_rules; i++) {
        printf("Rule %d:\n", i+1);
        printf("Source IP: %s\n", rules[i].source_ip);
        printf("Dest IP: %s\n", rules[i].dest_ip);
        printf("Protocol: %s\n", rules[i].protocol);
        printf("Source Port: %d\n", rules[i].source_port);
        printf("Dest Port: %d\n", rules[i].dest_port);
        printf("Action: %s\n\n", rules[i].action == 0? "Allow" : "Deny");
    }
}

void evaluate_packet(rule_t rules[], int num_rules, char* src_ip, char* dest_ip, char* protocol, int src_port, int dest_port) {
    for(int i=0; i<num_rules; i++) {
        if(strcmp(rules[i].source_ip, src_ip) == 0 &&
           strcmp(rules[i].dest_ip, dest_ip) == 0 &&
           strcmp(rules[i].protocol, protocol) == 0 &&
           rules[i].source_port == src_port &&
           rules[i].dest_port == dest_port) {
            if(rules[i].action == 0) {
                printf("Packet allowed.\n");
            } else {
                printf("Packet denied.\n");
            }
            return;
        }
    }
    printf("No matching rule found.\n");
}

int main() {
    rule_t rules[MAX_RULES];
    int num_rules = 0;

    add_rule(rules, num_rules);
    add_rule(rules, num_rules);
    add_rule(rules, num_rules);

    print_rules(rules, num_rules);

    char src_ip[16] = "192.168.1.1";
    char dest_ip[16] = "192.168.1.2";
    char protocol[10] = "TCP";
    int src_port = 80;
    int dest_port = 8080;

    evaluate_packet(rules, num_rules, src_ip, dest_ip, protocol, src_port, dest_port);

    return 0;
}