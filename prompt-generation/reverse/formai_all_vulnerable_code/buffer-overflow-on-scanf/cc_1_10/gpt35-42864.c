//FormAI DATASET v1.0 Category: Expense Tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define struct for expense details
struct expense{
    int amount;
    char description[100];
    char date[20];
};
//global variables
int total = 0;
int option = 0;
struct expense expenses[100];

//function to display the main menu
void mainMenu(){
    printf("\n-------------------\n");
    printf("EXPENSE TRACKER\n");
    printf("-------------------\n");
    printf("1. Add an expense\n");
    printf("2. View all expenses\n");
    printf("3. View total expenses\n");
    printf("4. Exit\n");
    printf("-------------------\n");
    printf("Enter your choice: ");
    scanf("%d",&option);
}

//function to add an expense
void addExpense(){
    printf("\n-------------------\n");
    printf("ADD AN EXPENSE\n");
    printf("-------------------\n");
    struct expense e;
    printf("Enter amount: ");
    scanf("%d",&e.amount);
    printf("Enter description: ");
    scanf("%s",&e.description);
    printf("Enter date (dd-mm-yyyy): ");
    scanf("%s",&e.date);
    expenses[total++] = e;
    printf("-------------------\n");
    printf("Expense Added Successfully!\n");
}

//function to view all expenses
void viewAllExpenses(){
    printf("\n-------------------\n");
    printf("VIEW ALL EXPENSES\n");
    printf("-------------------\n");
    printf("Amount\tDescription\tDate\n");
    for(int i=0;i<total;i++){
        printf("%d\t%s\t%s\n",expenses[i].amount,expenses[i].description,expenses[i].date);
    }
    printf("-------------------\n");
}

//function to view total expenses
void viewTotalExpenses(){
    printf("\n-------------------\n");
    printf("VIEW TOTAL EXPENSES\n");
    printf("-------------------\n");
    int sum = 0;
    for(int i=0;i<total;i++){
        sum += expenses[i].amount;
    }
    printf("Total Expenses: %d",sum);
    printf("\n-------------------\n");
}

int main(){
    while(option != 4){
        mainMenu();
        switch(option){
            case 1: addExpense();
                    break;
            case 2: viewAllExpenses();
                    break;
            case 3: viewTotalExpenses();
                    break;
            case 4: printf("\nExiting Expense Tracker. Goodbye!\n");
                    return 0;
            default:printf("\nInvalid Choice. Please try again.\n");
        }
    }
}