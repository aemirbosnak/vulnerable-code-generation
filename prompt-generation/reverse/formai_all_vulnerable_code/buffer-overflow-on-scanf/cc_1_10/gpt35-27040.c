//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: realistic
#include<stdio.h>
#include<stdlib.h>

#define MAX 50

int main()
{
    int n, m, i, j, count = 0;
    printf("Enter number of bags in the terminal: ");
    scanf("%d", &n);
    printf("Enter the number of bags that the conveyor belt can hold at a time: ");
    scanf("%d", &m);
    int bags[MAX], conveyor_belt[MAX];

    printf("Enter the bag numbers:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bags[i]);
    }

    printf("Initial Bag Queue:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", bags[i]);
    }

    printf("\nBags on the conveyor belt:\n");

    for (i = 0; i < n; i++)
    {
        if (i % m == 0 && i != 0) // If the conveyor belt is full, send it to the aircraft
        {
            printf("\nConveyor belt is sending bags to the aircraft.\n");
            for (j = 0; j < m; j++)
            {
                printf("%d ", conveyor_belt[j]);
            }
            printf("\n");
            count += m;
        }
        conveyor_belt[i % m] = bags[i]; //Put the bags on the conveyor belt
    }

    //Send the remaining bags to the aircraft
    printf("\nBags that are remaining:\n");
    for (i = count; i < n; i++)
    {
        printf("%d ", bags[i]);
    }
    printf("\nRemaining bags are being sent to the aircraft.\n");

    //The simulation is complete
    printf("\nAll bags have been loaded on to the aircraft, the simulation is complete.\n");

    return 0;
}