//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Create a baggage handling system
    int baggage_number = 1;
    char baggage_tag[10];
    char baggage_owner_name[20];
    int baggage_weight = 0;
    int baggage_status = 0;

    // Get the baggage tag, owner's name, and weight
    printf("Enter baggage tag: ");
    scanf("%s", baggage_tag);

    printf("Enter owner's name: ");
    scanf("%s", baggage_owner_name);

    printf("Enter baggage weight: ");
    scanf("%d", &baggage_weight);

    // Calculate the baggage status
    if (baggage_weight <= 20)
    {
        baggage_status = 1;
    }
    else
    {
        baggage_status = 2;
    }

    // Print the baggage status
    printf("Baggage status: ");
    if (baggage_status == 1)
    {
        printf("Acceptable");
    }
    else if (baggage_status == 2)
    {
        printf("Overweight");
    }

    // Increment the baggage number
    baggage_number++;

    // Print the baggage number
    printf("\nBaggage number: %d", baggage_number);

    return 0;
}