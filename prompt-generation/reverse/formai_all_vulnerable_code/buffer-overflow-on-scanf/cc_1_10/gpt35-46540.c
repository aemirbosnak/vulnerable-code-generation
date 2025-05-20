//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>

// function prototypes
void input_cashflow(int n_months, float *cashflow);
float compute_budget(float income, float expenses);
void print_report(float budget);

int main(){
    int n_months = 12; // assuming 12 months in a year
    float cashflow[n_months];
    float income = 0, expenses = 0, budget = 0;

    // read in monthly cashflow
    input_cashflow(n_months, cashflow);

    // compute income and expenses from cashflow
    for(int i=0; i<n_months; i++){
        if(cashflow[i] > 0){
            income += cashflow[i];
        } else {
            expenses += abs(cashflow[i]);
        }
    }

    // compute budget
    budget = compute_budget(income, expenses);

    // print budget report
    print_report(budget);

    return 0;
}

void input_cashflow(int n_months, float * cashflow){
    printf("Enter monthly cashflow for the year:\n");
    for(int i=0; i < n_months; i++){
        printf("Month %d: ", i+1);
        scanf("%f", cashflow+i);
    }
}

float compute_budget(float income, float expenses){
    printf("Computing budget...\n");
    return income - expenses;
}

void print_report(float budget){
    printf("******************************************\n");
    printf("**** Personal Finance Planner Report ****\n");
    printf("******************************************\n");
    printf("Your budget for the year is %f\n", budget);
    if(budget > 0){
        printf("Congratulations! You have a surplus of %f\n", budget);
    } else if(budget < 0){
        printf("Uh oh! You are in the red with a deficit of %f\n", budget);
    } else {
        printf("You are breaking even! \n");
    }
}