//FormAI DATASET v1.0 Category: Password management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PASSWORD_LENGTH 25
#define MAX_NUM_PASSWORDS 100

//struct representing password entry
typedef struct PasswordEntry {
    char website[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} PasswordEntry;

//function for adding new password entry
void addPasswordEntry(PasswordEntry* passwords, int* numPasswords) {
    //check if maximum number of passwords has been reached
    if (*numPasswords == MAX_NUM_PASSWORDS) {
        printf("Maximum number of password entries reached.\n");
        return;
    }

    //prompt user for website, username, and password
    char website[MAX_PASSWORD_LENGTH], username[MAX_PASSWORD_LENGTH], password[MAX_PASSWORD_LENGTH];
    printf("Enter website name: ");
    scanf("%s", website);
    printf("Enter username for %s: ", website);
    scanf("%s", username);
    printf("Enter password for %s: ", website);
    scanf("%s", password);

    //create new password entry
    PasswordEntry newEntry;
    strcpy(newEntry.website, website);
    strcpy(newEntry.username, username);
    strcpy(newEntry.password, password);

    //add new password entry to array
    passwords[*numPasswords] = newEntry;
    (*numPasswords)++;
}

//function for searching for password entry based on website name
void searchPasswordEntry(PasswordEntry* passwords, int numPasswords) {
    //prompt user for website name
    char website[MAX_PASSWORD_LENGTH];
    printf("Enter website name to search for: ");
    scanf("%s", website);

    //iterate through password entries to find matching website name
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].website, website) == 0) {
            printf("Username: %s\n", passwords[i].username);
            printf("Password: %s\n", passwords[i].password);
            return;
        }
    }

    //no match found
    printf("Website name not found in password database.\n");
}

//function for printing all password entries
void printPasswordEntries(PasswordEntry* passwords, int numPasswords) {
    //check if there are any password entries
    if (numPasswords == 0) {
        printf("No password entries found.\n");
        return;
    }

    //print all password entries
    printf("Website\t\tUsername\tPassword\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%-15s\t%-15s\t%s\n", passwords[i].website, passwords[i].username, passwords[i].password);
    }
}

int main() {
    PasswordEntry passwords[MAX_NUM_PASSWORDS];
    int numPasswords = 0;

    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Add new password entry\n");
        printf("2. Search for password entry\n");
        printf("3. Print all password entries\n");
        printf("4. Quit\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            addPasswordEntry(passwords, &numPasswords);
        } else if (choice == 2) {
            searchPasswordEntry(passwords, numPasswords);
        } else if (choice == 3) {
            printPasswordEntries(passwords, numPasswords);
        } else if (choice == 4) {
            break;
        }
    }

    return 0;
}