//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: surprised
// C Banking Record System Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store banking records
struct BankRecord {
    char name[50];
    char address[50];
    int account_no;
    float balance;
};

// Function to create a new banking record
void createRecord(struct BankRecord *record) {
    printf("Enter name: ");
    scanf("%s", record->name);
    printf("Enter address: ");
    scanf("%s", record->address);
    printf("Enter account number: ");
    scanf("%d", &record->account_no);
    printf("Enter initial balance: ");
    scanf("%f", &record->balance);
}

// Function to display banking record
void displayRecord(struct BankRecord *record) {
    printf("Name: %s\n", record->name);
    printf("Address: %s\n", record->address);
    printf("Account Number: %d\n", record->account_no);
    printf("Balance: %.2f\n", record->balance);
}

// Function to update banking record
void updateRecord(struct BankRecord *record) {
    printf("Enter name: ");
    scanf("%s", record->name);
    printf("Enter address: ");
    scanf("%s", record->address);
    printf("Enter account number: ");
    scanf("%d", &record->account_no);
    printf("Enter balance: ");
    scanf("%f", &record->balance);
}

// Function to delete banking record
void deleteRecord(struct BankRecord *record) {
    printf("Enter name: ");
    scanf("%s", record->name);
    printf("Enter address: ");
    scanf("%s", record->address);
    printf("Enter account number: ");
    scanf("%d", &record->account_no);
    printf("Enter balance: ");
    scanf("%f", &record->balance);
}

// Function to search banking record
void searchRecord(struct BankRecord *record) {
    printf("Enter name: ");
    scanf("%s", record->name);
    printf("Enter address: ");
    scanf("%s", record->address);
    printf("Enter account number: ");
    scanf("%d", &record->account_no);
    printf("Enter balance: ");
    scanf("%f", &record->balance);
}

// Main function
int main() {
    struct BankRecord record;

    // Create a new banking record
    createRecord(&record);

    // Display banking record
    displayRecord(&record);

    // Update banking record
    updateRecord(&record);

    // Delete banking record
    deleteRecord(&record);

    // Search banking record
    searchRecord(&record);

    return 0;
}