//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Romeo and Juliet
// Romeo and Juliet: A Personal Finance Planner

#include<stdio.h>

int main() {

    int romeo_income, juliet_income, romeo_expenses, juliet_expenses, romeo_savings, juliet_savings, total_income, total_expenses, savings_difference;

    printf("Enter Romeo's monthly income: ");
    scanf("%d", &romeo_income);

    printf("Enter Juliet's monthly income: ");
    scanf("%d", &juliet_income);

    printf("Enter Romeo's monthly expenses: ");
    scanf("%d", &romeo_expenses);

    printf("Enter Juliet's monthly expenses: ");
    scanf("%d", &juliet_expenses);

    romeo_savings = romeo_income - romeo_expenses;
    juliet_savings = juliet_income - juliet_expenses;
    total_income = romeo_income + juliet_income;
    total_expenses = romeo_expenses + juliet_expenses;
    savings_difference = romeo_savings - juliet_savings;

    printf("\n****************************************************\n");
    printf("\t\t PERSONAL FINANCE PLANNER\n");
    printf("\n****************************************************\n");

    printf("\nRomeo's monthly income: %d", romeo_income);
    printf("\nRomeo's monthly expenses: %d", romeo_expenses);
    printf("\nRomeo's monthly savings: %d", romeo_savings);

    printf("\n\nJuliet's monthly income: %d", juliet_income);
    printf("\nJuliet's monthly expenses: %d", juliet_expenses);
    printf("\nJuliet's monthly savings: %d", juliet_savings);

    // Romeo and Juliet's financial comparison in Shakespearean style
    if (savings_difference > 0) {
        printf("\n\nOh fair Juliet, Romeo's savings doth exceed\nThat of thine own, with surfeit to impede\nOur household's balance, a matter we must heave\nElse our fortune mayhap, to ruin we concede\n");
    }

    else if (savings_difference < 0) {
        printf("\n\nOh dear Romeo, your savings may fall short\nAnd leave us in debt, a matter we must sort\nOur household's balance, a challenge we must thwart\nEre our finances doth adjourn to the court\n");
    }

    else {
        printf("\n\nOh my love, our savings doth match\nA harmony in our finance to attach\nTogether we shall prosper, without a catch\nOur love shall surpass, all that we snatch\n");
    }

    printf("\nTotal monthly income: %d", total_income);
    printf("\nTotal monthly expenses: %d", total_expenses);

    return 0;
}