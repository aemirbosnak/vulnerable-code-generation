//FormAI DATASET v1.0 Category: Password management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 64
#define MAX_USERNAME_LENGTH 32

typedef struct user_account {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} UserAccount;

int main() {
    int num_accounts = 0;
    printf("Welcome to the Password Management System!\n\n");

    // Allocate memory for user accounts
    UserAccount *accounts = (UserAccount*) malloc(sizeof(UserAccount) * MAX_PASSWORD_LENGTH);

    while (1) {
        printf("What would you like to do?\n");
        printf("1. Add a new account\n");
        printf("2. Retrieve an existing account\n");
        printf("3. Exit\n\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {   // Add new account
                printf("\nEnter your username: ");
                scanf("%s", accounts[num_accounts].username);
                printf("Enter your password: ");
                scanf("%s", accounts[num_accounts].password);

                num_accounts++;
                printf("\nAccount added successfully!\n\n");
                break;
            }
            case 2: {   // Retrieve existing account
                char username[MAX_USERNAME_LENGTH];
                char password[MAX_PASSWORD_LENGTH];
                printf("\nEnter your username: ");
                scanf("%s", username);
                printf("Enter your password: ");
                scanf("%s", password);

                // Search for account in list
                int account_index = -1;
                for (int i = 0; i < num_accounts; i++) {
                    if (strcmp(username, accounts[i].username) == 0 &&
                            strcmp(password, accounts[i].password) == 0) {
                        account_index = i;
                        break;
                    }
                }

                if (account_index == -1) {
                    printf("\nAccount not found!\n\n");
                } else {
                    printf("\nUsername: %s\n", accounts[account_index].username);
                    printf("Password: %s\n\n", accounts[account_index].password);
                }
                break;
            }
            case 3: {   // Exit program
                free(accounts);
                printf("\nGoodbye!\n");
                return 0;
            }
            default: {  // Invalid choice
                printf("\nInvalid choice, try again!\n\n");
                break;
            }
        }
    }
}