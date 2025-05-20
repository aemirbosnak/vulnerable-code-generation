//FormAI DATASET v1.0 Category: Password management ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

// struct for storing password information
typedef struct {
    char website[50];
    char username[50];
    char password[50];
} PasswordInfo;

// function prototypes
void printMenu();
void addPassword(PasswordInfo passwords[], int *numPasswords);
void viewPasswords(PasswordInfo passwords[], int numPasswords);
void searchPasswords(PasswordInfo passwords[], int numPasswords);
int getPasswordIndex(PasswordInfo passwords[], int numPasswords, char website[]);
void deletePassword(PasswordInfo passwords[], int *numPasswords);
void savePasswords(PasswordInfo passwords[], int numPasswords);

int main() {
    PasswordInfo passwords[MAX_PASSWORDS];
    int numPasswords = 0;
    char choice;

    printf("**************************************************\n");
    printf("*            RETRO PASSWORD MANAGEMENT            *\n");
    printf("**************************************************\n\n");

    // continue showing menu until user chooses to exit
    do {
        printMenu();
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                addPassword(passwords, &numPasswords);
                break;
            case '2':
                viewPasswords(passwords, numPasswords);
                break;
            case '3':
                searchPasswords(passwords, numPasswords);
                break;
            case '4':
                deletePassword(passwords, &numPasswords);
                break;
            case '5':
                savePasswords(passwords, numPasswords);
                printf("Passwords saved successfully!\n");
                break;
            case '6':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != '6');

    return 0;
}

// prints the menu to the console
void printMenu() {
    printf("**************************************************\n");
    printf("*                  MENU OPTIONS                   *\n");
    printf("**************************************************\n");
    printf("* 1. Add new password                             *\n");
    printf("* 2. View all passwords                           *\n");
    printf("* 3. Search for a password                        *\n");
    printf("* 4. Delete a password                            *\n");
    printf("* 5. Save passwords                               *\n");
    printf("* 6. Exit program                                 *\n");
    printf("**************************************************\n\n");

    printf("Enter your choice: ");
}

// adds a new password to the system
void addPassword(PasswordInfo passwords[], int *numPasswords) {
    if (*numPasswords >= MAX_PASSWORDS) {
        printf("Maximum number of passwords reached.\n");
        return;
    }

    printf("Enter website: ");
    scanf(" %[^\n]", passwords[*numPasswords].website);

    printf("Enter username: ");
    scanf(" %[^\n]", passwords[*numPasswords].username);

    printf("Enter password: ");
    scanf(" %[^\n]", passwords[*numPasswords].password);

    printf("Password added successfully!\n");
    (*numPasswords)++;
}

// views all passwords stored in the system
void viewPasswords(PasswordInfo passwords[], int numPasswords) {
    if (numPasswords == 0) {
        printf("No passwords stored in the system.\n");
        return;
    }

    printf("**************************************************\n");
    printf("*              ALL STORED PASSWORDS               *\n");
    printf("**************************************************\n");
    printf("%-15s %-15s %-15s\n", "Website", "Username", "Password");
    printf("**************************************************\n");

    for (int i = 0; i < numPasswords; i++) {
        printf("%-15s %-15s %-15s\n", passwords[i].website, passwords[i].username, passwords[i].password);
    }

    printf("**************************************************\n");
}

// searches for a password based on website name
void searchPasswords(PasswordInfo passwords[], int numPasswords) {
    if (numPasswords == 0) {
        printf("No passwords stored in the system.\n");
        return;
    }

    char website[50];
    printf("Enter website to search for: ");
    scanf(" %[^\n]", website);

    int passwordIndex = getPasswordIndex(passwords, numPasswords, website);

    if (passwordIndex == -1) {
        printf("Password not found.\n");
    } else {
        printf("**************************************************\n");
        printf("*              PASSWORD DETAILS                   *\n");
        printf("**************************************************\n");
        printf("Website: %s\nUsername: %s\nPassword: %s\n", passwords[passwordIndex].website,
               passwords[passwordIndex].username, passwords[passwordIndex].password);
        printf("**************************************************\n");
    }
}

// searches for the index of a password in the system based on website name
int getPasswordIndex(PasswordInfo passwords[], int numPasswords, char website[]) {
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].website, website) == 0) {
            return i;
        }
    }

    return -1;
}

// deletes a password from the system based on website name
void deletePassword(PasswordInfo passwords[], int *numPasswords) {
    if (*numPasswords == 0) {
        printf("No passwords stored in the system.\n");
        return;
    }

    char website[50];
    printf("Enter website to delete password for: ");
    scanf(" %[^\n]", website);

    int passwordIndex = getPasswordIndex(passwords, *numPasswords, website);

    if (passwordIndex == -1) {
        printf("Password not found.\n");
    } else {
        for (int i = passwordIndex; i < (*numPasswords - 1); i++) {
            passwords[i] = passwords[i + 1];
        }

        (*numPasswords)--;
        printf("Password deleted successfully!\n");
    }
}

// saves all passwords to a text file
void savePasswords(PasswordInfo passwords[], int numPasswords) {
    FILE *passwordFile;
    passwordFile = fopen("passwords.txt", "w");

    if (passwordFile == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < numPasswords; i++) {
        fprintf(passwordFile, "%s %s %s\n", passwords[i].website, passwords[i].username, passwords[i].password);
    }

    fclose(passwordFile);
}