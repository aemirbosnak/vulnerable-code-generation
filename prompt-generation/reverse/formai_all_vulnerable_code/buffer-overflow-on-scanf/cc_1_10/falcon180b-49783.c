//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

struct expense{
    char category[MAX_SIZE];
    float amount;
    int month;
    int year;
};

void add_expense(struct expense expenses[], int size, char category[MAX_SIZE], float amount, int month, int year);
void display_expenses(struct expense expenses[], int size);

int main(){
    int size = 0;
    struct expense expenses[MAX_SIZE];

    while(size < MAX_SIZE){
        printf("Enter category (e.g. Food, Rent): ");
        scanf("%s", expenses[size].category);

        printf("Enter amount: ");
        scanf("%f", &expenses[size].amount);

        printf("Enter month (1-12): ");
        scanf("%d", &expenses[size].month);

        printf("Enter year (YYYY): ");
        scanf("%d", &expenses[size].year);

        size++;
    }

    printf("Expenses:\n");
    display_expenses(expenses, size);

    return 0;
}

void add_expense(struct expense expenses[], int size, char category[MAX_SIZE], float amount, int month, int year){
    if(size >= MAX_SIZE){
        printf("Cannot add more expenses.\n");
        return;
    }

    strcpy(expenses[size].category, category);
    expenses[size].amount = amount;
    expenses[size].month = month;
    expenses[size].year = year;

    size++;
}

void display_expenses(struct expense expenses[], int size){
    if(size == 0){
        printf("No expenses to display.\n");
        return;
    }

    printf("Category\tAmount\tMonth\tYear\n");
    for(int i=0; i<size; i++){
        printf("%s\t%.2f\t%d\t%d\n", expenses[i].category, expenses[i].amount, expenses[i].month, expenses[i].year);
    }
}