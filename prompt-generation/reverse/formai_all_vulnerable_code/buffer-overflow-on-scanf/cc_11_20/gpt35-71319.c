//FormAI DATASET v1.0 Category: Password management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 20
#define MAX_PASSWORD_LENGTH 30

char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];

int main() {
    int menuOption = 0, numberOfPasswords = 0, passwordIndexToDelete = 0, i = 0, j = 0;
    char buffer[MAX_PASSWORD_LENGTH];
    char newPassword[MAX_PASSWORD_LENGTH];
    char confirmationPassword[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    /* Loop until user selects option 5 to quit */
    while (menuOption != 5) {
        /* Display menu and get user input */
        printf("\nPassword Manager\n");
        printf("1. Display Passwords\n");
        printf("2. Add New Password\n");
        printf("3. Delete Password\n");
        printf("4. Update Password\n");
        printf("5. Quit\n");
        printf("Enter menu option: ");
        scanf("%d", &menuOption);

        switch (menuOption) {
            case 1:
                /* Display all passwords */
                printf("\n");
                for (i = 0; i < numberOfPasswords; i++) {
                    printf("%d. %s\n", i + 1, passwords[i]);
                }
                break;

            case 2:
                /* Add a new password */
                if (numberOfPasswords >= MAX_PASSWORDS) {
                    printf("\nError: Maximum number of passwords reached!\n");
                    break;
                }

                printf("\nEnter username: ");
                scanf("%s", username);

                printf("Enter password: ");
                scanf("%s", newPassword);

                printf("Confirm password: ");
                scanf("%s", confirmationPassword);

                if (strcmp(newPassword, confirmationPassword) != 0) {
                    printf("Passwords do not match!\n");
                    break;
                }

                if (strlen(newPassword) > MAX_PASSWORD_LENGTH) {
                    printf("Password is too long!\n");
                    break;
                }

                strncpy(passwords[numberOfPasswords], newPassword, MAX_PASSWORD_LENGTH);
                numberOfPasswords++;
                printf("Successfully added password!\n");
                break;

            case 3:
                /* Delete a password */
                if (numberOfPasswords <= 0) {
                    printf("\nError: No passwords to delete!\n");
                    break;
                }

                printf("\nEnter the index of the password to delete: ");
                scanf("%d", &passwordIndexToDelete);

                if (passwordIndexToDelete < 1 || passwordIndexToDelete > numberOfPasswords) {
                    printf("Invalid index!\n");
                    break;
                }

                for (i = passwordIndexToDelete - 1; i < numberOfPasswords - 1; i++) {
                    strcpy(passwords[i], passwords[i + 1]);
                }

                numberOfPasswords--;
                printf("Password successfully deleted!\n");
                break;

            case 4:
                /* Update a password */
                if (numberOfPasswords <= 0) {
                    printf("\nError: No passwords to update!\n");
                    break;
                }

                printf("\nEnter the index of the password to update: ");
                scanf("%d", &passwordIndexToDelete);

                if (passwordIndexToDelete < 1 || passwordIndexToDelete > numberOfPasswords) {
                    printf("Invalid index!\n");
                    break;
                }

                printf("Enter new password: ");
                scanf("%s", newPassword);

                printf("Confirm new password: ");
                scanf("%s", confirmationPassword);

                if (strcmp(newPassword, confirmationPassword) != 0) {
                    printf("Passwords do not match!\n");
                    break;
                }

                if (strlen(newPassword) > MAX_PASSWORD_LENGTH) {
                    printf("Password is too long!\n");
                    break;
                }

                strncpy(passwords[passwordIndexToDelete - 1], newPassword, MAX_PASSWORD_LENGTH);
                printf("Password successfully updated!\n");
                break;

            case 5:
                /* User selected quit */
                printf("\nGoodbye!\n");
                break;

            default:
                /* Invalid menu option */
                printf("\nInvalid menu option!\n");
                break;
        }
    }

    return 0;
}