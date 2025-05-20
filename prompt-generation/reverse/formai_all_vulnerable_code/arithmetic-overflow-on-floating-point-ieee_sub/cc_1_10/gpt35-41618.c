//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int i;
    float total_budget, expense, total_expense=0.0, remaining_budget;
    char choice;
    time_t t;
    srand((unsigned) time(&t));
    printf("\n\n\t\t*-*-*-*-*-*-Welcome to the Personal Finance Planner -*-*-*-*-*-*");
    printf("\n\n\nEnter your total budget for the month: ");
    scanf("%f",&total_budget);
    remaining_budget=total_budget;

    do{
        printf("\n\n1. Add Expense");
        printf("\n2. Show Expenses");
        printf("\n3. Show remaining budget");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf(" %c",&choice);

        switch(choice){
            case '1':
                printf("\n\nEnter the expense: ");
                scanf("%f",&expense);
                total_expense+=expense;
                remaining_budget=total_budget-total_expense;
                printf("\nExpense added successfully!");
                break;

            case '2':
                printf("\n\nList of Expenses:\n");
                for(i=1;i<=10;i++){
                    int r=rand()%1000+1;
                    printf("%d. Expense %d: %.2f\n",i,r,expense);
                }
                printf("\nTotal Expenses: $ %.2f",total_expense);
                break;

            case '3':
                printf("\n\nRemaining Budget: $ %.2f",remaining_budget);
                break;

            case '4':
                printf("\n\nThank you for using Personal Finance Planner!\n");
                break;

            default:
                printf("\n\nInvalid choice. Please select a valid option.");
        }

    }while(choice!='4');

    return 0;
}