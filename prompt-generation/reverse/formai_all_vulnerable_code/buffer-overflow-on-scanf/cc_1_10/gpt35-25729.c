//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: high level of detail
#include<stdio.h>

//function to print header of table
void printHeader(){
    printf("============================================\n");
    printf("\t\tPERSONAL FINANCE PLANNER\n");
    printf("============================================\n\n");
    printf("%-20s%-20s%-20s\n", "MONTH", "INCOME", "EXPENSES");
    printf("--------------------------------------------\n");
}

//function to calculate total income and expenses
void calculateTotal(int income[], int expenses[], int n){
    int totalIncome = 0, totalExpenses = 0;
    for(int i=0; i<n; i++){
        totalIncome += income[i];
        totalExpenses += expenses[i];
    }
    printf("\n\n");
    printf("Total Income: %d\n", totalIncome);
    printf("Total Expenses: %d\n\n", totalExpenses);
}

//main function
int main(){
    int n;
    printf("Enter the number of months: ");
    scanf("%d", &n);

    int income[n];
    int expenses[n];

    //taking input for income and expenses for each month
    for(int i=0; i<n; i++){
        printf("\n\n");
        printf("Month %d:\n", i+1);
        printf("Enter Income: ");
        scanf("%d", &income[i]);

        printf("Enter Expenses: ");
        scanf("%d", &expenses[i]);
    }

    //printing table
    printHeader();
    for(int i=0; i<n; i++){
        printf("%-20d%-20d%-20d\n", i+1, income[i], expenses[i]);
    }

    //calculating and printing total amount
    calculateTotal(income, expenses, n);

    return 0;
}