//FormAI DATASET v1.0 Category: Expense Tracker ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// A structure to hold the details of a single expense
typedef struct{
    char item[50];
    float cost;
    char date[20];
}Expense;

// A function to display the menu and get the user's choice
int getMenuChoice(){
    int choice;
    printf("\n-- MENU --\n");
    printf("1. Add expense\n");
    printf("2. View all expenses\n");
    printf("3. View expenses by date\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// A function to add a new expense to the database
void addExpense(Expense *database, int *count){
    printf("\n-- ADD EXPENSE --\n");
    printf("Enter item name: ");
    scanf("%s", (database + (*count))->item);
    printf("Enter cost: ");
    scanf("%f", &(database + (*count))->cost);
    printf("Enter date (yyyy-mm-dd): ");
    scanf("%s", (database + (*count))->date);
    (*count)++;
}

// A function to display all expenses in the database
void viewAllExpenses(Expense *database, int count){
    if(count == 0){
        printf("\nThere are no expenses in the database.\n");
        return;
    }
    printf("\n-- ALL EXPENSES --\n");
    for(int i=0; i<count; i++){
        printf("%s\t%.2f\t%s\n", (database+i)->item, (database+i)->cost, (database+i)->date);
    }
}

// A function to display expenses on a particular date
void viewExpensesByDate(Expense *database, int count){
    char date[20];
    printf("\nEnter date (yyyy-mm-dd): ");
    scanf("%s", date);
    printf("\n-- EXPENSES ON %s --\n", date);
    int noExpensesOnDate = 1;
    for(int i=0; i<count; i++){
        if(strcmp((database+i)->date, date) == 0){
            printf("%s\t%.2f\n", (database+i)->item, (database+i)->cost);
            noExpensesOnDate = 0;
        }
    }
    if(noExpensesOnDate){
        printf("No expenses on this date.\n");
    }
}

int main(){
    int count = 0;
    Expense *database = (Expense*) malloc(sizeof(Expense));
    int choice;
    do{
        choice = getMenuChoice();
        switch(choice){
            case 1: addExpense(database, &count);
                    break;
            case 2: viewAllExpenses(database, count);
                    break;
            case 3: viewExpensesByDate(database, count);
                    break;
            case 4: printf("\nExiting program...\n");
                    break;
            default: printf("\nInvalid choice. Please try again.\n");
        }
    }while(choice != 4);
    free(database);
    return 0;
}