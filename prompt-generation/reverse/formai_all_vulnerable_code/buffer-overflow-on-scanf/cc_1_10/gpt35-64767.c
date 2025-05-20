//FormAI DATASET v1.0 Category: Password management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[30];
    char password[MAX_PASSWORD_LENGTH];
} account;

account account_list[MAX_PASSWORDS];
int num_accounts = 0;

void add_account() {
    if (num_accounts < MAX_PASSWORDS) {
        account new_account;
        printf("Enter username: ");
        scanf("%s", new_account.username);
        printf("Enter password: ");
        scanf("%s", new_account.password);
        account_list[num_accounts++] = new_account;
        printf("Account added successfully.\n");
    } else {
        printf("Cannot add account. Maximum account limit reached.\n");
    }
}

void display_accounts() {
    if (num_accounts == 0) {
        printf("No accounts found.\n");
    } else {
        printf("%-15s%s\n", "Username", "Password");
        printf("------------------------\n");
        for (int i = 0; i < num_accounts; i++) {
            printf("%-15s%s\n", account_list[i].username, account_list[i].password);
        }
    }
}

void change_password(char username[]) {
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(account_list[i].username, username) == 0) {
            printf("Enter new password: ");
            scanf("%s", account_list[i].password);
            printf("Password changed successfully.\n");
            return;
        }
    }
    printf("Account not found.\n");
}

int main() {
    int option;
    do {
        printf("\nPassword Management System\n");
        printf("------------------------------\n");
        printf("1. Add Account\n");
        printf("2. Display Accounts\n");
        printf("3. Change Password\n");
        printf("4. Quit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_account();
                break;
            case 2:
                display_accounts();
                break;
            case 3:
                {
                    char username[30];
                    printf("Enter username: ");
                    scanf("%s", username);
                    change_password(username);
                    break;
                }
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid input. Try again.\n");
                break;
        }
    } while (option != 4);

    return 0;
}