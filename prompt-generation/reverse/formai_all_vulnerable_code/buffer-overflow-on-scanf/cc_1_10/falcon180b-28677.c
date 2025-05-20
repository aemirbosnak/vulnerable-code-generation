//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the personal finance planner
typedef struct{
    char name[50];
    float income;
    float expenses[10];
    float savings;
}PersonalFinance;

// Function to add expenses
void addExpense(PersonalFinance *pf){
    int i, n;
    printf("Enter the number of expenses: ");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("Enter the name of expense %d: ", i+1);
        scanf("%s", &pf->expenses[i]);
        printf("Enter the amount of expense %d: ", i+1);
        scanf("%f", &pf->expenses[i]);
    }
}

// Function to calculate total income, expenses and savings
void calculate(PersonalFinance *pf){
    int i;
    pf->income = 0;
    for(i=0; i<10; i++){
        pf->income += pf->expenses[i];
    }
    pf->savings = pf->income - pf->expenses[0];
}

// Function to display the personal finance planner
void display(PersonalFinance *pf){
    printf("\nPersonal Finance Planner\n");
    printf("Name: %s\n", pf->name);
    printf("Income: $%.2f\n", pf->income);
    printf("Expenses:\n");
    int i;
    for(i=0; i<10; i++){
        printf("%s: $%.2f\n", pf->expenses[i], pf->expenses[i]);
    }
    printf("Savings: $%.2f\n", pf->savings);
}

int main(){
    PersonalFinance pf;
    printf("Enter your name: ");
    scanf("%s", pf.name);
    printf("Enter your income: $");
    scanf("%f", &pf.income);
    addExpense(&pf);
    calculate(&pf);
    display(&pf);
    return 0;
}