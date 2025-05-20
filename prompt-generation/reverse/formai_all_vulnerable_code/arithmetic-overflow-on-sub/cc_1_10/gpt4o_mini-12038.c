//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RULES 100
#define RULE_LENGTH 256

typedef struct {
    char rule[RULE_LENGTH];
} FirewallRule;

FirewallRule rules[MAX_RULES];
int rule_count = 0;

// Function prototypes
void add_rule(const char *rule);
void remove_rule(int index);
void display_rules();
void save_rules_to_file(const char *filename);
void load_rules_from_file(const char *filename);
void clear_rules();

int main() {
    int choice;
    char rule[RULE_LENGTH];
    const char *filename = "firewall_rules.txt";

    load_rules_from_file(filename);
    printf("Welcome to the Exciting C Firewall!\n");
    
    while (true) {
        printf("\nMenu:\n");
        printf("1. Add Rule\n");
        printf("2. Remove Rule\n");
        printf("3. Display Rules\n");
        printf("4. Save Rules to File\n");
        printf("5. Load Rules from File\n");
        printf("6. Clear All Rules\n");
        printf("7. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character
        
        switch (choice) {
            case 1:
                printf("Enter the rule to add: ");
                fgets(rule, sizeof(rule), stdin);
                rule[strcspn(rule, "\n")] = 0; // Remove newline
                add_rule(rule);
                break;
            case 2:
                printf("Enter the rule number to remove (1-%d): ", rule_count);
                scanf("%d", &choice);
                remove_rule(choice - 1);
                break;
            case 3:
                display_rules();
                break;
            case 4:
                save_rules_to_file(filename);
                printf("Rules saved to '%s'\n", filename);
                break;
            case 5:
                load_rules_from_file(filename);
                printf("Rules loaded from '%s'\n", filename);
                break;
            case 6:
                clear_rules();
                break;
            case 7:
                save_rules_to_file(filename);
                printf("Exiting. Rules saved to '%s'. Thank you for using Exciting C Firewall!\n", filename);
                exit(0);
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}

void add_rule(const char *rule) {
    if (rule_count < MAX_RULES) {
        strncpy(rules[rule_count].rule, rule, RULE_LENGTH - 1);
        rules[rule_count].rule[RULE_LENGTH - 1] = '\0'; // Ensure null-termination
        rule_count++;
        printf("Rule added: %s\n", rule);
    } else {
        printf("Cannot add rule! Maximum limit reached.\n");
    }
}

void remove_rule(int index) {
    if (index >= 0 && index < rule_count) {
        printf("Removing rule: %s\n", rules[index].rule);
        for (int i = index; i < rule_count - 1; i++) {
            rules[i] = rules[i + 1]; // Shift the rules down
        }
        rule_count--;
    } else {
        printf("Invalid rule number!\n");
    }
}

void display_rules() {
    if (rule_count == 0) {
        printf("No rules found!\n");
    } else {
        printf("Current Rules:\n");
        for (int i = 0; i < rule_count; i++) {
            printf("%d. %s\n", i + 1, rules[i].rule);
        }
    }
}

void save_rules_to_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    for (int i = 0; i < rule_count; i++) {
        fprintf(file, "%s\n", rules[i].rule);
    }
    fclose(file);
}

void load_rules_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("No existing rules file found. Starting fresh!\n");
        return;
    }
    clear_rules();
    while (fgets(rules[rule_count].rule, sizeof(rules[rule_count].rule), file) != NULL) {
        rules[rule_count].rule[strcspn(rules[rule_count].rule, "\n")] = 0; // Remove newline
        rule_count++;
    }
    fclose(file);
}

void clear_rules() {
    rule_count = 0;
    printf("All rules cleared!\n");
}