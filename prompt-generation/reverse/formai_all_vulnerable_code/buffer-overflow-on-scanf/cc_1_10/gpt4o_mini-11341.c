//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 50

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

PasswordEntry passwordList[MAX_ENTRIES];
int entryCount = 0;

void printWelcomeMessage() {
    printf("Welcome to the Ultimate Password Manager!\n");
    printf("Secure, Fun and Extremely Useful!\n\n");
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Oh no! Maximum entries reached! Cannot add more passwords!\n");
        return;
    }
    
    PasswordEntry newEntry;
    printf("Enter Username: ");
    scanf("%s", newEntry.username);
    printf("Enter Password: ");
    scanf("%s", newEntry.password);
    
    passwordList[entryCount++] = newEntry;
    printf("Yay! Password for %s added successfully!\n\n", newEntry.username);
}

void retrievePassword() {
    char username[MAX_LENGTH];
    printf("Enter the Username to retrieve the password: ");
    scanf("%s", username);
    
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(passwordList[i].username, username) == 0) {
            printf("Password for %s is: %s\n", username, passwordList[i].password);
            return;
        }
    }
    printf("Oops! No entry found for %s. Try again!\n", username);
}

void deleteEntry() {
    char username[MAX_LENGTH];
    printf("Enter the Username to delete the password: ");
    scanf("%s", username);
    
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(passwordList[i].username, username) == 0) {
            for (int j = i; j < entryCount - 1; j++) {
                passwordList[j] = passwordList[j + 1];
            }
            entryCount--;
            printf("Password entry for %s has been removed! Bye-bye!\n\n", username);
            return;
        }
    }
    printf("Oops! No entry found for %s. Cannot delete!\n", username);
}

void displayAllEntries() {
    if (entryCount == 0) {
        printf("No password entries found!\n\n");
        return;
    }
    
    printf("Here are all saved passwords:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Username: %s, Password: %s\n", passwordList[i].username, passwordList[i].password);
    }
    printf("\n");
}

int main() {
    int choice;
    printWelcomeMessage();
    
    do {
        printf("Choose an option:\n");
        printf("1. Add Password\n");
        printf("2. Retrieve Password\n");
        printf("3. Delete Password\n");
        printf("4. Display All Passwords\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                retrievePassword();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                displayAllEntries();
                break;
            case 5:
                printf("Thank you for using the Ultimate Password Manager! Bye!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}