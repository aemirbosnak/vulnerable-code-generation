//FormAI DATASET v1.0 Category: Firewall ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the maximum size of the firewall's rule table
#define MAX_RULES 100

// define the maximum length of an IP address or subnet mask
#define MAX_IP_LEN 20

// define the maximum length of a port range
#define MAX_PORT_LEN 10

// define a struct to represent a firewall rule
typedef struct {
    char source_ip[MAX_IP_LEN];
    char dest_ip[MAX_IP_LEN];
    char port_range[MAX_PORT_LEN];
} FirewallRule;

int main() {
    // create an array to hold the firewall rules
    FirewallRule rules[MAX_RULES];

    // initialize the rule table to all zeros
    memset(rules, 0, sizeof(rules));

    // prompt the user to enter firewall rules until they enter "done"
    int num_rules = 0;
    while (1) {
        printf("Enter a firewall rule (source IP, destination IP, port range), or \"done\" to finish\n");
        char input[100];
        fgets(input, sizeof(input), stdin);

        // if the user entered "done", exit the loop
        if (strcmp(input, "done\n") == 0) {
            break;
        }

        // parse the input string into a rule struct
        FirewallRule rule;
        if (sscanf(input, "%s %s %s", rule.source_ip, rule.dest_ip, rule.port_range) != 3) {
            printf("Invalid input. Please enter a valid rule (e.g. 192.168.0.1 192.168.0.2 80-90)\n");
            continue;
        }

        // add the rule to the table
        rules[num_rules] = rule;
        num_rules++;

        // check if the rule table is full
        if (num_rules == MAX_RULES) {
            printf("Maximum number of rules reached (%d).\n", MAX_RULES);
            break;
        }
    }

    // prompt the user to enter an IP address and port number to test the firewall
    char test_ip[MAX_IP_LEN];
    char test_port[MAX_PORT_LEN];
    printf("Enter an IP address to test: ");
    fgets(test_ip, sizeof(test_ip), stdin);
    printf("Enter a port number to test: ");
    fgets(test_port, sizeof(test_port), stdin);

    // check if the test IP address and port number match any rules in the table
    int i;
    for (i = 0; i < num_rules; i++) {
        if (strcmp(test_ip, rules[i].source_ip) == 0
            && strcmp(test_port, rules[i].port_range) >= 0) {
            printf("Firewall rule matched: Allow\n");
            return 0;
        }
    }

    // if the test IP address and port number don't match any rules, deny the connection
    printf("Firewall rule not matched: Deny\n");
    return 0;
}