//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXPENSES 100

typedef struct Expense {
    char name[50];
    float amount;
    time_t timestamp;
} Expense;

Expense expenses[MAX_EXPENSES];
int current_expense = 0;

void print_welcome_message() {
    printf("\n*********************************\n");
    printf("*     Welcome to Expense Land!    *\n");
    printf("*              v1.0              *\n");
    printf("*********************************\n");
}

void add_expense(char* name, float amount) {
    expenses[current_expense].amount = amount;
    strcpy(expenses[current_expense].name, name);
    expenses[current_expense].timestamp = time(NULL);

    current_expense++;

    if (current_expense == MAX_EXPENSES) {
        printf("\nOops! You've reached the limit of %d expenses.\n", MAX_EXPENSES);
    }
}

void print_current_expenses() {
    printf("\nCurrent Expenses:\n");
    for (int i = 0; i < current_expense; i++) {
        printf("%s: $%.2f, %s\n", expenses[i].name, expenses[i].amount, ctime(&(expenses[i].timestamp)));
    }
}

void print_total_expenses() {
    float total_expenses = 0;

    printf("\nTotal Expenses:\n$");

    for (int i = 0; i < current_expense; i++) {
        total_expenses += expenses[i].amount;
    }

    printf("%.2f\n", total_expenses);
}

int main() {
    int choice;
    char name[50];
    float amount;

    print_welcome_message();

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an expense\n");
        printf("2. View current expenses\n");
        printf("3. View total expenses\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the expense: ");
                scanf("%s", name);
                printf("Enter the amount of the expense: $");
                scanf("%f", &amount);
                add_expense(name, amount);
                printf("Expense added successfully!\n");
                break;

            case 2:
                print_current_expenses();
                break;

            case 3:
                print_total_expenses();
                break;

            case 4:
                printf("Goodbye and happy expense tracking!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}