//FormAI DATASET v1.0 Category: Expense Tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

// structure to hold expense data
typedef struct {
    char description[50];
    float amount;
} Expense;

// function prototype
void display_menu();
int add_expense(Expense expenses[], int count);
void view_expenses(Expense expenses[], int count);

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    int choice;

    do {
        // display main menu and get user choice
        display_menu();
        scanf("%d", &choice);
        getchar();

        // execute choice based on user input
        switch (choice) {
            case 1:
                count = add_expense(expenses, count);
                break;
            case 2:
                view_expenses(expenses, count);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}

void display_menu() {
    printf("Expense Tracker Menu\n");
    printf("--------------------\n");
    printf("1. Add an Expense\n");
    printf("2. View Expenses\n");
    printf("3. Exit Program\n");
    printf("Enter your choice: ");
}

int add_expense(Expense expenses[], int count) {
    if (count == MAX_EXPENSES) {
        printf("Maximum number of expenses reached. Cannot add more expenses.\n");
        return count;
    }

    printf("Enter expense description: ");
    fgets(expenses[count].description, 50, stdin);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[count].amount);
    getchar();

    printf("Expense successfully added.\n");
    return count + 1;
}

void view_expenses(Expense expenses[], int count) {
    if (count == 0) {
        printf("There are no expenses to display.\n");
        return;
    }

    float total = 0.0;
    printf("%-30s %-10s\n", "DESCRIPTION", "AMOUNT");
    printf("------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-30s $%-9.2f\n", expenses[i].description, expenses[i].amount);
        total += expenses[i].amount;
    }
    printf("------------------------------------------\n");
    printf("Total expenses: $%.2f\n", total);
}