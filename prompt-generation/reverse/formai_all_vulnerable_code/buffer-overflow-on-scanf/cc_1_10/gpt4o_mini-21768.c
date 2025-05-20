//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int expense_count = 0;

void add_expense();
void view_expenses();
void total_expenses();
void display_menu();
void handle_choice(int choice);
void get_user_choice();

void add_expense() {
    if (expense_count >= MAX_EXPENSES) {
        printf("Expense limit reached! Can't add more expenses.\n");
        return;
    }

    Expense new_expense;

    printf("Enter the name of the expense: ");
    scanf("%s", new_expense.name);
    printf("Enter the amount of the expense: ");
    scanf("%f", &new_expense.amount);

    expenses[expense_count] = new_expense;
    expense_count++;

    printf("Expense added successfully!\n");
    get_user_choice(); // Navigate back to menu
}

void view_expenses() {
    if (expense_count == 0) {
        printf("No expenses recorded yet.\n");
    } else {
        printf("\nRecorded Expenses:\n");
        for (int i = 0; i < expense_count; i++) {
            printf("%d: %s - $%.2f\n", i + 1, expenses[i].name, expenses[i].amount);
        }
    }
    get_user_choice(); // Navigate back to menu
}

void total_expenses() {
    float total = 0;
    
    for (int i = 0; i < expense_count; i++) {
        total += expenses[i].amount;
    }
    
    printf("Total Expenses: $%.2f\n", total);
    get_user_choice(); // Navigate back to menu
}

void display_menu() {
    printf("\nPersonal Finance Planner Menu:\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Total Expenses\n");
    printf("4. Exit\n");
}

void handle_choice(int choice) {
    switch (choice) {
        case 1:
            add_expense();
            break;
        case 2:
            view_expenses();
            break;
        case 3:
            total_expenses();
            break;
        case 4:
            printf("Exiting the program. Thank you!\n");
            exit(0);
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            get_user_choice(); // Navigate back to menu
            break;
    }
}

void get_user_choice() {
    int choice;
    display_menu();
    printf("Enter your choice: ");
    scanf("%d", &choice);
    handle_choice(choice);
}

int main() {
    printf("Welcome to the Personal Finance Planner!\n");
    get_user_choice(); // Start the menu loop
    return 0;
}