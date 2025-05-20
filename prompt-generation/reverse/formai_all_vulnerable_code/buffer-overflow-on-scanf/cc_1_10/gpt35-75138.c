//FormAI DATASET v1.0 Category: Expense Tracker ; Style: detailed
#include <stdio.h>
#include <string.h>

#define MAX_EXPENSES 100

struct Expense {
    float amount;
    char category[20];
    char date[11];
    char description[50];
};

struct ExpenseTracker {
    struct Expense expenses[MAX_EXPENSES];
    int num_expenses;
};

void addExpense(struct ExpenseTracker* tracker, struct Expense expense) {
    // Check if tracker is full
    if (tracker->num_expenses == MAX_EXPENSES) {
        printf("Error: Expense tracker is full\n");
        return;
    }
    
    // Add expense to tracker
    tracker->expenses[tracker->num_expenses] = expense;
    tracker->num_expenses++;
}

void viewExpenses(struct ExpenseTracker tracker) {
    printf("\n");
    printf("Expenses:\n");
    printf("---------------------------------------------------------\n");
    printf("| %-12s | %-10s | %-15s | %-18s |\n", "Date", "Amount", "Category", "Description");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < tracker.num_expenses; i++) {
        printf("| %-12s | %-10.2f | %-15s | %-18s |\n", tracker.expenses[i].date, 
               tracker.expenses[i].amount, tracker.expenses[i].category, tracker.expenses[i].description);
    }
    printf("---------------------------------------------------------\n");
}

void searchExpenses(struct ExpenseTracker tracker) {
    char query[50];
    printf("\nEnter a keyword to search for: ");
    scanf("%s", query);
    printf("\nSearch Results:\n");
    printf("---------------------------------------------------------\n");
    printf("| %-12s | %-10s | %-15s | %-18s |\n", "Date", "Amount", "Category", "Description");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < tracker.num_expenses; i++) {
        if (strstr(tracker.expenses[i].description, query) != NULL) {
            printf("| %-12s | %-10.2f | %-15s | %-18s |\n", tracker.expenses[i].date, 
                   tracker.expenses[i].amount, tracker.expenses[i].category, tracker.expenses[i].description);
        }
    }
    printf("---------------------------------------------------------\n");
}

void printMenu() {
    printf("\nExpense Tracker\n");
    printf("1. Add expense\n");
    printf("2. View all expenses\n");
    printf("3. Search expenses\n");
    printf("4. Exit\n");
}

int main() {
    struct ExpenseTracker tracker;
    tracker.num_expenses = 0;
    int choice;
    
    do {
        printMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("\nEnter expense details:\n");
                struct Expense expense;
                printf("Amount: ");
                scanf("%f", &expense.amount);
                printf("Category: ");
                scanf("%s", expense.category);
                printf("Date (DD/MM/YYYY): ");
                scanf("%s", expense.date);
                printf("Description: ");
                scanf("%s", expense.description);
                addExpense(&tracker, expense);
                printf("\nExpense added successfully!\n");
                break;
            case 2:
                viewExpenses(tracker);
                break;
            case 3:
                searchExpenses(tracker);
                break;
            case 4:
                printf("\nThanks for using Expense Tracker!");
                break;
            default:
                printf("\nInvalid choice, please try again");
                break;
        }
    } while (choice != 4);
    
    return 0;
}