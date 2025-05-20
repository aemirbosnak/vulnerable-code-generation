//FormAI DATASET v1.0 Category: Password management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a password
typedef struct Password {
    char site[100]; // website or app name
    char username[100];
    char password[100];
} Password;

// Define an array to store passwords
Password passwords[100];

// Define a variable to keep track of number of passwords saved
int numPasswords = 0;

// Function to save a new password
void saveNewPassword() {
    Password newPass;

    printf("\nPlease enter the website or app name: ");
    scanf("%s", newPass.site);

    printf("\nPlease enter your username: ");
    scanf("%s", newPass.username);

    printf("\nPlease enter your password: ");
    scanf("%s", newPass.password);

    passwords[numPasswords] = newPass;
    numPasswords++;
    printf("\nPassword saved!\n");
}

// Function to view saved passwords
void viewSavedPasswords() {
    if(numPasswords == 0) {
        printf("\nNo passwords saved yet.\n");
        return;
    }

    printf("\nWebsite/App Name\tUsername\tPassword\n");
    for(int i = 0; i < numPasswords; i++) {
        printf("%s\t\t%s\t\t%s\n", passwords[i].site, passwords[i].username, passwords[i].password);
    }
}

// Function to search for a password by website or app name
void searchForPassword() {
    char searchSite[100];

    printf("\nPlease enter the website or app name to search for: ");
    scanf("%s", searchSite);

    int found = 0;
    for(int i = 0; i < numPasswords; i++) {
        if(strcmp(passwords[i].site, searchSite) == 0) {
            printf("\nWebsite/App Name\tUsername\tPassword\n");
            printf("%s\t\t%s\t\t%s\n", passwords[i].site, passwords[i].username, passwords[i].password);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("\nPassword for %s not found.\n", searchSite);
    }
}

int main() {
    int choice;

    printf("Welcome to Password Manager!\n");

    while(1) {
        printf("\nEnter your choice:\n");
        printf("1. Save a new password\n");
        printf("2. View saved passwords\n");
        printf("3. Search for a password\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                saveNewPassword();
                break;
            case 2:
                viewSavedPasswords();
                break;
            case 3:
                searchForPassword();
                break;
            case 4:
                printf("\nGoodbye!\n");
                exit(0); // Exit the program
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}