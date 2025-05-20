//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void baggage_handling(int passenger_id)
{
    // Passenger's name and baggage weight
    char passenger_name[20];
    int baggage_weight;

    // Get passenger's name and baggage weight
    printf("Enter passenger name: ");
    scanf("%s", passenger_name);

    printf("Enter baggage weight (in kg): ");
    scanf("%d", &baggage_weight);

    // Calculate baggage fee based on weight
    int baggage_fee = 0;
    if (baggage_weight <= 20)
    {
        baggage_fee = 50;
    }
    else if (baggage_weight <= 30)
    {
        baggage_fee = 75;
    }
    else
    {
        baggage_fee = 100;
    }

    // Print baggage fee
    printf("Baggage fee: $%d", baggage_fee);

    // Generate baggage tag
    char baggage_tag[10];
    sprintf(baggage_tag, "P%03d", passenger_id);

    // Print baggage tag
    printf("Baggage tag: %s", baggage_tag);
}

int main()
{
    // Passenger ID
    int passenger_id = 1;

    // Baggage handling
    baggage_handling(passenger_id);

    return 0;
}