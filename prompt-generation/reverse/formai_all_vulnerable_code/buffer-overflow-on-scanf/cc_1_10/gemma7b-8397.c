//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declare variables
    char name[20];
    int age;
    float salary;
    int month;
    float expenses[12];
    char category[20];
    int i;

    // Get user input
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your salary: ");
    scanf("%f", &salary);

    printf("Enter the month you want to track expenses for: ");
    scanf("%d", &month);

    // Calculate expenses
    for (i = 0; i < 12; i++) {
        expenses[i] = 0;
    }

    expenses[month - 1] = salary * 0.1;

    // Get category and amount of expense
    printf("Enter the category of your expense: ");
    scanf("%s", category);

    printf("Enter the amount of your expense: ");
    scanf("%f", &expenses[month - 1]);

    // Print expenses
    printf("Your expenses for %d are: ", month);
    for (i = 0; i < 12; i++) {
        if (expenses[i] > 0) {
            printf("%s: %.2f, ", category, expenses[i]);
        }
    }

    // Calculate total expenses
    float total_expenses = 0;
    for (i = 0; i < 12; i++) {
        total_expenses += expenses[i];
    }

    // Print total expenses
    printf("Total expenses: %.2f", total_expenses);

    return 0;
}