//FormAI DATASET v1.0 Category: Expense Tracker ; Style: modular
#include<stdio.h>
#include<stdlib.h>

struct Expense{
    char category[20];
    double amount;
};

void addExpense(struct Expense *e){
    printf("\nEnter the category of expense: ");
    scanf("%s", e->category);
    printf("Enter the amount spent: ");
    scanf("%lf", &e->amount);
}

void displayExpense(struct Expense *e){
    printf("\nCategory: %s", e->category);
    printf("\nAmount: %.2lf\n", e->amount);
}

int main(){
    int n, option;
    double total_expense = 0;
    struct Expense *expenses;
    printf("\nEnter the number of expenses: ");
    scanf("%d", &n);
    expenses = (struct Expense*)malloc(n*sizeof(struct Expense));
    for(int i=0; i<n; i++){
        printf("\nDetails of Expense %d:", i+1);
        addExpense(&expenses[i]);
        total_expense += expenses[i].amount;
    }
    
    while(1){
        printf("\n\nMenu:\n");
        printf("1. Display all expenses\n");
        printf("2. Display total expense\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        
        switch(option){
            case 1:
                printf("\nAll Expenses:\n");
                for(int i=0; i<n; i++){
                    printf("\nExpense %d:\n", i+1);
                    displayExpense(&expenses[i]);
                }
                break;
                
            case 2:
                printf("\nTotal Expense: %.2lf\n", total_expense);
                break;
                
            case 3:
                printf("\nExiting...\n");
                exit(0);
                
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
    
    free(expenses);
    return 0;
}