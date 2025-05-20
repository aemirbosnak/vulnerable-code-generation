//FormAI DATASET v1.0 Category: Expense Tracker ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct expense {
    char name[30];
    float amount;
    int day;
    int month;
    int year;
    char category[30];
} Expense;

void addExpense(Expense e[], int* count){
    printf("\nEnter the name of expense: ");
    scanf("%s",e[*count].name);
    printf("\nEnter the amount spent: ");
    scanf("%f",&e[*count].amount);
    printf("\nEnter the date (dd mm yyyy): ");
    scanf("%d %d %d",&e[*count].day,&e[*count].month,&e[*count].year);
    printf("\nEnter the category: ");
    scanf("%s",e[*count].category);
    (*count)++;
    printf("\nNew expense added successfully!");
}

void viewExpenses(Expense e[], int count){
    if(count == 0){
        printf("\nNo expenses added yet!");
        return;
    }
    printf("\nExpense Details:\n\n");
    for(int i=0;i<count;i++){
        printf("Name: %s\nAmount: %0.2f\nDate: %02d/%02d/%d\nCategory: %s\n\n",e[i].name,e[i].amount,e[i].day,e[i].month,e[i].year,e[i].category);
    }
}

void searchExpense(Expense e[], int count){
    if(count == 0){
        printf("\nNo expenses added yet!");
        return;
    }
    char name[30];
    printf("\nEnter the name of expense to be searched: ");
    scanf("%s",name);
    int found = 0;
    for(int i=0;i<count;i++){
        if(strcmp(name,e[i].name) == 0){
            printf("\nExpense Found!\n\nName: %s\nAmount: %0.2f\nDate: %02d/%02d/%d\nCategory: %s\n\n",e[i].name,e[i].amount,e[i].day,e[i].month,e[i].year,e[i].category);
            found = 1;
            break;
        }
    }
    if(found == 0){
        printf("\nExpense not found!");
    }
}

float calculateTotalExpense(Expense e[], int count){
    float total = 0.0;
    for(int i=0;i<count;i++){
        total += e[i].amount;
    }
    return total;
}

void expenseCategory(Expense e[], int count){
    if(count == 0){
        printf("\nNo expenses added yet!");
        return;
    }
    char category[30];
    printf("\nEnter the category to filter expenses: ");
    scanf("%s",category);
    int found = 0;
    printf("\nExpenses under the category - %s:\n\n",category);
    for(int i=0;i<count;i++){
        if(strcmp(category,e[i].category) == 0){
            printf("Name: %s\nAmount: %0.2f\nDate: %02d/%02d/%d\n\n",e[i].name,e[i].amount,e[i].day,e[i].month,e[i].year);
            found = 1;
        }
    }
    if(found == 0){
        printf("\nNo expenses found under the category - %s!",category);
    }
}

int main(){
    Expense expenses[100];
    int count = 0;
    int choice;
    while(1){
        printf("\nWelcome to the Expense Tracker App!\nChoose an option:\n1. Add Expense\n2. View Expenses\n3. Search Expense\n4. Calculate Total Expenses\n5. Filter Expenses by Category\n6. Exit\n\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: addExpense(expenses,&count); break;
            case 2: viewExpenses(expenses,count); break;
            case 3: searchExpense(expenses,count); break;
            case 4: printf("\nTotal expenses: %0.2f",calculateTotalExpense(expenses,count)); break;
            case 5: expenseCategory(expenses,count); break;
            case 6: exit(0);
            default: printf("\nInvalid choice! Please try again.");
        }
    }
    return 0;
}