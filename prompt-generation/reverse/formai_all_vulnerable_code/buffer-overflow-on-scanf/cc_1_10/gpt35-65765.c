//FormAI DATASET v1.0 Category: Firewall ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for the firewall rule
struct firewall_rule {
    char source_ip[16];
    char destination_ip[16];
    char protocol[10];
    int port_number;
    int action;
};

// Define a function to add a new rule to the firewall's ruleset
void add_rule(struct firewall_rule *ruleset, int *num_rules) {
    // Prompt the user for the rule's details
    printf("Enter the source IP address: ");
    scanf("%s", ruleset[*num_rules].source_ip);
    printf("Enter the destination IP address: ");
    scanf("%s", ruleset[*num_rules].destination_ip);
    printf("Enter the protocol (tcp or udp): ");
    scanf("%s", ruleset[*num_rules].protocol);
    printf("Enter the port number: ");
    scanf("%d", &ruleset[*num_rules].port_number);
    printf("Enter the action (0 for deny, 1 for allow): ");
    scanf("%d", &ruleset[*num_rules].action);

    // Increment the number of rules in the ruleset
    *num_rules += 1;
}

// Define a function to check whether a packet matches a rule in the firewall's ruleset
int is_packet_allowed(struct firewall_rule *ruleset, int num_rules, char *source_ip, char *destination_ip, char *protocol, int port_number) {
    int i;
    for (i = 0; i < num_rules; i++) {
        if (strcmp(ruleset[i].source_ip, source_ip) == 0
            && strcmp(ruleset[i].destination_ip, destination_ip) == 0
            && strcmp(ruleset[i].protocol, protocol) == 0
            && ruleset[i].port_number == port_number) {

            // If the packet matches the rule, return the action (0 for deny, 1 for allow)
            return ruleset[i].action;
        }
    }

    // If no rules match the packet, default to deny
    return 0;
}

int main() {
    // Initialize the firewall ruleset and number of rules
    struct firewall_rule ruleset[100];
    int num_rules = 0;

    while (1) {
        // Prompt the user for the packet's details
        printf("Enter the source IP address: ");
        char source_ip[16];
        scanf("%s", source_ip);
        printf("Enter the destination IP address: ");
        char destination_ip[16];
        scanf("%s", destination_ip);
        printf("Enter the protocol (tcp or udp): ");
        char protocol[10];
        scanf("%s", protocol);
        printf("Enter the port number: ");
        int port_number;
        scanf("%d", &port_number);

        // Check whether the packet is allowed by the firewall
        int action = is_packet_allowed(ruleset, num_rules, source_ip, destination_ip, protocol, port_number);

        if (action == 1) {
            // If the packet is allowed, print a success message
            printf("Packet accepted by firewall.\n");
        } else {
            // If the packet is denied, print a warning message
            printf("Packet denied by firewall.\n");
        }

        // Ask the user if they would like to add a new rule to the firewall
        printf("Would you like to add a new rule to the firewall? (y/n): ");
        char response[2];
        scanf("%s", response);
        if (strcmp(response, "y") == 0) {
            add_rule(ruleset, &num_rules);
        } else {
            break;
        }
    }

    return 0;
}