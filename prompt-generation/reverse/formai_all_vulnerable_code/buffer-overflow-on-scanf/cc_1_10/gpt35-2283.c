//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_ACCOUNTS 10
#define FILENAME "finance_data.txt"

struct account {
    char name[20];
    double balance;
    int account_num;
};

// Helper function to print menu
void print_menu() {
    printf("Welcome to the Personal Finance Planner!\n");
    printf("1. Add new account\n");
    printf("2. View accounts\n");
    printf("3. Save accounts to file\n");
    printf("4. Load accounts from file\n");
    printf("5. Quit\n");
}

// Helper function to add a new account
void add_account(struct account *accounts, int *num_accounts) {
    if (*num_accounts >= MAX_ACCOUNTS) {
        printf("Max number of accounts reached!\n");
        return;
    }

    struct account new_account;
    printf("Enter account name: ");
    scanf("%s", new_account.name);
    printf("Enter account balance: $");
    scanf("%lf", &new_account.balance);
    printf("Enter account number: ");
    scanf("%d", &new_account.account_num);

    accounts[*num_accounts] = new_account;
    (*num_accounts)++;
    printf("Account added successfully!\n");
}

// Helper function to view all accounts
void view_accounts(struct account *accounts, int num_accounts) {
    printf("%-20s%-10s%s\n", "Account Name", "Balance", "Account Number");
    for (int i = 0; i < num_accounts; i++) {
        printf("%-20s$%-9.2lf%d\n", accounts[i].name, accounts[i].balance, accounts[i].account_num);
    }
}

// Helper function to save accounts to file
void save_accounts(struct account *accounts, int num_accounts) {
    FILE *file = fopen(FILENAME, "w");
    fprintf(file, "%d\n", num_accounts);
    for (int i = 0; i < num_accounts; i++) {
        fprintf(file, "%s %lf %d\n", accounts[i].name, accounts[i].balance, accounts[i].account_num);
    }
    fclose(file);
    printf("Accounts saved to file!\n");
}

// Helper function to load accounts from file
void load_accounts(struct account *accounts, int *num_accounts) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error loading accounts from file!\n");
        return;
    }
    fscanf(file, "%d", num_accounts);

    for (int i = 0; i < *num_accounts; i++) {
        fscanf(file, "%s %lf %d", accounts[i].name, &accounts[i].balance, &accounts[i].account_num);
    }

    fclose(file);
    printf("Accounts loaded from file!\n");
}

int main() {
    struct account accounts[MAX_ACCOUNTS];
    int num_accounts = 0;
    int option = 0;

    while (option != 5) {
        print_menu();
        scanf("%d", &option);
        switch (option) {
            case 1:
                add_account(accounts, &num_accounts);
                break;
            case 2:
                view_accounts(accounts, num_accounts);
                break;
            case 3:
                save_accounts(accounts, num_accounts);
                break;
            case 4:
                load_accounts(accounts, &num_accounts);
                break;
            case 5:
                printf("Goodbye!");
                break;
            default:
                printf("Invalid option!\n");
                break;
        }
    }

    return 0;
}