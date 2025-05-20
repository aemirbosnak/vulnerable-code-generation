//FormAI DATASET v1.0 Category: Banking Record System ; Style: multiplayer
#include<stdio.h>
#include<string.h>
#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 1000

typedef struct {
    int account_number;
    float balance;
    char account_type[20];
} account;

typedef struct {
    char transaction_type[20];
    float amount;
    int account_number;
} transaction;

account accounts[MAX_ACCOUNTS];
transaction transactions[MAX_TRANSACTIONS];
int num_accounts = 0, num_transactions = 0;

// function to add a new account
void add_account(int account_number, float balance, char account_type[]) {
    if(num_accounts == MAX_ACCOUNTS) {
        printf("Error: Maximum accounts reached.\n");
        return;
    }
    accounts[num_accounts].account_number = account_number;
    accounts[num_accounts].balance = balance;
    strcpy(accounts[num_accounts].account_type, account_type);
    num_accounts++;
    printf("Account added successfully.\n");
}

// function to display all accounts
void display_accounts() {
    printf("Accounts:\n");
    printf("--------------------------------\n");
    printf("| Account No. | Balance | Type |\n");
    printf("--------------------------------\n");
    for(int i=0; i<num_accounts; i++) {
        printf("| %-11d | %-7.2f | %-4s |\n", accounts[i].account_number, accounts[i].balance, accounts[i].account_type);
    }
    printf("--------------------------------\n");
}

// function to add a new transaction
void add_transaction(char transaction_type[], float amount, int account_number) {
    if(num_transactions == MAX_TRANSACTIONS) {
        printf("Error: Maximum transactions reached.\n");
        return;
    }
    transactions[num_transactions].account_number = account_number;
    transactions[num_transactions].amount = amount;
    strcpy(transactions[num_transactions].transaction_type, transaction_type);
    num_transactions++;
    printf("Transaction added successfully.\n");
}

// function to display transactions for a particular account
void display_transactions(int account_number) {
    printf("Transactions for account %d:\n", account_number);
    printf("----------------------------------------\n");
    printf("| Transaction Type | Amount | Account No. |\n");
    printf("----------------------------------------\n");
    for(int i=0; i<num_transactions; i++) {
        if(transactions[i].account_number == account_number) {
            printf("| %-16s | %-6.2f | %-11d |\n", transactions[i].transaction_type, transactions[i].amount, transactions[i].account_number);
        }
    }
    printf("----------------------------------------\n");
}

int main() {
    int choice;
    do {
        printf("Enter choice:\n");
        printf("1. Add account\n");
        printf("2. Display all accounts\n");
        printf("3. Add transaction\n");
        printf("4. Display transactions for an account\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                int account_number;
                float balance;
                char account_type[20];
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter balance: ");
                scanf("%f", &balance);
                printf("Enter account type: ");
                scanf("%s", account_type);
                add_account(account_number, balance, account_type);
                break;
            }
            case 2: {
                display_accounts();
                break;
            }
            case 3: {
                char transaction_type[20];
                float amount;
                int account_number;
                printf("Enter transaction type: ");
                scanf("%s", transaction_type);
                printf("Enter amount: ");
                scanf("%f", &amount);
                printf("Enter account number: ");
                scanf("%d", &account_number);
                add_transaction(transaction_type, amount, account_number);
                break;
            }
            case 4: {
                int account_number;
                printf("Enter account number: ");
                scanf("%d", &account_number);
                display_transactions(account_number);
                break;
            }
            case 5: {
                printf("Exiting program...\n");
                break;
            }
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 5);
    return 0;
}