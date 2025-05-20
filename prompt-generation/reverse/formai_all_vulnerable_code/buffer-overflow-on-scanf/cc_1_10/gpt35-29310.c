//FormAI DATASET v1.0 Category: Password management ; Style: artistic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_ACCOUNTS 10
#define MAX_PASSWORD_LEN 20

struct account {
    char name[20];
    char password[MAX_PASSWORD_LEN];
};

struct account accounts[MAX_ACCOUNTS];
int account_count = 0;

void add_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached\n");
        return;
    }

    printf("Enter account name: ");
    scanf("%s", accounts[account_count].name);

    printf("Enter password: ");
    scanf("%s", accounts[account_count].password);

    account_count++;
}

void list_accounts() {
    printf("\nAccounts:\n");

    for (int i = 0; i < account_count; i++) {
        printf("%s\n", accounts[i].name);
    }
}

void check_password(char *password) {
    int digit = 0, uppercase = 0, lowercase = 0, symbol = 0;

    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            digit = 1;
        } else if (isupper(password[i])) {
            uppercase = 1;
        } else if (islower(password[i])) {
            lowercase = 1;
        } else {
            symbol = 1;
        }
    }

    if (strlen(password) < 8 || strlen(password) > 20 || digit == 0 || uppercase == 0 || lowercase == 0 | symbol == 0) {
        printf("Password must be between 8-20 characters and contain at least one digit, uppercase letter, lowercase letter, and symbol\n");
        exit(1);
    }
}

int main() {
    int choice;

    printf("1. Add Account\n");
    printf("2. List Accounts\n");
    printf("3. Exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_account();
                break;
            case 2:
                list_accounts();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    } while (1);
    return 0;
}