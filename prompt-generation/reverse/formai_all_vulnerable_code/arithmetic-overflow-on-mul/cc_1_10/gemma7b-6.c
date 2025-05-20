//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main()
{

    int baggage_quantity = 0;
    int baggage_weight = 0;
    char baggage_type[20];
    char baggage_owner[20];

    // Simulate baggage handling at the airport
    printf("Welcome to the C Airport Baggage Handling Simulator!\n");

    // Get the baggage quantity, weight, type, and owner
    printf("Please enter the number of bags you have: ");
    scanf("%d", &baggage_quantity);

    printf("Please enter the total weight of your baggage (in kilograms): ");
    scanf("%d", &baggage_weight);

    printf("Please enter the type of baggage (e.g. checked, hand carry): ");
    scanf("%s", baggage_type);

    printf("Please enter your name: ");
    scanf("%s", baggage_owner);

    // Calculate the baggage fees
    int baggage_fees = 0;
    if (baggage_quantity > 2)
    {
        baggage_fees += 50 * (baggage_quantity - 2);
    }
    if (baggage_weight > 20)
    {
        baggage_fees += 20 * (baggage_weight - 20);
    }

    // Print the baggage fees
    printf("Your total baggage fees are: $%d\n", baggage_fees);

    // Print the baggage handling receipt
    printf("------------------------------------------------------------------------\n");
    printf("C Airport Baggage Handling Receipt\n");
    printf("------------------------------------------------------------------------\n");
    printf("Baggage Quantity: %d\n", baggage_quantity);
    printf("Baggage Weight: %d kg\n", baggage_weight);
    printf("Baggage Type: %s\n", baggage_type);
    printf("Baggage Owner: %s\n", baggage_owner);
    printf("Total Baggage Fees: $%d\n", baggage_fees);
    printf("------------------------------------------------------------------------\n");

    return 0;
}