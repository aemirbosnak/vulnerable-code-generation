//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

//function prototypes
float calculate_net_income(float salary, float taxes, float expenses);
float calculate_savings(float net_income, float percentage_savings);
float calculate_investments(float savings, float percentage_investments);
float calculate_total_assets(float investments, float savings, float property_value);
float calculate_total_liabilities(float debts, float mortgage);
float calculate_net_worth(float total_assets, float total_liabilities);

int main(){
    //variable declarations
    float salary, taxes=0, expenses=0, percentage_savings=0, percentage_investments=0, property_value=0, debts=0, mortgage=0, net_income=0, savings=0, investments=0, total_assets=0, total_liabilities=0, net_worth=0;
    
    //input from user
    printf("Please enter your salary: ");
    scanf("%f", &salary);
    
    printf("Please enter your percentage taxes: ");
    scanf("%f", &taxes);
    
    printf("Please enter your monthly expenses: ");
    scanf("%f", &expenses);
    
    printf("Please enter your percentage savings: ");
    scanf("%f", &percentage_savings);
    
    printf("Please enter your percentage investments: ");
    scanf("%f", &percentage_investments);
    
    printf("Please enter the value of your property: ");
    scanf("%f", &property_value);
    
    printf("Please enter your total debts: ");
    scanf("%f", &debts);
    
    printf("Please enter your mortgage: ");
    scanf("%f", &mortgage);
    
    //calculations
    net_income = calculate_net_income(salary, taxes, expenses);
    savings = calculate_savings(net_income, percentage_savings);
    investments = calculate_investments(savings, percentage_investments);
    total_assets = calculate_total_assets(investments, savings, property_value);
    total_liabilities = calculate_total_liabilities(debts, mortgage);
    net_worth = calculate_net_worth(total_assets, total_liabilities);
    
    //output to user
    printf("Your net income is: $%.2f\n", net_income);
    printf("Your savings per month is: $%.2f\n", savings);
    printf("Your investments per month is: $%.2f\n", investments);
    printf("Your total assets are: $%.2f\n", total_assets);
    printf("Your total liabilities are: $%.2f\n", total_liabilities);
    printf("Your net worth is: $%.2f\n", net_worth);
    
    return 0;
}

float calculate_net_income(float salary, float taxes, float expenses){
    float net_income;
    net_income = (salary - (salary * (taxes/100))) - expenses;
    return net_income;
}

float calculate_savings(float net_income, float percentage_savings){
    float savings;
    savings = (net_income * (percentage_savings/100));
    return savings;
}

float calculate_investments(float savings, float percentage_investments){
    float investments;
    investments = (savings * (percentage_investments/100));
    return investments;
}

float calculate_total_assets(float investments, float savings, float property_value){
    float total_assets;
    total_assets = investments + savings + property_value;
    return total_assets;
}

float calculate_total_liabilities(float debts, float mortgage){
    float total_liabilities;
    total_liabilities = debts + mortgage;
    return total_liabilities;
}

float calculate_net_worth(float total_assets, float total_liabilities){
    float net_worth;
    net_worth = total_assets - total_liabilities;
    return net_worth;
}