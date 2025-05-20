//FormAI DATASET v1.0 Category: Banking Record System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

typedef struct {
    long int account_number;
    char name[50];
    float balance;
} Account;

void print_menu() {
    printf("\n");
    printf("***C BANKING RECORD SYSTEM***\n");
    printf("1. Add Account\n");
    printf("2. Display All Accounts\n");
    printf("3. Search for Account\n");
    printf("4. Delete Account\n");
    printf("5. Update Account Balance\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

void clear_buffer() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void add_account(Account *accounts, int *num_accounts) {
    Account new_account;

    printf("\n");
    printf("Enter Account Number: ");
    scanf("%ld", &new_account.account_number);
    clear_buffer();

    for (int i = 0; i < *num_accounts; i++) {
        if (accounts[i].account_number == new_account.account_number) {
            printf("Account with the given number already exists\n");
            return;
        }
    }

    printf("Enter Account Holder Name: ");
    fgets(new_account.name, 50, stdin);
    new_account.name[strcspn(new_account.name, "\n")] = '\0';

    printf("Enter Account Balance: ");
    scanf("%f", &new_account.balance);
    clear_buffer();

    accounts[*num_accounts] = new_account;
    *num_accounts += 1;

    printf("Account added successfully\n");
}

void display_all_accounts(Account *accounts, int num_accounts) {
    printf("\n");
    printf("ACCOUNT NUMBER\t\tACCOUNT HOLDER NAME\t\tBALANCE\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("%ld\t\t\t%s\t\t\t\t%.2f\n", accounts[i].account_number, accounts[i].name, accounts[i].balance);
    }
}

void search_account(Account *accounts, int num_accounts) {
    long int account_number;
    printf("\nEnter Account Number to search: ");
    scanf("%ld", &account_number);

    bool account_found = false;

    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("\nAccount found:\n");
            printf("ACCOUNT NUMBER\t\tACCOUNT HOLDER NAME\t\tBALANCE\n");
            printf("%ld\t\t\t%s\t\t\t\t%.2f\n", accounts[i].account_number, accounts[i].name, accounts[i].balance);
            account_found = true;
            break;
        }
    }

    if (!account_found) {
        printf("\nAccount with the given account number not found\n");
    }
}

void delete_account(Account *accounts, int *num_accounts) {
    long int account_number;
    printf("\nEnter Account Number to delete: ");
    scanf("%ld", &account_number);

    bool account_found = false;

    for (int i = 0; i < *num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            for (int j = i; j < *num_accounts - 1; j++) {
                accounts[j] = accounts[j + 1];
            }
            *num_accounts -= 1;
            printf("\nAccount deleted successfully\n");
            account_found = true;
            break;
        }
    }

    if (!account_found) {
        printf("\nAccount with the given account number not found\n");
    }
}

void update_account_balance(Account *accounts, int num_accounts) {
    long int account_number;
    printf("\nEnter Account Number to update: ");
    scanf("%ld", &account_number);

    bool account_found = false;

    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("\nEnter new account balance: ");
            scanf("%f", &accounts[i].balance);
            clear_buffer();
            printf("\nAccount balance updated successfully\n");
            account_found = true;
            break;
        }
    }

    if (!account_found) {
        printf("\nAccount with the given account number not found\n");
    }
}

int main() {
    Account accounts[BUFFER_SIZE];
    int num_accounts = 0;

    while (true) {
        print_menu();

        int choice;
        scanf("%d", &choice);
        clear_buffer();

        switch (choice) {
            case 1:
                add_account(accounts, &num_accounts);
                break;
            case 2:
                display_all_accounts(accounts, num_accounts);
                break;
            case 3:
                search_account(accounts, num_accounts);
                break;
            case 4:
                delete_account(accounts, &num_accounts);
                break;
            case 5:
                update_account_balance(accounts, num_accounts);
                break;
            case 6:
                printf("\nGoodbye\n");
                exit(EXIT_SUCCESS);
                break;
            default:
                printf("Invalid choice, please try again\n");
        }
    }

    return 0;
}