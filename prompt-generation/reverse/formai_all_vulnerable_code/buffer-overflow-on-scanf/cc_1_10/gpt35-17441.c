//FormAI DATASET v1.0 Category: Expense Tracker ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int day;
    int month;
    int year;
} date;

typedef struct {
    int id;
    char name[100];
    float amount;
    date incurred_date;
} expense;

float calculate_total_expenses(expense* expenses, int n);
void print_expenses(expense* expenses, int n);

int main() {
    int n, i;
    float total_expenses;
    expense* expenses_array;

    printf("Welcome to your Personal Expense Tracker!\n");
    printf("How many expenses do you want to track? ");
    scanf("%d", &n);
    expenses_array = (expense*)malloc(n * sizeof(expense));

    for(i=0; i<n; i++) {
        printf("Enter details of expense %d:\n", i+1);
        expenses_array[i].id = i+1;
        printf("Name of Expense: ");
        scanf("%s", expenses_array[i].name);
        printf("Amount Incurred: ");
        scanf("%f", &expenses_array[i].amount);
        printf("Date (dd/mm/yyyy): ");
        scanf("%d/%d/%d", &expenses_array[i].incurred_date.day, &expenses_array[i].incurred_date.month, &expenses_array[i].incurred_date.year);
    }

    total_expenses = calculate_total_expenses(expenses_array, n);
    printf("\nHere are your expenses:\n");
    print_expenses(expenses_array, n);
    printf("You have spent a total of $%.2f\n", total_expenses);

    free(expenses_array);

    return 0;
}

float calculate_total_expenses(expense* expenses, int n) {
    int i;
    float total = 0.0;
    for(i=0; i<n; i++) {
        total += expenses[i].amount;
    }
    return total;
}

void print_expenses(expense* expenses, int n) {
    int i;
    for(i=0; i<n; i++) {
        printf("\nExpense ID: %d\n", expenses[i].id);
        printf("Name: %s\n", expenses[i].name);
        printf("Amount incurred: $%.2f\n", expenses[i].amount);
        printf("Date incurred: %02d/%02d/%d\n", expenses[i].incurred_date.day, expenses[i].incurred_date.month, expenses[i].incurred_date.year);
    }
}