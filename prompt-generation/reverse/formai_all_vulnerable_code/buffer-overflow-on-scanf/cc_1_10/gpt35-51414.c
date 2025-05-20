//FormAI DATASET v1.0 Category: Expense Tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

//function to add expenses
void addExpense(int* expenseList, int* currentIndex, int* totalExpenses){
    int expenseAmount;
    printf("Enter the amount of the expense: ");
    scanf("%d", &expenseAmount);
    expenseList[*currentIndex] = expenseAmount;
    *currentIndex +=1;
    *totalExpenses += expenseAmount;
    printf("Expense added successfully!\n");
}

//function to view expenses
void viewExpenses(int* expenseList, int* currentIndex){
    printf("Expenses:\n");
    for(int i=0; i<*currentIndex; i++){
        printf("- $%d\n", expenseList[i]);
    }
}

//function to see total expenses
void showTotal(int* totalExpenses){
    printf("Total expenses: $%d\n", *totalExpenses);
}


//main program
int main(){
    int* expenseList = (int*) malloc(sizeof(int)*100);
    int currentIndex = 0;
    int totalExpenses = 0;
    char choice;
    do{
        printf("\nEXPENSE TRACKER\n");
        printf("-----------------\n");
        printf("1. Add an expense\n");
        printf("2. View expenses\n");
        printf("3. Show total expenses\n");
        printf("4. Exit\n");
        printf("-----------------\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch(choice){
            case '1':
                addExpense(expenseList, &currentIndex, &totalExpenses);
                break;
            case '2':
                viewExpenses(expenseList, &currentIndex);
                break;
            case '3':
                showTotal(&totalExpenses);
                break;
            case '4':
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }while(choice!='4');
    free(expenseList); //free memory allocated
    return 0;
}