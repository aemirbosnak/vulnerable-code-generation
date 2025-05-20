//FormAI DATASET v1.0 Category: Expense Tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to add Income to the Expense Tracker
void addIncome(float *balance){
    float income;
    printf("\nEnter the income amount: ");
    scanf("%f", &income);
    *balance += income;
    printf("\n%.2f added to balance successfully!\n",income);
}

//Function to add Expense to the Expense Tracker
void addExpense(float *balance){
    float expense;
    printf("\nEnter the expense amount: ");
    scanf("%f", &expense);
    *balance -= expense;
    printf("\n%.2f subtracted from balance successfully!\n",expense);
}

//Function to display the current balance in the Expense Tracker
void displayBalance(float balance){
    printf("\nCurrent Balance: Rs. %.2f\n",balance);
}

int main(){

    float balance = 0.0;
    int choice;

    printf("\nWelcome to Expense Tracker!\n\n");

    while(1){

        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Display Balance\n");
        printf("4. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                addIncome(&balance);
                break;
            case 2:
                addExpense(&balance);
                break;
            case 3:
                displayBalance(balance);
                break;
            case 4:
                printf("\nExiting Expense Tracker...\n");
                exit(0);
            default:
                printf("\nPlease enter a valid choice!\n");
        }
    }

    return 0;
}