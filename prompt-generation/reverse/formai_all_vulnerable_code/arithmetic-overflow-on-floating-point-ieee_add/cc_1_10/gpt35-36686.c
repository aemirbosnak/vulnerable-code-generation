//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main() {
    float salary = 0, tax_rate = 0, tax_amount = 0, net_income = 0, savings_percentage = 0, savings_amount = 0, rent = 0, utilities = 0, groceries = 0, transportation = 0, other_expenses = 0, total_expenses = 0;

    printf("Please enter your total annual salary: ");
    scanf("%f", &salary);

    if (salary <= 48535) {
        tax_rate = 0.15;
        tax_amount = salary * tax_rate;
    } else if (salary <= 97069) {
        tax_rate = 0.205;
        tax_amount = 7280.25 + ((salary - 48535) * tax_rate);
    } else if (salary <= 150473) {
        tax_rate = 0.26;
        tax_amount = 17229.72 + ((salary - 97069) * tax_rate);
    } else if (salary <= 214368) {
        tax_rate = 0.29;
        tax_amount = 31114.76 + ((salary - 150473) * tax_rate);
    } else {
        tax_rate = 0.33;
        tax_amount = 49644.31 + ((salary - 214368) * tax_rate);
    }

    net_income = salary - tax_amount;

    printf("Your total annual tax amount is: $%.2f\n", tax_amount);
    printf("Your total annual net income is: $%.2f\n", net_income);

    printf("What percentage of your net income do you want to save? ");
    scanf("%f", &savings_percentage);

    savings_amount = net_income * (savings_percentage / 100);

    printf("Your total annual savings amount is: $%.2f\n", savings_amount);

    printf("What is your monthly rent/mortgage payment? ");
    scanf("%f", &rent);

    printf("What is your average monthly utilities bill? ");
    scanf("%f", &utilities);

    printf("What is your average monthly grocery bill? ");
    scanf("%f", &groceries);

    printf("What is your average monthly transportation cost? ");
    scanf("%f", &transportation);

    printf("What is your average monthly cost for other expenses? ");
    scanf("%f", &other_expenses);

    total_expenses = rent + utilities + groceries + transportation + other_expenses;

    printf("Your total monthly expenses are: $%.2f\n", total_expenses);

    if (total_expenses > net_income) {
        printf("Warning: Your expenses exceed your income. Please adjust your budget.\n");
    } else {
        printf("Congratulations! You have a positive monthly cash flow of $%.2f\n", net_income - total_expenses);
    }

    return 0;
}