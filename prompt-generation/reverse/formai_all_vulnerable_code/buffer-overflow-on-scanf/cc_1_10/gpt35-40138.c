//FormAI DATASET v1.0 Category: Banking Record System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Account {
    int acc_number;
    char name[50];
    double balance;
} Account;

void open_account();
void deposit();
void withdraw();
void display();

int main() {
    int choice;
    while (1) {
        printf("Welcome to the C Banking Record System!\n");
        printf("\n");
        printf("1. Open an Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                open_account();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Thank you for using the C Banking Record System!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

void open_account() {
    Account acc;

    printf("Enter account number: ");
    scanf("%d", &acc.acc_number);

    printf("Enter name: ");
    scanf("%s", acc.name);

    printf("Enter initial balance: ");
    scanf("%lf", &acc.balance);

    FILE *fp;
    fp = fopen("accounts.bin", "ab");
    if (fp == NULL) {
        printf("Unable to open database!\n");
        exit(1);
    }

    fwrite(&acc, sizeof(Account), 1, fp);

    fclose(fp);

    printf("Account opened successfully!\n");
}

void deposit() {
    int acc_number;
    double amount;
    int found = 0;

    printf("Enter account number: ");
    scanf("%d", &acc_number);

    Account acc;
    FILE *fp;
    fp = fopen("accounts.bin", "rb+");
    if (fp == NULL) {
        printf("Unable to open database!\n");
        exit(1);
    }

    while (fread(&acc, sizeof(Account), 1, fp)) {
        if (acc.acc_number == acc_number) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter deposit amount: ");
    scanf("%lf", &amount);

    acc.balance += amount;

    fseek(fp, -sizeof(Account), SEEK_CUR);

    fwrite(&acc, sizeof(Account), 1, fp);

    fclose(fp);

    printf("Deposit successful!\n");
}

void withdraw() {
    int acc_number;
    double amount;
    int found = 0;

    printf("Enter account number: ");
    scanf("%d", &acc_number);

    Account acc;
    FILE *fp;
    fp = fopen("accounts.bin", "rb+");
    if (fp == NULL) {
        printf("Unable to open database!\n");
        exit(1);
    }

    while (fread(&acc, sizeof(Account), 1, fp)) {
        if (acc.acc_number == acc_number) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter withdrawal amount: ");
    scanf("%lf", &amount);

    if (amount > acc.balance) {
        printf("Insufficient balance!\n");
        return;
    }

    acc.balance -= amount;

    fseek(fp, -sizeof(Account), SEEK_CUR);

    fwrite(&acc, sizeof(Account), 1, fp);

    fclose(fp);

    printf("Withdrawal successful!\n");
}

void display() {
    Account acc;
    FILE *fp;
    fp = fopen("accounts.bin", "rb");
    if (fp == NULL) {
        printf("Unable to open database!\n");
        exit(1);
    }

    printf("Account Number\tName\t\tBalance\n");
    printf("----------------------------------------------------------\n");

    while (fread(&acc, sizeof(Account), 1, fp)) {
        printf("%d\t\t%s\t\t%.2lf\n", acc.acc_number, acc.name, acc.balance);
    }

    fclose(fp);
}