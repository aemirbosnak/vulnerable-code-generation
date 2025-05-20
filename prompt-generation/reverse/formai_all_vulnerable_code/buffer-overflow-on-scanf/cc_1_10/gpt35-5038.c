//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LUGGAGE_SIZE 100

int main(){
    int luggageCount, minWeight, maxWeight, minTime, maxTime;
    printf("Enter the number of luggages: ");
    scanf("%d", &luggageCount);
    printf("Enter the minimum and maximum weight (separated by space): ");
    scanf("%d %d", &minWeight, &maxWeight);
    printf("Enter the minimum and maximum time to transfer (in seconds, separated by space): ");
    scanf("%d %d", &minTime, &maxTime);

    srand(time(NULL));

    int* luggageWeights = malloc(luggageCount * sizeof(int));
    int totalWeight = 0;

    for(int i = 0; i < luggageCount; i++){
        int weight = rand() % (maxWeight - minWeight + 1) + minWeight;
        luggageWeights[i] = weight;
        totalWeight += weight;
    }

    printf("Total weight of luggage: %d kg\n", totalWeight);

    double transferTime = rand() % (maxTime - minTime + 1) + minTime;
    printf("Time to transfer all luggage: %.2lf minutes\n", transferTime/60);

    double avgTransferTime = transferTime / luggageCount;
    printf("Average transfer time per piece of luggage: %.2lf seconds\n", avgTransferTime);

    int conveyorSpeed, conveyorLength;
    printf("Enter the conveyor speed (in meters per minute): ");
    scanf("%d", &conveyorSpeed);
    printf("Enter the conveyor length (in meters): ");
    scanf("%d", &conveyorLength);

    double conveyorTime = (double)conveyorLength / conveyorSpeed;
    printf("Time for luggage to travel entire conveyor belt: %.2lf minutes\n", conveyorTime);

    if(avgTransferTime <= conveyorTime){
        printf("Luggage will be successfully transferred to the plane!\n");
    }
    else{
        int transferFailCount = 0;
        printf("Some luggage will not be transferred in time:\n");
        for(int i = 0; i < luggageCount; i++){
            double timeToTransfer = (double)luggageWeights[i] / conveyorSpeed * 60;
            if(timeToTransfer > avgTransferTime){
                printf("Luggage %d with weight %d kg will not be transferred in time by %.2lf seconds\n", i+1, luggageWeights[i], timeToTransfer - avgTransferTime);
                transferFailCount++;
            }
        }
        printf("%d out of %d pieces of luggage will not make it to the plane in time.\n", transferFailCount, luggageCount);
    }

    free(luggageWeights);
    return 0;
}