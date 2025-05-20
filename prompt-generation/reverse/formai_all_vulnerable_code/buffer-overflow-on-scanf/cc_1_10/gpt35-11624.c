//FormAI DATASET v1.0 Category: Expense Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold an expense record
struct Expense {
    char date[11];    // format: "YYYY-MM-DD"
    char description[50];
    float amount;
};

// Function to add a new expense record to the database
void addExpenseRecord(struct Expense* records, int* count) {
    struct Expense newRecord;

    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", newRecord.date);

    // Validate the date input
    if (strlen(newRecord.date) != 10 || newRecord.date[4] != '-' || newRecord.date[7] != '-') {
        printf("Invalid date format. Please use the format: YYYY-MM-DD\n");
        return;
    }

    printf("Enter the description: ");
    scanf(" %[^\n]s", newRecord.description);

    printf("Enter the amount: ");
    scanf("%f", &newRecord.amount);

    records[*count] = newRecord;
    (*count)++;

    printf("Record added successfully.\n");
}

// Function to display expense records in a table format
void showExpenseRecords(struct Expense* records, int count) {
    if (count == 0) {
        printf("No records found.\n");
        return;
    }

    printf("     Date     |     Description     |     Amount     \n");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%s | %-20s | %10.2f \n", records[i].date, records[i].description, records[i].amount);
    }
}

int main() {
    struct Expense expenseRecords[100];
    int recordCount = 0;
    int choice;

    while (1) {
        printf("\nEXPENSE TRACKER\n");
        printf("1. Add a new expense record\n");
        printf("2. Show all expense records\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpenseRecord(expenseRecords, &recordCount);
                break;
            case 2:
                showExpenseRecords(expenseRecords, recordCount);
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}