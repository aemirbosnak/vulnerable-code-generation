//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100
#define MAX_NAME_LENGTH 50

typedef struct PasswordNode {
    char name[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    struct PasswordNode* next;
} PasswordNode;

PasswordNode* head = NULL;

void addPassword() {
    PasswordNode* newNode = (PasswordNode*)malloc(sizeof(PasswordNode));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter the name for the password entry: ");
    scanf("%s", newNode->name);
    printf("Enter the password: ");
    scanf("%s", newNode->password);
    
    newNode->next = head;
    head = newNode;

    printf("Password entry added successfully!\n");
}

void displayPasswords() {
    PasswordNode* current = head;
    if (current == NULL) {
        printf("No stored passwords found.\n");
        return;
    }
    
    printf("\nStored Passwords:\n");
    while (current != NULL) {
        printf("Name: %s, Password: %s\n", current->name, current->password);
        current = current->next;
    }
}

void deletePassword() {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the password entry to delete: ");
    scanf("%s", name);
    
    PasswordNode* current = head;
    PasswordNode* prev = NULL;
    
    while (current != NULL && strcmp(current->name, name) != 0) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Password entry not found.\n");
        return;
    }
    
    if (prev == NULL) {
        head = current->next; // Deleting the head
    } else {
        prev->next = current->next; // Bypass the current node
    }

    free(current);
    printf("Password entry deleted successfully!\n");
}

void freeMemory() {
    PasswordNode* current = head;
    while (current != NULL) {
        PasswordNode* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    int choice;
    
    do {
        printf("\nPassword Management System\n");
        printf("1. Add Password\n");
        printf("2. Display Passwords\n");
        printf("3. Delete Password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                displayPasswords();
                break;
            case 3:
                deletePassword();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    
    freeMemory();
    return 0;
}