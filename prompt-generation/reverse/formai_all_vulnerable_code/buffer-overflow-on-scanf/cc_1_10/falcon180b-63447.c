//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a banking record
typedef struct {
    char name[50];
    int accountNumber;
    double balance;
} BankingRecord;

// Function to create a new banking record
void createRecord(BankingRecord* record) {
    printf("Enter your name: ");
    scanf("%s", record->name);
    printf("Enter your account number: ");
    scanf("%d", &record->accountNumber);
    printf("Enter your initial balance: ");
    scanf("%lf", &record->balance);
}

// Function to display a banking record
void displayRecord(BankingRecord record) {
    printf("Name: %s\n", record.name);
    printf("Account Number: %d\n", record.accountNumber);
    printf("Balance: $%.2lf\n", record.balance);
}

// Function to deposit money into an account
void depositMoney(BankingRecord* record, double amount) {
    record->balance += amount;
    printf("Deposit successful! Your new balance is $%.2lf.\n", record->balance);
}

// Function to withdraw money from an account
void withdrawMoney(BankingRecord* record, double amount) {
    if (record->balance >= amount) {
        record->balance -= amount;
        printf("Withdrawal successful! Your new balance is $%.2lf.\n", record->balance);
    } else {
        printf("Insufficient funds. Please try again.\n");
    }
}

// Function to check the balance of an account
void checkBalance(BankingRecord record) {
    printf("Your current balance is $%.2lf.\n", record.balance);
}

int main() {
    BankingRecord myRecord;
    createRecord(&myRecord);
    displayRecord(myRecord);
    depositMoney(&myRecord, 1000);
    checkBalance(myRecord);
    withdrawMoney(&myRecord, 500);
    checkBalance(myRecord);
    return 0;
}