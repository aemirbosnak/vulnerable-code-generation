//FormAI DATASET v1.0 Category: Expense Tracker ; Style: random
#include<stdio.h>
#include<stdlib.h>

struct expense{
    char category[20];
    float amount;
};

void addExpense(struct expense expenses[], int *size){
    printf("Enter expense category: ");
    scanf("%s", expenses[*size].category);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*size].amount);
    (*size)++;
    printf("\nExpense added successfully!\n");
}

void viewExpenses(struct expense expenses[], int size){
    float total_spent = 0.0;
    printf("Expenses:\n");
    for(int i=0; i<size; i++){
        printf("%s: $%.2f\n", expenses[i].category, expenses[i].amount);
        total_spent += expenses[i].amount;
    }
    printf("\nTotal spent: $%.2f\n", total_spent);
}

int main(){
    struct expense expenses[50];
    int size = 0, choice;
    printf("Welcome to the Expense Tracker!\n");
    do{
        printf("\nSelect an option:\n1. Add an expense\n2. View expenses\n3. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addExpense(expenses, &size);
                break;
            case 2:
                viewExpenses(expenses, size);
                break;
            case 3:
                printf("\nThank you for using the Expense Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }while(choice != 3);
    return 0;
}