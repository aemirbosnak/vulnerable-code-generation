//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SERVICES 100
#define MAX_PASSWORD_LENGTH 50
#define MAX_SERVICE_NAME_LENGTH 30

typedef struct {
    char serviceName[MAX_SERVICE_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} PasswordEntry;

PasswordEntry passwordManager[MAX_SERVICES];
int entryCount = 0;

void addPassword() {
    if (entryCount >= MAX_SERVICES) {
        printf("Password manager is full. Cannot add more entries.\n");
        return;
    }

    char serviceName[MAX_SERVICE_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter the service name: ");
    scanf("%s", serviceName);

    printf("Enter the password: ");
    scanf("%s", password);

    strcpy(passwordManager[entryCount].serviceName, serviceName);
    strcpy(passwordManager[entryCount].password, password);
    entryCount++;

    printf("Password for %s added successfully!\n", serviceName);
}

void viewPasswords() {
    if (entryCount == 0) {
        printf("No passwords saved yet.\n");
        return;
    }

    printf("\nStored Passwords:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Service: %s, Password: %s\n", passwordManager[i].serviceName, passwordManager[i].password);
    }
}

void deletePassword() {
    if (entryCount == 0) {
        printf("No passwords to delete.\n");
        return;
    }

    char serviceName[MAX_SERVICE_NAME_LENGTH];
    printf("Enter the service name to delete: ");
    scanf("%s", serviceName);

    int found = 0;
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(passwordManager[i].serviceName, serviceName) == 0) {
            found = 1;
            for (int j = i; j < entryCount - 1; j++) {
                passwordManager[j] = passwordManager[j + 1];
            }
            entryCount--;
            printf("Password for %s deleted successfully!\n", serviceName);
            break;
        }
    }

    if (!found) {
        printf("Service %s not found.\n", serviceName);
    }
}

void displayMenu() {
    printf("\nPassword Manager\n");
    printf("1. Add Password\n");
    printf("2. View Passwords\n");
    printf("3. Delete Password\n");
    printf("4. Exit\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

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
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}