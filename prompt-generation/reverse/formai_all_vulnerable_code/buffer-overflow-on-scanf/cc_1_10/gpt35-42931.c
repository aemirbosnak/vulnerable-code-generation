//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Dennis Ritchie
#include<stdio.h> //header file for standard input output operations
#include<string.h> //header file for string functions

struct Expense //creating a structure for expense tracker
{
    char date[20];
    char category[30];
    float amount;
};

void display_menu() //function to display menu options to user
{
    printf("\n\n1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Exit\n");
}

void add_expense(struct Expense expenses[], int *n) //function to add expenses to the tracker
{
    struct Expense expense;
    printf("\nEnter the date of expense (DD/MM/YYYY format): ");
    scanf("%s", expense.date);
    printf("\nEnter the category of expense: ");
    scanf("%s", expense.category);
    printf("\nEnter the amount of expense: ");
    scanf("%f", &expense.amount);
    expenses[*n] = expense; //adding the expense to the expenses array
    (*n)++; //increasing the size of the expenses array
    printf("\nExpense added successfully!\n");
}

void view_expenses(struct Expense expenses[], int n) //function to view all the expenses in the tracker
{
    printf("\n-----------------------------------\n");
    printf("Date\t\tCategory\t\tAmount\n");
    printf("-----------------------------------\n");
    for(int i=0; i<n; i++)
    {
        printf("%s\t\t%s\t\t%.2f\n", expenses[i].date, expenses[i].category, expenses[i].amount);
    }
    printf("-----------------------------------\n");
}

int main()
{
    struct Expense expenses[100]; //array to store expenses
    int n = 0; //variable to keep track of number of expenses
    int choice;
    
    do
    {
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                add_expense(expenses, &n);
                break;
            case 2:
                view_expenses(expenses, n);
                break;
            case 3:
                printf("\nExiting Expense Tracker...\n");
                break;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    } while(choice!=3);
    
    return 0;
}