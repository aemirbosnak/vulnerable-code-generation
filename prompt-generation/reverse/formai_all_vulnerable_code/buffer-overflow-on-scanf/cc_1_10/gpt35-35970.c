//FormAI DATASET v1.0 Category: Banking Record System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int accountNo;
    float balance;
} Account;

void displayAccounts(Account* accounts, int count) {
    printf("\n\nAccounts:\n");
    for(int i=0; i<count; i++) {
        printf("%d. %s, Account No.: %d, Balance: $%.2f\n", i+1, accounts[i].name, accounts[i].accountNo, accounts[i].balance);
    }
}

void deposit(Account* account, float amount) {
    printf("\nDepositing $%.2f into %s's account...\n", amount, account->name);
    account->balance += amount;
    printf("New balance: $%.2f\n\n", account->balance);
}

void withdraw(Account* account, float amount) {
    if(amount > account->balance) {
        printf("\nInsufficient balance. Cannot withdraw $%.2f from %s's account...\n", amount, account->name);
    } else {
        printf("\nWithdrawing $%.2f from %s's account...\n", amount, account->name);
        account->balance -= amount;
        printf("New balance: $%.2f\n\n", account->balance);
    }
}

Account* createAccount(char* name, int accountNo, float balance) {
    Account* account = (Account*)malloc(sizeof(Account));
    strcpy(account->name, name);
    account->accountNo = accountNo;
    account->balance = balance;
    return account;
}

int main() {
    Account* accounts[10];
    int accountCount = 0;

    printf("Welcome to the Bank of the Future!\n\n");
    while(1) {
        printf("What would you like to do?\n");
        printf("1. Create Account\n");
        printf("2. View Accounts\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");

        int choice;
        scanf("%d", &choice);

        if(choice == 1) {
            char name[50];
            int accountNo;
            float balance;
            printf("\n\nCreate Account:\n");
            printf("Name: ");
            scanf("%s", name);
            printf("Account No.: ");
            scanf("%d", &accountNo);
            printf("Initial Balance: ");
            scanf("%f", &balance);
            accounts[accountCount++] = createAccount(name, accountNo, balance);
            printf("\nAccount created successfully!\n\n");
        } else if(choice == 2) {
            displayAccounts(accounts, accountCount);
        } else if(choice == 3) {
            int accountNo;
            float amount;
            printf("\n\nDeposit:\n");
            printf("Account No.: ");
            scanf("%d", &accountNo);
            printf("Amount: ");
            scanf("%f", &amount);
            for(int i=0; i<accountCount; i++) {
                if(accounts[i]->accountNo == accountNo) {
                    deposit(accounts[i], amount);
                    break;
                }
            }
        } else if(choice == 4) {
            int accountNo;
            float amount;
            printf("\n\nWithdraw:\n");
            printf("Account No.: ");
            scanf("%d", &accountNo);
            printf("Amount: ");
            scanf("%f", &amount);
            for(int i=0; i<accountCount; i++) {
                if(accounts[i]->accountNo == accountNo) {
                    withdraw(accounts[i], amount);
                    break;
                }
            }
        } else if(choice == 5) {
            printf("\n\nThank you for banking with us! Goodbye!\n\n");
            break;
        } else {
            printf("\n\nInvalid choice. Please try again.\n\n");
        }
    }

    for(int i=0; i<accountCount; i++) {
        free(accounts[i]);
    }

    return 0;
}