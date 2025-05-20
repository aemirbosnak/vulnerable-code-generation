//Gemma-7B DATASET v1.0 Category: Mortgage Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables
    int mortgage_amount, down_payment, interest_rate;
    double monthly_payment, principal, interest, taxes, total_cost;

    // Paranoid security checks
    if (system("whoami") != 0)
    {
        printf("Error: Unauthorized access detected.\n");
        exit(1);
    }

    // Get mortgage amount
    printf("Enter mortgage amount: ");
    scanf("%d", &mortgage_amount);

    // Get down payment
    printf("Enter down payment: ");
    scanf("%d", &down_payment);

    // Get interest rate
    printf("Enter interest rate (as a decimal): ");
    scanf("%lf", &interest_rate);

    // Calculate principal
    principal = mortgage_amount - (down_payment * mortgage_amount / 100);

    // Calculate interest
    interest = principal * interest_rate;

    // Calculate taxes
    taxes = principal * 0.08;

    // Calculate total cost
    total_cost = principal + interest + taxes;

    // Display results
    printf("--------------------------------------------------------\n");
    printf("Mortgage Calculator Results\n");
    printf("--------------------------------------------------------\n");
    printf("Mortgage Amount: $%d\n", mortgage_amount);
    printf("Down Payment: $%d\n", down_payment);
    printf("Interest Rate: %.2f%\n", interest_rate);
    printf("Principal: $%f\n", principal);
    printf("Interest: $%f\n", interest);
    printf("Taxes: $%f\n", taxes);
    printf("Total Cost: $%f\n", total_cost);

    return 0;
}