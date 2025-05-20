//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defining Variables
int num_cars = 0, num_lanes = 0, time_limit = 0, avg_speed = 0, traffic_density = 0;

//Function to calculate the distance between two cars
int distance(int speed, int time) {
    return speed * time;
}

int main() {
    //Getting input from the user
    printf("Enter the number of cars: ");
    scanf("%d", &num_cars);

    printf("Enter the number of lanes: ");
    scanf("%d", &num_lanes);

    printf("Enter the traffic density: ");
    scanf("%d", &traffic_density);

    printf("Enter the average speed: ");
    scanf("%d", &avg_speed);

    printf("Enter the time limit: ");
    scanf("%d", &time_limit);

    //Initializing seed for randomization
    srand(time(NULL));

    //Calculating time taken by each car
    int time[num_cars];
    for (int i = 0; i < num_cars; i++) {
        int random_speed = avg_speed - (rand() % ((2 * traffic_density) + 1));
        time[i] = distance(random_speed, 1);
    }

    // Initializing arrays for car and lane position
    int car_pos[num_cars];
    int lane_pos[num_lanes][num_cars/num_lanes];

    // Displaying the start positions of cars and lanes
    printf("\nStart Positions:\n");
    for (int i = 0; i < num_cars; i++) {
        car_pos[i] = i;
        printf("Car %d starts at position %d\n", i + 1, car_pos[i]);
    }

    printf("\n\n");
    for (int j = 0; j < num_lanes; j++) {
        for (int i = 0; i < num_cars/num_lanes; i++) {
            lane_pos[j][i] = car_pos[(j*(num_cars/num_lanes))+i];
            printf("Lane %d position %d: Car %d\n", j+1, i+1, lane_pos[j][i]+1);
        }
        printf("\n");
    }

    // Running simulation for given time limit
    printf("\n\nSimulation:\n\n");
    for (int time_elapsed = 0; time_elapsed < time_limit; time_elapsed++) {
        // Displaying positions at each second
        printf("Time %d:\n", time_elapsed);
        for (int j = 0; j < num_lanes; j++) {
            printf("Lane %d: ", j+1);
            for (int i = 0; i < num_cars/num_lanes; i++) {
                if (time[lane_pos[j][i]] <= 0 && lane_pos[j][i] < num_cars-1) {
                    lane_pos[j][i]++;

                    if (lane_pos[j][i] > 0 && lane_pos[j][i] % traffic_density == 0) {
                        printf("ROADBLOCK{" "%d " "}", lane_pos[j][i] + 1);
                    } else {
                        printf("Car %d ", lane_pos[j][i]+1);
                    }

                    if (lane_pos[j][i] == num_cars-1) {
                        printf("FINISH\n");
                    }
                    time[lane_pos[j][i]] = distance(avg_speed - (rand() % ((2 * traffic_density) + 1)), 1);
                } else {
                    time[lane_pos[j][i]]--;
                    printf("= ");
                }
            }
            printf("\n");
        }
        printf("\n\n");
    }

    return 0;
}