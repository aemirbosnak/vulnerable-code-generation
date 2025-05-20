//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struct for expense item
typedef struct {
    char description[50];
    float amount;
    int month;
    int year;
} Expense;

// Function prototypes
void add_expense(Expense* expenses, int* num_expenses, char* description, float amount, int month, int year);
void display_expenses(Expense* expenses, int num_expenses);
void print_header(int month, int year);

int main() {
    int num_expenses = 0;
    Expense expenses[100];

    while (true) {
        printf("Enter a description for the expense: ");
        char description[50];
        scanf("%s", description);
        if (strcmp(description, "quit") == 0) {
            break;
        }

        printf("Enter the amount of the expense: ");
        float amount;
        scanf("%f", &amount);

        printf("Enter the month of the expense: ");
        int month;
        scanf("%d", &month);

        printf("Enter the year of the expense: ");
        int year;
        scanf("%d", &year);

        add_expense(expenses, &num_expenses, description, amount, month, year);
    }

    print_header(1, 2023);
    display_expenses(expenses, num_expenses);

    free(expenses);

    return 0;
}

void add_expense(Expense* expenses, int* num_expenses, char* description, float amount, int month, int year) {
    if (*num_expenses >= 100) {
        printf("Expense tracker is full.\n");
        return;
    }

    strcpy(expenses[*num_expenses].description, description);
    expenses[*num_expenses].amount = amount;
    expenses[*num_expenses].month = month;
    expenses[*num_expenses].year = year;
    (*num_expenses)++;
}

void display_expenses(Expense* expenses, int num_expenses) {
    for (int i = 0; i < num_expenses; i++) {
        printf("%s (%d/%d) - $%.2f\n", expenses[i].description, expenses[i].month, expenses[i].year, expenses[i].amount);
    }
}

void print_header(int month, int year) {
    printf("%s, %d\n", (month < 10 ? "   " : ""), month);
    printf("------------------------\n");
    printf("%s\n", (month < 3 ? "January" :
                   (month < 6 ? "April" :
                    (month < 9 ? "July" : "October"))));
    printf("%d\n", year);
}