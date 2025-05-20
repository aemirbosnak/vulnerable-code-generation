//FormAI DATASET v1.0 Category: Expense Tracker ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// function prototype
void addExpense();
void viewExpense();
void deleteExpenses();

// global variables
int num_of_expenses = 0;
float expenses[100];

int main(){
    int choice;
    while(1){
        printf("\n -- Expense Tracker Menu --\n");
        printf("1. Add an Expense\n");
        printf("2. View Expenses\n");
        printf("3. Delete Expenses\n");
        printf("4. Exit\n");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addExpense();
                break;
            case 2:
                viewExpense();
                break;
            case 3:
                deleteExpenses();
                break;
            case 4:
                printf("\n Thank you for using Expense Tracker! \n");
                exit(0);
                break;
            default:
                printf("\n Invalid choice, please try again! \n");
        }
    }   
}

// function to add new expense
void addExpense(){
    float expense;
    printf("\n Enter expense amount: ");
    scanf("%f", &expense);
    expenses[num_of_expenses] = expense;
    num_of_expenses++;
    printf("\n Expense added successfully! \n");
}

// function to view all expenses
void viewExpense(){
    if(num_of_expenses == 0){
        printf("\n No expenses found! \n");
        return;
    }
    printf("\n --- All expenses --- \n");
    for(int i=0; i<num_of_expenses; i++){
        printf(" %d. %.2f\n", i+1, expenses[i]);
    }
}

// function to delete expenses
void deleteExpenses(){
    if(num_of_expenses == 0){
        printf("\n No expenses found! \n");
        return;
    }
    char choice[10];
    printf("\n Are you sure you want to delete all expenses? (y/n) ");
    scanf("%s", choice);
    if(strcmp(choice, "y") == 0 || strcmp(choice, "Y") == 0){
        num_of_expenses = 0;
        printf("\n All expenses have been deleted successfully! \n");
    }
    else{
        printf("\n Deletion canceled. \n");
    }
}