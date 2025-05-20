//FormAI DATASET v1.0 Category: Arithmetic ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Defining the structure of a fraction number
struct fraction
{
    int numerator;
    int denominator;
};

// Function to add two fractions
struct fraction add_fractions(struct fraction f1, struct fraction f2)
{
    struct fraction result;

    // Finding the common denominator
    int common_denominator = f1.denominator * f2.denominator;

    // Adding the numerators using the common denominator
    int numerator_sum = (f1.numerator * f2.denominator) + (f2.numerator * f1.denominator);

    // Storing the result in the structure
    result.numerator = numerator_sum;
    result.denominator = common_denominator;

    // Simplifying the fraction by finding the greatest common divisor
    int gcd = 1;
    for (int i = 1; i <= result.numerator && i <= result.denominator; i++)
    {
        if (result.numerator % i == 0 && result.denominator % i == 0)
            gcd = i;
    }

    result.numerator /= gcd;
    result.denominator /= gcd;

    return result;
}

int main()
{
    printf("Welcome to the fraction calculator!\n");

    while (1)
    {
        printf("Enter the first fraction in the format (numerator/denominator): ");
        int n1, d1;
        scanf("%d/%d", &n1, &d1);

        struct fraction f1 = {n1, d1};

        printf("Enter the second fraction in the format (numerator/denominator): ");
        int n2, d2;
        scanf("%d/%d", &n2, &d2);

        struct fraction f2 = {n2, d2};

        struct fraction result = add_fractions(f1, f2);

        printf("The sum of %d/%d and %d/%d is %d/%d\n", f1.numerator, f1.denominator, f2.numerator, f2.denominator, result.numerator, result.denominator);

        char choice;
        printf("Do you want to calculate another sum? (Y/N): ");
        scanf(" %c", &choice);

        if (choice == 'N' || choice == 'n')
        {
            printf("Thank you for using the fraction calculator!\n");
            break;
        }
    }

    return 0;
}