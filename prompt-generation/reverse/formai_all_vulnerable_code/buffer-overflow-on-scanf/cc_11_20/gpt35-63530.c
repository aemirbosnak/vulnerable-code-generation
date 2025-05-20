//FormAI DATASET v1.0 Category: Firewall ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LENGTH 15
#define MAX_RULES 100

typedef struct {
    char ipAddress[MAX_IP_LENGTH+1];
    int portNumber;
} FirewallRule;

int main() {

    char input[MAX_IP_LENGTH+1];
    FirewallRule rules[MAX_RULES];
    int numRules = 0;

    while (1) {
        printf("Enter an IP address (q to quit): ");
        scanf("%s", input);
        if (strcmp(input, "q") == 0) {
            break;
        }
        printf("Enter a port number: ");
        int portNumber;
        scanf("%d", &portNumber);
        if (numRules < MAX_RULES) {
            FirewallRule newRule;
            strcpy(newRule.ipAddress, input);
            newRule.portNumber = portNumber;
            rules[numRules] = newRule;
            numRules++;
        }
        else {
            printf("Error: Maximum number of firewall rules reached.\n");
        }
    }

    printf("Rules in firewall:\n");
    for (int i = 0; i < numRules; i++) {
        printf("%s:%d\n", rules[i].ipAddress, rules[i].portNumber);
    }

    while (1) {
        printf("Enter an IP address and port number to test (q to quit): ");
        char ipAddress[MAX_IP_LENGTH+1];
        int portNumber;
        scanf("%s", ipAddress);
        if (strcmp(ipAddress, "q") == 0) {
            break;
        }
        scanf("%d", &portNumber);
        int allowed = 0;
        for (int i = 0; i < numRules; i++) {
            if (strcmp(ipAddress, rules[i].ipAddress) == 0 && portNumber == rules[i].portNumber) {
                allowed = 1;
                break;
            }
        }
        if (allowed) {
            printf("Access granted.\n");
        }
        else {
            printf("Access denied.\n");
        }
    }

    return 0;
}