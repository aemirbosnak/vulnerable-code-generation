//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 100

typedef struct {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Credential;

Credential credentials[MAX_PASSWORDS];
int count = 0;

void addCredential() {
    if (count >= MAX_PASSWORDS) {
        printf("Password storage is full!\n");
        return;
    }

    printf("Enter website: ");
    scanf("%s", credentials[count].website);
    
    printf("Enter username: ");
    scanf("%s", credentials[count].username);
    
    printf("Enter password: ");
    scanf("%s", credentials[count].password);
    
    count++;
    printf("Credential added successfully!\n");
}

void viewCredentials() {
    if (count == 0) {
        printf("No credentials stored yet.\n");
        return;
    }

    printf("\nStored Credentials:\n");
    for (int i = 0; i < count; i++) {
        printf("Website: %s, Username: %s, Password: %s\n", 
                credentials[i].website, 
                credentials[i].username, 
                credentials[i].password);
    }
}

void deleteCredential() {
    char website[MAX_LENGTH];
    printf("Enter website of the credential to delete: ");
    scanf("%s", website);
    
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(credentials[i].website, website) == 0) {
            found = 1;
            for (int j = i; j < count - 1; j++) {
                credentials[j] = credentials[j + 1];
            }
            count--;
            printf("Credential for %s deleted successfully!\n", website);
            break;
        }
    }

    if (!found) {
        printf("Credential for %s not found.\n", website);
    }
}

void clearCredentials() {
    count = 0;
    printf("All credentials have been cleared.\n");
}

void passwordManager() {
    int choice;
    do {
        printf("\nPassword Manager Menu\n");
        printf("1. Add Credential\n");
        printf("2. View Credentials\n");
        printf("3. Delete Credential\n");
        printf("4. Clear All Credentials\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addCredential();
                break;
            case 2:
                viewCredentials();
                break;
            case 3:
                deleteCredential();
                break;
            case 4:
                clearCredentials();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    printf("Welcome to the Password Manager\n");
    passwordManager();
    return 0;
}