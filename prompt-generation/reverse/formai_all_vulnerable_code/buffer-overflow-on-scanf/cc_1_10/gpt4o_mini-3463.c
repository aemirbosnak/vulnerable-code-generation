//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    char description[50];
    float amount;
    int is_income; // 1 for income, 0 for expense
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} FinancePlanner;

void initializePlanner(FinancePlanner *planner) {
    planner->count = 0;
}

void addRecord(FinancePlanner *planner, const char *description, float amount, int is_income) {
    if (planner->count < MAX_RECORDS) {
        strncpy(planner->records[planner->count].description, description, sizeof(planner->records[planner->count].description));
        planner->records[planner->count].amount = amount;
        planner->records[planner->count].is_income = is_income;
        planner->count++;
    } else {
        printf("Error: Maximum record limit reached.\n");
    }
}

void viewRecords(const FinancePlanner *planner) {
    printf("\nFinancial Records:\n");
    printf("%-20s %-10s %-10s\n", "Description", "Amount", "Type");
    printf("-----------------------------------------\n");
    for (int i = 0; i < planner->count; i++) {
        printf("%-20s %-10.2f %-10s\n", planner->records[i].description, 
               planner->records[i].amount, 
               planner->records[i].is_income ? "Income" : "Expense");
    }
}

float calculateTotalIncome(const FinancePlanner *planner) {
    float total = 0.0;
    for (int i = 0; i < planner->count; i++) {
        if (planner->records[i].is_income) {
            total += planner->records[i].amount;
        }
    }
    return total;
}

float calculateTotalExpense(const FinancePlanner *planner) {
    float total = 0.0;
    for (int i = 0; i < planner->count; i++) {
        if (!planner->records[i].is_income) {
            total += planner->records[i].amount;
        }
    }
    return total;
}

void viewSummary(const FinancePlanner *planner) {
    float total_income = calculateTotalIncome(planner);
    float total_expense = calculateTotalExpense(planner);
    float balance = total_income - total_expense;
    
    printf("\nFinancial Summary:\n");
    printf("Total Income:   %.2f\n", total_income);
    printf("Total Expense:  %.2f\n", total_expense);
    printf("Balance:        %.2f\n", balance);
}

void menu() {
    printf("\nPersonal Finance Planner\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. View Records\n");
    printf("4. View Summary\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    FinancePlanner planner;
    initializePlanner(&planner);
    
    int choice;
    char description[50];
    float amount;

    while (1) {
        menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter income description: ");
                scanf("%s", description);
                printf("Enter income amount: ");
                scanf("%f", &amount);
                addRecord(&planner, description, amount, 1);
                break;
            case 2:
                printf("Enter expense description: ");
                scanf("%s", description);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                addRecord(&planner, description, amount, 0);
                break;
            case 3:
                viewRecords(&planner);
                break;
            case 4:
                viewSummary(&planner);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}