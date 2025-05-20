//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[100];
    float amount;
} Expense;

Expense expenses[MAX_ENTRIES];
bool running = true;
int num_expenses = 0;

void display_menu() {
    printf("\nWelcome to Personal Finance Planner\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Total Expenses\n");
    printf("4. Exit\n");
    printf("Enter your choice:\n");
}

void add_expense() {
    char name[100];
    float amount;
    printf("Enter expense name:\n");
    scanf("%s", name);
    printf("Enter expense amount:\n");
    scanf("%f", &amount);

    strcpy(expenses[num_expenses].name, name);
    expenses[num_expenses].amount = amount;
    num_expenses++;
    printf("Expense added successfully.\n");
}

void view_expenses() {
    if (num_expenses == 0) {
        printf("No expenses to show.\n");
        return;
    }
    printf("\nList of Expenses\n");
    printf("-----------------\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s: $%.2f\n", expenses[i].name, expenses[i].amount);
    }
    printf("-----------------\n");
}

void total_expenses() {
	float total = 0;
	for (int i = 0; i < num_expenses; i++) {
		total += expenses[i].amount;
	}
	printf("Total expenses: $%.2f\n", total);
}

int main() {
    int choice;

    while (running) {
        display_menu();
        scanf("%d", &choice);

        switch(choice) {
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
                running = false;
                printf("Exiting Personal Finance Planner.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}