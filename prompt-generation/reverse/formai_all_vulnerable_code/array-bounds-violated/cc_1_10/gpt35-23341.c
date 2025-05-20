//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between min and max
int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    srand(time(NULL)); // Seed for generating random values
    int no_of_lanes, no_of_cars, simulation_time, i, j, total_cars_passed;

    printf("Enter the number of lanes: ");
    scanf("%d", &no_of_lanes);

    printf("Enter the number of cars in each lane: ");
    scanf("%d", &no_of_cars);

    int car_positions[no_of_lanes][no_of_cars+1]; // +1 for car waiting at traffic light
    int speeds[no_of_lanes][no_of_cars];

    // Initializing the car positions and speeds randomly
    for (i = 0; i < no_of_lanes; i++) {
        for (j = 0; j < no_of_cars; j++) {
            car_positions[i][j] = getRandomNumber(10, 1000);
            speeds[i][j] = getRandomNumber(10, 80);
        }
        car_positions[i][j] = 0; // Waiting at traffic light
    }

    printf("Enter the simulation time: ");
    scanf("%d", &simulation_time);

    // Simulation loop
    for (i = 0; i < simulation_time; i++) {

        // Traffic light timings (randomly generated between 2 and 5 seconds)
        int green_light_duration = getRandomNumber(2, 5);
        int red_light_duration = getRandomNumber(2, 5);

        // Car movement during green light
        for (int lane = 0; lane < no_of_lanes; lane++) {
            for (int car = 0; car < no_of_cars; car++) {
                if (car_positions[lane][car] < 500) {
                    car_positions[lane][car] += speeds[lane][car];
                }
                else {
                    // Car has passed the traffic light and is removed from the lane
                    car_positions[lane][car] = -1;
                }
            }
        }

        // Cars waiting at traffic light
        for (int lane = 0; lane < no_of_lanes; lane++) {
            if (car_positions[lane][no_of_cars] > 0) {
                car_positions[lane][no_of_cars] -= 1;
            }
            else if (car_positions[lane][no_of_cars] == 0) {
                car_positions[lane][no_of_cars] = -1; // Car has passed the traffic light
            }
        }

        // Counting number of cars that have passed the traffic light
        total_cars_passed = 0;
        for (int lane = 0; lane < no_of_lanes; lane++) {
            for (int car = 0; car < no_of_cars+1; car++) {
                if (car_positions[lane][car] == -1) {
                    total_cars_passed++;
                }
            }
        }

        // Printing the current state of the simulation
        printf("\nSimulation time: %d seconds\n", i);
        printf("Green light duration: %d seconds\n", green_light_duration);
        printf("Red light duration: %d seconds\n", red_light_duration);
        printf("Total cars passed: %d\n", total_cars_passed);
        printf("Current positions:\n");
        for (int lane = 0; lane < no_of_lanes; lane++) {
            printf("Lane %d: ", lane+1);
            for (int car = 0; car < no_of_cars+1; car++) {
                printf("%d ", car_positions[lane][car]);
            }
            printf("\n");
        }

        // Sleep for red light duration
        sleep(red_light_duration);
    }

    return 0;
}