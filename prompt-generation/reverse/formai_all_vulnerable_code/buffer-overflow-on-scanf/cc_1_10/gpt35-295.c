//FormAI DATASET v1.0 Category: Password management ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LEN 50
#define MAX_PASSWORD_LEN 50

typedef struct {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
} Account;

int main() {
    int numAccounts = 0;
    Account* accounts = NULL;
    int choice = 0;

    while (1) {
        printf("1. Add account\n");
        printf("2. Retrieve password\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                numAccounts++;
                accounts = (Account*)realloc(accounts, numAccounts * sizeof(Account));
                printf("Enter username: ");
                scanf("%s", accounts[numAccounts - 1].username);
                printf("Enter password: ");
                scanf("%s", accounts[numAccounts - 1].password);
                printf("Account added successfully!\n");
                break;
            }
            case 2: {
                char searchName[MAX_USERNAME_LEN];
                int foundIndex = -1;
                printf("Enter username to search: ");
                scanf("%s", searchName);
                for (int i = 0; i < numAccounts; i++) {
                    if (strcmp(accounts[i].username, searchName) == 0) {
                        foundIndex = i;
                        break;
                    }
                }
                if (foundIndex != -1) {
                    printf("Password for %s is %s\n", searchName, accounts[foundIndex].password);
                } else {
                    printf("Username not found.\n");
                }
                break;
            }
            case 3: {
                printf("Goodbye!\n");
                free(accounts);
                return 0;
            }
            default: {
                printf("Invalid choice. Try again.\n");
                break;
            }
        }
    }
}