//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 5
#define MAX_LENGTH 20

// Global variables
char passwords[MAX_PASSWORDS][MAX_LENGTH];
int numPasswords = 0;

// Function to read passwords from the user
void readPasswords() {
    int i;
    for (i = 0; i < MAX_PASSWORDS; i++) {
        printf("Enter password %d: ", i + 1);
        fgets(passwords[i], MAX_LENGTH, stdin);
    }
}

// Function to print the passwords
void printPasswords() {
    int i;
    for (i = 0; i < MAX_PASSWORDS; i++) {
        printf("%d: %s\n", i + 1, passwords[i]);
    }
}

int main() {
    // Initialize the password array with empty strings
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i][0] = '\0';
    }

    // Read the passwords from the user
    readPasswords();

    // Print the passwords
    printPasswords();

    // Ask the user to enter a number to select a password
    int selectedPassword = -1;
    printf("Select a password by entering its number (1-%d): ", MAX_PASSWORDS);
    scanf("%d", &selectedPassword);

    // If the user enters a valid number
    if (selectedPassword > 0 && selectedPassword <= MAX_PASSWORDS) {
        // Print the selected password
        printf("Selected password: %s\n", passwords[selectedPassword - 1]);
    } else {
        // If the user enters an invalid number
        printf("Invalid number. Please try again.\n");
    }

    return 0;
}