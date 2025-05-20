//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: modular
//Personal Finance Planner
#include <stdio.h>

float sum(float arr[], int n){
    float s = 0;
    for(int i = 0; i < n; i++){
        s = s + arr[i];
    }
    return s;
}

void main_menu(){
    printf("\n\nWelcome to the Personal Finance Planner\n\n");
    printf("1. Enter Income\n");
    printf("2. Enter Expenses\n");
    printf("3. Show Balance Sheet\n");
    printf("4. Exit\n\n");
    printf("Enter your Choice: ");
}

void enter_income(float *balance){
    float income;
    printf("\nEnter Income: ");
    scanf("%f", &income);
    *balance = *balance + income;
}

void enter_expenses(float *balance){
    float expenses;
    printf("\nEnter Expenses: ");
    scanf("%f", &expenses);
    *balance = *balance - expenses;
}

void show_balance(float *balance, float income[], float expenses[], int n){
    printf("\n\n---Balancesheet---\n\n");
    printf("Income: \n");
    for(int i = 0; i< n; i++){
        printf("Income[%d]: %.2f\n", i+1, income[i]);
    }
    printf("\nExpenses: \n");
    for(int i = 0; i< n; i++){
        printf("Expense[%d]: %.2f\n", i+1, expenses[i]);
    }
    printf("\nTotal Income: %.2f\n", sum(income, n));
    printf("Total Expenses: %.2f\n", sum(expenses, n));
    printf("Balance: %.2f\n", *balance);
}

int main(){
    float balance = 0;
    int n = 3;
    float income[n], expenses[n];
    for(int i = 0; i < n; i++){
        income[i] = 0;
        expenses[i] = 0;
    } 
    int choice;
    do{
        main_menu();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                enter_income(&balance);
                break;
            case 2:
                enter_expenses(&balance);
                break;
            case 3:
                show_balance(&balance, income, expenses, n);
                break;
            case 4:
                printf("\n\nThank you for using Personal Finance Planner\n\n");
                break;
            default:
                printf("\n\nInvalid Choice! Please try again.\n\n");
        }
    }while(choice != 4);
    
    return 0;
}