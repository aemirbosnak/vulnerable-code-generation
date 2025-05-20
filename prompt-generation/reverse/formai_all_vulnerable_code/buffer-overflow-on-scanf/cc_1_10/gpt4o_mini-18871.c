//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define DESC_LENGTH 100

typedef struct {
    char name[NAME_LENGTH];
    float amount;
    char description[DESC_LENGTH];
    char date[11]; // Format: YYYY-MM-DD
} Transaction;

typedef struct {
    Transaction transactions[MAX_ENTRIES];
    int count;
} FinancePlanner;

void initialize_planner(FinancePlanner* planner) {
    planner->count = 0;
}

void add_transaction(FinancePlanner* planner) {
    if (planner->count >= MAX_ENTRIES) {
        printf("Transaction limit reached!\n");
        return;
    }

    Transaction t;
    printf("Enter transaction name: ");
    scanf("%s", t.name);
    printf("Enter transaction amount: ");
    scanf("%f", &t.amount);
    printf("Enter transaction description: ");
    getchar(); // to consume newline left by scanf
    fgets(t.description, DESC_LENGTH, stdin);
    t.description[strcspn(t.description, "\n")] = 0; // Remove newline
    printf("Enter transaction date (YYYY-MM-DD): ");
    scanf("%s", t.date);
    
    planner->transactions[planner->count] = t;
    planner->count++;
    printf("Transaction added successfully!\n");
}

void view_transactions(const FinancePlanner* planner) {
    if (planner->count == 0) {
        printf("No transactions to display.\n");
        return;
    }

    printf("%-20s %-10s %-30s %-12s\n", "Name", "Amount", "Description", "Date");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < planner->count; i++) {
        printf("%-20s $%-9.2f %-30s %s\n", 
               planner->transactions[i].name, 
               planner->transactions[i].amount, 
               planner->transactions[i].description, 
               planner->transactions[i].date);
    }
}

void calculate_summary(const FinancePlanner* planner) {
    float total_income = 0.0;
    float total_expense = 0.0;

    for (int i = 0; i < planner->count; i++) {
        if (planner->transactions[i].amount >= 0) {
            total_income += planner->transactions[i].amount;
        } else {
            total_expense += planner->transactions[i].amount;
        }
    }

    printf("\n--- Financial Summary ---\n");
    printf("Total Income: $%.2f\n", total_income);
    printf("Total Expense: $%.2f\n", total_expense);
    printf("Net Savings: $%.2f\n", total_income + total_expense);
}

void menu() {
    printf("\n--- Welcome to Your Personal Finance Planner ---\n");
    printf("1. Add transaction\n");
    printf("2. View transactions\n");
    printf("3. Calculate summary\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    FinancePlanner planner;
    initialize_planner(&planner);

    int choice;
    do {
        menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_transaction(&planner);
                break;
            case 2:
                view_transactions(&planner);
                break;
            case 3:
                calculate_summary(&planner);
                break;
            case 4:
                printf("Exiting the program. Take care of your finances!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}