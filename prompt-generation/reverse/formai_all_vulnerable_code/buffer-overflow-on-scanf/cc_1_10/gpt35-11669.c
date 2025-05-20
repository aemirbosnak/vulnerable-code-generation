//FormAI DATASET v1.0 Category: Expense Tracker ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Defining the structure for a single expense */
typedef struct{
    char category[20];
    float amount;
    char date[15];
    char description[100];
} Expense;

/* Declaring global variable for tracking total expenses */
float total_expenses = 0;

/* Function to display all entered expenses */
void display_expenses(Expense *expenses, int num_expenses){
    printf("\n");
    if(num_expenses == 0){
        printf("No expenses entered yet.\n");
    }
    else{
        printf("Expenses:\n");
        for(int i=0; i<num_expenses; i++){
            printf("------------------------------\n");
            printf("Category: %s\n", expenses[i].category);
            printf("Amount: $%.2f\n", expenses[i].amount);
            printf("Date: %s\n", expenses[i].date);
            printf("Description: %s\n", expenses[i].description);
            printf("------------------------------\n");
        }
    }
}

/* Function to add new expense */
void add_expense(Expense *expenses, int *num_expenses){
    Expense new_expense;
    printf("\nEnter category: ");
    scanf("%s", new_expense.category);
    printf("Enter amount: $");
    scanf("%f", &new_expense.amount);
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", new_expense.date);
    printf("Enter description: ");
    scanf(" %[^\n]", new_expense.description);
    expenses[*num_expenses] = new_expense;
    *num_expenses += 1;
    total_expenses += new_expense.amount;
    printf("\nExpense added successfully!\n");
}

/* Function to search for expenses of a specific category */
void search_category(Expense *expenses, int num_expenses){
    char search_category[20];
    int count = 0;
    printf("\nEnter category to search: ");
    scanf("%s", search_category);
    printf("\nExpenses for category '%s':\n", search_category);
    for(int i=0; i<num_expenses; i++){
        if(strcmp(expenses[i].category, search_category) == 0){
            printf("------------------------------\n");
            printf("Amount: $%.2f\n", expenses[i].amount);
            printf("Date: %s\n", expenses[i].date);
            printf("Description: %s\n", expenses[i].description);
            printf("------------------------------\n");
            count++;
        }
    }
    if(count == 0){
        printf("No expenses found for category '%s'\n", search_category);
    }
}

/* Main function */
int main(){
    int option, num_expenses = 0;
    Expense expenses[100];
    do{
        printf("\nWelcome to Expense Tracker\n");
        printf("1. Display all expenses\n");
        printf("2. Add new expense\n");
        printf("3. Search expenses by category\n");
        printf("4. Exit\n");
        printf("\nEnter option: ");
        scanf("%d", &option);
        switch(option){
            case 1: display_expenses(expenses, num_expenses);
                    printf("\nTotal expenses: $%.2f\n", total_expenses);
                    break;
            case 2: add_expense(expenses, &num_expenses);
                    printf("\nTotal expenses: $%.2f\n", total_expenses);
                    break;
            case 3: search_category(expenses, num_expenses);
                    break;
            case 4: printf("\nThank you for using Expense Tracker!\n");
                    break;
            default: printf("\nInvalid option selected. Please try again.\n");
                     break;
        }
    }while(option!=4);
    return 0;
}