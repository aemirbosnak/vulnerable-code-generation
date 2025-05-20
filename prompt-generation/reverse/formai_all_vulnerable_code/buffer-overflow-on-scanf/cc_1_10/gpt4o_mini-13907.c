//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define DESC_LENGTH 100

typedef struct {
    char name[NAME_LENGTH];
    char description[DESC_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_ENTRIES];
    int totalExpenses;
} FinancePlanner;

void addExpense(FinancePlanner *planner) {
    if (planner->totalExpenses >= MAX_ENTRIES) {
        printf("Expense list is full! Cannot add more expenses.\n");
        return;
    }
    
    Expense newExpense;
    printf("Enter expense name: ");
    scanf(" %[^\n]s", newExpense.name);
    printf("Enter expense description: ");
    scanf(" %[^\n]s", newExpense.description);
    printf("Enter expense amount: ");
    scanf("%f", &newExpense.amount);

    planner->expenses[planner->totalExpenses] = newExpense;
    planner->totalExpenses++;
    printf("Expense added successfully!\n");
}

void viewExpenses(FinancePlanner *planner) {
    if (planner->totalExpenses == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    
    printf("\nList of Expenses:\n");
    for (int i = 0; i < planner->totalExpenses; i++) {
        printf("%d: %s\n", i + 1, planner->expenses[i].name);
        printf("   Description: %s\n", planner->expenses[i].description);
        printf("   Amount: %.2f\n", planner->expenses[i].amount);
    }
}

float calculateTotal(FinancePlanner *planner) {
    float total = 0.0;
    for (int i = 0; i < planner->totalExpenses; i++) {
        total += planner->expenses[i].amount;
    }
    return total;
}

void deleteExpense(FinancePlanner *planner) {
    if (planner->totalExpenses == 0) {
        printf("No expenses to delete.\n");
        return;
    }

    int index;
    printf("Enter the expense number to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > planner->totalExpenses) {
        printf("Invalid expense number.\n");
        return;
    }
    
    for (int i = index - 1; i < planner->totalExpenses - 1; i++) {
        planner->expenses[i] = planner->expenses[i + 1];
    }
    planner->totalExpenses--;
    printf("Expense deleted successfully!\n");
}

void displayMenu() {
    printf("\nPersonal Finance Planner\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. View Total Expenses\n");
    printf("4. Delete Expense\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    FinancePlanner planner;
    planner.totalExpenses = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addExpense(&planner);
                break;
            case 2:
                viewExpenses(&planner);
                break;
            case 3:
                printf("Total Expenses: %.2f\n", calculateTotal(&planner));
                break;
            case 4:
                deleteExpense(&planner);
                break;
            case 5:
                printf("Exiting the planner. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please select again.\n");
        }
    } while (choice != 5);

    return 0;
}