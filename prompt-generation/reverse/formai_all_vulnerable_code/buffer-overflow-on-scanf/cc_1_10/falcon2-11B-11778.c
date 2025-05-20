//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Global Variables
int totalExpenses = 0;
char user[50];

// Function Prototypes
void calculateTotal();
void displayTotal();
void addExpense();
void removeExpense();
void editExpense();
void exitProgram();

int main()
{
    int choice;

    while (1)
    {
        printf("\nWelcome to the Expense Tracker!\n");
        printf("\nPlease select an option:\n");
        printf("1. Add Expense\n");
        printf("2. Remove Expense\n");
        printf("3. Edit Expense\n");
        printf("4. Display Total Expenses\n");
        printf("5. Exit Program\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addExpense();
                break;
            case 2:
                removeExpense();
                break;
            case 3:
                editExpense();
                break;
            case 4:
                calculateTotal();
                displayTotal();
                break;
            case 5:
                exitProgram();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addExpense()
{
    printf("Enter the expense name: ");
    scanf("%s", user);

    printf("Enter the expense amount: ");
    scanf("%d", &totalExpenses);

    printf("Expense added successfully!\n");
}

void removeExpense()
{
    printf("Enter the expense name: ");
    scanf("%s", user);

    printf("Are you sure you want to remove this expense? (y/n): ");
    char confirm = getchar();

    if (confirm == 'y' || confirm == 'Y')
    {
        printf("Expense removed successfully!\n");
    }
    else
    {
        printf("Expense not removed. Please try again.\n");
    }
}

void editExpense()
{
    printf("Enter the expense name: ");
    scanf("%s", user);

    printf("Enter the new expense name: ");
    scanf("%s", user);

    printf("Enter the new expense amount: ");
    scanf("%d", &totalExpenses);

    printf("Expense edited successfully!\n");
}

void calculateTotal()
{
    printf("Total Expenses: $%.2f\n", totalExpenses);
}

void displayTotal()
{
    printf("Total Expenses: $%.2f\n", totalExpenses);
}

void exitProgram()
{
    printf("Thank you for using the Expense Tracker!\n");
}