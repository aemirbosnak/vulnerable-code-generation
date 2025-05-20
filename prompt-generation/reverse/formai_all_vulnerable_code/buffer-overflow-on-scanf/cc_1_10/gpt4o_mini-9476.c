//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXP 100
#define MAX_DESC 50

typedef struct {
    char description[MAX_DESC];
    float amount;
} Expense;

Expense expenses[MAX_EXP];
int exp_count = 0;

void add_expense() {
    if (exp_count < MAX_EXP) {
        printf("\nEnter expense description: ");
        scanf(" %[^\n]", expenses[exp_count].description);
        printf("Enter expense amount: ");
        scanf("%f", &expenses[exp_count].amount);
        exp_count++;
        printf("Expense added!\n");
    } else {
        printf("Maximum expense limit reached!\n");
    }
}

void view_expenses() {
    if (exp_count == 0) {
        printf("\nNo expenses recorded yet.\n");
        return;
    }
    printf("\nExpense List:\n");
    for (int i = 0; i < exp_count; i++) {
        printf("Description: %s, Amount: %.2f\n", expenses[i].description, expenses[i].amount);
    }
}

void total_expense() {
    float total = 0.0;
    for (int i = 0; i < exp_count; i++) {
        total += expenses[i].amount;
    }
    printf("\nTotal expenses: %.2f\n", total);
}

void delete_expense() {
    if (exp_count == 0) {
        printf("\nNo expenses to delete!\n");
        return;
    }
    int index;
    printf("\nEnter index of expense to delete (0-%d): ", exp_count - 1);
    scanf("%d", &index);
    if (index < 0 || index >= exp_count) {
        printf("Invalid index!\n");
    } else {
        for (int i = index; i < exp_count - 1; i++) {
            expenses[i] = expenses[i + 1];
        }
        exp_count--;
        printf("Expense deleted!\n");
    }
}

void menu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Total Expense\n");
    printf("4. Delete Expense\n");
    printf("5. Exit\n");
    printf("----------------------------\n");
    printf("Select an option: ");
}

int main() {
    int choice;
    while (1) {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                total_expense();
                break;
            case 4:
                delete_expense();
                break;
            case 5:
                printf("Exiting the Expense Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}