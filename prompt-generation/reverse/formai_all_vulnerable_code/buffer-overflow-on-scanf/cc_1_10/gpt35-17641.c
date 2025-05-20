//FormAI DATASET v1.0 Category: Firewall ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// define the maximum size of IP address and port number
#define MAX_IP_LEN 16
#define MAX_PORT_LEN 6

// define the maximum number of rules in the firewall
#define MAX_RULES 10

// define struct for firewall rule
typedef struct {
    char ip[MAX_IP_LEN];
    char port[MAX_PORT_LEN];
} Rule;

int main() {
    // initialize firewall with an empty rule set
    Rule rules[MAX_RULES];
    int num_rules = 0;

    // loop to get user input for firewall rules
    while (num_rules < MAX_RULES) {
        char ip[MAX_IP_LEN];
        char port[MAX_PORT_LEN];
        printf("Enter IP address and port number (separated by space) for rule %d (or 'done' to finish): ", num_rules + 1);
        scanf("%s %s", ip, port);

        // check if user has input 'done' to indicate that they are finished adding rules
        if (strcmp(ip, "done") == 0 || strcmp(port, "done") == 0) {
            break;
        }

        // validate user input to ensure that IP address and port number are valid
        struct sockaddr_in sa;
        int result = inet_pton(AF_INET, ip, &(sa.sin_addr));
        int port_num = atoi(port);
        if (result == 0 || port_num <= 0 || port_num > 65535) {
            printf("Invalid IP address or port number.\n");
            continue;
        }

        // add the rule to the firewall
        strcpy(rules[num_rules].ip, ip);
        strcpy(rules[num_rules].port, port);
        num_rules++;
    }

    // display the rules in the firewall
    printf("Firewall rules:\n");
    for (int i = 0; i < num_rules; i++) {
        printf("%d. IP address: %s \t Port: %s\n", i+1, rules[i].ip, rules[i].port);
    }

    return 0;
}