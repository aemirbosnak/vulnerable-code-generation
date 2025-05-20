//FormAI DATASET v1.0 Category: Password management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_ACCOUNT_LENGTH 20
#define MAX_USERNAME_LENGTH 20

struct account {
    char accountName[MAX_ACCOUNT_LENGTH];
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int numAccounts = 0;
struct account accounts[100];

void addPassword() {
    char account[MAX_ACCOUNT_LENGTH];
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter account name: ");
    scanf("%s", account);
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    struct account newAccount;
    strcpy(newAccount.accountName, account);
    strcpy(newAccount.username, username);
    strcpy(newAccount.password, password);

    accounts[numAccounts++] = newAccount;
}

void viewPasswords() {
    printf("Account\tUsername\tPassword\n");
    for (int i = 0; i < numAccounts; i++) {
        struct account curr = accounts[i];
        printf("%s\t%s\t%s\n", curr.accountName, curr.username, curr.password);
    }
}

int main() {
    while (1) {
        int choice;
        printf("1. Add a password\n2. View passwords\n3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                viewPasswords();
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}