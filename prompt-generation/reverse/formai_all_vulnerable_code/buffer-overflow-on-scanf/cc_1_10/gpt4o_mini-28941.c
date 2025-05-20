//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SITES 100
#define MAX_LENGTH 50

typedef struct {
    char site[MAX_LENGTH];
    char password[MAX_LENGTH];
} PasswordEntry;

PasswordEntry passwordList[MAX_SITES];
int entryCount = 0;

void addPassword() {
    if (entryCount >= MAX_SITES) {
        printf("The casebook is full! Cannot add more passwords.\n");
        return;
    }
    
    char site[MAX_LENGTH];
    char password[MAX_LENGTH];

    printf("Enter the website name: ");
    scanf("%s", site);
    printf("Enter the password: ");
    scanf("%s", password);
    
    strcpy(passwordList[entryCount].site, site);
    strcpy(passwordList[entryCount].password, password);
    entryCount++;
    
    printf("A new clue added for: %s\n\n", site);
}

void viewPasswords() {
    if (entryCount == 0) {
        printf("No entries in the casebook, dear Watson.\n\n");
        return;
    }

    printf("Here are the entries from the casebook:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%d. %s : %s\n", i + 1, passwordList[i].site, passwordList[i].password);
    }
    printf("\n");
}

void deletePassword() {
    if (entryCount == 0) {
        printf("The casebook is empty, nothing to delete.\n\n");
        return;
    }

    int index;
    viewPasswords();
    
    printf("Enter the number of the entry to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > entryCount) {
        printf("Invalid entry number!\n\n");
        return;
    }

    for (int i = index - 1; i < entryCount - 1; i++) {
        passwordList[i] = passwordList[i + 1];
    }
    entryCount--;
    printf("The entry has been deleted, Watson.\n\n");
}

void searchPassword() {
    char site[MAX_LENGTH];
    printf("Enter the website name to search: ");
    scanf("%s", site);
    
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(passwordList[i].site, site) == 0) {
            printf("Found Entry: %s : %s\n\n", passwordList[i].site, passwordList[i].password);
            return;
        }
    }
    printf("No entry found for %s, my dear Watson.\n\n", site);
}

void displayMenu() {
    printf("=== Sherlock Holmes' Password Management System ===\n");
    printf("1. Add Password\n");
    printf("2. View Passwords\n");
    printf("3. Delete Password\n");
    printf("4. Search Password\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
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
                searchPassword();
                break;
            case 5:
                printf("Farewell, Watson. Until we meet again.\n");
                exit(0);
            default:
                printf("That choice is as perplexing as the Ripper case, my dear Watson.\n\n");
                break;
        }
    }

    return 0;
}