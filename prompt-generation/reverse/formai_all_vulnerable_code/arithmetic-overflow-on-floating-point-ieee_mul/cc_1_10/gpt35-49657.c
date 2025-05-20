//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: accurate
#include<stdio.h>

float calculateTax(float income) {
    float taxAmount = 0.0;
    
    if(income <= 250000) {
        taxAmount = 0.0;
    }
    else if(income > 250000 && income <= 500000) {
        taxAmount = (income - 250000) * 0.05;
    }
    else if(income > 500000 && income <= 1000000) {
        taxAmount = ((income - 500000) * 0.2) + 12500;
    }
    else {
        taxAmount = ((income - 1000000) * 0.3) + 112500;
    }
    
    return taxAmount;
}

int main() {
    float income = 0.0;
    float savings = 0.0;
    float expenses = 0.0;
    float taxAmount = 0.0;
    
    printf("\n--------------------------------------");
    printf("\n\tPERSONAL FINANCE PLANNER");
    printf("\n--------------------------------------\n");
    
    printf("\nEnter your monthly income: ");
    scanf("%f", &income);
    
    printf("Enter your monthly savings: ");
    scanf("%f", &savings);
    
    printf("Enter your monthly expenses: ");
    scanf("%f", &expenses);
    
    taxAmount = calculateTax(income);
    
    printf("\n--------------------------------------");
    printf("\n\tMONTHLY FINANCIAL SUMMARY");
    printf("\n--------------------------------------\n");
    
    printf("Monthly Income:\t\t%.2f\n", income);
    printf("Monthly Savings:\t\t%.2f\n", savings);
    printf("Monthly Expenses:\t\t%.2f\n", expenses);
    
    printf("Tax Amount:\t\t\t%.2f\n", taxAmount);
    printf("Net Income (After Tax):\t%.2f\n", income - taxAmount);
    printf("Savings Rate:\t\t\t%.2f%%\n", (savings / income) * 100);
    printf("Expenses Rate:\t\t\t%.2f%%\n", (expenses / income) * 100);
    
    return 0;
}