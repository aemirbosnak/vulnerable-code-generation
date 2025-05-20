//FormAI DATASET v1.0 Category: Firewall ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
// Declaring constants for max length for the input variables
#define MAX_IP_LENGTH 15
#define MAX_PROTOCOL_LENGTH 10
#define MAX_PORT_LENGTH 10
 
// Declaring the input structure to hold firewall information
struct FirewallRule{
    int id;
    char ipAddress[MAX_IP_LENGTH];
    char protocol[MAX_PROTOCOL_LENGTH];
    char port[MAX_PORT_LENGTH];
};
 
// Function to add a rule to the firewall
void addRule(struct FirewallRule *rules, int *numRules){
    struct FirewallRule newRule;
 
    // Maximum allowed firewall rules is 100
    if(*numRules > 99){
        printf("Maximum number of firewall rules reached\n");
        return;
    }
 
    // Getting the input attributes of the new rule
    printf("Enter the IP address: ");
    scanf("%s",newRule.ipAddress);
    printf("Enter the protocol: ");
    scanf("%s",newRule.protocol);
    printf("Enter the port: ");
    scanf("%s",newRule.port);
 
    // Assigning ID to the rule
    newRule.id = *numRules + 1;
 
    // Adding the rule to the rules database
    rules[*numRules] = newRule;
    *numRules = *numRules + 1;
 
    printf("New rule added successfully\n");
}
 
// Function to delete a rule from the firewall
void deleteRule(struct FirewallRule *rules, int *numRules){
    int ruleId, i, found = 0;
 
    // Getting the rule id to be deleted
    printf("Enter the ID of the rule to be deleted: ");
    scanf("%d",&ruleId);
 
    // Finding the rule with given ID and deleting
    for(i=0; i<*numRules; i++){
        if(rules[i].id == ruleId){
            found = 1;
            break;
        }
    }
    if(found){
        for(; i<*numRules-1; i++){
            rules[i] = rules[i+1];
        }
        *numRules = *numRules - 1;
        printf("Rule with ID %d deleted successfully\n",ruleId);
    }
    else{
        printf("No rule exists with ID %d\n",ruleId);
    }
}
 
// Function to check if a given IP is allowed by the firewall
int checkIp(struct FirewallRule *rules, int *numRules, char *ipAddress){
    int i;
    for(i=0; i<*numRules; i++){
        if(strcmp(rules[i].ipAddress,ipAddress) == 0){
            return 1;
        }
    }
    return 0;
}
 
// Function to check if a given protocol is allowed by the firewall
int checkProtocol(struct FirewallRule *rules, int *numRules, char *protocol){
    int i;
    for(i=0; i<*numRules; i++){
        if(strcmp(rules[i].protocol,protocol) == 0){
            return 1;
        }
    }
    return 0;
}
 
// Function to check if a given port is allowed by the firewall
int checkPort(struct FirewallRule *rules, int *numRules, char *port){
    int i;
    for(i=0; i<*numRules; i++){
        if(strcmp(rules[i].port,port) == 0){
            return 1;
        }
    }
    return 0;
}
 
// Function to process packets through the firewall
void processPacket(struct FirewallRule *rules, int *numRules){
    char ipAddress[MAX_IP_LENGTH], protocol[MAX_PROTOCOL_LENGTH], port[MAX_PORT_LENGTH];
 
    // Getting the packet attributes
    printf("Enter the IP address of the packet: ");
    scanf("%s",ipAddress);
    printf("Enter the protocol of the packet: ");
    scanf("%s",protocol);
    printf("Enter the port of the packet: ");
    scanf("%s",port);
 
    // Checking if the packet is allowed through the firewall
    if(checkIp(rules,numRules,ipAddress) && checkProtocol(rules,numRules,protocol) && checkPort(rules,numRules,port)){
        printf("Packet accepted by the firewall\n");
    }
    else{
        printf("Packet rejected by the firewall\n");
    }
}
 
// Main function to run the firewall program
int main(){
    struct FirewallRule rules[100];
    int numRules = 0, option;
 
    do{
        // Displaying options to the user
        printf("\n---------------------------------------------\n");
        printf("Current number of firewall rules: %d\n",numRules);
        printf("1. Add Rule\n");
        printf("2. Delete Rule\n");
        printf("3. Process Packet\n");
        printf("4. Exit\n");
        printf("---------------------------------------------\n");
        printf("Enter your option: ");
        scanf("%d",&option);
 
        // Executing selected option
        switch(option){
            case 1:
                addRule(rules,&numRules);
                break;
            case 2:
                deleteRule(rules,&numRules);
                break;
            case 3:
                processPacket(rules,&numRules);
                break;
            case 4:
                printf("Thank you for using the firewall\n");
                break;
            default:
                printf("Invalid option selected\n");
                break;
        }
 
    }while(option != 4);
 
    return 0;
}