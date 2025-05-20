//FormAI DATASET v1.0 Category: Expense Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct{
    char name[20];
    float amount;
}Expense;

int menu();
void addExpense(Expense expenses[], int *numExpenses);
void viewExpenses(Expense expenses[], int numExpenses);
float totalExpenses(Expense expenses[], int numExpenses);

int main(){
    int choice, numExpenses = 0;
    Expense expenses[MAX_EXPENSES];
    
    do{
        choice = menu();
        
        switch(choice){
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                viewExpenses(expenses, numExpenses);
                break;
            case 3:
                printf("Total expenses: $%.2f\n", totalExpenses(expenses, numExpenses));
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }while(choice != 4);
    
    return 0;
}

int menu(){
    int choice;
    
    printf("Expense Tracker\n");
    printf("----------------\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Total Expenses\n");
    printf("4. Quit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    printf("\n");
    
    return choice;
}

void addExpense(Expense expenses[], int *numExpenses){
    if(*numExpenses >= MAX_EXPENSES){
        printf("Maximum number of expenses reached.");
        return;
    }
    
    Expense expense;
    printf("Enter expense name: ");
    scanf("%s", expense.name);
    printf("Enter expense amount: ");
    scanf("%f", &expense.amount);
    printf("\n");
    
    expenses[*numExpenses] = expense;
    (*numExpenses)++;
}

void viewExpenses(Expense expenses[], int numExpenses){
    if(numExpenses == 0){
        printf("No expenses to view.\n");
        return;
    }
    
    printf("%-20s %-10s\n", "Name", "Amount");
    printf("--------------------\n");
    for(int i = 0; i < numExpenses; i++){
        printf("%-20s $%-9.2f\n", expenses[i].name, expenses[i].amount);
    }
    printf("\n");
}

float totalExpenses(Expense expenses[], int numExpenses){
    float total = 0;
    
    for(int i = 0; i < numExpenses; i++){
        total += expenses[i].amount;
    }
    
    return total;
}