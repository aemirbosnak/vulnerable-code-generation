//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 100

typedef struct {
    char service[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Credential;

Credential credentials[MAX_ENTRIES];
int credential_count = 0;

void add_credential() {
    if (credential_count >= MAX_ENTRIES) {
        printf("Credential storage is full!\n");
        return;
    }
    
    Credential new_credential;
    printf("Enter service name: ");
    scanf(" %[^\n]s", new_credential.service);
    printf("Enter username: ");
    scanf(" %[^\n]s", new_credential.username);
    printf("Enter password: ");
    scanf(" %[^\n]s", new_credential.password);
    
    credentials[credential_count++] = new_credential;
    printf("Credential added successfully!\n\n");
}

void view_credentials() {
    if (credential_count == 0) {
        printf("No credentials stored.\n\n");
        return;
    }
    
    printf("Stored Credentials:\n");
    for (int i = 0; i < credential_count; i++) {
        printf("Service: %s\nUsername: %s\nPassword: %s\n\n",
               credentials[i].service,
               credentials[i].username,
               credentials[i].password);
    }
}

void edit_credential() {
    char service[MAX_LENGTH];
    printf("Enter the service name to edit: ");
    scanf(" %[^\n]s", service);
    
    for (int i = 0; i < credential_count; i++) {
        if (strcmp(credentials[i].service, service) == 0) {
            printf("Editing Credential for %s\n", service);
            printf("New Username: ");
            scanf(" %[^\n]s", credentials[i].username);
            printf("New Password: ");
            scanf(" %[^\n]s", credentials[i].password);
            printf("Credential updated successfully!\n\n");
            return;
        }
    }
    
    printf("No credential found for the service: %s\n\n", service);
}

void delete_credential() {
    char service[MAX_LENGTH];
    printf("Enter the service name to delete: ");
    scanf(" %[^\n]s", service);
    
    for (int i = 0; i < credential_count; i++) {
        if (strcmp(credentials[i].service, service) == 0) {
            // Shift left to remove the credential
            for (int j = i; j < credential_count - 1; j++) {
                credentials[j] = credentials[j + 1];
            }
            credential_count--;
            printf("Credential deleted successfully!\n\n");
            return;
        }
    }
    
    printf("No credential found for the service: %s\n\n", service);
}

void display_menu() {
    printf("Password Management System\n");
    printf("1. Add Credential\n");
    printf("2. View Credentials\n");
    printf("3. Edit Credential\n");
    printf("4. Delete Credential\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_credential();
                break;
            case 2:
                view_credentials();
                break;
            case 3:
                edit_credential();
                break;
            case 4:
                delete_credential();
                break;
            case 5:
                printf("Exiting the Password Management System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n\n");
                break;
        }
    }
    
    return 0;
}