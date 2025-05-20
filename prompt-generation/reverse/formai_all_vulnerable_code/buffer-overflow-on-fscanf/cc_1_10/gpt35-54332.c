//FormAI DATASET v1.0 Category: Banking Record System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for banking records
typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} record;

// Function to get new banking record from user input
record getRecord() {
    record newRecord;
    printf("\nEnter account number: ");
    scanf("%d", &newRecord.accountNumber);
    printf("Enter name: ");
    scanf("%s", newRecord.name);
    printf("Enter balance: ");
    scanf("%f", &newRecord.balance);
    return newRecord;
}

// Function to display banking record
void displayRecord(record r) {
    printf("\nAccount Number: %d", r.accountNumber);
    printf("\nName: %s", r.name);
    printf("\nBalance: %.2f", r.balance);
}

// Function to save a banking record to file
void saveToFile(record r) {
    FILE *file;
    file = fopen("bank_records.txt", "a");
    fprintf(file, "%d %s %.2f\n", r.accountNumber, r.name, r.balance);
    fclose(file);
}

// Function to load banking records from file
void loadFromFile() {
    FILE *file;
    file = fopen("bank_records.txt", "r");
    if (file == NULL) {
        printf("\nError: Failed to load banking records.");
    } else {
        printf("\nBanking Records:");
        record r;
        while (!feof(file)) {
            fscanf(file, "%d %s %f\n", &r.accountNumber, r.name, &r.balance);
            displayRecord(r);
        }
        fclose(file);
    }
}

int main() {
    int choice;
    do {
        printf("\nWelcome to the Banking Record System");
        printf("\n1. Add new record");
        printf("\n2. View all records");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                {
                    record newRecord = getRecord();
                    saveToFile(newRecord);
                    printf("\nNew record added: ");
                    displayRecord(newRecord);
                    break;
                }
            case 2:
                {
                    loadFromFile();
                    break;
                }
            case 3:
                printf("\nThank you for using the Banking Record System!");
                break;
            default:
                printf("\nError: Invalid choice. Please try again.");
                break;
        }
    } while (choice != 3);
    return 0;
}