//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Bank account structure
typedef struct {
    int account_number;
    char *name;
    double balance;
} bank_account;

// Bank database
bank_account database[] = {
    {123456, "John Doe", 1000.0},
    {654321, "Jane Doe", 2000.0},
    {987654, "John Smith", 3000.0},
};

// Number of accounts in the database
const int num_accounts = sizeof(database) / sizeof(bank_account);

// Function to find an account by account number
bank_account *find_account(int account_number) {
    for (int i = 0; i < num_accounts; i++) {
        if (database[i].account_number == account_number) {
            return &database[i];
        }
    }

    return NULL;
}

// Function to withdraw money from an account
void withdraw_money(bank_account *account, double amount) {
    if (amount > account->balance) {
        printf("Insufficient funds.\n");
    } else {
        account->balance -= amount;
        printf("Withdrawal successful.\n");
    }
}

// Function to deposit money into an account
void deposit_money(bank_account *account, double amount) {
    account->balance += amount;
    printf("Deposit successful.\n");
}

// Main function
int main() {
    // Get the account number from the user
    int account_number;
    printf("Enter your account number: ");
    scanf("%d", &account_number);

    // Find the account in the database
    bank_account *account = find_account(account_number);

    if (account == NULL) {
        printf("Account not found.\n");
        return 1;
    }

    // Get the transaction type from the user
    char transaction_type;
    printf("Enter transaction type (w/d): ");
    scanf(" %c", &transaction_type);

    // Get the amount from the user
    double amount;
    printf("Enter amount: ");
    scanf("%lf", &amount);

    // Perform the transaction
    switch (transaction_type) {
        case 'w':
            withdraw_money(account, amount);
            break;
        case 'd':
            deposit_money(account, amount);
            break;
        default:
            printf("Invalid transaction type.\n");
            return 1;
    }

    // Print the account balance
    printf("Your account balance is: %.2f\n", account->balance);

    return 0;
}