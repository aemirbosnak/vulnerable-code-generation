//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SERVICES 100
#define MAX_PASSWORD_LENGTH 128
#define SERVICE_NAME_LENGTH 64

typedef struct {
    char service[SERVICE_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} PasswordEntry;

PasswordEntry passwordDB[MAX_SERVICES];
int entryCount = 0;

void addPassword();
void viewPasswords();
void deletePassword();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;

    while (1) {
        printf("\n---- Password Manager ----\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Delete Password\n");
        printf("4. Exit\n");
        printf("Please choose an option: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 4.\n");
            while(getchar() != '\n'); // Clear the input buffer
            continue;
        }
        
        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                viewPasswords();
                break;
            case 3:
                deletePassword();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select again.\n");
                break;
        }
    }
}

void addPassword() {
    if (entryCount >= MAX_SERVICES) {
        printf("Password database is full. Cannot add more passwords.\n");
        return;
    }

    printf("Enter the service name: ");
    scanf("%s", passwordDB[entryCount].service);
    printf("Enter the password: ");
    scanf("%s", passwordDB[entryCount].password);
    
    entryCount++;
    printf("Password for %s added successfully!\n", passwordDB[entryCount - 1].service);
}

void viewPasswords() {
    if (entryCount == 0) {
        printf("No passwords stored.\n");
        return;
    }

    printf("\n--- Stored Passwords ---\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Service: %s, Password: %s\n", passwordDB[i].service, passwordDB[i].password);
    }
}

void deletePassword() {
    char serviceToDelete[SERVICE_NAME_LENGTH];
    printf("Enter the service name to delete: ");
    scanf("%s", serviceToDelete);
    
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(passwordDB[i].service, serviceToDelete) == 0) {
            // Shift the remaining entries leftward
            for (int j = i; j < entryCount - 1; j++) {
                passwordDB[j] = passwordDB[j + 1];
            }
            entryCount--;
            printf("Password for %s deleted successfully!\n", serviceToDelete);
            return;
        }
    }
    
    printf("Service not found.\n");
}