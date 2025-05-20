//FormAI DATASET v1.0 Category: Expense Tracker ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAX 50

struct expense {
    char expense_name[MAX];
    float amount;
    char date[MAX];
}expenses[MAX];

int count = 0;

void addExpense() {
    if(count == MAX) {
        printf("Maximum number of expenses reached!\n");
        return;
    }
    printf("Enter the name of the expense: ");
    fgets(expenses[count].expense_name, MAX, stdin);
    expenses[count].expense_name[strcspn(expenses[count].expense_name, "\n")] = 0;
    printf("Enter the amount of the expense: ");
    scanf("%f", &expenses[count].amount);
    printf("Enter the date of the expense (dd/mm/yyyy): ");
    getchar();
    fgets(expenses[count].date, MAX, stdin);
    expenses[count].date[strcspn(expenses[count].date, "\n")] = 0;
    count++;
}

void viewExpenses() {
    printf("-------------------------\n");
    printf("  Expenses for the month\n");
    printf("-------------------------\n");
    printf("Expense Name\tAmount\tDate\n");
    for(int i = 0; i < count; i++) {
        printf("%s\t%.2f\t%s\n", expenses[i].expense_name, expenses[i].amount, expenses[i].date);
    }
    printf("-------------------------\n");
}

int main() {
    char option;
    do {
        printf("\n---------Expense Tracker---------\n");
        printf("Choose an option:\n");
        printf("1. Add an expense\n");
        printf("2. View all expenses\n");
        printf("3. Exit\n");
        printf("----------------------------------\n");
        printf("Enter your choice: ");
        scanf(" %c", &option);
        option = toupper(option);
        
        switch(option) {
            case '1':
                addExpense();
                break;
            case '2':
                viewExpenses();
                break;
            case '3':
                printf("Thank you for using the Expense Tracker!\n\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while(option != '3');

    return 0;
}