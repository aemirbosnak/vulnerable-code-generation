//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Record {
    char name[50];
    char account_number[10];
    float balance;
};

void add_record(struct Record* records, int* num_records) {
    printf("Enter name: ");
    scanf("%s", records[*num_records].name);
    printf("Enter account number: ");
    scanf("%s", records[*num_records].account_number);
    printf("Enter balance: ");
    scanf("%f", &records[*num_records].balance);
    *num_records += 1;
}

void print_records(struct Record* records, int num_records) {
    for (int i = 0; i < num_records; i++) {
        printf("Name: %s\n", records[i].name);
        printf("Account number: %s\n", records[i].account_number);
        printf("Balance: %f\n\n", records[i].balance);
    }
}

void deposit(struct Record* records, int num_records) {
    char account_number[10];
    float amount;
    printf("Enter account number: ");
    scanf("%s", account_number);
    printf("Enter amount: ");
    scanf("%f", &amount);
    for (int i = 0; i < num_records; i++) {
        if (strcmp(records[i].account_number, account_number) == 0) {
            records[i].balance += amount;
            printf("Deposited %f into account %s.\n", amount, account_number);
            break;
        }
    }
}

void withdraw(struct Record* records, int num_records) {
    char account_number[10];
    float amount;
    printf("Enter account number: ");
    scanf("%s", account_number);
    printf("Enter amount: ");
    scanf("%f", &amount);
    for (int i = 0; i < num_records; i++) {
        if (strcmp(records[i].account_number, account_number) == 0) {
            if (records[i].balance >= amount) {
                records[i].balance -= amount;
                printf("Withdrew %f from account %s.\n", amount, account_number);
                break;
            } else {
                printf("Insufficient funds.\n");
            }
        }
    }
}

int main() {
    struct Record records[100];
    int num_records = 0;
    int choice;
    while (1) {
        printf("1. Add record\n");
        printf("2. Print records\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Quit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_record(records, &num_records);
                break;
            case 2:
                print_records(records, num_records);
                break;
            case 3:
                deposit(records, num_records);
                break;
            case 4:
                withdraw(records, num_records);
                break;
            case 5:
                return 0;
        }
    }
    return 0;
}