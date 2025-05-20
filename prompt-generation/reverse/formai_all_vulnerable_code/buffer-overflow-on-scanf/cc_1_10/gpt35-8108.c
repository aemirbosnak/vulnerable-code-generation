//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: peaceful
#include <stdio.h>

int main() {
    double salary, expenses;
    double savings, investments, debt;
    
    printf("Welcome to the Personal Finance Planner!\n");
    printf("Please enter your monthly salary: ");
    scanf("%lf", &salary);
    printf("\n");
    
    printf("Great! Now let's calculate your expenses for the month.\n");
    printf("How much do you spend on rent/mortgage: ");
    scanf("%lf", &expenses);
    printf("\n");
    
    printf("How much do you spend on utilities: ");
    scanf("%lf", &expenses);
    printf("\n");
    
    printf("How much do you spend on groceries: ");
    scanf("%lf", &expenses);
    printf("\n");
    
    printf("How much do you spend on transportation: ");
    scanf("%lf", &expenses);
    printf("\n");
    
    printf("Thank you for inputting your expenses!\n");
    
    savings = salary - expenses;
    debt = 0;
    investments = 0;
    
    printf("Based on the information you have provided, you have %.2lf dollars in savings per month.\n", savings);
    
    printf("Would you like to invest or pay off any debt? (Enter I for Invest, D for Debt, or N for None): ");
    char choice;
    scanf("%c", &choice);
    printf("\n");
    
    if (choice == 'I') {
        printf("How much would you like to invest: ");
        scanf("%lf", &investments);
        printf("\n");
    } else if (choice == 'D') {
        printf("How much debt do you have to pay off: ");
        scanf("%lf", &debt);
        printf("\n");
    } else {
        printf("Thank you for using the Personal Finance Planner!\n");
        return 0;
    }
    
    printf("Here is your updated financial plan:\n");
    printf("Monthly Income:               $%.2lf\n", salary);
    printf("Monthly Expenses:             $%.2lf\n", expenses);
    printf("Monthly Savings:              $%.2lf\n", savings);
    printf("Investments (Monthly):        $%.2lf\n", investments);
    printf("Debt Payoff (Monthly):        $%.2lf\n", debt);
    
    printf("Thank you for using the Personal Finance Planner!\n");
    return 0;
}