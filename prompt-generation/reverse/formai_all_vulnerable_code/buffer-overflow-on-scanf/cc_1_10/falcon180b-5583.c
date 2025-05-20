//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 1000

struct Expense{
    char date[11];
    char category[50];
    float amount;
};

void addExpense(struct Expense expenses[], int size){
    char date[11];
    char category[50];
    float amount;

    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", date);

    printf("Enter the category: ");
    scanf("%s", category);

    printf("Enter the amount: ");
    scanf("%f", &amount);

    strcpy(expenses[size].date, date);
    strcpy(expenses[size].category, category);
    expenses[size].amount = amount;

    size++;
}

void displayExpenses(struct Expense expenses[], int size){
    int i;

    for(i=0; i<size; i++){
        printf("%s - %s - %.2f\n", expenses[i].date, expenses[i].category, expenses[i].amount);
    }
}

int main(){
    struct Expense expenses[MAX_SIZE];
    int size = 0;

    while(1){
        printf("\n1. Add expense\n2. Display expenses\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice){
            case 1:
                if(size >= MAX_SIZE){
                    printf("Maximum size reached.\n");
                }
                else{
                    addExpense(expenses, size);
                    size++;
                }
                break;

            case 2:
                if(size == 0){
                    printf("No expenses added yet.\n");
                }
                else{
                    displayExpenses(expenses, size);
                }
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}