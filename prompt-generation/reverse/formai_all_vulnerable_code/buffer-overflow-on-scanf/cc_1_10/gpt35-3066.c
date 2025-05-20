//FormAI DATASET v1.0 Category: Password management ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 10

typedef struct {
    char username[50];
    char password[50];
} Account;

Account accounts[MAX_ACCOUNTS];

int num_accounts = 0;

void add_account() {
    if (num_accounts >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached!\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", accounts[num_accounts].username);

    printf("Enter password: ");
    scanf("%s", accounts[num_accounts].password);

    num_accounts++;
}

void print_all_accounts() {
    for (int i = 0; i < num_accounts; i++) {
        printf("Username: %s\n", accounts[i].username);
        printf("Password: %s\n", accounts[i].password);
        printf("\n");
    }
}

void print_menu() {
    printf("1. Add Account\n");
    printf("2. Print All Accounts\n");
    printf("3. Exit\n");
}

int main() {
    int choice;

    do {
        print_menu();

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_account();
                break;
            case 2:
                print_all_accounts();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

        printf("\n");
    } while (choice != 3);

    return 0;
}