//FormAI DATASET v1.0 Category: Firewall ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100 //maximum rules defined as 100

typedef struct {
    char src_ip[20]; //source ip address
    char dst_ip[20]; //destination ip address
    char protocol[20]; //protocol
    int src_port; //source port number
    int dst_port; //destination port number
    int allow; //whether the traffic should be allowed or not
} Rule;

int main() {

    Rule rules[MAX_RULES]; //declaring array of rules
    int num_rules = 0; //initializing the number of rules to 0

    printf("*** Welcome to Curious Firewall ***\n\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Rule\n");
        printf("2. Remove Rule\n");
        printf("3. Show Rules\n");
        printf("4. Check Traffic\n");
        printf("5. Exit\n");

        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1: //Adding a new rule

                if (num_rules == MAX_RULES) { //checking if maximum rules have been defined
                    printf("\nCannot add more rules. Maximum %d rules are allowed!\n", MAX_RULES);
                    break;
                }

                printf("\nEnter the details for the new rule:\n");

                Rule r;

                printf("Source IP: ");
                scanf("%s", r.src_ip);

                printf("Destination IP: ");
                scanf("%s", r.dst_ip);

                printf("Protocol: ");
                scanf("%s", r.protocol);

                printf("Source Port: ");
                scanf("%d", &r.src_port);

                printf("Destination Port: ");
                scanf("%d", &r.dst_port);

                printf("Allow/Deny (1/0): ");
                scanf("%d", &r.allow);

                rules[num_rules] = r; //adding the new rule to the array
                num_rules++;

                printf("Rule added successfully!\n");
                
                break;

            case 2: //Removing a rule

                if (num_rules == 0) { //checking if there are any rules to remove
                    printf("\nNo rules to remove!\n");
                    break;
                }

                printf("\nEnter the index of the rule to remove (0-%d): ", num_rules-1);

                int index;
                scanf("%d", &index);

                if (index < 0 || index >= num_rules) { //checking if index is valid
                    printf("\nInvalid index!\n");
                    break;
                }

                for (int i = index; i < num_rules-1; i++) { //shifting rules to fill the gap
                    rules[i] = rules[i+1];
                }

                num_rules--;

                printf("Rule removed successfully!\n");

                break;

            case 3: //Displaying all the rules

                if (num_rules == 0) { //checking if there are any rules to display
                    printf("\nNo rules defined yet!\n");
                    break;
                }

                printf("\nList of all Rules:\n");
                printf("-------------------------------------------------------------------------\n");
                printf("| Index | Source IP | Destination IP | Protocol | Source Port | Destination Port | Allow |\n");
                printf("-------------------------------------------------------------------------\n");

                for (int i = 0; i < num_rules; i++) {
                    printf("| %5d | %9s | %13s | %8s | %11d | %16d | %5d |\n", i, rules[i].src_ip, rules[i].dst_ip,
                    rules[i].protocol, rules[i].src_port, rules[i].dst_port, rules[i].allow);
                }

                printf("-------------------------------------------------------------------------\n");

                break;

            case 4: //Checking traffic

                if (num_rules == 0) { //checking if there are any rules defined
                    printf("\nNo rules defined yet!\n");
                    break;
                }

                printf("\nEnter details of the incoming traffic to check:\n");

                char src_ip[20];
                char dst_ip[20];
                char protocol[20];
                int src_port;
                int dst_port;

                printf("Source IP: ");
                scanf("%s", src_ip);

                printf("Destination IP: ");
                scanf("%s", dst_ip);

                printf("Protocol: ");
                scanf("%s", protocol);

                printf("Source Port: ");
                scanf("%d", &src_port);

                printf("Destination Port: ");
                scanf("%d", &dst_port);

                int traffic_allowed = 0;

                for (int i = 0; i < num_rules; i++) {

                    if (strcmp(src_ip, rules[i].src_ip) == 0 || strcmp(rules[i].src_ip, "*") == 0) { //checking source IP or * for all sources
                        if (strcmp(dst_ip, rules[i].dst_ip) == 0 || strcmp(rules[i].dst_ip, "*") == 0) { //checking destination IP or * for all destinations
                            if (strcmp(protocol, rules[i].protocol) == 0 || strcmp(rules[i].protocol, "*") == 0) { //checking protocol or * for all protocols
                                if (src_port == rules[i].src_port || rules[i].src_port == -1) { //checking source port or -1 for all ports
                                    if (dst_port == rules[i].dst_port || rules[i].dst_port == -1) { //checking destination port or -1 for all ports
                                        traffic_allowed = rules[i].allow; //allowing or denying traffic based on the rule
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }

                if (traffic_allowed) {
                    printf("\nTraffic allowed!\n");
                } else {
                    printf("\nTraffic denied!\n");
                }

                break;

            case 5: //Exiting the program
                printf("\nThank you for using Curious Firewall!\n");
                exit(0);
                break;

            default: //Invalid choice
                printf("\nInvalid Choice!\n");
                break;
        }
    }

    return 0;
}