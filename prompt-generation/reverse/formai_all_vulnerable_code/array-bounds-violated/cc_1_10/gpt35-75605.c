//FormAI DATASET v1.0 Category: Password management ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 5
#define MAX_PASSWORD_LENGTH 20
#define PASSWORDS_FILE "passwords.txt"

void displayMenu() {
    printf("Welcome to Password Management tool\n");
    printf("1. Add a new password\n");
    printf("2. Display all saved passwords\n");
    printf("3. Search for a password\n");
    printf("4. Delete a password\n");
    printf("5. Exit\n");
}

void savePasswordsToFile(char passwords[][MAX_PASSWORD_LENGTH]) {
    FILE *file = fopen(PASSWORDS_FILE, "w");
    if (file == NULL) {
        printf("Error: Unable to open file\n");
        return;
    }
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        fprintf(file, "%s\n", passwords[i]);
    }
    fclose(file);
}

void loadPasswordsFromFile(char passwords[][MAX_PASSWORD_LENGTH]) {
    FILE *file = fopen(PASSWORDS_FILE, "r");
    if (file == NULL) {
        printf("No saved passwords found\n");
        return;
    }
    int i = 0;
    char password[MAX_PASSWORD_LENGTH];
    while (fgets(password, MAX_PASSWORD_LENGTH, file) != NULL) {
        password[strlen(password)-1] = '\0';
        strcpy(passwords[i], password);
        i++;
    }
    fclose(file);
}

int addPassword(char passwords[][MAX_PASSWORD_LENGTH], int numPasswords) {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Maximum number of passwords reached\n");
        return numPasswords;
    }
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter new password (maximum %d characters): ", MAX_PASSWORD_LENGTH-1);
    scanf("%s", password);
    while (strlen(password) >= MAX_PASSWORD_LENGTH) {
        printf("Password is too long. Please enter a password of maximum %d characters: ", MAX_PASSWORD_LENGTH-1);
        scanf("%s", password);
    }
    // Check if password contains only alphanumeric characters
    int isAlphaNumeric = 1;
    for (int i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            isAlphaNumeric = 0;
            break;
        }
    }
    if (!isAlphaNumeric) {
        printf("Password contains non-alphanumeric characters. Please enter a password containing only letters and numbers\n");
        return numPasswords;
    }
    // Check if password already exists
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i], password) == 0) {
            printf("Password already exists. Please enter a new password\n");
            return numPasswords;
        }
    }
    strcpy(passwords[numPasswords], password);
    numPasswords++;
    printf("Password successfully added\n");
    savePasswordsToFile(passwords);
    return numPasswords;
}

void displayPasswords(char passwords[][MAX_PASSWORD_LENGTH], int numPasswords) {
    if (numPasswords == 0) {
        printf("No saved passwords found\n");
        return;
    }
    printf("Saved passwords:\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%d. %s\n", i+1, passwords[i]);
    }
}

void searchPasswords(char passwords[][MAX_PASSWORD_LENGTH], int numPasswords) {
    if (numPasswords == 0) {
        printf("No saved passwords found\n");
        return;
    }
    char search[MAX_PASSWORD_LENGTH];
    printf("Enter search query: ");
    scanf("%s", search);
    int resultsFound = 0;
    for (int i = 0; i < numPasswords; i++) {
        if (strstr(passwords[i], search) != NULL) {
            printf("%s\n", passwords[i]);
            resultsFound = 1;
        }
    }
    if (!resultsFound) {
        printf("No results found for search query\n");
    }
}

int deletePassword(char passwords[][MAX_PASSWORD_LENGTH], int numPasswords) {
    if (numPasswords == 0) {
        printf("No saved passwords found\n");
        return numPasswords;
    }
    displayPasswords(passwords, numPasswords);
    int selection;
    printf("Enter selection to delete: ");
    scanf("%d", &selection);
    selection--;
    if (selection >= 0 && selection < numPasswords) {
        for (int i = selection; i < numPasswords-1; i++) {
            strcpy(passwords[i], passwords[i+1]);
        }
        numPasswords--;
        printf("Password successfully deleted\n");
        savePasswordsToFile(passwords);
    } else {
        printf("Invalid selection\n");
    }
    return numPasswords;
}

int main() {
    char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];
    loadPasswordsFromFile(passwords);
    int numPasswords = 0;
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        if (strlen(passwords[i]) > 0) {
            numPasswords++;
        }
    }
    int running = 1;
    while (running) {
        displayMenu();
        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                numPasswords = addPassword(passwords, numPasswords);
                break;
            case 2:
                displayPasswords(passwords, numPasswords);
                break;
            case 3:
                searchPasswords(passwords, numPasswords);
                break;
            case 4:
                numPasswords = deletePassword(passwords, numPasswords);
                break;
            case 5:
                printf("Goodbye!\n");
                running = 0;
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}