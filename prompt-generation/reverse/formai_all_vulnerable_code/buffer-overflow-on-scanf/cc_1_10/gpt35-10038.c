//FormAI DATASET v1.0 Category: Expense Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct expense{
    char category[MAX];
    float amount;
    char date[MAX];
    char description[MAX];
};

//function to add an expense
void add_expense(struct expense expenses[], int *counter){
    printf("Enter category: ");
    scanf("%s", expenses[*counter].category);
    printf("Enter amount: ");
    scanf("%f", &expenses[*counter].amount);
    printf("Enter date (mm/dd/yyyy): ");
    scanf("%s",expenses[*counter].date);
    printf("Enter description: ");
    scanf("%s", expenses[*counter].description);
    (*counter)++;
}

//function to display all expenses
void display_all_expenses(struct expense expenses[], int counter){
    int i;
    printf("\n%-10s%-10s%-20s%-20s\n", "Category", "Amount", "Date", "Description");
    for(i=0; i<counter; i++){
        printf("%-10s$%-9.2f%-20s%-20s\n", expenses[i].category, expenses[i].amount, expenses[i].date, expenses[i].description);
    }
}

//function to display expenses of a particular category
void display_category_expenses(struct expense expenses[], int counter, char category[]){
    int i, flag=0;
    printf("\n%-10s%-10s%-20s%-20s\n", "Category", "Amount", "Date", "Description");
    for(i=0; i<counter; i++){
        if(strcmp(expenses[i].category, category)==0){
            printf("%-10s$%-9.2f%-20s%-20s\n", expenses[i].category, expenses[i].amount, expenses[i].date, expenses[i].description);
            flag=1;
        }
    }
    if(!flag){
        printf("No expenses found for this category\n");
    }
}

//function to display expenses above a certain amount
void display_above_amount(struct expense expenses[], int counter, float amount){
    int i, flag=0;
    printf("\n%-10s%-10s%-20s%-20s\n", "Category", "Amount", "Date", "Description");
    for(i=0; i<counter; i++){
        if(expenses[i].amount > amount){
            printf("%-10s$%-9.2f%-20s%-20s\n", expenses[i].category, expenses[i].amount, expenses[i].date, expenses[i].description);
            flag=1;
        }
    }
    if(!flag){
        printf("No expenses greater than %.2f found\n", amount);
    }
}

int main(){
    int choice, counter=0;
    struct expense expenses[MAX];
    while(1){
        printf("\n1. Add expense\n2. Display all expenses\n3. Display expenses of a particular category\n4. Display expenses above a certain amount\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: add_expense(expenses, &counter); break;
            case 2: display_all_expenses(expenses, counter); break;
            case 3: {
                char category[MAX];
                printf("Enter category: ");
                scanf("%s", category);
                display_category_expenses(expenses, counter, category);
                break;
            }
            case 4: {
                float amount;
                printf("Enter amount: ");
                scanf("%f", &amount);
                display_above_amount(expenses, counter, amount);
                break;
            }
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}