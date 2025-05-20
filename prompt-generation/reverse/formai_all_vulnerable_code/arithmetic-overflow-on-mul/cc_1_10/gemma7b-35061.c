//Gemma-7B DATASET v1.0 Category: Mortgage Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int principle, rate, years, i, total_interest = 0;
    char menu_choice;

    // Shape-shifting mortgage calculator
    system("clear");
    printf("Welcome to the Shape-Shifting Mortgage Calculator!\n");
    printf("Please select an option:\n");
    printf("1. Calculate Mortgage Payment\n");
    printf("2. Calculate Total Interest\n");
    printf("3. Calculate Loan-to-Value Ratio\n");
    printf("Enter your choice: ");

    scanf("%c", &menu_choice);

    switch (menu_choice)
    {
        case '1':
            printf("Enter the principal amount: ");
            scanf("%d", &principle);
            printf("Enter the interest rate (as a decimal): ");
            scanf("%f", &rate);
            printf("Enter the number of years: ");
            scanf("%d", &years);

            // Calculate mortgage payment
            double mortgage_payment = principle * rate * years / 100;
            printf("Your mortgage payment is: $%.2f\n", mortgage_payment);

            break;
        case '2':
            printf("Enter the principal amount: ");
            scanf("%d", &principle);
            printf("Enter the interest rate (as a decimal): ");
            scanf("%f", &rate);
            printf("Enter the number of years: ");
            scanf("%d", &years);

            // Calculate total interest
            double total_interest = principle * rate * years - principle;
            printf("Your total interest is: $%.2f\n", total_interest);

            break;
        case '3':
            printf("Enter the principal amount: ");
            scanf("%d", &principle);
            printf("Enter the value of the property: ");
            scanf("%d", &years);

            // Calculate loan-to-value ratio
            double loan_to_value_ratio = (principle / years) * 100;
            printf("Your loan-to-value ratio is: %d%\n", loan_to_value_ratio);

            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}