//FormAI DATASET v1.0 Category: Password management ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char password[50];
    char savedPassword[50] = "password123";
    int attempts = 3;

    printf("Welcome to the Top Secret Password Manager!\n");
    printf("This program is not responsible for the security of your passwords, so don't blame us if they get hacked.\n");
    printf("Please enter your password to continue: ");
    scanf("%s", password);

    while (strcmp(password, savedPassword) != 0) {
        attempts--;
        if (attempts == 0) {
            printf("\nYou have been locked out of the system. Please see the IT department for assistance.\n");
            return 0;
        } else {
            printf("\nWrong password! You have %d attempts remaining. Try again: ", attempts);
            scanf("%s", password);
        }
    }

    printf("\nCongratulations! You have accessed the password manager!\n");
    printf("What would you like to do?\n");
    printf("1. Save a new password\n");
    printf("2. View an existing password\n");
    printf("3. Update an existing password\n");
    printf("4. Delete an existing password\n");
    printf("5. Exit the password manager\n");
    printf("Please enter your choice (1-5): ");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nPlease enter the name of the website or application: ");
            char website[50];
            scanf("%s", website);
            printf("\nPlease enter your username: ");
            char username[50];
            scanf("%s", username);
            printf("\nPlease enter your new password: ");
            char newPassword[50];
            scanf("%s", newPassword);
            printf("\nSuccess! Your new password has been saved.\n");
            break;

        case 2:
            printf("\nPlease enter the name of the website or application: ");
            char website2[50];
            scanf("%s", website2);
            printf("\nYour password for %s is: %s\n", website2, newPassword);
            break;

        case 3:
            printf("\nPlease enter the name of the website or application: ");
            char website3[50];
            scanf("%s", website3);
            printf("\nPlease enter your new password: ");
            char newPassword2[50];
            scanf("%s", newPassword2);
            printf("\nSuccess! Your password for %s has been updated to %s.\n", website3, newPassword2);
            break;

        case 4:
            printf("\nPlease enter the name of the website or application: ");
            char website4[50];
            scanf("%s", website4);
            printf("\nAre you sure you want to delete your password for %s? (Y/N): ", website4);
            char response;
            scanf(" %c", &response);
            if (response == 'Y') {
                printf("\nPassword for %s has been deleted.\n", website4);
            } else {
                printf("\nDeletion cancelled.\n");
            }
            break;

        case 5:
            printf("\nThank you for using the Top Secret Password Manager!\n");
            break;

        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
    }

    return 0;
}