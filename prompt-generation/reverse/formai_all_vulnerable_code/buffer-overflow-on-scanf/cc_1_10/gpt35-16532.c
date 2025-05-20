//FormAI DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 20
#define MAX_PASS_LEN 25

void encrypt(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {     // loop through string
        password[i] += 5;                        // add 5 to each character
    }
}

void decrypt(char *password) {
    int i;
    for (i = 0; i < strlen(password); i++) {     // loop through string
        password[i] -= 5;                        // subtract 5 from each character
    }
}

int main() {
    char passwords[MAX_PASSWORDS][MAX_PASS_LEN]; // array to store passwords
    int numPasswords = 0;

    int choice;
    char tempPass[MAX_PASS_LEN];

    while (1) {
        // Display menu
        printf("\n1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // User chooses to add password
        if (choice == 1) {
            if (numPasswords == MAX_PASSWORDS) {
                printf("Max number of passwords reached.\n");
            }
            else {
                printf("Enter password to add: ");
                scanf("%s", tempPass);
                encrypt(tempPass);          // encrypt password
                strcpy(passwords[numPasswords], tempPass); // add password to list
                numPasswords++;
                printf("Password added!\n");
            }
        }
        // User chooses to view passwords
        else if (choice == 2) {
            if (numPasswords == 0) {
                printf("No passwords stored.\n");
            }
            else {
                int i;
                printf("\nPasswords:\n");
                for (i = 0; i < numPasswords; i++) {
                    decrypt(passwords[i]);  // decrypt password for display
                    printf("%d. %s\n", i+1, passwords[i]);
                    encrypt(passwords[i]);  // encrypt password again for storage
                }
            }
        }
        // User chooses to exit
        else if (choice == 3) {
            break;
        }
        // Invalid choice
        else {
            printf("Invalid choice. Please enter a number from 1-3.\n");
        }
    }

    return 0;
}