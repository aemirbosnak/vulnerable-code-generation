//FormAI DATASET v1.0 Category: Firewall ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for firewall rules
struct rule{
    char protocol[10];
    char sourceAddress[16];
    int sourcePort;
    char destinationAddress[16];
    int destinationPort;
    char action[7];
};

// Define function to add new rule
void addRule(struct rule *rules, int *numRules){
    struct rule newRule;
    // Get new rule details from user
    printf("Enter the details of the new rule:\n");
    printf("\tProtocol (TCP/UDP): ");
    scanf("%s", newRule.protocol);
    printf("\tSource Address: ");
    scanf("%s", newRule.sourceAddress);
    printf("\tSource Port: ");
    scanf("%d", &newRule.sourcePort);
    printf("\tDestination Address: ");
    scanf("%s", newRule.destinationAddress);
    printf("\tDestination Port: ");
    scanf("%d", &newRule.destinationPort);
    printf("\tAction (ALLOW/BLOCK): ");
    scanf("%s", newRule.action);
    // Add new rule to array of rules
    rules[(*numRules)] = newRule;
    (*numRules)++;
    printf("Rule added successfully.\n");
}

// Define function to remove existing rule
void removeRule(struct rule *rules, int *numRules){
    int i, j, removeIndex;
    char confirm[4];
    // Get index of rule to remove
    printf("Enter the index of the rule to remove (0-%d): ", (*numRules)-1);
    scanf("%d", &removeIndex);
    // Confirm removal
    printf("Are you sure you want to remove the following rule?\n");
    printf("Protocol: %s\n", rules[removeIndex].protocol);
    printf("Source Address: %s\n", rules[removeIndex].sourceAddress);
    printf("Source Port: %d\n", rules[removeIndex].sourcePort);
    printf("Destination Address: %s\n", rules[removeIndex].destinationAddress);
    printf("Destination Port: %d\n", rules[removeIndex].destinationPort);
    printf("Action: %s\n", rules[removeIndex].action);
    printf("Type YES to confirm removal: ");
    scanf("%s", confirm);
    if(strcmp(confirm, "YES") != 0){
        printf("Removal cancelled.\n");
        return;
    }
    // Remove rule by shifting elements over
    for(i=removeIndex; i<(*numRules)-1; i++){
        rules[i] = rules[i+1];
    }
    (*numRules)--;
    printf("Rule removed successfully.\n");
}

// Define function to print all current rules
void printRules(struct rule *rules, int numRules){
    int i;
    printf("Current Firewall Rules:\n");
    for(i=0; i<numRules; i++){
        printf("%d. Protocol: %s, Source Address: %s, Source Port: %d, Destination Address: %s, Destination Port: %d, Action: %s\n", i, rules[i].protocol, rules[i].sourceAddress, rules[i].sourcePort, rules[i].destinationAddress, rules[i].destinationPort, rules[i].action);
    }
}

// Define main function
int main(){
    struct rule rules[100];
    int numRules = 0;
    int i;
    char input[7];
    
    // Initialize some sample rules
    struct rule rule1 = {"TCP", "10.2.1.5", 8080, "192.168.0.1", 80, "ALLOW"};
    rules[numRules++] = rule1;
    struct rule rule2 = {"UDP", "192.168.0.2", 1234, "10.2.1.5", 5678, "BLOCK"};
    rules[numRules++] = rule2;
    
    printf("Welcome to the Future Firewall!\n");
    printf("Enter commands as follows:\n");
    printf("\tADD - Add a new rule\n");
    printf("\tREMOVE - Remove an existing rule\n");
    printf("\tPRINT - Print all current rules\n");
    printf("\tEXIT - Exit the program\n");
    
    while(1){
        printf("Enter command: ");
        scanf("%s", input);
        if(strcmp(input, "ADD") == 0){
            addRule(rules, &numRules);
        }
        else if(strcmp(input, "REMOVE") == 0){
            removeRule(rules, &numRules);
        }
        else if(strcmp(input, "PRINT") == 0){
            printRules(rules, numRules);
        }
        else if(strcmp(input, "EXIT") == 0){
            printf("Exiting Program.\n");
            exit(0);
        }
        else{
            printf("Invalid command. Please try again.\n");
        }
    }
    return 0;
}