//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEVATOR_CAPACITY 10
#define MAX_TIME 10000

int main()
{
    int elevator_floor = 0;
    int current_time = 0;
    int num_passengers = 0;
    int destination_floors[MAX_ELEVATOR_CAPACITY];
    int passenger_floors[MAX_TIME];
    int num_passengers_per_floor[MAX_TIME] = {0};

    while (current_time < MAX_TIME) {
        // Generate new passengers
        int new_passengers = rand() % 5;
        for (int i = 0; i < new_passengers; i++) {
            int random_floor = rand() % 10;
            passenger_floors[current_time]++;
            num_passengers_per_floor[random_floor]++;
        }

        // Move elevator
        if (elevator_floor == 0) {
            elevator_floor = 9;
        } else {
            elevator_floor--;
        }

        // Check if any passengers want to exit at current floor
        int passengers_to_remove = 0;
        for (int i = 0; i < num_passengers; i++) {
            if (destination_floors[i] == elevator_floor) {
                passengers_to_remove++;
            } else {
                destination_floors[i - passengers_to_remove] = destination_floors[i];
            }
        }
        num_passengers -= passengers_to_remove;

        // Check if any passengers want to enter
        int passengers_to_add = 0;
        for (int i = 0; i < num_passengers_per_floor[elevator_floor]; i++) {
            if (num_passengers < MAX_ELEVATOR_CAPACITY) {
                destination_floors[num_passengers] = rand() % 10;
                num_passengers_per_floor[elevator_floor]--;
                num_passengers++;
                passengers_to_add++;
            } else {
                break;
            }
        }

        // Print current floor and number of passengers
        printf("Time %d: Floor %d, %d passengers\n", current_time, elevator_floor, num_passengers);

        // Increment current time
        current_time++;
    }

    return 0;
}