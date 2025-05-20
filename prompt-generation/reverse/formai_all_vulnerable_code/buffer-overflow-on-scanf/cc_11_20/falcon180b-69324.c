//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_INCOME 100

typedef struct {
    char name[50];
    float amount;
    char date[20];
} expense;

typedef struct {
    char source[50];
    float amount;
    char date[20];
} income;

int main() {
    int num_expenses = 0, num_incomes = 0;
    expense expenses[MAX_EXPENSES];
    income incomes[MAX_INCOME];

    printf("Welcome to Personal Finance Planner\n");

    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add Expense\n");
        printf("2. Add Income\n");
        printf("3. View Expenses\n");
        printf("4. View Incomes\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_expenses >= MAX_EXPENSES) {
                    printf("Maximum number of expenses reached.\n");
                    break;
                }
                printf("Enter expense name: ");
                scanf("%s", expenses[num_expenses].name);
                printf("Enter expense amount: ");
                scanf("%f", &expenses[num_expenses].amount);
                printf("Enter expense date (dd/mm/yyyy): ");
                scanf("%s", expenses[num_expenses].date);
                num_expenses++;
                break;

            case 2:
                if(num_incomes >= MAX_INCOME) {
                    printf("Maximum number of incomes reached.\n");
                    break;
                }
                printf("Enter income source: ");
                scanf("%s", incomes[num_incomes].source);
                printf("Enter income amount: ");
                scanf("%f", &incomes[num_incomes].amount);
                printf("Enter income date (dd/mm/yyyy): ");
                scanf("%s", incomes[num_incomes].date);
                num_incomes++;
                break;

            case 3:
                if(num_expenses == 0) {
                    printf("No expenses added.\n");
                } else {
                    printf("\nExpenses:\n");
                    for(int i=0; i<num_expenses; i++) {
                        printf("Name: %s\nAmount: %.2f\nDate: %s\n", expenses[i].name, expenses[i].amount, expenses[i].date);
                    }
                }
                break;

            case 4:
                if(num_incomes == 0) {
                    printf("No incomes added.\n");
                } else {
                    printf("\nIncomes:\n");
                    for(int i=0; i<num_incomes; i++) {
                        printf("Source: %s\nAmount: %.2f\nDate: %s\n", incomes[i].source, incomes[i].amount, incomes[i].date);
                    }
                }
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}