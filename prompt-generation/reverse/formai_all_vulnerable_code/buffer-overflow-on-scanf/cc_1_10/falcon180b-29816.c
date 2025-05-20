//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 10

struct expense{
    char category[20];
    float amount;
};

struct expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense(){
    char category[20];
    float amount;

    printf("Enter expense category: ");
    scanf("%s",category);

    printf("Enter expense amount: ");
    scanf("%f",&amount);

    strcpy(expenses[num_expenses].category,category);
    expenses[num_expenses].amount = amount;

    num_expenses++;
    printf("\nExpense added successfully!\n");
}

void view_expenses(){
    printf("\nExpense Report\n");
    printf("---------------------\n");
    printf("Category\tAmount\n");

    for(int i=0;i<num_expenses;i++){
        printf("%s\t%.2f\n",expenses[i].category,expenses[i].amount);
    }
}

void main(){
    int choice;

    do{
        printf("\nExpense Tracker\n");
        printf("---------------------\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                add_expense();
                break;

            case 2:
                view_expenses();
                break;

            case 3:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }while(choice!=3);
}