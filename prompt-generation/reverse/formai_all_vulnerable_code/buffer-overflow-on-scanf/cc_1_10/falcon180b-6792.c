//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_RECORDS 100
#define MAX_NAME_LEN 50
#define MAX_ACCOUNT_NUMBER_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char account_number[MAX_ACCOUNT_NUMBER_LEN];
    double balance;
} BankRecord;

void deposit(BankRecord* record, double amount) {
    record->balance += amount;
    printf("Deposited $%.2f into account %s\n", amount, record->account_number);
}

void withdraw(BankRecord* record, double amount) {
    if (record->balance >= amount) {
        record->balance -= amount;
        printf("Withdrew $%.2f from account %s\n", amount, record->account_number);
    } else {
        printf("Insufficient funds in account %s\n", record->account_number);
    }
}

void print_record(BankRecord* record) {
    printf("Name: %s\n", record->name);
    printf("Account Number: %s\n", record->account_number);
    printf("Balance: $%.2f\n", record->balance);
}

int main() {
    BankRecord records[MAX_RECORDS];
    int num_records = 0;

    while (num_records < MAX_RECORDS) {
        printf("Enter name (or type 'exit' to stop): ");
        scanf("%s", records[num_records].name);

        if (strcmp(records[num_records].name, "exit") == 0) {
            break;
        }

        printf("Enter account number: ");
        scanf("%s", records[num_records].account_number);

        num_records++;
    }

    printf("Enter transaction type (deposit or withdraw): ");
    char transaction_type[10];
    scanf("%s", transaction_type);

    while (strcmp(transaction_type, "exit")!= 0) {
        printf("Enter account number: ");
        scanf("%s", records[0].account_number);

        if (strcmp(transaction_type, "deposit") == 0) {
            deposit(&records[0], 100);
        } else if (strcmp(transaction_type, "withdraw") == 0) {
            withdraw(&records[0], 50);
        }

        printf("Enter transaction type (deposit or withdraw): ");
        scanf("%s", transaction_type);
    }

    return 0;
}