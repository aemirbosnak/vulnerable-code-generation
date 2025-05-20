//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRAFFIC 100
// Define maximum number of cars allowed on the road

void simulate_traffic(int traffic)
{
    int i, j, k;
    int speed[MAX_TRAFFIC], position[MAX_TRAFFIC], distance[MAX_TRAFFIC];

    for (i = 0; i < traffic; i++) {
        speed[i] = 60 + (rand() % 40); // Assign random speeds between 60 to 100 km/h
        position[i] = rand() % 10000;  // Randomly position cars on the road
        distance[i] = 0;
    }

    while(1) { // Start traffic simulation

        printf("Time Elapsed: %d seconds\n", k);
        for (i = 0; i < traffic; i++) {

            printf("Car %d: speed = %d km/h, position = %d m\n", i, speed[i], position[i]);

            // Check distance to next car
            for (j = i+1; j < traffic; j++) {
                if ((position[j] - position[i]) > 50) {
                    distance[i] = position[j] - position[i] - 50;
                    break;
                }
            }

            if (distance[i] == 0) { // No car ahead
                position[i] += speed[i] * 10; // Update position of car
            }
            else { // Car ahead
                if ((speed[i] * 10) < distance[i]) {
                    position[i] += speed[i] * 10; // Update position of car
                }
                else {
                    speed[i] = distance[i] / 10; // Reduce speed to avoid collision
                    position[i] += speed[i] * 10; // Update position of car
                }
            }

            if (position[i] > 10000) {
                printf("Car %d has reached the destination\n", i);
                traffic--;
                for (j = i; j < traffic; j++) { // Move remaining cars up
                    speed[j] = speed[j+1];
                    position[j] = position[j+1];
                    distance[j] = distance[j+1];
                }
            }
        }

        if (traffic == 0) {
            printf("All cars have reached the destination\n");
            break;
        }

        printf("\n");
        k++; // Increment time elapsed
        sleep(1); // Sleep for 1 second
    }
}

int main()
{
    int n;

    srand(time(NULL)); // Set seed for random number generator
    printf("Welcome to the traffic flow simulation program.\n");

    do {
        printf("Please enter the number of cars on the road (1-100): ");
        scanf("%d", &n);
    } while (n < 1 || n > 100);

    simulate_traffic(n);

    return 0;
}