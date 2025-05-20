//FormAI DATASET v1.0 Category: Password management ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char website[30];
    char username[30];
    char password[30];
} Account;

int main() {
    Account accounts[10];
    int numAccounts = 0;

    while (1) {
        printf("Enter command (1=add, 2=print, 3=find, 4=quit): ");
        int command;
        scanf("%d", &command);
        getchar();

        switch (command) {
            case 1:
                if (numAccounts == 10) {
                    printf("Maximum number of accounts reached.\n");
                    break;
                }

                Account newAccount;
                printf("Enter website: ");
                fgets(newAccount.website, sizeof(newAccount.website), stdin);
                newAccount.website[strcspn(newAccount.website, "\n")] = 0;

                printf("Enter username: ");
                fgets(newAccount.username, sizeof(newAccount.username), stdin);
                newAccount.username[strcspn(newAccount.username, "\n")] = 0;

                printf("Enter password: ");
                fgets(newAccount.password, sizeof(newAccount.password), stdin);
                newAccount.password[strcspn(newAccount.password, "\n")] = 0;

                accounts[numAccounts] = newAccount;
                numAccounts++;

                printf("New account added.\n");
                break;
            case 2:
                if (numAccounts == 0) {
                    printf("There are no accounts.\n");
                    break;
                }

                printf("Accounts:\n");
                for (int i = 0; i < numAccounts; i++) {
                    printf("\tWebsite: %s\n", accounts[i].website);
                    printf("\tUsername: %s\n", accounts[i].username);
                    printf("\tPassword: %s\n", accounts[i].password);
                }
                break;
            case 3:
                if (numAccounts == 0) {
                    printf("There are no accounts.\n");
                    break;
                }

                char website[30];
                printf("Enter website: ");
                fgets(website, sizeof(website), stdin);
                website[strcspn(website, "\n")] = 0;

                int found = 0;
                for (int i = 0; i < numAccounts; i++) {
                    if (strcmp(accounts[i].website, website) == 0) {
                        printf("Account:\n");
                        printf("\tWebsite: %s\n", accounts[i].website);
                        printf("\tUsername: %s\n", accounts[i].username);
                        printf("\tPassword: %s\n", accounts[i].password);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("No accounts found for that website.\n");
                }
                break;
            case 4:
                printf("Goodbye.\n");
                return 0;
            default:
                printf("Invalid command.\n");
                break;
        }
    }

    return 0;
}