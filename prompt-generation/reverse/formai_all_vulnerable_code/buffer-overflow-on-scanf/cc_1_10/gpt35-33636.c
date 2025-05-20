//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //Initialize variables for number of check-in desks, baggage belts, and passengers
    int numDesks, numBelts, numPassengers;
    
    //Get user input for number of check-in desks
    printf("Enter the number of check-in desks: ");
    scanf("%d", &numDesks);
    
    //Get user input for number of baggage belts
    printf("Enter the number of baggage belts: ");
    scanf("%d", &numBelts);
    
    //Get user input for number of passengers
    printf("Enter the number of passengers: ");
    scanf("%d", &numPassengers);
    
    //Initialize arrays for storing passenger information
    int* passengerIds = (int*) malloc(sizeof(int) * numPassengers);
    int* checkinTimes = (int*) malloc(sizeof(int) * numPassengers);
    int* baggageTimes = (int*) malloc(sizeof(int) * numPassengers);
    int* baggageBelts = (int*) malloc(sizeof(int) * numPassengers);
    int* pickupTimes = (int*) malloc(sizeof(int) * numPassengers);
    
    //Seed the random number generator
    srand(time(NULL));
    
    //Simulate the check-in process
    for(int i = 0; i < numPassengers; i++)
    {
        //Assign a random passenger ID
        passengerIds[i] = i + 1;
        
        //Assign a random check-in time between 1 and 5 minutes
        checkinTimes[i] = rand() % 5 + 1;
        
        //Print the passenger's check-in information
        printf("Passenger %d checked in at desk %d in %d minutes\n", passengerIds[i], rand() % numDesks + 1, checkinTimes[i]);
    }
    
    //Simulate the baggage handling process
    for(int i = 0; i < numPassengers; i++)
    {
        //Assign a random baggage handling time between 5 and 10 minutes
        baggageTimes[i] = rand() % 6 + 5;
        
        //Assign a random baggage belt between 1 and numBelts
        baggageBelts[i] = rand() % numBelts + 1;
        
        //Print the passenger's baggage handling information
        printf("Passenger %d's baggage is being handled at belt %d for %d minutes\n", passengerIds[i], baggageBelts[i], baggageTimes[i]);
    }
    
    //Simulate the baggage pickup process
    for(int i = 0; i < numPassengers; i++)
    {
        //Assign a random pickup time between 2 and 5 minutes
        pickupTimes[i] = rand() % 4 + 2;
        
        //Print the passenger's baggage pickup information
        printf("Passenger %d picked up their baggage at belt %d in %d minutes\n", passengerIds[i], baggageBelts[i], pickupTimes[i]);
    }
    
    //Calculate total time spent at the airport
    int totalWaitTime = 0;
    for(int i = 0; i < numPassengers; i++)
    {
        totalWaitTime += checkinTimes[i] + baggageTimes[i] + pickupTimes[i];
    }
    
    //Calculate average wait time per passenger
    double avgWaitTime = (double) totalWaitTime / numPassengers;
    
    //Print final statistics
    printf("Total time spent at the airport: %d minutes\n", totalWaitTime);
    printf("Average wait time per passenger: %f minutes\n", avgWaitTime);
    
    //Free memory allocated for arrays
    free(passengerIds);
    free(checkinTimes);
    free(baggageTimes);
    free(baggageBelts);
    free(pickupTimes);
    
    return 0;
}