//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

void main()
{
    // Declare variables
    char name[20];
    int month, day, year;
    float expense;
    char category[50];

    // Get user input
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter the month of the expense: ");
    scanf("%d", &month);

    printf("Enter the day of the expense: ");
    scanf("%d", &day);

    printf("Enter the year of the expense: ");
    scanf("%d", &year);

    printf("Enter the expense amount: ");
    scanf("%f", &expense);

    printf("Enter the expense category: ");
    scanf("%s", category);

    // Calculate total expense for the month
    float total_expense = expense;

    // Display expense summary
    printf("\n**Expense Summary for %s %d %d**", name, month, year);
    printf("\n");
    printf("Name: %s", name);
    printf("\n");
    printf("Month: %d", month);
    printf("\n");
    printf("Day: %d", day);
    printf("\n");
    printf("Year: %d", year);
    printf("\n");
    printf("Expense Category: %s", category);
    printf("\n");
    printf("Expense Amount: $%.2f", expense);
    printf("\n");
    printf("Total Expense for Month: $%.2f", total_expense);
    printf("\n");
    printf("Thank you for using the Expense Tracker, %s!", name);
    printf("\n");
}