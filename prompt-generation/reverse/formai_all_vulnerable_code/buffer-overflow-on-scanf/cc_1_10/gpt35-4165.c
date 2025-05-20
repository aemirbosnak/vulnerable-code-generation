//FormAI DATASET v1.0 Category: Password management ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // for rand() function

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

void printMenu();
void addPassword(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int *passwordCount);
void viewPasswords(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int *passwordCount);
void generatePassword(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int *passwordCount);

int main() {
    // Initialize variables
    char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];
    int passwordCount = 0;
    int selection = 0;

    // Seed random number generator
    srand(time(NULL));

    // User interface loop
    while (1) {
        printMenu();
        scanf("%d", &selection);

        switch (selection) {
            case 1:
                addPassword(passwords, &passwordCount);
                break;
            case 2:
                viewPasswords(passwords, &passwordCount);
                break;
            case 3:
                generatePassword(passwords, &passwordCount);
                break;
            case 4:
                printf("Exiting program...");
                return 0;
            default:
                printf("Invalid selection. Please try again.\n");
                break;
        }
    }
    return 0;
}

// Prints the main menu options
void printMenu() {
    printf("\n---- PASSWORD MANAGER ----\n");
    printf("1. Add a Password\n");
    printf("2. View Passwords\n");
    printf("3. Generate a Password\n");
    printf("4. Exit\n");
    printf("Please make a selection: ");
}

// Adds a password to the list
void addPassword(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int *passwordCount) {
    // Check if list is full
    if (*passwordCount >= MAX_PASSWORDS) {
        printf("Maximum number of passwords reached.\n");
        return;
    }

    // Prompt user for password and add to list
    printf("Enter password: ");
    scanf("%s", passwords[*passwordCount]);
    *passwordCount += 1;
  
    printf("Password added successfully.\n");
}

// Displays all saved passwords
void viewPasswords(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int *passwordCount) {
    // Check if list is empty
    if (*passwordCount == 0) {
        printf("No passwords saved.\n");
        return;
    }

    // Print all saved passwords
    printf("Saved Passwords:\n");
    for (int i = 0; i < *passwordCount; i++) {
        printf("%d. %s\n", i+1, passwords[i]);
    }
}

// Generates a random password and adds it to the list
void generatePassword(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH], int *passwordCount) {
    // Check if list is full
    if (*passwordCount >= MAX_PASSWORDS) {
        printf("Maximum number of passwords reached.\n");
        return;
    }

    // Generate random password
    char password[MAX_PASSWORD_LENGTH + 1];
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-={}[]\\|;:'\",.<>/?";
    const size_t charsetLength = strlen(charset);

    for (int i = 0; i < MAX_PASSWORD_LENGTH; i++) {
        int index = rand() % charsetLength;
        password[i] = charset[index];
    }

    password[MAX_PASSWORD_LENGTH] = '\0';

    // Add password to list and increment count
    strcpy(passwords[*passwordCount], password);
    *passwordCount += 1;
  
    printf("Generated password: %s\n", password);
}