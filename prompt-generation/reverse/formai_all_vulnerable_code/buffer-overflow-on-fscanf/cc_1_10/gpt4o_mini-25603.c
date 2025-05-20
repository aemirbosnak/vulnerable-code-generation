//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50

typedef struct {
    int accountNumber;
    char name[NAME_LENGTH];
    float balance;
} BankRecord;

void addRecord(BankRecord records[], int *count);
void displayRecords(const BankRecord records[], int count);
void deposit(BankRecord records[], int count);
void withdraw(BankRecord records[], int count);
void saveRecordsToFile(const BankRecord records[], int count);
void loadRecordsFromFile(BankRecord records[], int *count);

int main() {
    BankRecord records[MAX_RECORDS];
    int count = 0;
    int choice;

    // Load records from file
    loadRecordsFromFile(records, &count);

    while (1) {
        printf("\n=== Banking Record System ===\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Save Records\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addRecord(records, &count);
                break;
            case 2:
                displayRecords(records, count);
                break;
            case 3:
                deposit(records, count);
                break;
            case 4:
                withdraw(records, count);
                break;
            case 5:
                saveRecordsToFile(records, count);
                break;
            case 6:
                printf("Exiting program. Thank you!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addRecord(BankRecord records[], int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Maximum record limit reached!\n");
        return;
    }
    
    BankRecord newRecord;
    
    printf("Enter account number: ");
    scanf("%d", &newRecord.accountNumber);
    
    printf("Enter name: ");
    scanf(" %[^\n]", newRecord.name); // read string with spaces
    
    printf("Enter initial balance: ");
    scanf("%f", &newRecord.balance);
    
    records[*count] = newRecord;
    (*count)++;
    
    printf("Record added successfully!\n");
}

void displayRecords(const BankRecord records[], int count) {
    if (count == 0) {
        printf("No records to display!\n");
        return;
    }
    
    printf("\n=== Bank Records ===\n");
    for (int i = 0; i < count; i++) {
        printf("Account Number: %d\n", records[i].accountNumber);
        printf("Name: %s\n", records[i].name);
        printf("Balance: %.2f\n", records[i].balance);
        printf("----------------------\n");
    }
}

void deposit(BankRecord records[], int count) {
    int accountNumber;
    float amount;
    int found = 0;

    printf("Enter account number to deposit: ");
    scanf("%d", &accountNumber);
    
    for (int i = 0; i < count; i++) {
        if (records[i].accountNumber == accountNumber) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            records[i].balance += amount;
            printf("Successfully deposited %.2f. New balance: %.2f\n", amount, records[i].balance);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Account number not found!\n");
    }
}

void withdraw(BankRecord records[], int count) {
    int accountNumber;
    float amount;
    int found = 0;

    printf("Enter account number to withdraw: ");
    scanf("%d", &accountNumber);
    
    for (int i = 0; i < count; i++) {
        if (records[i].accountNumber == accountNumber) {
            printf("Current balance: %.2f\n", records[i].balance);
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount <= records[i].balance) {
                records[i].balance -= amount;
                printf("Successfully withdrawn %.2f. New balance: %.2f\n", amount, records[i].balance);
            } else {
                printf("Insufficient balance!\n");
            }
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Account number not found!\n");
    }
}

void saveRecordsToFile(const BankRecord records[], int count) {
    FILE *file = fopen("bank_records.txt", "w");
    if (file == NULL) {
        printf("Error saving records to file!\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%.2f\n", records[i].accountNumber, records[i].name, records[i].balance);
    }
    
    fclose(file);
    printf("Records saved successfully!\n");
}

void loadRecordsFromFile(BankRecord records[], int *count) {
    FILE *file = fopen("bank_records.txt", "r");
    if (file == NULL) {
        printf("No saved records found. Starting fresh.\n");
        return;
    }
    
    while (fscanf(file, "%d,%49[^,],%f\n", &records[*count].accountNumber, records[*count].name, &records[*count].balance) == 3) {
        (*count)++;
        if (*count >= MAX_RECORDS) break;
    }
    
    fclose(file);
    printf("Records loaded successfully!\n");
}