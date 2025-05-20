//FormAI DATASET v1.0 Category: Password management ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 50
#define MAX_USERNAME_LENGTH 50

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Account;

int main() {
    int numAccounts = 0;
    int choice;
    Account *accounts = calloc(numAccounts, sizeof(Account));

    while (1) {
        printf("1. Create New Account\n2. Login\n3. Quit\nEnter Your Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nEnter Your Username: ");
            char tempUsername[MAX_USERNAME_LENGTH];
            scanf("%s", tempUsername);

            for (int i = 0; i < numAccounts; i++) {
                if (strcmp(accounts[i].username, tempUsername) == 0) {
                    printf("\nSorry, That Username is Taken. Please Try Again.\n");
                    break;
                }
            }

            printf("Enter Your Password: ");
            char tempPassword[MAX_PASSWORD_LENGTH];
            scanf("%s", tempPassword);

            if (strlen(tempPassword) < 8) {
                printf("\nSorry, Your Password Must Be At Least 8 Characters Long.\n");
            } else if (strlen(tempPassword) >= MAX_PASSWORD_LENGTH) {
                printf("\nSorry, Your Password Cannot Be Longer Than %d Characters.\n", MAX_PASSWORD_LENGTH - 1);
            } else {
                int hasLowercase = 0;
                int hasUppercase = 0;
                int hasDigit = 0;

                for (int i = 0; i < strlen(tempPassword); i++) {
                    if (islower(tempPassword[i])) {
                        hasLowercase = 1;
                    } else if (isupper(tempPassword[i])) {
                        hasUppercase = 1;
                    } else if (isdigit(tempPassword[i])) {
                        hasDigit = 1;
                    }
                }

                if (hasLowercase && hasUppercase && hasDigit) {
                    numAccounts++;
                    accounts = realloc(accounts, numAccounts * sizeof(Account));

                    strcpy(accounts[numAccounts-1].username, tempUsername);
                    strcpy(accounts[numAccounts-1].password, tempPassword);

                    printf("\nYour Account Has Been Created Successfully.\n");
                } else {
                    printf("\nSorry, Your Password Must Contain At Least One Uppercase Letter, One Lowercase Letter, And One Digit.\n");
                }
            }
        } else if (choice == 2) {
            if (numAccounts == 0) {
                printf("\nSorry, There Are No Accounts Yet. Please Create One First.\n");
            } else {
                printf("\nEnter Your Username: ");
                char tempUsername[MAX_USERNAME_LENGTH];
                scanf("%s", tempUsername);

                int index = -1;

                for (int i = 0; i < numAccounts; i++) {
                    if (strcmp(accounts[i].username, tempUsername) == 0) {
                        index = i;
                        break;
                    }
                }

                if (index == -1) {
                    printf("\nSorry, That Username Does Not Exist. Please Try Again.\n");
                } else {
                    printf("Enter Your Password: ");
                    char tempPassword[MAX_PASSWORD_LENGTH];
                    scanf("%s", tempPassword);

                    if (strcmp(accounts[index].password, tempPassword) == 0) {
                        printf("\nWelcome %s! You Have Successfully Logged In.\n", tempUsername);
                    } else {
                        printf("\nSorry, Incorrect Password. Please Try Again.\n");
                    }
                }
            }
        } else if (choice == 3) {
            printf("\nGoodbye!\n");
            break;
        } else {
            printf("\nInvalid Choice. Please Try Again.\n");
        }
    }

    free(accounts);
    return 0;
}