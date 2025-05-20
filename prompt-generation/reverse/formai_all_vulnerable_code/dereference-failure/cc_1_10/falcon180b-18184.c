//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define the structure of the banking record
typedef struct {
    int accountNumber;
    char name[50];
    double balance;
} BankingRecord;

// Function to create a new banking record
BankingRecord* createBankingRecord(int accountNumber, char* name, double balance) {
    BankingRecord* record = (BankingRecord*) malloc(sizeof(BankingRecord));
    record->accountNumber = accountNumber;
    strcpy(record->name, name);
    record->balance = balance;
    return record;
}

// Function to display a banking record
void displayBankingRecord(BankingRecord* record) {
    printf("Account Number: %d\n", record->accountNumber);
    printf("Name: %s\n", record->name);
    printf("Balance: $%.2f\n", record->balance);
}

// Function to deposit money into an account
void depositMoney(BankingRecord* record, double amount) {
    record->balance += amount;
}

// Function to withdraw money from an account
void withdrawMoney(BankingRecord* record, double amount) {
    if (record->balance >= amount) {
        record->balance -= amount;
    } else {
        printf("Insufficient funds.\n");
    }
}

// Main function
int main() {
    // Create a new banking record
    BankingRecord* record = createBankingRecord(12345, "John Doe", 1000.00);

    // Display the initial record
    displayBankingRecord(record);

    // Deposit some money
    depositMoney(record, 500.00);

    // Display the updated record
    displayBankingRecord(record);

    // Withdraw some money
    withdrawMoney(record, 200.00);

    // Display the updated record
    displayBankingRecord(record);

    // Free the memory used by the record
    free(record);

    return 0;
}