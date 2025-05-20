//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: innovative
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void baggage_handling(int baggage_number)
{
    char baggage_tag[10];
    int weight;
    char owner_name[50];

    printf("Enter baggage tag: ");
    scanf("%s", baggage_tag);

    printf("Enter baggage weight (in kg): ");
    scanf("%d", &weight);

    printf("Enter owner's name: ");
    scanf("%s", owner_name);

    printf("Baggage information:\n");
    printf("Baggage tag: %s\n", baggage_tag);
    printf("Baggage weight: %d kg\n", weight);
    printf("Owner's name: %s\n", owner_name);

    printf("Processing baggage...\n");

    switch (baggage_number)
    {
        case 1:
            printf("Baggage 1 has been processed.\n");
            break;
        case 2:
            printf("Baggage 2 has been processed.\n");
            break;
        case 3:
            printf("Baggage 3 has been processed.\n");
            break;
        default:
            printf("Error: invalid baggage number.\n");
    }

    printf("Baggage handling complete.\n");
}

int main()
{
    int baggage_number;

    printf("Enter the number of baggage: ");
    scanf("%d", &baggage_number);

    baggage_handling(baggage_number);

    return 0;
}