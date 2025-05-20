//FormAI DATASET v1.0 Category: Firewall ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold firewall rules
typedef struct Firewall_Rule {
    char source_ip[16];
    char destination_ip[16];
    char protocol[6];
    int source_port;
    int destination_port;
    int action; // 1 : allow, 0 : deny
} Firewall_Rule;

// Function to add a new firewall rule
void add_rule(Firewall_Rule rules[], int *num_rules) {
    if (*num_rules == 10) {
        printf("Firewall rule limit reached!\n");
        return;
    }
    
    Firewall_Rule new_rule;
    printf("Enter source IP: ");
    scanf("%s", new_rule.source_ip);
    printf("Enter destination IP: ");
    scanf("%s", new_rule.destination_ip);
    printf("Enter protocol (TCP or UDP): ");
    scanf("%s", new_rule.protocol);
    printf("Enter source port: ");
    scanf("%d", &new_rule.source_port);
    printf("Enter destination port: ");
    scanf("%d", &new_rule.destination_port);
    printf("Enter action (1 : allow, 0 : deny): ");
    scanf("%d", &new_rule.action);
    
    rules[*num_rules] = new_rule;
    (*num_rules)++;
}

// Function to remove a firewall rule
void remove_rule(Firewall_Rule rules[], int *num_rules) {
    int rule_num;
    
    printf("Enter the number of the rule to be removed: ");
    scanf("%d", &rule_num);
    
    if (rule_num < 1 || rule_num > *num_rules) {
        printf("Invalid rule number!\n");
        return;
    }
    
    for (int i = rule_num; i < *num_rules; i++) {
        rules[i-1] = rules[i];
    }
    (*num_rules)--;
}

// Function to check whether a packet should be allowed or not
int check_packet(Firewall_Rule rules[], int num_rules, char source_ip[], char destination_ip[], char protocol[], int source_port, int destination_port) {
    for (int i = 0; i < num_rules; i++) {
        if (strcmp(rules[i].protocol, protocol)) {
            continue;
        }
        if (strcmp(rules[i].source_ip, source_ip)) {
            continue;
        }
        if (strcmp(rules[i].destination_ip, destination_ip)) {
            continue;
        }
        if (rules[i].source_port != source_port) {
            continue;
        }
        if (rules[i].destination_port != destination_port) {
            continue;
        }
        
        return rules[i].action;
    }
    
    // If no rule matches, deny the packet by default
    return 0;
}

int main() {
    Firewall_Rule rules[10];
    int num_rules = 0;
    
    while (1) {
        printf("\n");
        printf("---------------\n");
        printf("  MENU OPTIONS\n");
        printf("---------------\n");
        printf("1. Add firewall rule\n");
        printf("2. Remove firewall rule\n");
        printf("3. Check packet\n");
        printf("4. Exit\n");
        printf("\n");
        
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_rule(rules, &num_rules);
                break;
            case 2:
                remove_rule(rules, &num_rules);
                break;
            case 3: {
                char source_ip[16];
                char destination_ip[16];
                char protocol[6];
                int source_port;
                int destination_port;
                
                printf("Enter source IP: ");
                scanf("%s", source_ip);
                printf("Enter destination IP: ");
                scanf("%s", destination_ip);
                printf("Enter protocol (TCP or UDP): ");
                scanf("%s", protocol);
                printf("Enter source port: ");
                scanf("%d", &source_port);
                printf("Enter destination port: ");
                scanf("%d", &destination_port);
                
                int result = check_packet(rules, num_rules, source_ip, destination_ip, protocol, source_port, destination_port);
                if (result) {
                    printf("Packet allowed!\n");
                }
                else {
                    printf("Packet denied!\n");
                }
                break;
            }
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}