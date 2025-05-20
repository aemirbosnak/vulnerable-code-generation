//FormAI DATASET v1.0 Category: Firewall ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the max size of the firewall list
#define MAX_FIREWALL_LIST 50

// Define struct to represent each firewall rule
typedef struct {
    char sourceIP[16];
    char destIP[16];
    char protocol[10];
    int port;
} FirewallRule;

// Function to check if a given IP address is valid
int isValidIP(char* IP) {
    char* token;
    int count = 0;

    token = strtok(IP, ".");
    while (token != NULL) {
        count++;
        if (count > 4) return 0;
        int num = atoi(token);
        if (num < 0 || num > 255) return 0;
        token = strtok(NULL, ".");
    }

    return (count == 4);
}

// Function to check if a given port number is valid
int isValidPort(int port) {
    return (port >= 0 && port <= 65535);
}

// Function to add a new firewall rule to the list
void addFirewallRule(FirewallRule* firewallList, int* numRules) {
    char sourceIP[16], destIP[16], protocol[10];
    int port;

    printf("Enter source IP address: ");
    scanf("%s", sourceIP);
    if (!isValidIP(sourceIP)) {
        printf("Invalid IP address.\n");
        return;
    }

    printf("Enter destination IP address: ");
    scanf("%s", destIP);
    if (!isValidIP(destIP)) {
        printf("Invalid IP address.\n");
        return;
    }

    printf("Enter protocol: ");
    scanf("%s", protocol);

    printf("Enter port number: ");
    scanf("%d", &port);
    if (!isValidPort(port)) {
        printf("Invalid port number.\n");
        return;
    }

    FirewallRule rule;
    strcpy(rule.sourceIP, sourceIP);
    strcpy(rule.destIP, destIP);
    strcpy(rule.protocol, protocol);
    rule.port = port;

    firewallList[*numRules] = rule;
    (*numRules)++;
}

// Function to remove a firewall rule from the list
void removeFirewallRule(FirewallRule* firewallList, int* numRules) {
    char sourceIP[16], destIP[16], protocol[10];
    int port;

    printf("Enter source IP address: ");
    scanf("%s", sourceIP);

    printf("Enter destination IP address: ");
    scanf("%s", destIP);

    printf("Enter protocol: ");
    scanf("%s", protocol);

    printf("Enter port number: ");
    scanf("%d", &port);

    for (int i = 0; i < *numRules; i++) {
        if (strcmp(firewallList[i].sourceIP, sourceIP) == 0 &&
            strcmp(firewallList[i].destIP, destIP) == 0 &&
            strcmp(firewallList[i].protocol, protocol) == 0 &&
            firewallList[i].port == port) {
            for (int j = i; j < *numRules - 1; j++) {
                firewallList[j] = firewallList[j + 1];
            }
            (*numRules)--;
            printf("Firewall rule removed.\n");
            return;
        }
    }

    printf("Firewall rule not found.\n");
}

// Function to check if a given packet matches any of the firewall rules
int checkFirewallRules(FirewallRule* firewallList, int numRules, char* sourceIP, char* destIP, char* protocol, int port) {
    for (int i = 0; i < numRules; i++) {
        if (strcmp(firewallList[i].sourceIP, sourceIP) == 0 || strcmp(firewallList[i].sourceIP, "*") == 0) {
            if (strcmp(firewallList[i].destIP, destIP) == 0 || strcmp(firewallList[i].destIP, "*") == 0) {
                if (strcmp(firewallList[i].protocol, protocol) == 0 || strcmp(firewallList[i].protocol, "*") == 0) {
                    if (firewallList[i].port == port || firewallList[i].port == -1) {
                        return 1;
                    }
                }
            }
        }
    }

    return 0;
}

// Main function
int main() {
    FirewallRule firewallList[MAX_FIREWALL_LIST];
    int numRules = 0;

    printf("FIREWALL EXAMPLE PROGRAM\n\n");

    while (1) {
        printf("\n");
        printf("1. Add firewall rule\n");
        printf("2. Remove firewall rule\n");
        printf("3. Check packet against firewall rules\n");
        printf("4. Exit\n");
        printf("\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addFirewallRule(firewallList, &numRules);
                break;
            case 2:
                removeFirewallRule(firewallList, &numRules);
                break;
            case 3: {
                char sourceIP[16], destIP[16], protocol[10];
                int port;

                printf("Enter source IP address: ");
                scanf("%s", sourceIP);

                printf("Enter destination IP address: ");
                scanf("%s", destIP);

                printf("Enter protocol: ");
                scanf("%s", protocol);

                printf("Enter port number: ");
                scanf("%d", &port);

                int result = checkFirewallRules(firewallList, numRules, sourceIP, destIP, protocol, port);
                if (result) {
                    printf("Packet allowed.\n");
                } else {
                    printf("Packet blocked.\n");
                }

                break;
            }
            case 4:
                printf("Exiting program.\n");
                return 0;
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}