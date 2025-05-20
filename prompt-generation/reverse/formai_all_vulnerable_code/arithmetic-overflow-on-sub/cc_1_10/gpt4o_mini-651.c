//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 100
#define MAX_IP_LENGTH 16
#define MAX_DESC_LENGTH 100

typedef struct {
    char ip[MAX_IP_LENGTH];
    char description[MAX_DESC_LENGTH];
} FirewallRule;

typedef struct {
    FirewallRule rules[MAX_RULES];
    int count;
} Firewall;

void add_rule(Firewall *fw, const char *ip, const char *description) {
    if (fw->count >= MAX_RULES) {
        printf("Cannot add more rules. Maximum limit reached.\n");
        return;
    }
    strncpy(fw->rules[fw->count].ip, ip, MAX_IP_LENGTH);
    strncpy(fw->rules[fw->count].description, description, MAX_DESC_LENGTH);
    fw->count++;
    printf("Rule added: %s - %s\n", ip, description);
}

void display_rules(Firewall *fw) {
    if (fw->count == 0) {
        printf("No rules in the firewall.\n");
        return;
    }
    printf("Current Firewall Rules:\n");
    for (int i = 0; i < fw->count; i++) {
        printf("%d: %s - %s\n", i + 1, fw->rules[i].ip, fw->rules[i].description);
    }
}

void delete_rule(Firewall *fw, int index) {
    if (index < 0 || index >= fw->count) {
        printf("Invalid rule index.\n");
        return;
    }
    for (int i = index; i < fw->count - 1; i++) {
        fw->rules[i] = fw->rules[i + 1];
    }
    fw->count--;
    printf("Rule deleted at index %d.\n", index + 1);
}

void manage_firewall(Firewall *fw) {
    int choice;
    char ip[MAX_IP_LENGTH];
    char description[MAX_DESC_LENGTH];
    int rule_number;

    while (1) {
        printf("\nFirewall Management Menu:\n");
        printf("1. Add Rule\n");
        printf("2. Display Rules\n");
        printf("3. Delete Rule\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter IP to block: ");
                scanf("%s", ip);
                printf("Enter description: ");
                getchar();  // To consume the newline character
                fgets(description, MAX_DESC_LENGTH, stdin);
                description[strcspn(description, "\n")] = 0;  // Remove newline
                add_rule(fw, ip, description);
                break;
            case 2:
                display_rules(fw);
                break;
            case 3:
                printf("Enter rule index to delete: ");
                scanf("%d", &rule_number);
                delete_rule(fw, rule_number - 1);
                break;
            case 4:
                printf("Exiting...\n");
                return; // Exit the while loop
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    Firewall fw = {.count = 0};
    printf("Welcome to the Firewall Management System\n");
    manage_firewall(&fw);
    return 0;
}