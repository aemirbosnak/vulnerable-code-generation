//FormAI DATASET v1.0 Category: Expense Tracker ; Style: safe
#include <stdio.h>

void printMenu();
void addExpense();
void viewExpenses();
void calculateTotalExpenses();

//Global Variables
float expenses[100] = {0.0f};
int expenseCount = 0;
float totalExpenses = 0.0f;

int main()
{
    int choice;

    do
    {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                calculateTotalExpenses();
                break;
            case 4:
                printf("Thank you for using the Expense Tracker Program.\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void printMenu()
{
    printf("Expense Tracker Program\n");
    printf("------------------------\n");
    printf("1. Add an Expense\n");
    printf("2. View Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Exit Program\n");
}

void addExpense()
{
    float amount;
    printf("Enter expense amount: ");
    scanf("%f", &amount);

    if (expenseCount >= 100)
    {
        printf("Error: Maximum expense limit reached.\n");
        return;
    }

    expenses[expenseCount] = amount;
    expenseCount++;
    printf("Expense added successfully.\n");
}

void viewExpenses()
{
    if (expenseCount == 0)
    {
        printf("No expenses found.\n");
        return;
    }

    printf("Expenses:\n");
    for (int i = 0; i < expenseCount; i++)
    {
        printf("%.2f\n", expenses[i]);
    }
}

void calculateTotalExpenses()
{
    if (expenseCount == 0)
    {
        printf("No expenses found.\n");
        return;
    }

    for (int i = 0; i < expenseCount; i++)
    {
        totalExpenses += expenses[i];
    }

    printf("Total Expenses: %.2f\n", totalExpenses);
}