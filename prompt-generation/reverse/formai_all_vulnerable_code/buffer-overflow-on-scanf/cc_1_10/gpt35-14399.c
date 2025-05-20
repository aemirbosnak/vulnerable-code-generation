//FormAI DATASET v1.0 Category: Password management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 50
#define MAX_PASSWORD_LENGTH 20

// function prototypes
void addPassword(char arr[][MAX_PASSWORD_LENGTH]);
void listPasswords(char arr[][MAX_PASSWORD_LENGTH]);
void deletePassword(char arr[][MAX_PASSWORD_LENGTH]);

int main() {
    char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH]; // array to hold passwords
    char choice; // variable to hold user's choice from menu

    // welcome message
    printf("Welcome to the Password Management Program. Here you can store up to %d passwords of length %d.\n", MAX_PASSWORDS, MAX_PASSWORD_LENGTH-1);

    // loop for menu
    while (1) {
        printf("\nChoose an option:\n");
        printf("A: Add a password\n");
        printf("L: List all passwords\n");
        printf("D: Delete a password\n");
        printf("Q: Quit program\n");
        printf("Choice: ");
        scanf(" %c", &choice);

        // switch statement for menu options
        switch (toupper(choice)) {
            case 'A':
                addPassword(passwords);
                break;
            case 'L':
                listPasswords(passwords);
                break;
            case 'D':
                deletePassword(passwords);
                break;
            case 'Q':
                printf("Thank you for using the Password Management Program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}

// function to add a password to the array
void addPassword(char arr[][MAX_PASSWORD_LENGTH]) {
    char password[MAX_PASSWORD_LENGTH];
    int i;

    // get new password from user and validate input
    printf("Enter new password (up to %d characters): ", MAX_PASSWORD_LENGTH-1);
    scanf(" %s", password);
    if (strlen(password) > MAX_PASSWORD_LENGTH-1) {
        printf("Password is too long.\n");
        return;
    }
    for (i=0; i<strlen(password); i++) {
        if (!isalnum(password[i])) {
            printf("Password can only contain alphanumeric characters.\n");
            return;
        }
    }

    // find next available slot in array and add password
    for (i=0; i<MAX_PASSWORDS; i++) {
        if (strcmp(arr[i], "") == 0) { // if password slot is empty
            strncpy(arr[i], password, strlen(password)+1); // copy password to array
            printf("Password added.\n");
            return;
        }
    }

    // if array is full
    printf("Cannot add password. Maximum number of passwords reached.\n");
    return;
}

// function to list all passwords in the array
void listPasswords(char arr[][MAX_PASSWORD_LENGTH]) {
    int i;

    // if array is empty
    if (strcmp(arr[0], "") == 0) {
        printf("No passwords stored.\n");
        return;
    }

    // print all stored passwords
    printf("Stored passwords:\n");
    for (i=0; i<MAX_PASSWORDS; i++) {
        if (strcmp(arr[i], "") != 0) {
            printf("%d. %s\n", i+1, arr[i]);
        }
    }
}

// function to delete a password from the array
void deletePassword(char arr[][MAX_PASSWORD_LENGTH]) {
    int index;
    int i;

    // if array is empty
    if (strcmp(arr[0], "") == 0) {
        printf("No passwords stored.\n");
        return;
    }

    // get index of password to delete from user and validate input
    printf("Enter the number of the password to delete: ");
    scanf(" %d", &index);
    if (index < 1 || index > MAX_PASSWORDS || strcmp(arr[index-1], "") == 0) {
        printf("Invalid input.\n");
        return;
    }

    // delete password
    strncpy(arr[index-1], "", 1);
    printf("Password deleted.\n");

    // shift remaining passwords left in array
    for (i=index-1; i<MAX_PASSWORDS-1; i++) {
        strncpy(arr[i], arr[i+1], strlen(arr[i+1])+1);
        strncpy(arr[i+1], "", 1);
    }
}