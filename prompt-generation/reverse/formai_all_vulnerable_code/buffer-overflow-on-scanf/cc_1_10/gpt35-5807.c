//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to get input from user
void getInput(int size, float *arr) {
    for(int i=0; i<size; i++) {
        printf("Enter income/expense amount %d: ", i+1);
        scanf("%f", &arr[i]);
    }
}

// Function to calculate total income and expense
float getTotal(int size, float *arr) {
    float total = 0;
    for(int i=0; i<size; i++) {
        total += arr[i];
    }
    return total;
}

// Function to print the financial report
void printReport(float income, float expense) {
    printf("\n\n**** Financial Report ****\n\n");
    printf("Total Income: $%.2f\n", income);
    printf("Total Expense: $%.2f\n", expense);
    if(income > expense) {
        printf("Profit: $%.2f\n", income - expense);
    } else if(expense > income) {
        printf("Loss: $%.2f\n", expense - income);
    } else {
        printf("No profit or loss.\n");
    }
}

// Main function
int main() {
    float income[MAX_SIZE];
    float expense[MAX_SIZE];
    int n, m;
    printf("Enter number of income sources: ");
    scanf("%d", &n);
    getInput(n, income);
    printf("Enter number of expenses: ");
    scanf("%d", &m);
    getInput(m, expense);
    float total_income = getTotal(n, income);
    float total_expense = getTotal(m, expense);
    printReport(total_income, total_expense);
    return 0;
}