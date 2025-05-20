//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: peaceful
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{

    // Create a serene atmosphere
    srand(time(NULL));
    int peaceful_music = rand() % 2;

    // Baggage Handling Simulation
    int baggage_count = 0;
    int baggage_size = 0;
    char baggage_type[20];

    // Passenger arrives at the baggage counter
    printf("Click! A passenger has arrived at the baggage counter.\n");

    // Passenger checks in baggage
    printf("Please enter the number of bags you have: ");
    scanf("%d", &baggage_count);

    // Calculate baggage size and type
    for (int i = 0; i < baggage_count; i++)
    {
        printf("Please enter the size of your bag (in kg): ");
        scanf("%d", &baggage_size);

        if (baggage_size <= 20)
        {
            strcpy(baggage_type, "Carry-on");
        }
        else if (baggage_size <= 50)
        {
            strcpy(baggage_type, "Checked");
        }
        else
        {
            strcpy(baggage_type, "Excess");
        }
    }

    // Baggage is weighed and tagged
    printf("Weighing your baggage...\n");
    sleep(2);
    printf("Baggage is weighed and tagged.\n");

    // Passenger departs
    printf("Click! The passenger has departed.\n");

    // Play calming music
    if (peaceful_music)
    {
        printf("Ding! Music starts...\n");
        sleep(5);
    }

    return 0;
}