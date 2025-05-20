//FormAI DATASET v1.0 Category: Banking Record System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 1000

typedef struct {
    int account_number;
    char name[50];
    float balance;
} Account;

typedef struct {
    Account accounts[MAX_RECORDS];
    int num_records;
} Bank;

void add_account(Bank *bank, Account account) {
    if (bank->num_records < MAX_RECORDS) {
        bank->accounts[bank->num_records] = account;
        bank->num_records++;
        printf("Account added successfully.\n");
    }
    else {
        printf("Maximum number of accounts reached.\n");
    }
}

void view_account(Bank *bank, int account_number) {
    for (int i = 0; i < bank->num_records; i++) {
        if (bank->accounts[i].account_number == account_number) {
            printf("Account number: %d\nName: %s\nBalance: %.2f\n", 
                    bank->accounts[i].account_number, bank->accounts[i].name, bank->accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void delete_account(Bank *bank, int account_number) {
    for (int i = 0; i < bank->num_records; i++) {
        if (bank->accounts[i].account_number == account_number) {

            for(int j = i; j < bank->num_records - 1; j++) {
                bank->accounts[j] = bank->accounts[j + 1];
            }
            bank->num_records--;
            printf("Account deleted successfully.\n");
            return;
        }
    }
    printf("Account not found.\n");
}

void print_menu(){
    printf("\nWelcome to Neon Bank\n");
    printf("--------------------\n");
    printf("1. Add account\n");
    printf("2. View account\n");
    printf("3. Delete account\n");
    printf("4. Exit\n");
}

int main() {

    srand(time(NULL));
    Bank bank = { .accounts = {}, .num_records = 0 };

    int choice;
    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    Account account;
                    account.account_number = rand() % 100000;
                    printf("Enter account name: ");
                    scanf("%s", account.name);
                    printf("Enter account balance: ");
                    scanf("%f", &account.balance);
                    add_account(&bank, account);
                    break;
                }
            case 2:
                {
                    int account_number;
                    printf("Enter account number: ");
                    scanf("%d", &account_number);
                    view_account(&bank, account_number);
                    break;
                }
            case 3:
                {
                    int account_number;
                    printf("Enter account number: ");
                    scanf("%d", &account_number);
                    delete_account(&bank, account_number);
                    break;
                }
            case 4:
                printf("Thank you for banking with us!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}