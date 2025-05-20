//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // initialize random number generator

    int current_floor = 0;
    int destination_floor;
    int delta;
    int passengers = 0;
    int max_passengers;
    int floors[10] = {0};
    int i;

    printf("Welcome to the Surrealist Elevator Simulation!\n");
    printf("Enter the maximum number of passengers: ");
    scanf("%d", &max_passengers);

    while (1) {
        printf("\nCurrent floor: %d\n", current_floor);
        printf("Number of passengers: %d\n", passengers);

        for (i = 0; i < 10; i++) {
            if (floors[i] > 0) {
                printf("%d passenger(s) waiting on floor %d\n", floors[i], i);
            }
        }

        printf("Enter destination floor or -1 to exit: ");
        scanf("%d", &destination_floor);

        if (destination_floor == -1) {
            printf("Exiting program...\n");
            break;
        }

        delta = destination_floor - current_floor;

        if (delta > 0) {
            printf("Going up...\n");
            for (i = 0; i < delta; i++) {
                current_floor += 1;
                printf("Floor %d\n", current_floor);
                if (current_floor < 10 && floors[current_floor] > 0) {
                    printf("%d passenger(s) got on the elevator\n", floors[current_floor]);
                    passengers += floors[current_floor];
                    floors[current_floor] = 0;
                    if (passengers > max_passengers) {
                        printf("Elevator overloaded! Dropping passengers on floor %d\n", current_floor);
                        passengers = max_passengers;
                    }
                }
            }
        } else if (delta < 0) {
            printf("Going down...\n");
            for (i = 0; i > delta; i--) {
                current_floor -= 1;
                printf("Floor %d\n", current_floor);
                if (current_floor >= 0 && floors[current_floor] > 0) {
                    printf("%d passenger(s) got on the elevator\n", floors[current_floor]);
                    passengers += floors[current_floor];
                    floors[current_floor] = 0;
                    if (passengers > max_passengers) {
                        printf("Elevator overloaded! Dropping passengers on floor %d\n", current_floor);
                        passengers = max_passengers;
                    }
                }
            }
        } else {
            printf("You are already on that floor!\n");
        }

        printf("Enter number of passengers to add to floor %d: ", current_floor);
        int added_passengers;
        scanf("%d", &added_passengers);
        if (added_passengers < 0) {
            printf("Nice try!\n");
        } else {
            int available_space = max_passengers - passengers;
            if (available_space == 0) {
                printf("Elevator full! Please wait for the next one.\n");
                floors[current_floor] += added_passengers;
            } else if (added_passengers > available_space) {
                printf("%d passenger(s) added to floor %d\n", available_space, current_floor);
                passengers += available_space;
            } else {
                printf("%d passenger(s) added to floor %d\n", added_passengers, current_floor);
                passengers += added_passengers;
            }
        }
    }

    return 0;
}