//FormAI DATASET v1.0 Category: Banking Record System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct record {
    int account_number;
    char name[50];
    float balance;
} Record;

Record accounts[MAX_ACCOUNTS];
int num_accounts = 0;

void add_account() {
    Record account;
    printf("Enter account number: ");
    scanf("%d", &account.account_number);
    printf("Enter name: ");
    scanf("%s", account.name);
    printf("Enter balance: ");
    scanf("%f", &account.balance);

    accounts[num_accounts] = account;
    num_accounts++;
}

void list_accounts() {
    printf("Account\tName\tBalance\n");
    for (int i = 0; i < num_accounts; i++) {
        Record account = accounts[i];
        printf("%d\t%s\t%.2f\n", account.account_number, account.name, account.balance);
    }
}

void deposit() {
    int account_number;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &account_number);

    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("New balance for account %d: %.2f\n", accounts[i].account_number, accounts[i].balance);
            return;
        }
    }

    printf("Account %d not found.\n", account_number);
}

void withdraw() {
    int account_number;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &account_number);

    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (accounts[i].balance < amount) {
                printf("Insufficient balance\n");
                return;
            }
            accounts[i].balance -= amount;
            printf("New balance for account %d: %.2f\n", accounts[i].account_number, accounts[i].balance);
            return;
        }
    }

    printf("Account %d not found.\n", account_number);
}

void save_records() {
    FILE* fp = fopen("records.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    for (int i = 0; i < num_accounts; i++) {
        fprintf(fp, "%d,%s,%.2f\n", accounts[i].account_number, accounts[i].name, accounts[i].balance);
    }

    fclose(fp);
}

void load_records() {
    FILE* fp = fopen("records.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    num_accounts = 0;
    char line[100];
    char* token;
    while (fgets(line, 100, fp) != NULL) {
        Record account;
        token = strtok(line, ",");
        account.account_number = atoi(token);
        token = strtok(NULL, ",");
        strcpy(account.name, token);
        token = strtok(NULL, ",");
        account.balance = atof(token);
        accounts[num_accounts] = account;
        num_accounts++;
    }

    fclose(fp);
}

int main() {
    int choice;
    while (1) {
        printf("\nBanking Record System\n");
        printf("------------------------\n");
        printf("1. Add Account\n");
        printf("2. List Accounts\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Save Records\n");
        printf("6. Load Records\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_account();
                break;
            case 2:
                list_accounts();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                save_records();
                break;
            case 6:
                load_records();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}