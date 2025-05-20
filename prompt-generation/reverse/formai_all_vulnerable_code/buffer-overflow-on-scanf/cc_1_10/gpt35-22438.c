//FormAI DATASET v1.0 Category: Expense Tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 50

struct Expense { 
    char description[50];
    float amount;
};

void addExpense(struct Expense expenses[], int *index){
    if(*index >= MAX_EXPENSES){
        printf("Maximum number of expenses reached!");      
        return;
    }
    char buffer[50];
    float amount;
    printf("Enter expense description: ");
    fgets(buffer, 50, stdin);
    strcpy(expenses[*index].description, buffer);
    
    printf("Enter amount: $");
    scanf("%f", &amount);
    getchar();  // to flush the '\n' character
    expenses[*index].amount = amount;
    
    printf("Expense added successfully!\n\n");
    (*index)++;
}

void printExpenses(struct Expense expenses[], int index){
    if(index == 0){
        printf("No expenses found!");
        return;
    }
    float sum = 0.0;
    printf("%-25s %s\n", "Description", "Amount");
    for(int i=0; i<index; i++){
        printf("%-25s $%.2f\n", expenses[i].description, expenses[i].amount);
        sum += expenses[i].amount;
    }
    printf("\nTotal expenses: $%.2f\n\n", sum);
}

void printMenu(){
    printf("Expense Tracker\n");
    printf("----------------\n");
    printf("1. Add expense\n");
    printf("2. View expenses\n");
    printf("3. Exit\n\n");
}

int main(){
    struct Expense expenses[MAX_EXPENSES];
    int index = 0;
    int option;
    
    printf("Welcome to the Expense Tracker!\n\n");
    
    do {
        printMenu();
        printf("Enter your choice (1-3): ");
        scanf("%d", &option);
        getchar();  // to flush the '\n' character
        
        switch(option){
            case 1:
                addExpense(expenses, &index);
                break;
            case 2:
                printExpenses(expenses, index);
                break;
            case 3:
                printf("Thank you for using Expense Tracker!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
        
    } while(option != 3);
    
    return 0;
}