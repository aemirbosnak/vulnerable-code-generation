//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    float amount;
    char type[10]; // income or expense
} Record;

void addRecord(Record records[], int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Maximum record limit reached!\n");
        return;
    }

    printf("Enter name of the record: ");
    scanf("%s", records[*count].name);
    printf("Enter amount: ");
    scanf("%f", &records[*count].amount);
    printf("Enter type (income/expense): ");
    scanf("%s", records[*count].type);
    (*count)++;
    printf("Record added successfully!\n");
}

void viewRecords(Record records[], int count) {
    if (count == 0) {
        printf("No records to display.\n");
        return;
    }
    printf("\n--- Financial Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("Record %d: Name = %s, Amount = %.2f, Type = %s\n", 
               i + 1, records[i].name, records[i].amount, records[i].type);
    }
}

float calculateTotal(Record records[], int count, const char* type) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        if (strcmp(records[i].type, type) == 0) {
            total += records[i].amount;
        }
    }
    return total;
}

void getReport(Record records[], int count) {
    float totalIncome = calculateTotal(records, count, "income");
    float totalExpense = calculateTotal(records, count, "expense");
    
    printf("\n--- Financial Summary ---\n");
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expense: %.2f\n", totalExpense);
    printf("Net Savings: %.2f\n", totalIncome - totalExpense);
}

void displayMenu() {
    printf("\n--- Personal Finance Planner ---\n");
    printf("1. Add Record\n");
    printf("2. View Records\n");
    printf("3. Generate Report\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    Record records[MAX_RECORDS];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(records, &count);
                break;
            case 2:
                viewRecords(records, count);
                break;
            case 3:
                getReport(records, count);
                break;
            case 4:
                printf("Exiting the Personal Finance Planner...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}