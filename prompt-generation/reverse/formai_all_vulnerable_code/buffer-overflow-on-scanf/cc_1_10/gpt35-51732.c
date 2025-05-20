//FormAI DATASET v1.0 Category: Expense Tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a data structure to store expense records
struct Expense {
    char category[30];
    float amount;
    int day;
    int month;
    int year;
};

// Declare a global array to store expense records
struct Expense expenses[100];
int totalExpenses = 0;

// Declare functions
void initialize();
void addExpense();
void listExpensesByCategory();
void listExpensesByMonth();
void listAllExpenses();

int main()
{
    int option;
    char buffer[50];

    // Display the menu and ask for user input
    while (1)
    {
        printf("\nExpense Tracker:\n");
        printf("1. Add an expense\n");
        printf("2. List expenses by category\n");
        printf("3. List expenses by month\n");
        printf("4. List all expenses\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        fgets(buffer, sizeof(buffer), stdin);
        option = atoi(buffer);

        // Call appropriate function based on user input
        switch (option)
        {
            case 1:
                addExpense();
                break;
            case 2:
                listExpensesByCategory();
                break;
            case 3:
                listExpensesByMonth();
                break;
            case 4:
                listAllExpenses();
                break;
            case 5:
                printf("\nGoodbye!\n\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}

void initialize()
{
    totalExpenses = 0;
}

void addExpense()
{
    char category[30], buffer[50];
    float amount;
    int day, month, year;

    // Ask for details of the new expense
    printf("\nCategory: ");
    fgets(category, sizeof(category), stdin);
    printf("Amount: ");
    fgets(buffer, sizeof(buffer), stdin);
    amount = atof(buffer);
    printf("Day: ");
    fgets(buffer, sizeof(buffer), stdin);
    day = atoi(buffer);
    printf("Month: ");
    fgets(buffer, sizeof(buffer), stdin);
    month = atoi(buffer);
    printf("Year: ");
    fgets(buffer, sizeof(buffer), stdin);
    year = atoi(buffer);

    // Add the new expense record to the array
    strcpy(expenses[totalExpenses].category, category);
    expenses[totalExpenses].amount = amount;
    expenses[totalExpenses].day = day;
    expenses[totalExpenses].month = month;
    expenses[totalExpenses].year = year;
    totalExpenses++;

    printf("\nExpense added successfully.\n");
}

void listExpensesByCategory()
{
    char category[30];
    float total = 0;

    // Ask for the category to filter by
    printf("\nEnter category to list expenses for: ");
    fgets(category, sizeof(category), stdin);

    // Loop through the array and print matching expense records
    printf("\nExpenses for category \"%s\":\n", category);
    for (int i = 0; i < totalExpenses; i++)
    {
        if (strcmp(expenses[i].category, category) == 0)
        {
            printf("- $%.2f on %02d/%02d/%d\n", expenses[i].amount,
                   expenses[i].day, expenses[i].month, expenses[i].year);
            total += expenses[i].amount;
        }
    }

    printf("Total expenses for \"%s\": $%.2f\n", category, total);
}

void listExpensesByMonth()
{
    int month;
    float total = 0;

    // Ask for the month to filter by
    printf("\nEnter month (1-12) to list expenses for: ");
    scanf("%d", &month);

    // Loop through the array and print matching expense records
    printf("\nExpenses for month %d:\n", month);
    for (int i = 0; i < totalExpenses; i++)
    {
        if (expenses[i].month == month)
        {
            printf("- $%.2f on %02d/%02d/%d (%s)\n", expenses[i].amount,
                   expenses[i].day, expenses[i].month, expenses[i].year,
                   expenses[i].category);
            total += expenses[i].amount;
        }
    }

    printf("Total expenses for month %d: $%.2f\n", month, total);
}

void listAllExpenses()
{
    float total = 0;

    // Loop through the array and print all expense records
    printf("\nAll expenses:\n");
    for (int i = 0; i < totalExpenses; i++)
    {
        printf("- $%.2f on %02d/%02d/%d (%s)\n", expenses[i].amount,
               expenses[i].day, expenses[i].month, expenses[i].year,
               expenses[i].category);
        total += expenses[i].amount;
    }

    printf("Total expenses: $%.2f\n", total);
}