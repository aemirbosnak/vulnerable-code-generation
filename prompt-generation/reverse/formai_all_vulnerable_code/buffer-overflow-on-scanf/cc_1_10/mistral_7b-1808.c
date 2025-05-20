//MISTRAL-7B DATASET v1.0 Category: Banking Record System ; Style: calm
#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    char name[50];
    float balance;
    int account_number;
} Account;

Account accounts[MAX_ACCOUNTS];
int num_accounts = 0;

int find_available_account(void);
void create_account(void);
void deposit(void);
void withdraw(void);
void check_balance(void);

int main() {
    int choice;

    while (1) {
        printf("\n1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                check_balance();
                break;
            case 5:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

int find_available_account(void) {
    int i;

    for (i = 0; i < MAX_ACCOUNTS; i++) {
        if (accounts[i].account_number == 0) {
            accounts[i].account_number = num_accounts + 1;
            return i;
        }
    }

    printf("Sorry, all accounts are full.\n");
    return -1;
}

void create_account(void) {
    int account_index;

    if ((account_index = find_available_account()) == -1) {
        return;
    }

    printf("Enter your name: ");
    scanf("%s", accounts[account_index].name);
    accounts[account_index].balance = 0.0;

    printf("Account created successfully. Your account number is %d.\n", accounts[account_index].account_number);
    num_accounts++;
}

void deposit(void) {
    int account_number;
    float amount;
    int i;

    printf("Enter your account number: ");
    scanf("%d", &account_number);

    for (i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Enter the amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Deposit successful.\n");
            return;
        }
    }

    printf("Account not found.\n");
}

void withdraw(void) {
    int account_number;
    float amount;
    int i;

    printf("Enter your account number: ");
    scanf("%d", &account_number);

    for (i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Enter the amount to withdraw: ");
            scanf("%f", &amount);

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

void check_balance(void) {
    int account_number;
    int i;

    printf("Enter your account number: ");
    scanf("%d", &account_number);

    for (i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Your account balance is %.2f.\n", accounts[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}