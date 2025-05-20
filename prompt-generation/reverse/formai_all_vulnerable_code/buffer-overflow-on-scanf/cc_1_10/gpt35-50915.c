//FormAI DATASET v1.0 Category: Firewall ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100
#define MAX_RULES 10

struct packet{
    char sourceIP[16];
    char destIP[16];
    int port;
};

struct rule{
    char sourceIP[16];
    char destIP[16];
    int port;
    char action[6];
};

struct packet createPacket(char* sourceIP, char* destIP, int port){
    struct packet p;
    strcpy(p.sourceIP, sourceIP);
    strcpy(p.destIP, destIP);
    p.port = port;
    return p;
}

void printPacket(struct packet p){
    printf("Source IP: %s\n", p.sourceIP);
    printf("Destination IP: %s\n", p.destIP);
    printf("Port: %d\n", p.port);
}

void addRule(struct rule rules[], int numRules){
    printf("Enter the source IP: ");
    scanf("%s", rules[numRules].sourceIP);
    printf("Enter the destination IP: ");
    scanf("%s", rules[numRules].destIP);
    printf("Enter the port: ");
    scanf("%d", &rules[numRules].port);
    printf("Enter the action (allow/deny): ");
    scanf("%s", rules[numRules].action);
}

void printRules(struct rule rules[], int numRules){
    printf("Rules:\n");
    for(int i=0; i<numRules; i++){
        printf("Rule %d:\n", i+1);
        printf("\tSource IP: %s\n", rules[i].sourceIP);
        printf("\tDestination IP: %s\n", rules[i].destIP);
        printf("\tPort: %d\n", rules[i].port);
        printf("\tAction: %s\n", rules[i].action);
    }
}

int checkPacket(struct packet p, struct rule rules[], int numRules){
    for(int i=0; i<numRules; i++){
        if(strcmp(rules[i].action, "allow") == 0){
            if(strcmp(rules[i].sourceIP, p.sourceIP) == 0 && strcmp(rules[i].destIP, p.destIP) == 0 && rules[i].port == p.port){
                return 1;
            }
        }
        else{
            if(strcmp(rules[i].sourceIP, p.sourceIP) == 0 && strcmp(rules[i].destIP, p.destIP) == 0 && rules[i].port == p.port){
                return -1;
            }
        }
    }
    return 0;
}

int main(){
    struct rule rules[MAX_RULES];
    int numRules = 0;

    while(1){
        printf("\n1. Add rule\n");
        printf("2. Print rules\n");
        printf("3. Check packet\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        if(choice == 1){
            if(numRules < MAX_RULES){
                addRule(rules, numRules);
                numRules++;
                printf("Rule added successfully!\n");
            }
            else{
                printf("Maximum number of rules reached!\n");
            }
        }
        else if(choice == 2){
            printRules(rules, numRules);
        }
        else if(choice == 3){
            printf("Enter the source IP: ");
            char sourceIP[MAX_INPUT_LENGTH];
            scanf("%s", sourceIP);
            printf("Enter the destination IP: ");
            char destIP[MAX_INPUT_LENGTH];
            scanf("%s", destIP);
            printf("Enter the port: ");
            int port;
            scanf("%d", &port);
            struct packet p = createPacket(sourceIP, destIP, port);
            int result = checkPacket(p, rules, numRules);
            if(result == 1){
                printf("Packet allowed!\n");
            }
            else if(result == -1){
                printf("Packet denied!\n");
            }
            else{
                printf("No matching rule found!\n");
            }
        }
        else if(choice == 4){
            break;
        }
        else{
            printf("Invalid choice!\n");
        }
    }

    return 0;
}