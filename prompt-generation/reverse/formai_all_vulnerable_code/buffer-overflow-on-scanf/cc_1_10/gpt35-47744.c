//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRAFFIC_LIGHT_TIME 5 // duration of each traffic light cycle (in seconds)

// function declarations
void printTime(int seconds);
void simulateTrafficFlow(int numOfCycles);

int main() {
    int numOfCycles;

    printf("Welcome to the Traffic Flow Simulation.\n");
    printf("Please enter the number of cycles you wish to simulate: ");
    scanf("%d", &numOfCycles);

    simulateTrafficFlow(numOfCycles);

    printf("\nSimulation completed.\n");

    return 0;
}

void printTime(int seconds) {
    int minutes = seconds / 60;
    int remainingSeconds = seconds % 60;

    printf("%d:%02d", minutes, remainingSeconds);
}

void simulateTrafficFlow(int numOfCycles) {
    int i;
    int currentCycleTime = 0;
    int totalNumOfCars = 0;
    int totalWaitingTime = 0;

    srand(time(0)); // seed the random number generator

    for (i = 1; i <= numOfCycles; i++) {
        int greenLightTime = rand() % 6 + 5; // randomize green light time between 5 and 10 seconds
        int eastWestCars = rand() % 51; // randomize number of cars going east/west between 0 and 50
        int northSouthCars = rand() % 51; // randomize number of cars going north/south between 0 and 50
        int totalCars = eastWestCars + northSouthCars;

        totalNumOfCars += totalCars;

        printf("---------------------------\n");
        printf("Cycle %d:\n", i);
        printf("Green Light time: %d seconds\n", greenLightTime);
        printf("East/West cars: %d\n", eastWestCars);
        printf("North/South cars: %d\n", northSouthCars);
        printf("Total cars: %d\n", totalCars);

        currentCycleTime += TRAFFIC_LIGHT_TIME; // add the traffic light time to the cycle time

        while (greenLightTime > 0) {
            int waitingTime = 0;

            // calculate waiting time for each car
            if (eastWestCars > 0) {
                waitingTime = rand() % 6; // randomize waiting time between 0 and 5 seconds
                totalWaitingTime += waitingTime;
                eastWestCars--;
            } else if (northSouthCars > 0) {
                waitingTime = rand() % 6; // randomize waiting time between 0 and 5 seconds
                totalWaitingTime += waitingTime;
                northSouthCars--;
            }

            // print current time and waiting time
            printf("Current time: ");
            printTime(currentCycleTime);
            printf(", Waiting Time: %d seconds\n", waitingTime);

            currentCycleTime++;
            greenLightTime--;
        }

        currentCycleTime += TRAFFIC_LIGHT_TIME; // add the traffic light time to the cycle time
    }

    printf("---------------------------\n");
    printf("Average number of cars per cycle: %.2f\n", (float) totalNumOfCars / numOfCycles);
    printf("Average waiting time per car: %.2f seconds\n", (float) totalWaitingTime / totalNumOfCars);
}