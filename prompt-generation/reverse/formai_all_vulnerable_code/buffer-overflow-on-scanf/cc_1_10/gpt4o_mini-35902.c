//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_PASS_LEN 100

// Structure to hold password details
typedef struct PasswordEntry {
    char name[MAX_NAME_LEN];
    char password[MAX_PASS_LEN];
    struct PasswordEntry* next;
} PasswordEntry;

// Head of the linked list
PasswordEntry* head = NULL;

// Function to create a new password entry
PasswordEntry* createEntry(const char* name, const char* password) {
    PasswordEntry* newEntry = (PasswordEntry*)malloc(sizeof(PasswordEntry));
    if (newEntry == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strncpy(newEntry->name, name, MAX_NAME_LEN);
    strncpy(newEntry->password, password, MAX_PASS_LEN);
    newEntry->next = NULL;
    return newEntry;
}

// Function to add a password entry
void addPassword(const char* name, const char* password) {
    PasswordEntry* newEntry = createEntry(name, password);
    newEntry->next = head;
    head = newEntry;
    printf("Password for '%s' added successfully!\n", name);
}

// Function to retrieve a password by name
void getPassword(const char* name) {
    PasswordEntry* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Password for '%s': %s\n", name, current->password);
            return;
        }
        current = current->next;
    }
    printf("No password found for '%s'.\n", name);
}

// Function to delete a password by name
void deletePassword(const char* name) {
    PasswordEntry* current = head;
    PasswordEntry* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next; // Delete head
            } else {
                previous->next = current->next; // Skip over current
            }
            free(current);
            printf("Password for '%s' deleted successfully!\n", name);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("No password found for '%s' to delete.\n", name);
}

// Function to display all passwords (for testing, not recommended in production)
void displayPasswords() {
    PasswordEntry* current = head;
    printf("Stored Passwords:\n");
    while (current != NULL) {
        printf("Name: %s, Password: %s\n", current->name, current->password);
        current = current->next;
    }
}

// Menu for user interaction
void displayMenu() {
    printf("\nPassword Management System\n");
    printf("1. Add Password\n");
    printf("2. Retrieve Password\n");
    printf("3. Delete Password\n");
    printf("4. Display All Passwords\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char name[MAX_NAME_LEN], password[MAX_PASS_LEN];

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // To remove newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, MAX_NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                printf("Enter password: ");
                fgets(password, MAX_PASS_LEN, stdin);
                password[strcspn(password, "\n")] = 0; // Remove newline
                addPassword(name, password);
                break;

            case 2:
                printf("Enter name to retrieve: ");
                fgets(name, MAX_NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                getPassword(name);
                break;

            case 3:
                printf("Enter name to delete: ");
                fgets(name, MAX_NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                deletePassword(name);
                break;

            case 4:
                displayPasswords();
                break;

            case 5:
                printf("Exiting program.\n");
                // Free the linked list before exiting
                while (head != NULL) {
                    PasswordEntry* temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;

            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}