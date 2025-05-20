//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Account struct to store account information
typedef struct {
    char *name;
    double balance;
    pthread_mutex_t lock;
} Account;

// List of accounts
Account accounts[] = {
    {"Checking", 1000.00},
    {"Savings", 2000.00},
    {"Investment", 3000.00}
};

// Number of accounts
const int num_accounts = sizeof(accounts) / sizeof(Account);

// Thread function to withdraw money from an account
void *withdraw(void *arg) {
    // Get account and amount to withdraw
    Account *account = (Account *)arg;
    double amount;
    printf("Enter amount to withdraw from %s: ", account->name);
    scanf("%lf", &amount);

    // Lock account
    pthread_mutex_lock(&account->lock);

    // Check if enough balance
    if (account->balance < amount) {
        printf("Insufficient balance in %s\n", account->name);
    } else {
        // Withdraw money
        account->balance -= amount;
        printf("Withdrew %lf from %s\n", amount, account->name);
    }

    // Unlock account
    pthread_mutex_unlock(&account->lock);

    return NULL;
}

// Thread function to deposit money into an account
void *deposit(void *arg) {
    // Get account and amount to deposit
    Account *account = (Account *)arg;
    double amount;
    printf("Enter amount to deposit into %s: ", account->name);
    scanf("%lf", &amount);

    // Lock account
    pthread_mutex_lock(&account->lock);

    // Deposit money
    account->balance += amount;
    printf("Deposited %lf into %s\n", amount, account->name);

    // Unlock account
    pthread_mutex_unlock(&account->lock);

    return NULL;
}

// Thread function to print account balances
void *print_balances(void *arg) {
    while (1) {
        // Lock all accounts
        for (int i = 0; i < num_accounts; i++) {
            pthread_mutex_lock(&accounts[i].lock);
        }

        // Print balances
        printf("Account balances:\n");
        for (int i = 0; i < num_accounts; i++) {
            printf("%s: %lf\n", accounts[i].name, accounts[i].balance);
        }

        // Unlock all accounts
        for (int i = 0; i < num_accounts; i++) {
            pthread_mutex_unlock(&accounts[i].lock);
        }

        sleep(1);
    }

    return NULL;
}

int main() {
    // Initialize mutexes
    for (int i = 0; i < num_accounts; i++) {
        pthread_mutex_init(&accounts[i].lock, NULL);
    }

    // Create threads
    pthread_t withdraw_thread, deposit_thread, print_balances_thread;
    pthread_create(&withdraw_thread, NULL, withdraw, &accounts[0]);
    pthread_create(&deposit_thread, NULL, deposit, &accounts[1]);
    pthread_create(&print_balances_thread, NULL, print_balances, NULL);

    // Join threads
    pthread_join(withdraw_thread, NULL);
    pthread_join(deposit_thread, NULL);
    pthread_join(print_balances_thread, NULL);

    return 0;
}