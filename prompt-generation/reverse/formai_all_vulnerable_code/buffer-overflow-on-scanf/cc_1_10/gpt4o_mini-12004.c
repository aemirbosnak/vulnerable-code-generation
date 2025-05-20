//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define ACCOUNT_NUMBER_LENGTH 20
#define FILE_NAME "bank_records.txt"

typedef struct {
    char name[NAME_LENGTH];
    char account_number[ACCOUNT_NUMBER_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int account_count = 0;

void load_accounts();
void save_accounts();
void create_account();
void deposit();
void withdraw();
void view_account();
void list_accounts();

int main() {
    load_accounts();
    int choice;

    while (1) {
        printf("\n----- Banking Record System -----\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. View Account\n");
        printf("5. List All Accounts\n");
        printf("6. Exit\n");
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
                view_account();
                break;
            case 5:
                list_accounts();
                break;
            case 6:
                save_accounts();
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void load_accounts() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        return; // No file found, no accounts to load
    }
    
    while (fscanf(file, "%s %s %f\n", accounts[account_count].account_number,
                   accounts[account_count].name, &accounts[account_count].balance) != EOF) {
        account_count++;
    }
    fclose(file);
}

void save_accounts() {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Error saving accounts!\n");
        return;
    }

    for (int i = 0; i < account_count; i++) {
        fprintf(file, "%s %s %.2f\n", accounts[i].account_number,
                accounts[i].name, accounts[i].balance);
    }
    fclose(file);
}

void create_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Account limit reached! Cannot create more accounts.\n");
        return;
    }

    printf("Enter account number: ");
    scanf("%s", accounts[account_count].account_number);
    printf("Enter account holder's name: ");
    scanf(" %[^\n]", accounts[account_count].name);
    accounts[account_count].balance = 0.0f;
    account_count++;

    printf("Account created successfully!\n");
}

void deposit() {
    char account_number[ACCOUNT_NUMBER_LENGTH];
    float amount;

    printf("Enter account number for deposit: ");
    scanf("%s", account_number);
    
    for (int i = 0; i < account_count; i++) {
        if (strcmp(accounts[i].account_number, account_number) == 0) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            if (amount > 0) {
                accounts[i].balance += amount;
                printf("Deposited %.2f. New balance: %.2f\n", amount, accounts[i].balance);
            } else {
                printf("Invalid amount!\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}

void withdraw() {
    char account_number[ACCOUNT_NUMBER_LENGTH];
    float amount;

    printf("Enter account number for withdrawal: ");
    scanf("%s", account_number);
    
    for (int i = 0; i < account_count; i++) {
        if (strcmp(accounts[i].account_number, account_number) == 0) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > 0 && amount <= accounts[i].balance) {
                accounts[i].balance -= amount;
                printf("Withdrew %.2f. New balance: %.2f\n", amount, accounts[i].balance);
            } else {
                printf("Invalid amount or insufficient balance!\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}

void view_account() {
    char account_number[ACCOUNT_NUMBER_LENGTH];

    printf("Enter account number to view: ");
    scanf("%s", account_number);
    
    for (int i = 0; i < account_count; i++) {
        if (strcmp(accounts[i].account_number, account_number) == 0) {
            printf("Account Number: %s\n", accounts[i].account_number);
            printf("Account Holder: %s\n", accounts[i].name);
            printf("Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void list_accounts() {
    printf("\n----- List of Accounts -----\n");
    for (int i = 0; i < account_count; i++) {
        printf("Account Number: %s, Name: %s, Balance: %.2f\n",
               accounts[i].account_number, accounts[i].name, accounts[i].balance);
    }
}