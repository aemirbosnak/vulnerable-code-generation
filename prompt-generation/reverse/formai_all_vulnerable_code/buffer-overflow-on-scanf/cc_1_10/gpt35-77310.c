//FormAI DATASET v1.0 Category: Password management ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASSWORDS 1000
#define MAX_PASSWORD_LENGTH 16

// Create a structure to hold passwords and their associated services
typedef struct {
    char service[50];
    char password[MAX_PASSWORD_LENGTH];
} Password;

// Function prototypes
void addPassword(Password* passwords, int* numPasswords);
void viewPasswords(Password* passwords, int numPasswords);
void searchPasswords(Password* passwords, int numPasswords);
void generatePassword(char* password, int length);

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;
    int choice = 0;

    srand(time(NULL));

    while (choice != 4) {
        printf("\nPassword Management System\n");
        printf("1. Add password\n");
        printf("2. View passwords\n");
        printf("3. Search passwords\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword(passwords, &numPasswords);
                break;
            case 2:
                viewPasswords(passwords, numPasswords);
                break;
            case 3:
                searchPasswords(passwords, numPasswords);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}

void addPassword(Password* passwords, int* numPasswords) {
    char service[50];
    char password[MAX_PASSWORD_LENGTH];

    printf("\nEnter service name: ");
    scanf("%s", service);

    generatePassword(password, MAX_PASSWORD_LENGTH);
    printf("Generated password: %s\n", password);

    int i;
    for (i = 0; i < *numPasswords; i++) {
        if (strcmp(passwords[i].service, service) == 0) {
            printf("Password for service already exists, please try again.\n");
            return;
        }
    }

    Password newPassword;
    strcpy(newPassword.service, service);
    strcpy(newPassword.password, password);

    passwords[*numPasswords] = newPassword;
    (*numPasswords)++;

    printf("Password added successfully!\n");
}

void viewPasswords(Password* passwords, int numPasswords) {
    if (numPasswords == 0) {
        printf("There are no passwords to view.\n");
        return;
    }

    printf("\n%-20s%-20s\n", "Service", "Password");

    int i;
    for (i = 0; i < numPasswords; i++) {
        printf("%-20s%-20s\n", passwords[i].service, passwords[i].password);
    }
}

void searchPasswords(Password* passwords, int numPasswords) {
    if (numPasswords == 0) {
        printf("There are no passwords to search.\n");
        return;
    }

    char service[50];
    printf("\nEnter service name: ");
    scanf("%s", service);

    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].service, service) == 0) {
            printf("Password for service '%s' is: %s\n", service, passwords[i].password);
            return;
        }
    }

    printf("Password for service '%s' not found.\n", service);
}

void generatePassword(char* password, int length) {
    const char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=";
    int numCharacters = strlen(characters);

    int i;
    for (i = 0; i < length - 1; i++) {
        password[i] = characters[rand() % numCharacters];
    }

    password[length - 1] = '\0';
}