//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: puzzling
#include <stdio.h>

int main() {
    float income, expenses, savings;
    printf("Enter your monthly income: ");
    scanf("%f", &income);
    printf("Enter your monthly expenses: ");
    scanf("%f", &expenses);
    
    float diff = income - expenses;
    if(diff < 0) {
        printf("Whoops! You are spending more than you earn. Time to cut down on some expenses.\n");
    } else {
        printf("Congratulations! You are doing a great job with your finances.\n");
    }
    
    printf("Let's break down your expenses:\n");
    printf("Housing: ");
    float housing;
    scanf("%f", &housing);
    
    printf("Food: ");
    float food;
    scanf("%f", &food);
    
    printf("Transportation: ");
    float transportation;
    scanf("%f", &transportation);
    
    printf("Utilities: ");
    float utilities;
    scanf("%f", &utilities);
    
    printf("Entertainment: ");
    float entertainment;
    scanf("%f", &entertainment);
    
    float total_expenses = housing + food + transportation + utilities + entertainment;
    printf("Total expenses: $%.2f\n", total_expenses);
    
    float percentage_housing = (housing / total_expenses) * 100;
    printf("Percentage of expenses on housing: %.2f%%\n", percentage_housing);
    
    float percentage_food = (food / total_expenses) * 100;
    printf("Percentage of expenses on food: %.2f%%\n", percentage_food);
    
    float percentage_transportation = (transportation / total_expenses) * 100;
    printf("Percentage of expenses on transportation: %.2f%%\n", percentage_transportation);
    
    float percentage_utilities = (utilities / total_expenses) * 100;
    printf("Percentage of expenses on utilities: %.2f%%\n", percentage_utilities);
    
    float percentage_entertainment = (entertainment / total_expenses) * 100;
    printf("Percentage of expenses on entertainment: %.2f%%\n", percentage_entertainment);
    
    savings = diff - total_expenses;
    printf("Savings: $%.2f\n", savings);
    
    printf("Based on your expenses, here are a few more suggestions to save some money: \n");
    
    if(percentage_housing > 30) {
        printf("Consider moving to a cheaper place or getting a roommate.\n");
    }
    
    if(percentage_food > 20) {
        printf("You might be overspending on food. Try cooking at home more often or getting groceries on sale.\n");
    }
    
    if(percentage_transportation > 15) {
        printf("If possible, try taking public transportation or carpooling to reduce costs.\n");
    }
    
    if(percentage_utilities > 10) {
        printf("Check if any of your utility bills can be reduced by conservation or switching providers.\n");
    }
    
    if(percentage_entertainment > 5) {
        printf("While it's important to enjoy life, consider cutting back on unnecessary entertainment expenses, like movies and concerts.\n");
    }
    
    printf("Good luck with your financial planning!\n");
    return 0;
}