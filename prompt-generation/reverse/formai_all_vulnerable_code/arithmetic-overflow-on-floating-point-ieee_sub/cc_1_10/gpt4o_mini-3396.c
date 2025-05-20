//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float income;
    float expenses;
    float savings;
} PersonalFinance;

void displayMenu() {
    printf("\n----- Personal Finance Planner -----\n");
    printf("1. Add a new financial record\n");
    printf("2. View all financial records\n");
    printf("3. Calculate and view budget summary\n");
    printf("4. Exit\n");
    printf("-------------------------------------\n");
}

void addFinancialRecord(PersonalFinance *record) {
    printf("Enter Name: ");
    scanf("%s", record->name);
    printf("Enter Income: ");
    scanf("%f", &record->income);
    printf("Enter Expenses: ");
    scanf("%f", &record->expenses);
    record->savings = record->income - record->expenses;
}

void viewFinancialRecords(PersonalFinance *records, int count) {
    printf("\n----- Financial Records -----\n");
    for (int i = 0; i < count; i++) {
        printf("Record %d: Name: %s, Income: %.2f, Expenses: %.2f, Savings: %.2f\n", 
                i + 1, records[i].name, records[i].income, records[i].expenses, records[i].savings);
    }
    printf("------------------------------\n");
}

void calculateBudgetSummary(PersonalFinance *records, int count) {
    float totalIncome = 0, totalExpenses = 0, totalSavings = 0;
    for (int i = 0; i < count; i++) {
        totalIncome += records[i].income;
        totalExpenses += records[i].expenses;
        totalSavings += records[i].savings;
    }
    printf("\n----- Budget Summary -----\n");
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expenses: %.2f\n", totalExpenses);
    printf("Total Savings: %.2f\n", totalSavings);
    printf("---------------------------\n");
}

int main() {
    int option, recordCount = 0;
    PersonalFinance records[100]; // Limiting to 100 records for simplicity

    while (1) {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (recordCount < 100) {
                    addFinancialRecord(&records[recordCount]);
                    recordCount++;
                } else {
                    printf("Maximum record limit reached!\n");
                }
                break;

            case 2:
                if (recordCount > 0) {
                    viewFinancialRecords(records, recordCount);
                } else {
                    printf("No records available!\n");
                }
                break;

            case 3:
                if (recordCount > 0) {
                    calculateBudgetSummary(records, recordCount);
                } else {
                    printf("No records available!\n");
                }
                break;

            case 4:
                printf("Exiting the program...\n");
                exit(0);
                break;

            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    
    return 0;
}