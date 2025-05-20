//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define IP_LENGTH 16

typedef struct {
    char sourceIP[IP_LENGTH];
    char destIP[IP_LENGTH];
    int allow;  // 1 for allow, 0 for block
} Rule;

Rule rules[MAX_RULES];
int ruleCount = 0;

void addRule(const char *sourceIP, const char *destIP, int allow);
void listRules();
int filterPacket(const char *sourceIP, const char *destIP);

int main() {
    int choice;
    char sourceIP[IP_LENGTH], destIP[IP_LENGTH];

    printf("Welcome to the Retro C Firewall!\n");
    printf("-----------------------------------\n");

    while (1) {
        printf("\n1. Add Rule\n");
        printf("2. List Rules\n");
        printf("3. Filter Packet\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar();  // Consume newline

        switch (choice) {
            case 1:
                printf("Enter Source IP: ");
                fgets(sourceIP, IP_LENGTH, stdin);
                sourceIP[strcspn(sourceIP, "\n")] = 0;  // Remove newline
                
                printf("Enter Destination IP: ");
                fgets(destIP, IP_LENGTH, stdin);
                destIP[strcspn(destIP, "\n")] = 0;  // Remove newline
                
                printf("Allow (1) or Block (0): ");
                int allow;
                scanf("%d", &allow);
                getchar();  // Consume newline
                
                addRule(sourceIP, destIP, allow);
                break;

            case 2:
                listRules();
                break;

            case 3:
                printf("Enter Source IP of the packet: ");
                fgets(sourceIP, IP_LENGTH, stdin);
                sourceIP[strcspn(sourceIP, "\n")] = 0;  // Remove newline
                
                printf("Enter Destination IP of the packet: ");
                fgets(destIP, IP_LENGTH, stdin);
                destIP[strcspn(destIP, "\n")] = 0;  // Remove newline
                
                if (filterPacket(sourceIP, destIP)) {
                    printf("Packet from %s to %s is allowed.\n", sourceIP, destIP);
                } else {
                    printf("Packet from %s to %s is blocked.\n", sourceIP, destIP);
                }
                break;

            case 4:
                printf("Exiting the Retro C Firewall. Stay safe!\n");
                exit(0);
                break;

            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }
    return 0;
}

void addRule(const char *sourceIP, const char *destIP, int allow) {
    if (ruleCount < MAX_RULES) {
        strncpy(rules[ruleCount].sourceIP, sourceIP, IP_LENGTH);
        strncpy(rules[ruleCount].destIP, destIP, IP_LENGTH);
        rules[ruleCount].allow = allow;
        ruleCount++;
        printf("Rule added: %s to %s is %s\n", 
            sourceIP, destIP, allow ? "allowed" : "blocked");
    } else {
        printf("Rule limit reached!\n");
    }
}

void listRules() {
    if (ruleCount == 0) {
        printf("No rules defined.\n");
    } else {
        printf("Current Firewall Rules:\n");
        for (int i = 0; i < ruleCount; i++) {
            printf("Rule %d: %s to %s is %s\n", 
                i + 1, 
                rules[i].sourceIP, 
                rules[i].destIP, 
                rules[i].allow ? "allowed" : "blocked");
        }
    }
}

int filterPacket(const char *sourceIP, const char *destIP) {
    for (int i = 0; i < ruleCount; i++) {
        if (strcmp(rules[i].sourceIP, sourceIP) == 0 && 
            strcmp(rules[i].destIP, destIP) == 0) {
            return rules[i].allow;
        }
    }
    return 1;  // Default action is to allow if no rule matches
}