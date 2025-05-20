//FormAI DATASET v1.0 Category: Password management ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Password {
    char account_name[50];
    char username[50];
    char password[50];
} Password;

int main() {
    Password passwords[50];
    int num_of_passwords = 0;

    while (1) {
        printf("Welcome to your password manager! What would you like to do?\n");
        printf("(1) Add a password\n");
        printf("(2) Retrieve a password\n");
        printf("(3) Quit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add a password
                if (num_of_passwords >= 50) {
                    printf("Sorry, you have reached the maximum number of passwords!\n");
                    break;
                }
                printf("Enter the account name: ");
                scanf("%s", passwords[num_of_passwords].account_name);
                printf("Enter the username: ");
                scanf("%s", passwords[num_of_passwords].username);
                printf("Enter the password: ");
                scanf("%s", passwords[num_of_passwords].password);
                num_of_passwords++;
                printf("Password added successfully!\n");
                break;

            case 2: // Retrieve a password
                if (num_of_passwords == 0) {
                    printf("Sorry, no passwords saved yet!\n");
                    break;
                }
                printf("Enter the account name: ");
                char account_name[50];
                scanf("%s", account_name);
                for (int i = 0; i < num_of_passwords; i++) {
                    if (strcmp(passwords[i].account_name, account_name) == 0) {
                        printf("Account name: %s\n", account_name);
                        printf("Username: %s\n", passwords[i].username);
                        printf("Password: %s\n", passwords[i].password);
                        break;
                    }
                    if (i == num_of_passwords - 1) {
                        printf("Sorry, no password found for that account name!\n");
                    }
                }
                break;

            case 3: // Quit
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice, please enter a number 1-3.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}