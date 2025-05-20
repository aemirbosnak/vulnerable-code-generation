//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define MAX_EXPENSES 100
#define LINE_LENGTH 100

typedef struct Expense {
    char category[30];
    float amount;
    time_t timestamp;
} Expense;

void print_header() {
    printf("%-30s %-10s %-20s\n", "Expense Category", "Amount", "Date and Time");
}

void print_expense(Expense expense) {
    char date_time[20];
    strftime(date_time, sizeof(date_time), "%Y-%m-%d %H:%M:%S", localtime(&(expense.timestamp)));
    printf("%-30s %-10.2f %-20s\n", expense.category, expense.amount, date_time);
}

void add_expense(Expense expenses[MAX_EXPENSES], int *num_expenses, char *category, float amount) {
    if (*num_expenses >= MAX_EXPENSES) {
        printf("Expense Tracker is full!\n");
        return;
    }
    strcpy(expenses[*num_expenses].category, category);
    expenses[*num_expenses].amount = amount;
    expenses[*num_expenses].timestamp = time(NULL);
    (*num_expenses)++;
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int num_expenses = 0;
    char input[LINE_LENGTH];
    char category[30];
    float amount;

    print_header();

    while (true) {
        printf("\nEnter expense category (or 'quit' to exit): ");
        fgets(input, LINE_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "quit") == 0) {
            break;
        }

        strcpy(category, input);

        printf("Enter expense amount: ");
        scanf("%f", &amount);

        add_expense(expenses, &num_expenses, category, amount);

        printf("Expense added successfully! Showing updated list:\n");
        for (int i = 0; i < num_expenses; i++) {
            print_expense(expenses[i]);
        }
    }

    printf("\nExpense Tracker: Happy and Successful!\n");

    return 0;
}