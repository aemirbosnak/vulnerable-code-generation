//FormAI DATASET v1.0 Category: Password management ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define PASSWORD_LENGTH 20

int main() {
    char password[MAX_PASSWORDS][PASSWORD_LENGTH];
    char username[MAX_PASSWORDS][PASSWORD_LENGTH];
    int numPasswords = 0;
    int count = 0;

    while (1) {
        // Menu
        printf("Password Management Program\n");
        printf("===================================\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            // Add password
            if (numPasswords == MAX_PASSWORDS) {
                printf("You have reached the maximum number of passwords\n");
            } else {
                printf("Enter new username: ");
                scanf("%s", username[numPasswords]);
                printf("Enter new password: ");
                scanf("%s", password[numPasswords]);
                numPasswords++;
                printf("Password added successfully\n");
            }
        } else if (choice == 2) {
            // View passwords
            printf("Username\tPassword\n");
            printf("========\t========\n");
            for (count=0; count<numPasswords; count++) {
                printf("%s\t\t%s\n", username[count], password[count]);
            }
        } else if (choice == 3) {
            // Quit
            printf("Goodbye!\n");
            return 0;
        } else {
            printf("Invalid choice, please try again\n");
        }
    }
}