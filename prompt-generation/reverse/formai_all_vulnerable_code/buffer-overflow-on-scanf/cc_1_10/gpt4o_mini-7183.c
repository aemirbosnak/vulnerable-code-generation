//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct PasswordNode {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    struct PasswordNode* next;
} PasswordNode;

PasswordNode* head = NULL;

void addPassword() {
    PasswordNode* new_node = (PasswordNode*)malloc(sizeof(PasswordNode));
    
    if (!new_node) {
        printf("Memory allocation failed. Unable to add new password.\n");
        return;
    }

    printf("Enter website name: ");
    scanf("%s", new_node->website);
    printf("Enter username: ");
    scanf("%s", new_node->username);
    printf("Enter password: ");
    scanf("%s", new_node->password);

    new_node->next = head;
    head = new_node;
    printf("Password added successfully!\n");
}

void retrievePassword() {
    char website[MAX_LENGTH];
    printf("Enter the website name to retrieve password: ");
    scanf("%s", website);
    
    PasswordNode* current = head;
    while (current) {
        if (strcmp(current->website, website) == 0) {
            printf("Website: %s\nUsername: %s\nPassword: %s\n", current->website, current->username, current->password);
            return;
        }
        current = current->next;
    }
    printf("No password found for website: %s\n", website);
}

void deletePassword() {
    char website[MAX_LENGTH];
    printf("Enter the website name to delete password: ");
    scanf("%s", website);
    
    PasswordNode* current = head;
    PasswordNode* previous = NULL;

    while (current) {
        if (strcmp(current->website, website) == 0) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            printf("Password deleted successfully!\n");
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("No password found for website: %s\n", website);
}

void displayAllPasswords() {
    if (!head) {
        printf("No passwords saved.\n");
        return;
    }
    PasswordNode* current = head;
    printf("Stored Passwords:\n");
    while (current) {
        printf("Website: %s, Username: %s\n", current->website, current->username);
        current = current->next;
    }
}

void freeMemory() {
    PasswordNode* current = head;
    PasswordNode* next_node;
    
    while (current) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    
    head = NULL;
}

int main() {
    int choice;
    
    do {
        printf("\n--- Password Manager ---\n");
        printf("1. Add Password\n");
        printf("2. Retrieve Password\n");
        printf("3. Delete Password\n");
        printf("4. Display All Passwords\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                retrievePassword();
                break;
            case 3:
                deletePassword();
                break;
            case 4:
                displayAllPasswords();
                break;
            case 5:
                freeMemory();
                printf("Exiting the Password Manager. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}