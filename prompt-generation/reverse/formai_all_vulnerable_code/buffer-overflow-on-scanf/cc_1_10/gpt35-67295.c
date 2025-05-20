//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BAGGAGE 100     // The maximum number of bags the airport can handle
#define MAX_PASSENGERS 50   // The maximum number of passengers the airport can accommodate

typedef struct {
    int passengerID;        // The passenger to whom the bag belongs
    int weight;             // The weight of the bag in kg
} Baggage;

typedef struct {
    int passengerID;        // The ID of the passenger
    int numBags;            // The number of bags the passenger is carrying
    Baggage bags[MAX_BAGGAGE];  // An array of bags belonging to the passenger
} Passenger;

// This function will simulate the process of loading bags onto the plane
void loadBags(Baggage *bags, int numBags)
{
    printf("Loading %d bags onto the plane...\n", numBags);
    for(int i = 0; i < numBags; i++)
    {
        printf("Loading bag belonging to passenger %d, weighing %d kg\n", bags[i].passengerID, bags[i].weight);
    }
}

int main()
{
    Passenger passengers[MAX_PASSENGERS]; // An array of passengers
    int numPassengers;                    // The number of passengers travelling

    // Code to read in the passenger details and their bags
    printf("Enter the number of passengers: ");
    scanf("%d", &numPassengers);

    for(int i = 0; i < numPassengers; i++)
    {
        printf("\nEnter details for passenger %d:\n", i+1);
        printf("Enter passenger ID: ");
        scanf("%d", &passengers[i].passengerID);
        printf("Enter number of bags: ");
        scanf("%d", &passengers[i].numBags);

        for(int j = 0; j < passengers[i].numBags; j++)
        {
            printf("Enter details of bag %d:\n", j+1);
            printf("Enter bag weight in kg: ");
            scanf("%d", &passengers[i].bags[j].weight);
            passengers[i].bags[j].passengerID = passengers[i].passengerID;
        }
    }

    // Code to sort the bags based on weight using bubble sort
    for(int i = 0; i < numPassengers; i++)
    {
        for(int j = 0; j < passengers[i].numBags-1; j++)
        {
            for(int k = 0; k < passengers[i].numBags-j-1; k++)
            {
                if(passengers[i].bags[k].weight > passengers[i].bags[k+1].weight)
                {
                    Baggage temp = passengers[i].bags[k];
                    passengers[i].bags[k] = passengers[i].bags[k+1];
                    passengers[i].bags[k+1] = temp;
                }
            }
        }
    }

    // Code to load the bags onto the plane
    for(int i = 0; i < numPassengers; i++)
    {
        loadBags(passengers[i].bags, passengers[i].numBags);
    }

  return 0;
}