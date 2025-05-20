//FormAI DATASET v1.0 Category: Firewall ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 1000 // Maximum number of rules

typedef struct {
    char protocol[10];
    char srcIP[20];
    char destIP[20];
    int srcPort;
    int destPort;
    char action[6];
} Rule;

int main() {
    Rule rules[MAX_RULES]; // Array of rules
    int numOfRules = 0; // Number of rules currently stored
    
    printf("Welcome to the Happy Firewall!\n");
    
    // Loop to add rules
    while(numOfRules < MAX_RULES) {
        Rule newRule;
        printf("Please enter the protocol (TCP/UDP): ");
        scanf("%s", newRule.protocol);
        printf("Please enter the source IP address: ");
        scanf("%s", newRule.srcIP);
        printf("Please enter the destination IP address: ");
        scanf("%s", newRule.destIP);
        printf("Please enter the source port number: ");
        scanf("%d", &newRule.srcPort);
        printf("Please enter the destination port number: ");
        scanf("%d", &newRule.destPort);
        printf("Please enter the action (allow/deny): ");
        scanf("%s", newRule.action);
        
        // Add the new rule to the array of rules
        rules[numOfRules] = newRule;
        numOfRules++;
        
        // Ask if the user wants to add another rule
        char answer[4];
        printf("Do you want to add another rule? (yes/no): ");
        scanf("%s", answer);
        if(strcmp(answer, "no") == 0) {
            break;
        }
    }
    
    // Loop to check packets against rules
    char packetProtocol[10];
    char packetSrcIP[20];
    char packetDestIP[20];
    int packetSrcPort;
    int packetDestPort;
    char packetAction[6];
    
    printf("\nLet's start filtering packets! Enter 'stop' to exit.\n");
    
    while(1) {
        printf("\nEnter the protocol (TCP/UDP): ");
        scanf("%s", packetProtocol);
        if(strcmp(packetProtocol, "stop") == 0) {
            break;
        }
        printf("Enter the source IP address: ");
        scanf("%s", packetSrcIP);
        printf("Enter the destination IP address: ");
        scanf("%s", packetDestIP);
        printf("Enter the source port number: ");
        scanf("%d", &packetSrcPort);
        printf("Enter the destination port number: ");
        scanf("%d", &packetDestPort);
        
        // Loop through all rules to find a match
        int matchFound = 0;
        for(int i=0; i<numOfRules; i++) {
            if(strcmp(packetProtocol, rules[i].protocol) == 0 &&
               strcmp(packetSrcIP, rules[i].srcIP) == 0 &&
               strcmp(packetDestIP, rules[i].destIP) == 0 &&
               packetSrcPort == rules[i].srcPort &&
               packetDestPort == rules[i].destPort) {
                   strcpy(packetAction, rules[i].action);
                   matchFound = 1;
                   break;
               }
        }
        
        // If a rule match was found, print the action taken
        if(matchFound) {
            printf("Action taken: %s\n", packetAction);
        }
        // If no rule match was found, allow the packet by default
        else {
            printf("No matching rule found, allowing packet.\n");
        }
    }
    
    printf("\nThanks for using the Happy Firewall!\n");
    
    return 0;
}