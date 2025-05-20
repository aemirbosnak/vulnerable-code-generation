//FormAI DATASET v1.0 Category: Expense Tracker ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100

typedef struct
{
    int day;
    int month;
    int year;
}Date;

typedef struct
{
    char category[25];
    float amount;
    Date date; //expense date
}Expense;

int count = 0; //to keep track of total expenses

//function to get current date
void getCurrentDate(Date *date)
{
    time_t t = time(NULL);
    struct tm *current_time = localtime(&t);
    date->day = current_time->tm_mday;
    date->month = current_time->tm_mon + 1; //as month starts from 0
    date->year = current_time->tm_year + 1900; //add 1900 to get current year
}

//function to add a new expense
void addExpense(Expense *expenses)
{
    printf("\n----- Add New Expense -----\n");
    printf("Category: ");
    scanf("%s", expenses[count].category);
    printf("Amount: ");
    scanf("%f", &expenses[count].amount);
    getCurrentDate(&expenses[count].date);
    printf("\nExpense added successfully!\n");
    count++; //increase counter after adding expense
}

//function to display all expenses
void displayExpenses(Expense *expenses)
{
    printf("\n----- Display All Expenses -----\n");
    if(count == 0)
    {
        printf("No expenses found!\n");
    }
    else
    {
        printf("%-10s %-15s %-10s\n", "Date", "Category", "Amount");
        printf("---------------------------------\n");
        for(int i = 0; i < count; i++)
        {
            printf("%02d/%02d/%d  %-15s %.2f\n", expenses[i].date.day, expenses[i].date.month, expenses[i].date.year, expenses[i].category, expenses[i].amount);
        }
    }
}

//function to display expenses by category
void displayExpensesByCategory(Expense *expenses, char *category)
{
    printf("\n----- Display Expenses by Category -----\n");
    int flag = 0;
    printf("%-10s %-15s %-10s\n", "Date", "Category", "Amount");
    printf("---------------------------------\n");
    for(int i = 0; i < count; i++)
    {
        if(strcmp(expenses[i].category, category) == 0)
        {
            printf("%02d/%02d/%d  %-15s %.2f\n", expenses[i].date.day, expenses[i].date.month, expenses[i].date.year, expenses[i].category, expenses[i].amount);
            flag++;
        }
    }
    if(flag == 0)
    {
        printf("No expenses found for %s category!\n", category);
    }
}

//function to display expenses by month
void displayExpensesByMonth(Expense *expenses, int month)
{
    printf("\n----- Display Expenses by Month -----\n");
    int flag = 0;
    printf("%-10s %-15s %-10s\n", "Date", "Category", "Amount");
    printf("---------------------------------\n");
    for(int i = 0; i < count; i++)
    {
        if(expenses[i].date.month == month)
        {
            printf("%02d/%02d/%d  %-15s %.2f\n", expenses[i].date.day, expenses[i].date.month, expenses[i].date.year, expenses[i].category, expenses[i].amount);
            flag++;
        }
    }
    if(flag == 0)
    {
        printf("No expenses found for %d month!\n", month);
    }
}

int main()
{
    Expense expenses[MAX];
    int choice, month;
    char category[25];
    
    do
    {
        printf("\n----- Expense Tracker -----\n");
        printf("1. Add Expense\n");
        printf("2. Display All Expenses\n");
        printf("3. Display Expenses by Category\n");
        printf("4. Display Expenses by Month\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                addExpense(expenses);
                break;
            case 2:
                displayExpenses(expenses);
                break;
            case 3:
                printf("\nEnter category to search: ");
                scanf("%s", category);
                displayExpensesByCategory(expenses, category);
                break;
            case 4:
                printf("\nEnter month to search (1-12): ");
                scanf("%d", &month);
                displayExpensesByMonth(expenses, month);
                break;
            case 5:
                printf("\nThank you for using Expense Tracker!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }while(1);
    
    return 0;
}