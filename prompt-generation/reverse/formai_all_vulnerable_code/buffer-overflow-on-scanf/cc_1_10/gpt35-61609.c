//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

//Structure for storing personal finance data
struct PersonalFinance {
    float income; //Monthly income
    float expenses[12]; //Array for monthly expenses
    int expenseCount; //Number of monthly expenses
    float totalExpenses; //Total monthly expenses
    float savings; //Savings from income after expenses
    float investments[12]; //Array for monthly investments
    int investmentCount; //Number of monthly investments
    float totalInvestments; //Total monthly investments
    float netWorth; //Total savings + investments
};

//Function to get monthly expenses from user
void getExpenses(struct PersonalFinance *pf) {
    printf("Enter number of monthly expenses: ");
    scanf("%d", &pf->expenseCount);
    
    for(int i=0; i<pf->expenseCount; i++) {
        printf("Enter monthly expense %d: ", i+1);
        scanf("%f", &pf->expenses[i]);
        pf->totalExpenses += pf->expenses[i];
    }
}

//Function to calculate savings from income after expenses
void calculateSavings(struct PersonalFinance *pf) {
    pf->savings = pf->income - pf->totalExpenses;
}

//Function to get monthly investments from user
void getInvestments(struct PersonalFinance *pf) {
    printf("Enter number of monthly investments: ");
    scanf("%d", &pf->investmentCount);
    
    for(int i=0; i<pf->investmentCount; i++) {
        printf("Enter monthly investment %d: ", i+1);
        scanf("%f", &pf->investments[i]);
        pf->totalInvestments += pf->investments[i];
    }
}

//Function to calculate net worth (total savings + investments)
void calculateNetWorth(struct PersonalFinance *pf) {
    pf->netWorth = pf->savings + pf->totalInvestments;
}

//Function to display personal finance data
void displayPersonalFinance(struct PersonalFinance *pf) {
    printf("Personal Finance Data:\n");
    printf("Monthly Income: %f\n", pf->income);
    printf("Monthly Expenses: %f\n", pf->totalExpenses);
    printf("Savings: %f\n", pf->savings);
    printf("Monthly Investments: %f\n", pf->totalInvestments);
    printf("Net Worth: %f\n", pf->netWorth);
}

int main() {
    struct PersonalFinance pf;
    
    printf("Enter monthly income: ");
    scanf("%f", &pf.income);
    
    getExpenses(&pf);
    calculateSavings(&pf);
    getInvestments(&pf);
    calculateNetWorth(&pf);
    displayPersonalFinance(&pf);
    
    return 0;
}