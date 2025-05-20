//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_NAME_LENGTH 50
#define MAX_BUFFER 256

typedef struct {
    int account_number;
    char name[MAX_NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

void create_account();
void view_accounts();
void deposit();
void withdraw();
void transfer();
void display_menu();
int find_account(int account_number);

int main() {
    int choice;

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: create_account(); break;
            case 2: view_accounts(); break;
            case 3: deposit(); break;
            case 4: withdraw(); break;
            case 5: transfer(); break;
            case 6: printf("Exiting... \n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void display_menu() {
    printf("\n--- Banking Record System Menu ---\n");
    printf("1. Create Account\n");
    printf("2. View Accounts\n");
    printf("3. Deposit\n");
    printf("4. Withdraw\n");
    printf("5. Transfer\n");
    printf("6. Exit\n");
}

void create_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached!\n");
        return;
    }

    Account new_account;
    printf("Enter account number: ");
    scanf("%d", &new_account.account_number);
    printf("Enter name: ");
    getchar(); // to consume the newline character left by previous input
    fgets(new_account.name, MAX_NAME_LENGTH, stdin);
    new_account.name[strcspn(new_account.name, "\n")] = 0; // remove newline
    new_account.balance = 0.0;

    accounts[account_count++] = new_account;
    printf("Account created successfully!\n");
}

void view_accounts() {
    printf("\n--- List of Accounts ---\n");
    for (int i = 0; i < account_count; i++) {
        printf("Account Number: %d, Name: %s, Balance: %.2f\n",
               accounts[i].account_number, accounts[i].name, accounts[i].balance);
    }
}

void deposit() {
    int account_number;
    float amount;
    printf("Enter account number to deposit: ");
    scanf("%d", &account_number);
    int index = find_account(account_number);

    if (index != -1) {
        printf("Enter deposit amount: ");
        scanf("%f", &amount);
        if (amount > 0) {
            accounts[index].balance += amount;
            printf("Deposited %.2f to account %d.\n", amount, account_number);
        } else {
            printf("Invalid deposit amount!\n");
        }
    } else {
        printf("Account not found!\n");
    }
}

void withdraw() {
    int account_number;
    float amount;
    printf("Enter account number to withdraw: ");
    scanf("%d", &account_number);
    int index = find_account(account_number);

    if (index != -1) {
        printf("Enter withdrawal amount: ");
        scanf("%f", &amount);
        if (amount > 0 && amount <= accounts[index].balance) {
            accounts[index].balance -= amount;
            printf("Withdrew %.2f from account %d.\n", amount, account_number);
        } else {
            printf("Invalid withdrawal amount!\n");
        }
    } else {
        printf("Account not found!\n");
    }
}

void transfer() {
    int from_account, to_account;
    float amount;
    printf("Enter your account number: ");
    scanf("%d", &from_account);
    int from_index = find_account(from_account);

    if (from_index != -1) {
        printf("Enter recipient account number: ");
        scanf("%d", &to_account);
        int to_index = find_account(to_account);

        if (to_index != -1) {
            printf("Enter transfer amount: ");
            scanf("%f", &amount);
            if (amount > 0 && amount <= accounts[from_index].balance) {
                accounts[from_index].balance -= amount;
                accounts[to_index].balance += amount;
                printf("Transferred %.2f from account %d to %d.\n", amount, from_account, to_account);
            } else {
                printf("Invalid transfer amount!\n");
            }
        } else {
            printf("Recipient account not found!\n");
        }
    } else {
        printf("Your account not found!\n");
    }
}

int find_account(int account_number) {
    for (int i = 0; i < account_count; i++) {
        if (accounts[i].account_number == account_number) {
            return i;
        }
    }
    return -1;
}