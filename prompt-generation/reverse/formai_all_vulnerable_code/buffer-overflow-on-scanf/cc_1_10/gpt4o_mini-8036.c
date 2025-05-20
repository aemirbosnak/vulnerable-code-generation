//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void display_menu() {
    printf("Simple C Firewall\n");
    printf("1. Add Rule\n");
    printf("2. View Rules\n");
    printf("3. Delete Rule\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

void add_rule(char *rule) {
    char command[256];
    snprintf(command, sizeof(command), "sudo iptables -A %s", rule);
    if (system(command) == -1) {
        perror("Failed to add rule");
    } else {
        printf("Rule added: %s\n", rule);
    }
}

void view_rules() {
    printf("Current firewall rules:\n");
    if (system("sudo iptables -L") == -1) {
        perror("Failed to view rules");
    }
}

void delete_rule(char *rule) {
    char command[256];
    snprintf(command, sizeof(command), "sudo iptables -D %s", rule);
    if (system(command) == -1) {
        perror("Failed to delete rule");
    } else {
        printf("Rule deleted: %s\n", rule);
    }
}

int main() {
    int choice;
    char rule[256];

    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar();  // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter the rule to add (e.g., INPUT -p tcp --dport 80 -j ACCEPT): ");
                fgets(rule, sizeof(rule), stdin);
                rule[strcspn(rule, "\n")] = 0;  // Remove newline character
                add_rule(rule);
                break;
            case 2:
                view_rules();
                break;
            case 3:
                printf("Enter the rule to delete (e.g., INPUT -p tcp --dport 80 -j ACCEPT): ");
                fgets(rule, sizeof(rule), stdin);
                rule[strcspn(rule, "\n")] = 0;  // Remove newline character
                delete_rule(rule);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}