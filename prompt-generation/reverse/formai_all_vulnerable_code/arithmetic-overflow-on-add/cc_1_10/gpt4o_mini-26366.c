//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 50

typedef struct {
    char name[MAX_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_ENTRIES];
    int count;
} ExpenseTracker;

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Expense tracker is full! Cannot add more expenses.\n");
        return;
    }
    
    printf("Enter the name of the expense: ");
    scanf("%s", tracker->expenses[tracker->count].name);
    printf("Enter the amount of the expense: ");
    scanf("%f", &tracker->expenses[tracker->count].amount);
    
    tracker->count++;
    printf("Expense added successfully!\n");
}

void viewExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }
    
    printf("\nList of Expenses:\n");
    printf("--------------------------------------------------\n");
    printf("%-30s | %-10s\n", "Expense Name", "Amount");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%-30s | $%-9.2f\n", tracker->expenses[i].name, tracker->expenses[i].amount);
    }
    printf("--------------------------------------------------\n");
}

void calculateTotal(const ExpenseTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    printf("Total expenses: $%.2f\n", total);
}

void saveExpensesToFile(const ExpenseTracker *tracker) {
    FILE *file = fopen("expenses.txt", "w");
    if (file == NULL) {
        printf("Failed to open file for writing.\n");
        return;
    }
    
    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s:%.2f\n", tracker->expenses[i].name, tracker->expenses[i].amount);
    }
    
    fclose(file);
    printf("Expenses saved to 'expenses.txt' successfully!\n");
}

void loadExpensesFromFile(ExpenseTracker *tracker) {
    FILE *file = fopen("expenses.txt", "r");
    if (file == NULL) {
        printf("No saved expenses found.\n");
        return;
    }
    
    tracker->count = 0;
    while (fscanf(file, "%[^:]:%f\n", tracker->expenses[tracker->count].name, &tracker->expenses[tracker->count].amount) != EOF) {
        tracker->count++;
        if (tracker->count >= MAX_ENTRIES) {
            break;
        }
    }
    
    fclose(file);
    printf("Expenses loaded successfully! %d expenses found.\n", tracker->count);
}

void displayMenu() {
    printf("\nPersonal Finance Planner\n");
    printf("1. Add an Expense\n");
    printf("2. View Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Save Expenses to File\n");
    printf("5. Load Expenses from File\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    ExpenseTracker tracker = {{0}, 0};
    int choice;
    
    loadExpensesFromFile(&tracker);
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
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
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}