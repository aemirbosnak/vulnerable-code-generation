//FormAI DATASET v1.0 Category: Banking Record System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50 // Maximum length of strings

typedef struct {
    char account_no[MAX_LENGTH];
    char customer_name[MAX_LENGTH];
    char address[MAX_LENGTH];
    double balance;
} Account;

void display_menu(); // function to display the menu options
void add_account(Account accounts[], int *num_accounts); // function to add a new account
void search_account(Account accounts[], int num_accounts); // function to search for an existing account
void update_account(Account accounts[], int num_accounts); // function to update an existing account
void delete_account(Account accounts[], int *num_accounts); // function to delete an existing account
void display_all_accounts(Account accounts[], int num_accounts); // function to display all accounts

int main() {
    Account accounts[100]; // maximum of 100 accounts
    int num_accounts = 0; // initialize number of accounts to 0
    
    int choice;
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_account(accounts, &num_accounts);
                break;
            case 2:
                search_account(accounts, num_accounts);
                break;
            case 3:
                update_account(accounts, num_accounts);
                break;
            case 4:
                delete_account(accounts, &num_accounts);
                break;
            case 5:
                display_all_accounts(accounts, num_accounts);
                break;
            case 6:
                printf("Thank you for using our system!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 6);
    
    return 0;
}

void display_menu() {
    printf("Welcome to our banking record system!\n");
    printf("1. Add a new account\n");
    printf("2. Search for an account\n");
    printf("3. Update an account\n");
    printf("4. Delete an account\n");
    printf("5. Display all accounts\n");
    printf("6. Exit the system\n");
}

void add_account(Account accounts[], int *num_accounts) {
    Account new_account;
    printf("Enter account number: ");
    scanf("%s", new_account.account_no);
    printf("Enter customer name: ");
    scanf("%s", new_account.customer_name);
    printf("Enter address: ");
    scanf("%s", new_account.address);
    printf("Enter balance: ");
    scanf("%lf", &new_account.balance);
    accounts[*num_accounts] = new_account;
    *num_accounts += 1;
    printf("Account added successfully!\n");
}

void search_account(Account accounts[], int num_accounts) {
    char account_no[MAX_LENGTH];
    printf("Enter account number to search: ");
    scanf("%s", account_no);
    int i;
    for(i = 0; i < num_accounts; i++) {
        if(strcmp(account_no, accounts[i].account_no) == 0) {
            printf("Account found!\n");
            printf("Account number: %s\n", accounts[i].account_no);
            printf("Customer name: %s\n", accounts[i].customer_name);
            printf("Address: %s\n", accounts[i].address);
            printf("Balance: %.2lf\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void update_account(Account accounts[], int num_accounts) {
    char account_no[MAX_LENGTH];
    printf("Enter account number to update: ");
    scanf("%s", account_no);
    int i;
    for(i = 0; i < num_accounts; i++) {
        if(strcmp(account_no, accounts[i].account_no) == 0) {
            printf("Account found!\n");
            printf("Enter new customer name (Press enter to skip): ");
            char new_name[MAX_LENGTH];
            getchar(); // to clear input buffer
            fgets(new_name, sizeof(new_name), stdin);
            new_name[strcspn(new_name, "\n")] = 0; // to remove newline character from string
            if(strlen(new_name) > 0) {
                strcpy(accounts[i].customer_name, new_name);
            }
            printf("Enter new address (Press enter to skip): ");
            char new_address[MAX_LENGTH];
            fgets(new_address, sizeof(new_address), stdin);
            new_address[strcspn(new_address, "\n")] = 0;
            if(strlen(new_address) > 0) {
                strcpy(accounts[i].address, new_address);
            }
            printf("Enter new balance (Press enter to skip): ");
            char new_balance[MAX_LENGTH];
            fgets(new_balance, sizeof(new_balance), stdin);
            new_balance[strcspn(new_balance, "\n")] = 0;
            if(strlen(new_balance) > 0) {
                accounts[i].balance = atof(new_balance);
            }
            printf("Account updated successfully!\n");
            return;
        }
    }
    printf("Account not found.\n");
}

void delete_account(Account accounts[], int *num_accounts) {
    char account_no[MAX_LENGTH];
    printf("Enter account number to delete: ");
    scanf("%s", account_no);
    int i;
    for(i = 0; i < *num_accounts; i++) {
        if(strcmp(account_no, accounts[i].account_no) == 0) {
            printf("Account found!\n");
            int j;
            for(j = i; j < *num_accounts - 1; j++) {
                accounts[j] = accounts[j + 1];
            }
            *num_accounts -= 1;
            printf("Account deleted successfully!\n");
            return;
        }
    }
    printf("Account not found.\n");
}

void display_all_accounts(Account accounts[], int num_accounts) {
    printf("All accounts:\n");
    int i;
    for(i = 0; i < num_accounts; i++) {
        printf("Account number: %s\n", accounts[i].account_no);
        printf("Customer name: %s\n", accounts[i].customer_name);
        printf("Address: %s\n", accounts[i].address);
        printf("Balance: %.2lf\n", accounts[i].balance);
        printf("\n");
    }
    printf("Total accounts: %d\n", num_accounts);
}