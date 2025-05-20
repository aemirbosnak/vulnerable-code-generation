//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FLOOR 10

int num_passengers = 0;
int current_floor = 1;

void print_stats() {
    printf("--- ELEVATOR STATISTICS ---\n");
    printf("CURRENT FLOOR: %d\n", current_floor);
    printf("NUMBER OF PASSENGERS: %d\n", num_passengers);
}

void move_elevator(int destination_floor) {
    printf("ELEVATOR MOVING from floor %d to floor %d\n", current_floor, destination_floor);
    sleep(abs(destination_floor - current_floor) * 2);
    current_floor = destination_floor;
    printf("ELEVATOR ARRIVED at floor %d\n", current_floor);
}

void add_passenger() {
    if (num_passengers < 10) {
        num_passengers++;
        printf("PASSENGER ADDED. Total passengers: %d\n", num_passengers);
    } else {
        printf("ELEVATOR FULL. Cannot add more passengers.\n");
    }
}

void remove_passenger() {
    if (num_passengers > 0) {
        num_passengers--;
        printf("PASSENGER REMOVED. Total passengers: %d\n", num_passengers);
    } else {
        printf("ELEVATOR EMPTY. Cannot remove passengers.\n");
    }
}

int main() {
    printf("WELCOME TO THE ELEVATOR SIMULATION!\n");

    while (1) {
        print_stats();

        // Get user input
        printf("Enter your choice:\n");
        printf("1. Move elevator to a floor\n");
        printf("2. Add a passenger\n");
        printf("3. Remove a passenger\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter destination floor:\n");
                int destination_floor;
                scanf("%d", &destination_floor);
                if (destination_floor < 1 || destination_floor > MAX_FLOOR) {
                    printf("INVALID FLOOR NUMBER\n");
                } else if (destination_floor == current_floor) {
                    printf("ELEVATOR ALREADY ON THIS FLOOR\n");
                } else {
                    move_elevator(destination_floor);
                }
                break;
            case 2:
                add_passenger();
                break;
            case 3:
                remove_passenger();
                break;
            default:
                printf("INVALID CHOICE\n");
        }

        printf("\n\n");
    }

    return 0;
}