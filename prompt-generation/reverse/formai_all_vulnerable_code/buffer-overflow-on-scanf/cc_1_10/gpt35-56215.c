//FormAI DATASET v1.0 Category: Expense Tracker ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct date{
    int day;
    int month;
    int year;
} Date;

typedef struct expense{
    char category[20];
    float amount;
    Date date;
} Expense;

void addExpense(Expense* expenses, int* size){
    printf("Enter Category: ");
    scanf("%s", expenses[*size].category);
    printf("Enter Amount: ");
    scanf("%f", &expenses[*size].amount);
    printf("Enter Date (DD MM YYYY): ");
    scanf("%d %d %d", &expenses[*size].date.day, &expenses[*size].date.month, &expenses[*size].date.year);
    (*size)++;
}

void displayExpenses(Expense* expenses, int size){
    if(size == 0){
        printf("No expenses to display!\n");
        return;
    }
    printf("Category\tAmount\t\tDate\n");
    for(int i=0; i<size; i++){
        printf("%s\t\t%.2f\t%d-%d-%d\n", expenses[i].category, expenses[i].amount, expenses[i].date.day, expenses[i].date.month, expenses[i].date.year);
    }
}

void displayTotal(Expense* expenses, int size){
    if(size == 0){
        printf("No expenses to display!\n");
        return;
    }
    float total = 0;
    for(int i=0; i<size; i++){
        total += expenses[i].amount;
    }
    printf("Total Expenses: %.2f\n", total);
}

int main(){
    Expense expenses[100];
    int size = 0;
    int choice;
    do{
        printf("Expense Tracker\n");
        printf("----------------\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Display Total Expenses\n");
        printf("4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: addExpense(expenses, &size);
                    break;
            case 2: displayExpenses(expenses, size);
                    break;
            case 3: displayTotal(expenses, size);
                    break;
            case 4: printf("Exiting program...\n");
                    break;
            default: printf("Invalid Choice\n");
                     break;
        }
    }while(choice != 4);

    return 0;
}