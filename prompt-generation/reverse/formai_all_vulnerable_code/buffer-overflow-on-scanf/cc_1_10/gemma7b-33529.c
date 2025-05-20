//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: realistic
#include <stdio.h>
#include <string.h>

// Define a structure to store banking records
typedef struct bank_record {
    char name[50];
    int account_number;
    double balance;
    char transaction_type;
    char transaction_date[20];
    double transaction_amount;
} bank_record;

// Function to add a new banking record
void add_record(bank_record *record) {
    printf("Enter your name: ");
    scanf("%s", record->name);

    printf("Enter your account number: ");
    scanf("%d", &record->account_number);

    printf("Enter your initial balance: ");
    scanf("%lf", &record->balance);

    printf("Enter the transaction type (deposit/withdrawal): ");
    scanf("%c", &record->transaction_type);

    printf("Enter the transaction date: ");
    scanf("%s", record->transaction_date);

    printf("Enter the transaction amount: ");
    scanf("%lf", &record->transaction_amount);
}

// Function to print a banking record
void print_record(bank_record record) {
    printf("Name: %s\n", record.name);
    printf("Account Number: %d\n", record.account_number);
    printf("Balance: %.2lf\n", record.balance);
    printf("Transaction Type: %c\n", record.transaction_type);
    printf("Transaction Date: %s\n", record.transaction_date);
    printf("Transaction Amount: %.2lf\n", record.transaction_amount);
    printf("\n");
}

// Main function
int main() {
    // Create an array of banking records
    bank_record records[100];

    // Add a new banking record
    add_record(records);

    // Print the banking record
    print_record(records[0]);

    return 0;
}