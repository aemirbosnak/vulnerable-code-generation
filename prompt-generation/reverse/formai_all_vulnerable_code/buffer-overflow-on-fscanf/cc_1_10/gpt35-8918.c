//FormAI DATASET v1.0 Category: Banking Record System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

struct account {
    int account_number;
    char name[50];
    float balance;
};

struct bank {
    int num_accounts;
    struct account accounts[MAX_ACCOUNTS];
};

void add_account(struct bank *b) {
    if (b->num_accounts == MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached.");
        return;
    }
    struct account a;
    printf("Enter account number, name, and balance: ");
    scanf("%d %s %f", &a.account_number, a.name, &a.balance);
    b->accounts[b->num_accounts] = a;
    b->num_accounts++;
    printf("Account added.");
    return;
}

void list_accounts(struct bank b) {
    for (int i = 0; i < b.num_accounts; i++) {
        printf("Account number: %d, Name: %s, Balance: %.2f\n", b.accounts[i].account_number, b.accounts[i].name, b.accounts[i].balance);
    }
}

void deposit(struct bank *b) {
    int account_number;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for (int i = 0; i < b->num_accounts; i++) {
        if (b->accounts[i].account_number == account_number) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            b->accounts[i].balance += amount;
            printf("Deposit successful. New balance: %.2f\n", b->accounts[i].balance);
            return;
        }
    }
    printf("Account not found.");
    return;
}

void withdraw(struct bank *b) {
    int account_number;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &account_number);
    for (int i = 0; i < b->num_accounts; i++) {
        if (b->accounts[i].account_number == account_number) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (b->accounts[i].balance >= amount) {
                b->accounts[i].balance -= amount;
                printf("Withdrawal successful. New balance: %.2f\n", b->accounts[i].balance);
            } else {
                printf("Insufficient funds.");
            }
            return;
        }
    }
    printf("Account not found.");
    return;
}

void save_accounts(struct bank b) {
    FILE *file = fopen("accounts.txt", "w");
    fprintf(file, "%d\n", b.num_accounts);
    for (int i = 0; i < b.num_accounts; i++) {
        fprintf(file, "%d %s %.2f\n", b.accounts[i].account_number, b.accounts[i].name, b.accounts[i].balance);
    }
    fclose(file);
    printf("Accounts saved to file.");
    return;
}

void load_accounts(struct bank *b) {
    FILE *file = fopen("accounts.txt", "r");
    if (file == NULL) {
        printf("No file found.");
        return;
    }
    int num_accounts;
    fscanf(file, "%d", &num_accounts);
    b->num_accounts = num_accounts;
    for (int i = 0; i < num_accounts; i++) {
        struct account a;
        fscanf(file, "%d %s %f", &a.account_number, a.name, &a.balance);
        b->accounts[i] = a;
    }
    fclose(file);
    printf("Accounts loaded from file.");
    return;
}

int main() {
    struct bank b;
    b.num_accounts = 0;
    int option;
    do {
        printf("\n");
        printf("1. Add account\n");
        printf("2. List accounts\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Save accounts to file\n");
        printf("6. Load accounts from file\n");
        printf("0. Exit\n");
        printf("Enter an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_account(&b);
                break;
            case 2:
                list_accounts(b);
                break;
            case 3:
                deposit(&b);
                break;
            case 4:
                withdraw(&b);
                break;
            case 5:
                save_accounts(b);
                break;
            case 6:
                load_accounts(&b);
                break;
            case 0:
                printf("Goodbye!");
                break;
            default:
                printf("Invalid option. Please try again.");
        }
    } while (option != 0);

    return 0;
}