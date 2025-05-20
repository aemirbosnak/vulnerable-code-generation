//FormAI DATASET v1.0 Category: Banking Record System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int accNo;
    float balance;
} account;

void addAccount(account[], int*);
void displayAll(account[], int);
void searchAccount(account[], int);
void withdrawAmount(account[], int);
void depositAmount(account[], int);
void deleteAccount(account[], int*);

int main() {
    account record[100];
    int num_records = 0;
    int choice;

    do {
        printf("\nBanking Record System\n");
        printf("1. Add an account\n");
        printf("2. Display all accounts\n");
        printf("3. Search an account\n");
        printf("4. Withdraw an amount\n");
        printf("5. Deposit an amount\n");
        printf("6. Delete an account\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                addAccount(record, &num_records);
                break;
            case 2:
                displayAll(record, num_records);
                break;
            case 3:
                searchAccount(record, num_records);
                break;
            case 4:
                withdrawAmount(record, num_records);
                break;
            case 5:
                depositAmount(record, num_records);
                break;
            case 6:
                deleteAccount(record, &num_records);
                break;
            case 7:
                printf("\nThank you for using the Banking Record System.\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a valid choice.\n");
        }
    } while (choice != 7);

    return 0;
}

void addAccount(account record[], int *num_records) {
    printf("\nEnter details for account %d:\n", (*num_records)+1);
    printf("Name: ");
    scanf("%s", record[*num_records].name);
    printf("Account number: ");
    scanf("%d", &record[*num_records].accNo);
    printf("Balance: ");
    scanf("%f", &record[*num_records].balance);
    (*num_records)++;
    printf("Account added successfully.\n");
}

void displayAll(account record[], int num_records) {
    if (num_records == 0) {
        printf("\nNo records found.\n");
        return;
    }

    printf("\nAll accounts:\n");
    for (int i = 0; i < num_records; i++) {
        printf("\nName: %s\n", record[i].name);
        printf("Account number: %d\n", record[i].accNo);
        printf("Balance: %.2f\n", record[i].balance);
    }
}

void searchAccount(account record[], int num_records) {
    if (num_records == 0) {
        printf("\nNo records found.\n");
        return;
    }

    int accNo;
    printf("\nEnter account number to search: ");
    scanf("%d", &accNo);

    for (int i = 0; i < num_records; i++) {
        if (record[i].accNo == accNo) {
            printf("\nRecord found:\n");
            printf("Name: %s\n", record[i].name);
            printf("Account number: %d\n", record[i].accNo);
            printf("Balance: %.2f\n", record[i].balance);
            return;
        }
    }

    printf("\nRecord not found.\n");
}

void withdrawAmount(account record[], int num_records) {
    if (num_records == 0) {
        printf("\nNo records found.\n");
        return;
    }

    int accNo;
    float amount;
    printf("\nEnter account number to withdraw from: ");
    scanf("%d", &accNo);

    for (int i = 0; i < num_records; i++) {
        if (record[i].accNo == accNo) {
            printf("\nEnter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > record[i].balance) {
                printf("\nInsufficient balance.\n");
                return;
            }
            record[i].balance -= amount;
            printf("\nAmount withdrawn successfully.\n");
            printf("New balance: %.2f\n", record[i].balance);
            return;
        }
    }

    printf("\nRecord not found.\n");
}

void depositAmount(account record[], int num_records) {
    if (num_records == 0) {
        printf("\nNo records found.\n");
        return;
    }

    int accNo;
    float amount;
    printf("\nEnter account number to deposit to: ");
    scanf("%d", &accNo);

    for (int i = 0; i < num_records; i++) {
        if (record[i].accNo == accNo) {
            printf("\nEnter amount to deposit: ");
            scanf("%f", &amount);
            record[i].balance += amount;
            printf("\nAmount deposited successfully.\n");
            printf("New balance: %.2f\n", record[i].balance);
            return;
        }
    }

    printf("\nRecord not found.\n");
}

void deleteAccount(account record[], int *num_records) {
    if (*num_records == 0) {
        printf("\nNo records found.\n");
        return;
    }

    int accNo;
    printf("\nEnter account number to delete: ");
    scanf("%d", &accNo);

    for (int i = 0; i < *num_records; i++) {
        if (record[i].accNo == accNo) {
            *num_records -= 1;
            for (int j = i; j < *num_records; j++) {
                record[j] = record[j+1];
            }
            printf("\nAccount deleted successfully.\n");
            return;
        }
    }

    printf("\nRecord not found.\n");
}