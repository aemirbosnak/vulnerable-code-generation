//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

PasswordEntry passwordList[MAX_PASSWORDS];
int passwordCount = 0;

void addPassword();
void retrievePassword();
void deletePassword();
void listPasswords();
void savePasswords();
void loadPasswords();
void displayMenu();

int main() {
    loadPasswords();
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume newline character

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                retrievePassword();
                break;
            case 3:
                deletePassword();
                break;
            case 4:
                listPasswords();
                break;
            case 5:
                savePasswords();
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void displayMenu() {
    printf("\nPassword Manager\n");
    printf("1. Add Password\n");
    printf("2. Retrieve Password\n");
    printf("3. Delete Password\n");
    printf("4. List All Passwords\n");
    printf("5. Save Passwords to File\n");
    printf("6. Exit\n");
}

void addPassword() {
    if (passwordCount >= MAX_PASSWORDS) {
        printf("Password list is full. Cannot add more passwords.\n");
        return;
    }

    printf("Enter name/identifier for the password: ");
    fgets(passwordList[passwordCount].name, MAX_LENGTH, stdin);
    strtok(passwordList[passwordCount].name, "\n"); // Remove newline character

    printf("Enter password: ");
    fgets(passwordList[passwordCount].password, MAX_LENGTH, stdin);
    strtok(passwordList[passwordCount].password, "\n"); // Remove newline character

    passwordCount++;
    printf("Password added successfully!\n");
}

void retrievePassword() {
    char name[MAX_LENGTH];
    printf("Enter the name/identifier of the password to retrieve: ");
    fgets(name, MAX_LENGTH, stdin);
    strtok(name, "\n"); // Remove newline character

    for (int i = 0; i < passwordCount; i++) {
        if (strcmp(passwordList[i].name, name) == 0) {
            printf("Password for '%s': %s\n", name, passwordList[i].password);
            return;
        }
    }

    printf("No password found for '%s'.\n", name);
}

void deletePassword() {
    char name[MAX_LENGTH];
    printf("Enter the name/identifier of the password to delete: ");
    fgets(name, MAX_LENGTH, stdin);
    strtok(name, "\n"); // Remove newline character

    for (int i = 0; i < passwordCount; i++) {
        if (strcmp(passwordList[i].name, name) == 0) {
            for (int j = i; j < passwordCount - 1; j++) {
                passwordList[j] = passwordList[j + 1];
            }
            passwordCount--;
            printf("Password for '%s' deleted successfully!\n", name);
            return;
        }
    }

    printf("No password found for '%s'.\n", name);
}

void listPasswords() {
    printf("\nList of Passwords:\n");
    if (passwordCount == 0) {
        printf("No passwords stored.\n");
    } else {
        for (int i = 0; i < passwordCount; i++) {
            printf("Name: %s\n", passwordList[i].name);
        }
    }
}

void savePasswords() {
    FILE *file = fopen("passwords.txt", "w");
    if (file == NULL) {
        printf("Failed to save passwords!\n");
        return;
    }

    for (int i = 0; i < passwordCount; i++) {
        fprintf(file, "%s\n%s\n", passwordList[i].name, passwordList[i].password);
    }

    fclose(file);
    printf("Passwords saved successfully!\n");
}

void loadPasswords() {
    FILE *file = fopen("passwords.txt", "r");
    if (file == NULL) {
        return; // No file found, first time running program
    }

    while (fgets(passwordList[passwordCount].name, MAX_LENGTH, file) != NULL && passwordCount < MAX_PASSWORDS) {
        strtok(passwordList[passwordCount].name, "\n"); // Remove newline character
        fgets(passwordList[passwordCount].password, MAX_LENGTH, file);
        strtok(passwordList[passwordCount].password, "\n"); // Remove newline character
        passwordCount++;
    }

    fclose(file);
    printf("Passwords loaded successfully!\n");
}