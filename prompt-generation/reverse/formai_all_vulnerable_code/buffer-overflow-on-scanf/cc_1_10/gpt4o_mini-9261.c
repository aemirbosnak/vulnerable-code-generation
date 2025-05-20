//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PasswordEntry {
    char *account;
    char *password;
    struct PasswordEntry *next;
} PasswordEntry;

PasswordEntry *head = NULL;

void addPassword(const char *account, const char *password) {
    PasswordEntry *newEntry = (PasswordEntry *)malloc(sizeof(PasswordEntry));
    newEntry->account = strdup(account);
    newEntry->password = strdup(password);
    newEntry->next = head;
    head = newEntry;
    printf("Password added for account: %s\n", account);
}

void viewPasswords() {
    PasswordEntry *current = head;
    if (current == NULL) {
        printf("No passwords stored.\n");
        return;
    }
    printf("Stored Passwords:\n");
    while (current != NULL) {
        printf("Account: %s | Password: %s\n", current->account, current->password);
        current = current->next;
    }
}

void deletePassword(const char *account) {
    PasswordEntry *current = head;
    PasswordEntry *previous = NULL;
    
    while (current != NULL && strcmp(current->account, account) != 0) {
        previous = current;
        current = current->next;
    }
    
    if (current == NULL) {
        printf("No account found with the name: %s\n", account);
        return;
    }

    if (previous == NULL) {
        head = current->next; // Deleting the head
    } else {
        previous->next = current->next;
    }

    free(current->account);
    free(current->password);
    free(current);
    printf("Deleted password for account: %s\n", account);
}

void freeMemory() {
    PasswordEntry *current = head;
    PasswordEntry *nextEntry;

    while (current != NULL) {
        nextEntry = current->next;
        free(current->account);
        free(current->password);
        free(current);
        current = nextEntry;
    }

    head = NULL;
}

int main() {
    int choice;
    char account[50];
    char password[50];

    do {
        printf("\n=== Password Management System ===\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Delete Password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter account name: ");
                scanf("%s", account);
                printf("Enter password: ");
                scanf("%s", password);
                addPassword(account, password);
                break;
            case 2:
                viewPasswords();
                break;
            case 3:
                printf("Enter account name to delete: ");
                scanf("%s", account);
                deletePassword(account);
                break;
            case 4:
                printf("Exiting...\n");
                freeMemory();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}