//FormAI DATASET v1.0 Category: Firewall ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FirewallRule {
    char sourceIP[16];
    char destinationIP[16];
    char protocol[10];
    int sourcePort;
    int destinationPort;
};

int main() {
    int numOfRules = 0;
    struct FirewallRule firewall[10];

    while (1) {
        printf("Enter a command (add/rm/check/exit): ");

        char command[10];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            if (numOfRules >= 10) {
                printf("Error: Maximum number of rules reached.\n");
            } else {
                printf("Enter the source IP address: ");
                scanf("%s", firewall[numOfRules].sourceIP);

                printf("Enter the destination IP address: ");
                scanf("%s", firewall[numOfRules].destinationIP);

                printf("Enter the protocol (TCP/UDP/ICMP): ");
                scanf("%s", firewall[numOfRules].protocol);

                printf("Enter the source port: ");
                scanf("%d", &firewall[numOfRules].sourcePort);

                printf("Enter the destination port: ");
                scanf("%d", &firewall[numOfRules].destinationPort);

                printf("Rule added successfully.\n");

                numOfRules++;
            }
        } else if (strcmp(command, "rm") == 0) {
            if (numOfRules == 0) {
                printf("Error: No rules to remove.\n");
            } else {
                printf("Enter the rule number to remove: ");
                int ruleNo;
                scanf("%d", &ruleNo);

                if (ruleNo < 1 || ruleNo > numOfRules) {
                    printf("Error: Invalid rule number.\n");
                } else {
                    for (int i = ruleNo - 1; i < numOfRules - 1; i++) {
                        strcpy(firewall[i].sourceIP, firewall[i+1].sourceIP);
                        strcpy(firewall[i].destinationIP, firewall[i+1].destinationIP);
                        strcpy(firewall[i].protocol, firewall[i+1].protocol);
                        firewall[i].sourcePort = firewall[i+1].sourcePort;
                        firewall[i].destinationPort = firewall[i+1].destinationPort;
                    }

                    numOfRules--;

                    printf("Rule removed successfully.\n");
                }
            }
        } else if (strcmp(command, "check") == 0) {
            printf("Enter the source IP address: ");
            char sourceIP[16];
            scanf("%s", sourceIP);

            printf("Enter the destination IP address: ");
            char destinationIP[16];
            scanf("%s", destinationIP);

            printf("Enter the protocol (TCP/UDP/ICMP): ");
            char protocol[10];
            scanf("%s", protocol);

            printf("Enter the source port: ");
            int sourcePort;
            scanf("%d", &sourcePort);

            printf("Enter the destination port: ");
            int destinationPort;
            scanf("%d", &destinationPort);

            int matchFound = 0;
            for (int i = 0; i < numOfRules; i++) {
                if (strcmp(sourceIP, firewall[i].sourceIP) == 0 &&
                    strcmp(destinationIP, firewall[i].destinationIP) == 0 &&
                    strcmp(protocol, firewall[i].protocol) == 0 &&
                    sourcePort == firewall[i].sourcePort &&
                    destinationPort == firewall[i].destinationPort) {
                    printf("Match found with rule %d.\n", i+1);
                    matchFound = 1;
                    break;
                }
            }

            if (!matchFound) {
                printf("No match found.\n");
            }
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting...\n");
            exit(0);
        } else {
            printf("Error: Invalid command.\n");
        }
    }
}