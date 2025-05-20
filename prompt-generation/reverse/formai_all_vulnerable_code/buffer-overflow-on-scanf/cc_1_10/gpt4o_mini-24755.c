//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for storing financial records.
struct FinanceRecord {
    char description[100];
    double amount;
    char type[10]; // income or expense
};

// Function declarations
void addRecord(struct FinanceRecord *records, int *size);
void viewRecords(struct FinanceRecord *records, int size);
void calculateBalance(struct FinanceRecord *records, int size);
void displayMenu();
void clearBuffer();

int main() {
    struct FinanceRecord records[100]; // Array to hold up to 100 records
    int size = 0; // Current number of records
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addRecord(records, &size);
                break;
            case 2:
                viewRecords(records, size);
                break;
            case 3:
                calculateBalance(records, size);
                break;
            case 4:
                printf("Thank you for using the Personal Finance Planner. Goodbye!\n");
                exit(0);
            default:
                printf("Please enter a valid option.\n");
        }
    }
    return 0;
}

// Function to display the menu options.
void displayMenu() {
    printf("\n--- Personal Finance Planner ---\n");
    printf("1. Add a financial record\n");
    printf("2. View all records\n");
    printf("3. Calculate balance\n");
    printf("4. Exit\n");
    printf("Please choose an option: ");
}

// Function to add a finance record.
void addRecord(struct FinanceRecord *records, int *size) {
    if (*size >= 100) {
        printf("Record limit reached. Cannot add more records.\n");
        return;
    }

    struct FinanceRecord newRecord;
    printf("Enter a description: ");
    fgets(newRecord.description, sizeof(newRecord.description), stdin);
    newRecord.description[strcspn(newRecord.description, "\n")] = 0; // Remove newline

    printf("Enter the amount: ");
    scanf("%lf", &newRecord.amount);
    clearBuffer(); // Clear buffer after reading amount

    printf("Enter type (income/expense): ");
    fgets(newRecord.type, sizeof(newRecord.type), stdin);
    newRecord.type[strcspn(newRecord.type, "\n")] = 0; // Remove newline

    // Save the new record
    records[*size] = newRecord;
    (*size)++;
    printf("Record added successfully.\n");
}

// Function to view all finance records.
void viewRecords(struct FinanceRecord *records, int size) {
    if (size == 0) {
        printf("No records to display.\n");
        return;
    }

    printf("\n--- Financial Records ---\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s: %.2lf (%s)\n", i + 1, records[i].description, records[i].amount, records[i].type);
    }
}

// Function to calculate the balance of income and expenses.
void calculateBalance(struct FinanceRecord *records, int size) {
    double totalIncome = 0, totalExpense = 0;

    for (int i = 0; i < size; i++) {
        if (strcmp(records[i].type, "income") == 0) {
            totalIncome += records[i].amount;
        } else if (strcmp(records[i].type, "expense") == 0) {
            totalExpense += records[i].amount;
        }
    }

    double balance = totalIncome - totalExpense;
    printf("\n--- Financial Summary ---\n");
    printf("Total Income: %.2lf\n", totalIncome);
    printf("Total Expense: %.2lf\n", totalExpense);
    printf("Current Balance: %.2lf\n", balance);
}

// Function to clear the input buffer
void clearBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}