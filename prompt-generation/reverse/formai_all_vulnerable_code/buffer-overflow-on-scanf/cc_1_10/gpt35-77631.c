//FormAI DATASET v1.0 Category: Password management ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_LENGTH 20

int main() {

    char passwords[MAX_PASSWORDS][MAX_LENGTH]; // A two dimensional array to store our passwords
    int passwordCount = 0; // Keeps track of how many passwords we have saved

    printf("Welcome to the Password Keeper 2000!\n\n");

    while (1) { // Loop until the user decides to quit

        printf("What would you like to do?\n");
        printf("1. Save a new password\n");
        printf("2. Print all saved passwords\n");
        printf("3. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {

            case 1: // Save a new password

                if (passwordCount >= MAX_PASSWORDS) {
                    printf("Sorry, you have reached the maximum number of passwords (%d)\n\n", MAX_PASSWORDS);
                    break;
                }

                char newPassword[MAX_LENGTH]; // Store the new password temporarily
                printf("\nEnter a new password (maximum %d characters):\n", MAX_LENGTH);
                scanf("%s", newPassword);

                if (strlen(newPassword) > MAX_LENGTH) {
                    printf("Sorry, that password is too long!\n\n");
                    break;
                }

                strcpy(passwords[passwordCount], newPassword); // Copy the new password into our array
                passwordCount++; // Increment the count of passwords saved
                printf("\nYour new password has been saved successfully!\n\n");

                break;

            case 2: // Print all saved passwords

                printf("\nHere are all your saved passwords:\n");

                for (int i = 0; i < passwordCount; i++) {
                    printf("Password %d: %s\n", i + 1, passwords[i]);
                }

                printf("\n");

                break;

            case 3: // Quit
                printf("\nGoodbye! Thanks for using Password Keeper 2000!\n");
                exit(0);

            default: // Invalid choice
                printf("\nSorry, that is not a valid choice.\n\n");
                break;

        }

    }

    return 0;
}