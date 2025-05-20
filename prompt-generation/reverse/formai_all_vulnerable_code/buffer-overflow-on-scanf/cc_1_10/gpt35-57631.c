//FormAI DATASET v1.0 Category: Expense Tracker ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure to store expense details
typedef struct{
    int expense_id;
    char description[50];
    float amount;
}Expense;

//function to add expense
void addExpense(Expense *expenses, int *count){
    printf("\nAdding New Expense\n");

    expenses = realloc(expenses, sizeof(Expense) * (*count + 1));
    printf("Enter Expense ID: ");
    scanf("%d", &expenses[*count].expense_id);

    printf("Enter Expense Description: ");
    scanf(" %[^\n]s", expenses[*count].description);

    printf("Enter Expense Amount: ");
    scanf("%f", &expenses[*count].amount);

    printf("\nExpense Added Successfully!\n");
    (*count)++;
}

//function to display all expenses
void displayExpenses(Expense *expenses, int count){
    printf("\nExpense Details\n");
    printf("Expense ID\t Description\t Amount\n");
    for(int i=0; i<count; i++){
        printf("%d\t\t %s\t\t %.2f\n", expenses[i].expense_id, expenses[i].description, expenses[i].amount);
    }
}

int main(){
    Expense *expenses = NULL;

    int choice = 0, count = 0;
    printf("Welcome to the Cheerful Expense Tracker!\n");

    do{
        printf("\nChoose an option:\n");
        printf("1. Add Expense\n");
        printf("2. Display All Expenses\n");
        printf("3. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                displayExpenses(expenses, count);
                break;
            case 3:
                printf("\nThank You for using Cheerful Expense Tracker!\n");
                break;
            default:
                printf("\nInvalid Choice! Please try again.\n");
                break;
        }
    }while(choice != 3);

    free(expenses);
    return 0;
}