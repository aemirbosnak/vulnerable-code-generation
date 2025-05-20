//Falcon-180B DATASET v1.0 Category: Password management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

// Password structure
struct Password {
    char username[50];
    char password[50];
};

// Function to compare two passwords
int comparePasswords(struct Password *password1, struct Password *password2) {
    return strcmp(password1->username, password2->username);
}

// Function to add a new password
void addPassword(struct Password passwords[], int numPasswords) {
    printf("Enter username: ");
    scanf("%s", passwords[numPasswords].username);

    printf("Enter password: ");
    scanf("%s", passwords[numPasswords].password);

    numPasswords++;
}

// Function to remove a password
void removePassword(struct Password passwords[], int numPasswords) {
    printf("Enter username to remove: ");
    char username[50];
    scanf("%s", username);

    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            memmove(&passwords[i], &passwords[i+1], sizeof(struct Password) * (numPasswords - i - 1));
            numPasswords--;
            break;
        }
    }

    if (i == numPasswords) {
        printf("Username not found.\n");
    }
}

// Function to display all passwords
void displayPasswords(struct Password passwords[], int numPasswords) {
    printf("Usernames and passwords:\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

// Function to sort passwords by username
void sortPasswords(struct Password passwords[], int numPasswords) {
    qsort(passwords, numPasswords, sizeof(struct Password), comparePasswords);
}

int main() {
    struct Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    // Initialize passwords array
    strcpy(passwords[numPasswords].username, "username1");
    strcpy(passwords[numPasswords].password, "password1");
    numPasswords++;

    strcpy(passwords[numPasswords].username, "username2");
    strcpy(passwords[numPasswords].password, "password2");
    numPasswords++;

    strcpy(passwords[numPasswords].username, "username3");
    strcpy(passwords[numPasswords].password, "password3");
    numPasswords++;

    // Add new password
    addPassword(passwords, numPasswords);

    // Display all passwords
    displayPasswords(passwords, numPasswords);

    // Sort passwords by username
    sortPasswords(passwords, numPasswords);

    // Display all passwords after sorting
    displayPasswords(passwords, numPasswords);

    // Remove a password
    removePassword(passwords, numPasswords);

    // Display all passwords after removing
    displayPasswords(passwords, numPasswords);

    return 0;
}