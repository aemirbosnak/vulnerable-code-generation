//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 5

int main()
{
    int current_floor = 1;
    int passengers_count = 0;
    int passengers_destination[MAX_PASSENGERS];
    
    while (1) {
        printf("Elevator is at floor %d.\n", current_floor);
        printf("Enter the number of passengers you want to board (max. %d): ", MAX_PASSENGERS-passengers_count);
        int passengers_to_board;
        scanf("%d", &passengers_to_board);
        if (passengers_to_board <= 0 || passengers_to_board > MAX_PASSENGERS-passengers_count) {
            printf("Invalid number of passengers.\n");
            continue;
        }
        printf("Enter the destination floor for each passenger (1 to %d):\n", MAX_FLOORS);
        for (int i = 0; i < passengers_to_board; i++) {
            int destination_floor;
            scanf("%d", &destination_floor);
            if (destination_floor == current_floor) {
                printf("The passenger can't get off at the same floor he boarded.\n");
                continue;
            } else if (destination_floor < 1 || destination_floor > MAX_FLOORS) {
                printf("Invalid destination floor.\n");
                continue;
            }
            passengers_destination[passengers_count] = destination_floor;
            passengers_count++;
        }
        int min_destination = MAX_FLOORS+1;
        int min_destination_index = -1;
        for (int i = 0; i < passengers_count; i++) {
            if (passengers_destination[i] < min_destination) {
                min_destination = passengers_destination[i];
                min_destination_index = i;
            }
        }
        if (min_destination_index == -1) {
            printf("There are no passengers in the elevator.\n");
            continue;
        }
        int next_floor = min_destination > current_floor ? current_floor+1 : current_floor-1;
        printf("Elevator is going %s to floor %d.\n", next_floor > current_floor ? "up" : "down", next_floor);
        while (current_floor != next_floor) {
            current_floor = next_floor > current_floor ? current_floor+1 : current_floor-1;
            printf("Elevator is at floor %d.\n", current_floor);
            for (int i = 0; i < passengers_count; i++) {
                if (passengers_destination[i] == current_floor) {
                    printf("Passenger %d got off the elevator.\n", i+1);
                    passengers_count--;
                    for (int j = i; j < passengers_count; j++) {
                        passengers_destination[j] = passengers_destination[j+1];
                    }
                    break;
                }
            }
        }
    }
    
    return 0;
}