//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 256
#define SERVICE_LENGTH 64

typedef struct {
    char service[SERVICE_LENGTH];
    char password[PASSWORD_LENGTH];
} PasswordEntry;

PasswordEntry passwordDatabase[MAX_PASSWORDS];
int passwordCount = 0;

void addPassword();
void deletePassword();
void viewPasswords();
void saveToFile();
void loadFromFile();
void clearScreen();

int main() {
    loadFromFile();
    
    int choice;
    do {
        clearScreen();
        printf("Password Management System\n");
        printf("===========================\n");
        printf("1. Add Password\n");
        printf("2. Delete Password\n");
        printf("3. View Passwords\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                deletePassword();
                break;
            case 3:
                viewPasswords();
                break;
            case 4:
                saveToFile();
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}

void addPassword() {
    if (passwordCount >= MAX_PASSWORDS) {
        printf("Password limit reached. Cannot add more passwords.\n");
        return;
    }

    char service[SERVICE_LENGTH];
    char password[PASSWORD_LENGTH];

    printf("Enter service name: ");
    scanf("%s", service);
    
    printf("Enter password: ");
    // Using %255s to avoid buffer overflow
    scanf("%255s", password);

    strcpy(passwordDatabase[passwordCount].service, service);
    strcpy(passwordDatabase[passwordCount].password, password);
    passwordCount++;

    printf("Password for '%s' added successfully!\n", service);
    sleep(2); // Pause for 2 seconds
}

void deletePassword() {
    if (passwordCount == 0) {
        printf("No passwords available to delete.\n");
        return;
    }

    char service[SERVICE_LENGTH];
    printf("Enter service name to delete: ");
    scanf("%s", service);

    for (int i = 0; i < passwordCount; i++) {
        if (strcmp(passwordDatabase[i].service, service) == 0) {
            // Shift remaining entries
            for (int j = i; j < passwordCount - 1; j++) {
                passwordDatabase[j] = passwordDatabase[j + 1];
            }
            passwordCount--;
            printf("Password for '%s' deleted successfully!\n", service);
            return;
        }
    }
    printf("Service '%s' not found.\n", service);
    sleep(2); // Pause for 2 seconds
}

void viewPasswords() {
    if (passwordCount == 0) {
        printf("No passwords available.\n");
        return;
    }

    printf("Stored Passwords:\n");
    printf("------------------\n");
    for (int i = 0; i < passwordCount; i++) {
        printf("Service: %s\n", passwordDatabase[i].service);
        printf("Password: %s\n", passwordDatabase[i].password);
        printf("------------------\n");
    }
    printf("Press enter to continue...\n");
    getchar(); // consume the newline character
    getchar(); // Wait for user to press enter
}

void saveToFile() {
    FILE *file = fopen("passwords.dat", "w");
    if (file != NULL) {
        for (int i = 0; i < passwordCount; i++) {
            fprintf(file, "%s %s\n", passwordDatabase[i].service, passwordDatabase[i].password);
        }
        fclose(file);
        printf("Passwords saved to file.\n");
    } else {
        printf("Error saving passwords to file.\n");
    }
}

void loadFromFile() {
    FILE *file = fopen("passwords.dat", "r");
    if (file != NULL) {
        while (fscanf(file, "%s %s", passwordDatabase[passwordCount].service, passwordDatabase[passwordCount].password) == 2) {
            passwordCount++;
            if (passwordCount >= MAX_PASSWORDS) break; // safeguard
        }
        fclose(file);
    }
}

void clearScreen() {
    // Clear the screen using ANSI escape code for Linux
    printf("\033[H\033[J");
}