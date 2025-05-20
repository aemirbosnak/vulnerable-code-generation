//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: safe
#include <stdio.h>

#define MAX_FLOOR 10
#define MIN_FLOOR 1
#define ELEVATOR_CAPACITY 10

int main()
{
    int current_floor = MIN_FLOOR;
    int destination_floor;
    int num_passengers = 0;
    int passengers_to_dest[MAX_FLOOR] = {0};
    int i;

    printf("Welcome to the Elevator Simulation.\n\n");

    while(1) {
        printf("You are currently on floor %d.\n", current_floor);

        if(num_passengers == ELEVATOR_CAPACITY) {
            printf("The elevator is full. Please select your destination floor (1-10): ");
            scanf("%d", &destination_floor);

            if(destination_floor < MIN_FLOOR || destination_floor > MAX_FLOOR) {
                printf("Invalid floor selected.\n\n");
                continue;
            }

            passengers_to_dest[destination_floor - 1]++;
            printf("The elevator doors are closing...\n");
            printf("Next stop: floor %d\n\n", destination_floor);

            if(passengers_to_dest[destination_floor - 1] > 0) {
                printf("You have reached floor %d. %d passenger(s) exit the elevator.\n", 
                       destination_floor, passengers_to_dest[destination_floor - 1]);

                num_passengers -= passengers_to_dest[destination_floor - 1];
                passengers_to_dest[destination_floor - 1] = 0;
            }

            current_floor = destination_floor;
        }
        else {
            printf("Please select your destination floor (1-10): ");
            scanf("%d", &destination_floor);

            if(destination_floor < MIN_FLOOR || destination_floor > MAX_FLOOR) {
                printf("Invalid floor selected.\n\n");
                continue;
            }

            passengers_to_dest[destination_floor - 1]++;
            num_passengers++;

            printf("The elevator doors are closing...\n");
            printf("Next stop: floor %d\n\n", destination_floor);

            if(passengers_to_dest[destination_floor - 1] > 0) {
                printf("You have reached floor %d. %d passenger(s) exit the elevator.\n", 
                       destination_floor, passengers_to_dest[destination_floor - 1]);

                num_passengers -= passengers_to_dest[destination_floor - 1];
                passengers_to_dest[destination_floor - 1] = 0;
            }

            current_floor = destination_floor;
        }
    }

    return 0;
}