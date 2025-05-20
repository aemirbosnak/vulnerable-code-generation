//FormAI DATASET v1.0 Category: Expense Tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Expense structure
struct Expense {
    char name[50];
    int day;
    int month;
    int year;
    float amount;
};

//Function to add an expense to the expense list
void addExpense(struct Expense *expense, int *count) {
    //Increment expense count
    (*count)++;
    //Allocate memory for new expense
    expense = (struct Expense*) realloc(expense, (*count)*sizeof(struct Expense));
    //Get expense details
    printf("Enter expense name: ");
    scanf("%s", expense[(*count)-1].name);
    printf("Enter expense amount: ");
    scanf("%f", &expense[(*count)-1].amount);
    printf("Enter expense date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &expense[(*count)-1].day, &expense[(*count)-1].month, &expense[(*count)-1].year);
}

//Function to print all expenses
void printExpenses(struct Expense *expense, int count) {
    printf("--------------------\n");
    printf("Expense List\n");
    printf("--------------------\n");
    printf("Name\t\tAmount\t\tDate\n");
    for(int i=0; i<count; i++) {
        printf("%s\t\t%.2f\t\t%d/%d/%d\n", expense[i].name, expense[i].amount, expense[i].day, expense[i].month, expense[i].year);
    }
    printf("--------------------\n");
}

//Function to calculate total expenses
float calculateTotalExpenses(struct Expense *expense, int count) {
    float total = 0;
    for(int i=0; i<count; i++) {
        total += expense[i].amount;
    }
    return total;
}

//Function to print expenses within a defined date range
void printExpensesWithinRange(struct Expense *expense, int count) {
    int start_day, start_month, start_year, end_day, end_month, end_year;
    printf("Enter start date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &start_day, &start_month, &start_year);
    printf("Enter end date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &end_day, &end_month, &end_year);
    printf("--------------------\n");
    printf("Expenses between %d/%d/%d and %d/%d/%d\n", start_day, start_month, start_year, end_day, end_month, end_year);
    printf("--------------------\n");
    printf("Name\t\tAmount\t\tDate\n");
    for(int i=0; i<count; i++) {
        if(expense[i].year > start_year && expense[i].year < end_year ||
           expense[i].year == start_year && expense[i].month > start_month ||
           expense[i].year == end_year && expense[i].month < end_month ||
           expense[i].year == start_year && expense[i].month == start_month && expense[i].day >= start_day ||
           expense[i].year == end_year && expense[i].month == end_month && expense[i].day <= end_day ||
           expense[i].year == start_year && expense[i].month == start_month && expense[i].day >= start_day && expense[i].day <= end_day ||
           expense[i].year == end_year && expense[i].month == end_month && expense[i].day >= start_day && expense[i].day <= end_day) {
            printf("%s\t\t%.2f\t\t%d/%d/%d\n", expense[i].name, expense[i].amount, expense[i].day,expense[i].month, expense[i].year);
        }
    }
    printf("--------------------\n");
}

//Main function
int main() {
    //Initialize expense count
    int count = 0;
    //Initialize expense pointer
    struct Expense *expense = NULL;
    //Display menu
    while(1) {
        printf("Expense Tracker\n");
        printf("--------------------\n");
        printf("1. Add expense\n");
        printf("2. Print all expenses\n");
        printf("3. Calculate total expenses\n");
        printf("4. Print expenses within a date range\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        //Get user input
        char input[10];
        scanf("%s", input);
        //Check user input
        if(strcmp(input, "1") == 0) {
            addExpense(expense, &count);
        }
        else if(strcmp(input, "2") == 0) {
            printExpenses(expense, count);
        }
        else if(strcmp(input, "3") == 0) {
            printf("Total expenses: %.2f\n", calculateTotalExpenses(expense, count));
        }
        else if(strcmp(input, "4") == 0) {
            printExpensesWithinRange(expense, count);
        }
        else if(strcmp(input, "5") == 0) {
            free(expense);
            exit(0);
        }
        else {
            printf("Invalid option\n");
        }
    }
    return 0;
}