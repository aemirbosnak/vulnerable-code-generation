//FormAI DATASET v1.0 Category: Expense Tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 50

typedef struct {
    char category[20];
    float amount;
    char description[50];
} expense;

int menu() {
    int choice;
    printf("Expense Tracker\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses by Category\n");
    printf("3. View All Expenses\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int addExpense(expense* list, int count) {
    if (count == MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached\n");
        return count;
    }
    printf("Enter Expense Details:\n");
    printf("Category: ");
    scanf("%s", list[count].category);
    printf("Amount: ");
    scanf("%f", &list[count].amount);
    printf("Description: ");
    scanf("%s", list[count].description);
    return count + 1;
}

void viewExpensesByCategory(expense* list, int count) {
    char category[20];
    float total = 0.0;
    int found = 0;
    printf("Enter Category: ");
    scanf("%s", category);
    printf("Expenses for Category %s:\n", category);
    for (int i = 0; i < count; i++) {
        if (strcmp(list[i].category, category) == 0) {
            printf("%s\t$%.2f\t%s\n", list[i].category, 
                   list[i].amount, list[i].description);
            total += list[i].amount;
            found = 1;
        }
    }
    if (!found) {
        printf("No expenses found for Category %s\n", category);
    } else {
        printf("Total: $%.2f\n", total);
    }
}

void viewAllExpenses(expense* list, int count) {
    float total = 0.0;
    printf("All Expenses:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t$%.2f\t%s\n", list[i].category, 
               list[i].amount, list[i].description);
        total += list[i].amount;
    }
    printf("Total: $%.2f\n", total);
}

int main() {
    int choice, count = 0;
    expense expenses[MAX_EXPENSES];
    do {
        choice = menu();
        switch (choice) {
            case 1:
                count = addExpense(expenses, count);
                break;
            case 2:
                viewExpensesByCategory(expenses, count);
                break;
            case 3:
                viewAllExpenses(expenses, count);
                break;
            case 4:
                printf("Exiting Expense Tracker\n");
                break;
            default:
                printf("Invalid Choice\n");
        }
        printf("\n");
    } while (choice != 4);
    return 0;
}