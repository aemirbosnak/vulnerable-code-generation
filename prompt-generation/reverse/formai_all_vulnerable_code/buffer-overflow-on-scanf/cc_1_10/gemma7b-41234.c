//Gemma-7B DATASET v1.0 Category: Mortgage Calculator ; Style: romantic
#include <stdio.h>
#include <math.h>

int main()
{
    float principal, interestRate, years, monthlyPayment, totalPayment, interestCharge;
    char name[20];

    printf("Welcome to the Enchanted Mortgage Calculator, %s!\n", name);
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Would you like to be a homeowner or renter? (H/R) ");
    char choice;
    scanf("%c", &choice);

    if (choice == 'H')
    {
        printf("Please enter the principal amount you want to borrow: ");
        scanf("%f", &principal);

        printf("Please enter the interest rate you are being offered: ");
        scanf("%f", &interestRate);

        printf("Please enter the number of years you want to borrow for: ");
        scanf("%f", &years);

        interestCharge = principal * interestRate * years;
        totalPayment = principal + interestCharge;
        monthlyPayment = totalPayment / 12;

        printf("Congratulations, %s, you have been pre-approved for a mortgage of $%.2f!\n", name, principal);
        printf("Your total payment over %d years will be $%.2f.\n", years, totalPayment);
        printf("Your monthly payment will be $%.2f.\n", monthlyPayment);
    }
    else if (choice == 'R')
    {
        printf("Please enter the monthly rent you want to afford: ");
        scanf("%f", &monthlyPayment);

        printf("Please enter the number of years you want to rent for: ");
        scanf("%f", &years);

        totalPayment = monthlyPayment * years;

        printf("Congratulations, %s, you have been pre-approved for a rental of $%.2f!\n", name, totalPayment);
        printf("Your total payment over %d years will be $%.2f.\n", years, totalPayment);
    }
    else
    {
        printf("Invalid input. Please try again.\n");
    }

    return 0;
}