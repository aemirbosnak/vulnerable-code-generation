//FormAI DATASET v1.0 Category: Firewall ; Style: invasive
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define IP_LENGTH 16   // Maximum length of an IP address
#define MAX_RULES 50    // Maximum number of rules that the firewall can handle
#define MAX_PORTS 100   // Maximum number of ports that the firewall can handle

typedef struct {
    char name[50];
    char ip[IP_LENGTH];
} rule;

int blocked_ports[MAX_PORTS] = {0}; // Initializing the blocked ports to zero
rule rules[MAX_RULES];  // Initializing the rule array

int main()
{
    int num_rules = 0;  // Keeps track of the number of rules added to the firewall

    while (true) {
        printf("\n");
        printf("1. Add rule\n");
        printf("2. Block port\n");
        printf("3. Unblock port\n");
        printf("4. Exit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Adding a new rule to the firewall
                printf("Enter the rule name: ");
                scanf("%s", rules[num_rules].name);
                printf("Enter the rule IP address: ");
                scanf("%s", rules[num_rules].ip);
                num_rules++;
                break;

            case 2: // Blocking a port
                printf("Enter the port number: ");
                int port_num;
                scanf("%d", &port_num);
                blocked_ports[port_num] = 1;
                printf("Port %d has been successfully blocked.\n", port_num);
                break;

            case 3: // Unblocking a port
                printf("Enter the port number: ");
                int port_num2;
                scanf("%d", &port_num2);
                blocked_ports[port_num2] = 0;
                printf("Port %d has been successfully unblocked.\n", port_num2);
                break;

            case 4: // Exits the program
                printf("Exiting firewall...\n");
                exit(0);

            default: // If an invalid option is entered
                printf("Invalid option selected.\n");
                break;
        }
    }

    return 0;
}