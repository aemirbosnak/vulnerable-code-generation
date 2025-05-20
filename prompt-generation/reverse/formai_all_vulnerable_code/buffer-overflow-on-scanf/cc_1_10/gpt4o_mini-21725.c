//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PASS_LENGTH 50

// Define a struct for Password Entry
typedef struct PasswordEntry {
    char name[MAX_NAME_LENGTH];
    char password[MAX_PASS_LENGTH];
    struct PasswordEntry* next;
} PasswordEntry;

// Function declarations
void addPassword(PasswordEntry** head);
void viewPasswords(PasswordEntry* head);
void searchPassword(PasswordEntry* head);
void deletePassword(PasswordEntry** head);
void freeList(PasswordEntry* head);
void printMenu();

int main() {
    PasswordEntry* passwordList = NULL;
    int choice;

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character

        switch (choice) {
            case 1:
                addPassword(&passwordList);
                break;
            case 2:
                viewPasswords(passwordList);
                break;
            case 3:
                searchPassword(passwordList);
                break;
            case 4:
                deletePassword(&passwordList);
                break;
            case 5:
                freeList(passwordList);
                printf("Exiting the password manager. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void printMenu() {
    printf("\n=== Password Manager ===\n");
    printf("1. Add Password\n");
    printf("2. View All Passwords\n");
    printf("3. Search Password\n");
    printf("4. Delete Password\n");
    printf("5. Exit\n");
}

void addPassword(PasswordEntry** head) {
    PasswordEntry* newEntry = (PasswordEntry*)malloc(sizeof(PasswordEntry));
    if (newEntry == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter account name: ");
    fgets(newEntry->name, MAX_NAME_LENGTH, stdin);
    newEntry->name[strcspn(newEntry->name, "\n")] = 0; // Remove newline

    printf("Enter password: ");
    fgets(newEntry->password, MAX_PASS_LENGTH, stdin);
    newEntry->password[strcspn(newEntry->password, "\n")] = 0; // Remove newline

    newEntry->next = *head;
    *head = newEntry;

    printf("Password added successfully!\n");
}

void viewPasswords(PasswordEntry* head) {
    if (head == NULL) {
        printf("No passwords stored.\n");
        return;
    }

    printf("\n=== Stored Passwords ===\n");
    PasswordEntry* current = head;
    while (current != NULL) {
        printf("Account: %s, Password: %s\n", current->name, current->password);
        current = current->next;
    }
}

void searchPassword(PasswordEntry* head) {
    char accountName[MAX_NAME_LENGTH];
    printf("Enter the account name to search: ");
    fgets(accountName, MAX_NAME_LENGTH, stdin);
    accountName[strcspn(accountName, "\n")] = 0; // Remove newline

    PasswordEntry* current = head;
    while (current != NULL) {
        if (strcmp(current->name, accountName) == 0) {
            printf("Found: Account: %s, Password: %s\n", current->name, current->password);
            return;
        }
        current = current->next;
    }

    printf("Account not found.\n");
}

void deletePassword(PasswordEntry** head) {
    char accountName[MAX_NAME_LENGTH];
    printf("Enter the account name to delete: ");
    fgets(accountName, MAX_NAME_LENGTH, stdin);
    accountName[strcspn(accountName, "\n")] = 0; // Remove newline

    PasswordEntry* current = *head;
    PasswordEntry* previous = NULL;

    while (current != NULL && strcmp(current->name, accountName) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Account not found.\n");
        return;
    }

    if (previous == NULL) {
        *head = current->next; // Deleting the head
    } else {
        previous->next = current->next; // Bypass the current
    }

    free(current);
    printf("Password entry deleted successfully!\n");
}

void freeList(PasswordEntry* head) {
    PasswordEntry* current = head;
    while (current != NULL) {
        PasswordEntry* next = current->next;
        free(current);
        current = next;
    }
}