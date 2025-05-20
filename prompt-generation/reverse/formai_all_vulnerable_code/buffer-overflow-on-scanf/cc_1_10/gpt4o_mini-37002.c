//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SERVICE_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

typedef struct PasswordNode {
    char service[MAX_SERVICE_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    struct PasswordNode* next;
} PasswordNode;

PasswordNode* head = NULL;

// Function to create a new password node
PasswordNode* createNode(const char* service, const char* password) {
    PasswordNode* newNode = (PasswordNode*)malloc(sizeof(PasswordNode));
    strncpy(newNode->service, service, MAX_SERVICE_LENGTH);
    strncpy(newNode->password, password, MAX_PASSWORD_LENGTH);
    newNode->next = NULL;
    return newNode;
}

// Function to add a new password
void addPassword(const char* service, const char* password) {
    PasswordNode* newNode = createNode(service, password);
    newNode->next = head;
    head = newNode;
    printf("Password for '%s' added successfully.\n", service);
}

// Function to view all stored passwords
void viewPasswords() {
    PasswordNode* current = head;
    if (!current) {
        printf("No passwords stored.\n");
        return;
    }
    printf("\nStored Passwords:\n");
    while (current) {
        printf("Service: %s, Password: %s\n", current->service, current->password);
        current = current->next;
    }
}

// Function to delete a password
void deletePassword(const char* service) {
    PasswordNode* current = head;
    PasswordNode* previous = NULL;

    while (current != NULL && strcmp(current->service, service) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("No password found for service '%s'.\n", service);
        return;
    }

    if (previous == NULL) {
        head = current->next; // Deleting the head
    } else {
        previous->next = current->next; // Bypass current
    }

    free(current);
    printf("Password for '%s' deleted successfully.\n", service);
}

// Function to free all allocated memory
void freePasswords() {
    PasswordNode* current = head;
    PasswordNode* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

// Main function to interact with the user
int main() {
    int choice;
    char service[MAX_SERVICE_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    do {
        printf("\n---- Password Manager ----\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Delete Password\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // to consume newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter service name: ");
                fgets(service, MAX_SERVICE_LENGTH, stdin);
                service[strcspn(service, "\n")] = 0; // Remove newline character

                printf("Enter password: ");
                fgets(password, MAX_PASSWORD_LENGTH, stdin);
                password[strcspn(password, "\n")] = 0; // Remove newline character

                addPassword(service, password);
                break;
            case 2:
                viewPasswords();
                break;
            case 3:
                printf("Enter service name to delete: ");
                fgets(service, MAX_SERVICE_LENGTH, stdin);
                service[strcspn(service, "\n")] = 0; // Remove newline character

                deletePassword(service);
                break;
            case 4:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 4);

    freePasswords(); // Free up allocated memory before exiting
    return 0;
}