//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: energetic
#include <stdio.h>
#include <string.h>

// Define a structure to store bank record data
struct bank_record {
    char name[50];
    int account_number;
    double balance;
    char transaction_type;
    double amount;
    char date[20];
};

// Define a function to add a new bank record
void add_record(struct bank_record *record) {
    printf("Enter your name: ");
    scanf("%s", record->name);

    printf("Enter your account number: ");
    scanf("%d", &record->account_number);

    printf("Enter your current balance: ");
    scanf("%lf", &record->balance);

    printf("Enter the transaction type (deposit/withdrawal): ");
    scanf(" %c", &record->transaction_type);

    printf("Enter the amount: ");
    scanf("%lf", &record->amount);

    printf("Enter the date: ");
    scanf("%s", record->date);
}

// Define a function to display a bank record
void display_record(struct bank_record record) {
    printf("Name: %s\n", record.name);
    printf("Account Number: %d\n", record.account_number);
    printf("Balance: %.2lf\n", record.balance);
    printf("Transaction Type: %c\n", record.transaction_type);
    printf("Amount: %.2lf\n", record.amount);
    printf("Date: %s\n", record.date);
}

// Main function
int main() {
    // Create a structure to store bank records
    struct bank_record records[100];

    // Add a new bank record
    add_record(records);

    // Display the bank record
    display_record(records[0]);

    return 0;
}