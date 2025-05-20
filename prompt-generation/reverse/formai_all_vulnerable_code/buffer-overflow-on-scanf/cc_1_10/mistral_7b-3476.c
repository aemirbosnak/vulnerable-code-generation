//MISTRAL-7B DATASET v1.0 Category: Banking Record System ; Style: minimalist
#include <stdio.h>
#define MAX_ACCOUNTS 50

typedef struct {
    int account_number;
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int num_accounts = 0;

void create_account(int account_number) {
    if (num_accounts >= MAX_ACCOUNTS) {
        printf("Sorry, maximum number of accounts reached.\n");
        return;
    }

    accounts[num_accounts].account_number = account_number;
    accounts[num_accounts].balance = 0.0;
    num_accounts++;

    printf("Account created successfully.\n");
}

void deposit(int account_number, float amount) {
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            accounts[i].balance += amount;
            printf("Deposit successful.\n");
            return;
        }
    }

    printf("Account not found.\n");
}

void withdraw(int account_number, float amount) {
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful.\n");
                return;
            } else {
                printf("Insufficient balance.\n");
                return;
            }
        }
    }

    printf("Account not found.\n");
}

void check_balance(int account_number) {
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Your account balance is: $%.2f\n", accounts[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}

int main() {
    int choice, account_number;
    float amount;

    while (1) {
        printf("\nBanking Record System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                create_account(account_number);
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(account_number, amount);
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(account_number, amount);
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                check_balance(account_number);
                break;
            case 5:
                printf("Thank you for using our Banking Record System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}