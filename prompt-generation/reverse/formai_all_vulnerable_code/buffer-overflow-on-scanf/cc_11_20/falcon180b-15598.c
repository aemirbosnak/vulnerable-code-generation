//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    char name[30];
    float income, expense, balance = 0, total_income = 0, total_expense = 0;
    time_t now = time(0);
    struct tm *t = localtime(&now);
    printf("Welcome to Personal Finance Planner\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hello, %s! Today is %s", name, asctime(t));
    do {
        system("clear");
        printf("\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Balance\n");
        printf("4. View Transactions\n");
        printf("5. Exit\n");
        printf("\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter Income: ");
                scanf("%f", &income);
                total_income += income;
                balance += income;
                printf("\nIncome added successfully!\n");
                break;
            case 2:
                printf("Enter Expense: ");
                scanf("%f", &expense);
                total_expense += expense;
                balance -= expense;
                printf("\nExpense added successfully!\n");
                break;
            case 3:
                printf("\nYour current balance is $%.2f\n", balance);
                break;
            case 4:
                printf("\nTransaction History:\n");
                if(total_income == 0 && total_expense == 0) {
                    printf("No transactions yet.\n");
                }
                else {
                    printf("Income:\n");
                    for(int i = 0; i < total_income; i++) {
                        printf("$%.2f\n", i);
                    }
                    printf("\nExpense:\n");
                    for(int j = 0; j < total_expense; j++) {
                        printf("$%.2f\n", j);
                    }
                }
                break;
            case 5:
                printf("\nThank you for using Personal Finance Planner!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while(choice!= 5);
    return 0;
}