//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    double amount;
    char date[11]; // Format: YYYY-MM-DD
} Expense;

typedef struct {
    Expense expenses[MAX_ENTRIES];
    int count;
} ExpenseTracker;

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Expense limit reached. Cannot add more expenses.\n");
        return;
    }
    
    Expense newExpense;
    printf("Enter Expense Name: ");
    scanf("%s", newExpense.name);
    printf("Enter Expense Category: ");
    scanf("%s", newExpense.category);
    printf("Enter Expense Amount: ");
    scanf("%lf", &newExpense.amount);
    printf("Enter Expense Date (YYYY-MM-DD): ");
    scanf("%s", newExpense.date);

    tracker->expenses[tracker->count++] = newExpense;
    printf("Expense added successfully!\n");
}

void viewExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    
    printf("\n----- Expense Report -----\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Name: %s, Category: %s, Amount: %.2f, Date: %s\n", 
               tracker->expenses[i].name, 
               tracker->expenses[i].category, 
               tracker->expenses[i].amount, 
               tracker->expenses[i].date);
    }
    printf("--------------------------\n");
}

void calculateTotal(const ExpenseTracker *tracker) {
    double total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    
    printf("Total Expenses: %.2f\n", total);
}

void saveExpensesToFile(const ExpenseTracker *tracker) {
    FILE *file = fopen("expenses.txt", "w");
    if (!file) {
        printf("Could not open file to save expenses.\n");
        return;
    }
    
    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s,%s,%.2f,%s\n", 
                tracker->expenses[i].name, 
                tracker->expenses[i].category, 
                tracker->expenses[i].amount, 
                tracker->expenses[i].date);
    }
    fclose(file);
    printf("Expenses saved to 'expenses.txt'\n");
}

void loadExpensesFromFile(ExpenseTracker *tracker) {
    FILE *file = fopen("expenses.txt", "r");
    if (!file) {
        printf("No previous expenses found.\n");
        return;
    }
    
    while (!feof(file) && tracker->count < MAX_ENTRIES) {
        Expense newExpense;
        fscanf(file, "%[^,],%[^,],%lf,%s\n", 
               newExpense.name, 
               newExpense.category, 
               &newExpense.amount, 
               newExpense.date);
        tracker->expenses[tracker->count++] = newExpense;
    }
    fclose(file);
    printf("Previous expenses loaded successfully!\n");
}

void displayMenu() {
    printf("\n----- Personal Finance Planner -----\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Save Expenses to File\n");
    printf("5. Load Expenses from File\n");
    printf("0. Exit\n");
    printf("-------------------------------------\n");
}

int main() {
    ExpenseTracker tracker = { .count = 0 };
    int choice;

    loadExpensesFromFile(&tracker);

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                viewExpenses(&tracker);
                break;
            case 3:
                calculateTotal(&tracker);
                break;
            case 4:
                saveExpensesToFile(&tracker);
                break;
            case 5:
                loadExpensesFromFile(&tracker);
                break;
            case 0:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}