//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_IP_LENGTH 16

// Structure to hold a blocking rule
typedef struct {
    char ipAddress[MAX_IP_LENGTH];
} BlockRule;

// Global array of blocking rules
BlockRule blockList[MAX_RULES];
int ruleCount = 0;

// Function to add a blocking rule
void addBlockRule(const char *ip) {
    if (ruleCount < MAX_RULES) {
        strncpy(blockList[ruleCount].ipAddress, ip, MAX_IP_LENGTH);
        ruleCount++;
        printf("Hooray! Blocked IP: %s\n", ip);
    } else {
        printf("Oops! Maximum block rules reached!\n");
    }
}

// Function to display currently blocked IPs
void displayBlockedIPs() {
    if (ruleCount == 0) {
        printf("No IPs are currently blocked. All smiles here!\n");
        return;
    }
    printf("Currently blocked IPs:\n");
    for (int i = 0; i < ruleCount; i++) {
        printf(" - %s\n", blockList[i].ipAddress);
    }
}

// Function to check if an IP is blocked
int isBlocked(const char *ip) {
    for (int i = 0; i < ruleCount; i++) {
        if (strcmp(ip, blockList[i].ipAddress) == 0) {
            return 1; // IP is blocked
        }
    }
    return 0; // IP is not blocked
}

// Main firewall loop
void firewallLoop() {
    char command[50], ip[MAX_IP_LENGTH];

    printf("\nWelcome to the Cheerful Firewall!\n");
    printf("Let's keep the digital space happy and safe! 😊\n");

    while (1) {
        printf("\nEnter a command (add, block check, display, exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Please enter IP address to block: ");
            scanf("%s", ip);
            addBlockRule(ip);
        } 
        else if (strcmp(command, "check") == 0) {
            printf("Enter IP address to check: ");
            scanf("%s", ip);
            if (isBlocked(ip)) {
                printf("Alert! The IP %s is blocked! 🚫\n", ip);
            } else {
                printf("All clear! The IP %s is not blocked! 😊\n", ip);
            }
        } 
        else if (strcmp(command, "display") == 0) {
            displayBlockedIPs();
        } 
        else if (strcmp(command, "exit") == 0) {
            printf("Thank you for using the Cheerful Firewall! Bye! 👋\n");
            break;
        } 
        else {
            printf("Unknown command! Let's be cheerful and try again! ☀️\n");
        }
    }
}

// Main function
int main() {
    firewallLoop();
    return 0;
}