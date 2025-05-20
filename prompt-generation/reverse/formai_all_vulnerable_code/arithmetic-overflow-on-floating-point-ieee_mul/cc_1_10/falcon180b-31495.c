//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main() {

    double salary = 0;
    double rent = 0;
    double utilities = 0;
    double groceries = 0;
    double entertainment = 0;
    double savings = 0;

    printf("Welcome to the Budget Calculator!\n");
    printf("Please enter your monthly salary: ");
    scanf("%lf", &salary);

    printf("\n");

    printf("Please enter your monthly rent/mortgage payment: ");
    scanf("%lf", &rent);

    printf("\n");

    printf("Please enter your monthly utility bill: ");
    scanf("%lf", &utilities);

    printf("\n");

    printf("Please enter your monthly grocery bill: ");
    scanf("%lf", &groceries);

    printf("\n");

    printf("Please enter your monthly entertainment budget: ");
    scanf("%lf", &entertainment);

    printf("\n");

    printf("Please enter the percentage of your salary you would like to save: ");
    scanf("%lf", &savings);

    double totalExpenses = rent + utilities + groceries + entertainment;
    double totalSavings = salary * savings;

    printf("\n");

    printf("Your monthly salary is: $%.2lf\n", salary);
    printf("Your monthly rent/mortgage payment is: $%.2lf\n", rent);
    printf("Your monthly utility bill is: $%.2lf\n", utilities);
    printf("Your monthly grocery bill is: $%.2lf\n", groceries);
    printf("Your monthly entertainment budget is: $%.2lf\n", entertainment);
    printf("You are saving %.2lf%% of your salary, which is $%.2lf\n", savings, totalSavings);

    printf("\n");

    if (totalExpenses > salary) {
        printf("You are spending more than you earn! Please adjust your budget.\n");
    } else if (totalExpenses == salary) {
        printf("You are living paycheck to paycheck. Please consider saving more.\n");
    } else {
        printf("Congratulations! You are living within your means and saving $%.2lf per month.\n", totalSavings);
    }

    return 0;
}