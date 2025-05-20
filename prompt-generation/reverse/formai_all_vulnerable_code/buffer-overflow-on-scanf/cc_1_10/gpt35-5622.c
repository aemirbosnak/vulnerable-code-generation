//FormAI DATASET v1.0 Category: Expense Tracker ; Style: systematic
#include<stdio.h>
#include<string.h>

//This program is designed to keep track of daily expenses using C programming language.

//structure to store date and expense details
struct Expense{
    char date[20];
    char item[50];
    float cost;
};

int main(){

    int numExpenses = 0; //variable to keep track of number of expenses entered by user
    struct Expense expenses[100]; //array of struct to store expenses upto 100 entries

    while(1){
        printf("\n\nEXPENSE TRACKER\n");
        printf("\n1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Exit\n");
        printf("\nEnter your choice (1-3): ");
        int choice;
        scanf("%d",&choice);

        switch(choice){
            case 1: //adding new expense
                printf("\nEnter the date (dd/mm/yyyy): ");
                scanf("%s", expenses[numExpenses].date);
                printf("Enter the item description: ");
                scanf("%s", expenses[numExpenses].item);
                printf("Enter the cost: ");
                scanf("%f", &expenses[numExpenses].cost);
                numExpenses++;
                printf("\nExpense added successfully!\n");
                break;

            case 2: //viewing expenses
                printf("\n\nDATE\t\tITEM DESCRIPTION\t\tCOST\n");
                float total = 0; //variable to calculate total cost of all expenses
                for(int i=0; i<numExpenses; i++){ //looping through all expenses and printing details
                    printf("%s\t\t%s\t\t\t%.2f\n", expenses[i].date, expenses[i].item, expenses[i].cost);
                    total += expenses[i].cost;
                }
                printf("\nTOTAL COST: %.2f\n", total); //printing total cost
                break;

            case 3: //exiting program
                printf("\nThank you for using Expense Tracker!\n");
                return 0;

            default: //handling invalid inputs
                printf("\nInvalid input! Please try again.\n");
        }
    }

    return 0;
}