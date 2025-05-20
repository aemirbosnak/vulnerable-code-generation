//FormAI DATASET v1.0 Category: Banking Record System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Customer {
    char full_name[100];
    char address[100];
    char dob[11];
    char contact_no[11];
    char id[20];
};

struct Account {
    int account_no;
    char account_type[10];
    float balance;
    struct Customer customer;
};

void register_customer(struct Customer* customer) {
    printf("Please provide your full name: ");
    scanf("%s", customer->full_name);

    printf("Please provide your address: ");
    scanf("%s", customer->address);

    printf("Please provide your date of birth (DD/MM/YYYY): ");
    scanf("%s", customer->dob);

    printf("Please provide your contact number: ");
    scanf("%s", customer->contact_no);

    printf("Please provide your identification number: ");
    scanf("%s", customer->id);
}

void create_account(struct Account* account) {
    static int account_counter = 100001;
    printf("Choose account type (savings/checking/current): ");
    scanf("%s", account->account_type);

    account->account_no = account_counter++;
    
    printf("Enter initial deposit amount: ");
    float deposit_amount;
    scanf("%f", &deposit_amount);

    account->balance = deposit_amount;
    
    printf("Your account has been successfully created. Account number: %d\n", account->account_no);
}

void deposit(struct Account* account) {
    printf("Please enter deposit amount: ");
    float deposit_amount;
    scanf("%f", &deposit_amount);

    account->balance += deposit_amount;
    printf("Deposit successful. Current balance: %.2f\n", account->balance);
}

void withdraw(struct Account* account) {
    printf("Please enter withdrawal amount: ");
    float withdrawal_amount;
    scanf("%f", &withdrawal_amount);

    if (withdrawal_amount > account->balance) {
        printf("Insufficient balance. Current balance: %.2f\n", account->balance);
        return;
    }

    account->balance -= withdrawal_amount;
    printf("Withdrawal successful. Current balance: %.2f\n", account->balance);
}

void transfer(struct Account* sender, struct Account* receiver) {
    printf("Please enter recipient account number: ");
    int recipient_account_no;
    scanf("%d", &recipient_account_no);

    if (sender->account_no == recipient_account_no) {
        printf("Sender and recipient account numbers cannot be the same.\n");
        return;
    }

    float transfer_amount;
    printf("Please enter transfer amount: ");
    scanf("%f", &transfer_amount);

    if (transfer_amount > sender->balance) {
        printf("Insufficient balance. Current balance: %.2f\n", sender->balance);
        return;
    }

    sender->balance -= transfer_amount;
    receiver->balance += transfer_amount;

    printf("Transfer successful. Sender's current balance: %.2f\n", sender->balance);
}

void view_transactions(struct Account* account) {
    printf("Transaction history for account number: %d\n", account->account_no);

    printf("Account type: %s\n", account->account_type);

    printf("Customer name: %s\n", account->customer.full_name);

    printf("Transaction details:\n");

    // Implement transaction history retrieval logic here
}

int main() {
    printf("Welcome to our banking record system program!\n");
    printf("Please follow the instructions to make the most of our services.\n");

    struct Account account;
    struct Customer customer;
    register_customer(&customer);
    create_account(&account);

    bool is_running = true;

    while (is_running) {
        int option;
        printf("\nPlease choose an option:\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Transfer\n");
        printf("4. Transaction history\n");
        printf("5. Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                deposit(&account);
                break;
            case 2:
                withdraw(&account);
                break;
            case 3:
                transfer(&account, &account);
                break;
            case 4:
                view_transactions(&account);
                break;
            case 5:
                is_running = false;
                printf("Thank you for using our banking record system program.\n");
                break;
        }
    }

    return 0;
}