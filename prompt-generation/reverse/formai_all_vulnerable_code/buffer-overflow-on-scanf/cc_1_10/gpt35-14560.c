//FormAI DATASET v1.0 Category: Password management ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

// Function to print the menu options
void printMenu() {
    printf("==== Mathy Password Manager ====\n");
    printf("1. Add new password\n");
    printf("2. Display all passwords\n");
    printf("3. Generate a random password\n");
    printf("4. Find a password\n");
    printf("5. Delete a password\n");
    printf("6. Exit the program\n");
}

// Function to add a new password
void addPassword(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH]) {
    int i;
    printf("Enter the password to add: ");
    char newPassword[MAX_PASSWORD_LENGTH];
    scanf("%s", newPassword);
    // Check if password already exists
    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (strcmp(passwords[i], newPassword) == 0) {
            printf("Error: Password already exists\n");
            return;
        }
    }
    // Add new password to first empty slot
    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (strlen(passwords[i]) == 0) {
            strcpy(passwords[i], newPassword);
            printf("Password added successfully\n");
            return;
        }
    }
    printf("Error: Maximum number of passwords reached\n");
}

// Function to display all passwords
void displayPasswords(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH]) {
    int i;
    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (strlen(passwords[i]) > 0) {
            printf("%d. %s\n", i+1, passwords[i]);
        }
    }
}

// Function to generate a random password
void generatePassword() {
    int length, i, randNum;
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter the length of the password: ");
    scanf("%d", &length);
    // Generate random password
    for (i = 0; i < length; i++) {
        randNum = rand() % 94 + 33; // ASCII characters from ! to ~
        password[i] = (char)randNum;
    }
    password[length] = '\0';
    printf("Generated password: %s\n", password);
}

// Function to find a password
void findPassword(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH]) {
    int i;
    char searchPass[MAX_PASSWORD_LENGTH];
    printf("Enter the password to find: ");
    scanf("%s", searchPass);
    // Check if password exists
    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (strcmp(passwords[i], searchPass) == 0) {
            printf("Password found at position %d\n", i+1);
            return;
        }
    }
    printf("Error: Password not found\n");
}

// Function to delete a password
void deletePassword(char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH]) {
    int i, passNum;
    displayPasswords(passwords);
    printf("Enter the number of the password to delete: ");
    scanf("%d", &passNum);
    if (passNum > 0 && passNum <= MAX_PASSWORDS && strlen(passwords[passNum-1]) > 0) {
        memset(passwords[passNum-1], 0, MAX_PASSWORD_LENGTH);
        printf("Password deleted successfully\n");
    } else {
        printf("Error: Invalid password number\n");
    }
}

int main() {
    char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH] = {0};
    int choice;
    srand(12345); // Set random seed for consistent output
    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addPassword(passwords);
                break;
            case 2:
                displayPasswords(passwords);
                break;
            case 3:
                generatePassword();
                break;
            case 4:
                findPassword(passwords);
                break;
            case 5:
                deletePassword(passwords);
                break;
            case 6:
                printf("Exiting the program\n");
                break;
            default:
                printf("Error: Invalid choice\n");
        }
    } while (choice != 6);
    return 0;
}