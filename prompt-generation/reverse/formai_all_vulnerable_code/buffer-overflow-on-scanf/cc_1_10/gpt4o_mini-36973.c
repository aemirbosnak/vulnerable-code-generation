//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_LENGTH 50

typedef struct {
    char description[DESCRIPTION_LENGTH];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int expense_count = 0;

void display_menu() {
    printf("\n--- Expense Tracker ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Exit\n");
    printf("-----------------------\n");
    printf("Choose an option: ");
}

void add_expense() {
    if (expense_count >= MAX_EXPENSES) {
        printf("Expense limit reached, cannot add more expenses.\n");
        return;
    }
    Expense new_expense;
    printf("Enter description: ");
    getchar(); // to consume newline left by previous input
    fgets(new_expense.description, DESCRIPTION_LENGTH, stdin);
    new_expense.description[strcspn(new_expense.description, "\n")] = 0; // remove newline
    printf("Enter amount: ");
    scanf("%f", &new_expense.amount);
    expenses[expense_count] = new_expense;
    expense_count++;
    printf("Expense added!\n");
}

void view_expenses() {
    printf("\n--- List of Expenses ---\n");
    if (expense_count == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    for (int i = 0; i < expense_count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
    }
    printf("-----------------------\n");
}

void delete_expense() {
    int index;
    view_expenses();
    if (expense_count == 0) {
        return;
    }
    printf("Enter the number of the expense you want to delete: ");
    scanf("%d", &index);
    if (index < 1 || index > expense_count) {
        printf("Invalid selection.\n");
        return;
    }
    for (int i = index - 1; i < expense_count - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    expense_count--;
    printf("Expense deleted!\n");
}

int main() {
    int choice;
    
    while (1) {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                delete_expense();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}