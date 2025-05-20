//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10
#define MAX_CAPACITY 1000
#define MAX_PASSENGERS 20
#define MAX_DESTINATIONS 20

struct elevator {
    int current_floor;
    int direction;
    int capacity;
    int passengers;
    int destinations[MAX_DESTINATIONS];
    int num_destinations;
};

struct passenger {
    int floor;
    int destination;
};

void add_destination(struct elevator *elevator, int floor) {
    if (elevator->num_destinations == MAX_DESTINATIONS) {
        printf("Elevator is full of destinations!\n");
        return;
    }
    elevator->destinations[elevator->num_destinations++] = floor;
}

int main() {
    struct elevator elevator;
    elevator.current_floor = 0;
    elevator.direction = 0;
    elevator.capacity = MAX_CAPACITY;
    elevator.passengers = 0;
    elevator.num_destinations = 0;

    struct passenger passengers[MAX_PASSENGERS];
    int num_passengers = 0;

    int choice;

    while (1) {
        printf("Welcome to the elevator simulation!\n");
        printf("Current floor: %d\n", elevator.current_floor);

        if (num_passengers > 0) {
            printf("Passengers waiting:\n");
            for (int i = 0; i < num_passengers; i++) {
                printf("Floor %d -> Floor %d\n", passengers[i].floor, passengers[i].destination);
            }
        }

        printf("Choose an option:\n");
        printf("1. Call elevator\n");
        printf("2. Add destination\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (elevator.passengers == elevator.capacity) {
                    printf("Elevator is full!\n");
                } else {
                    printf("Enter your floor number: ");
                    int floor = 0;
                    scanf("%d", &floor);
                    add_destination(&elevator, floor);
                    elevator.passengers++;
                    num_passengers++;
                }
                break;
            case 2:
                printf("Enter floor number: ");
                int destination = 0;
                scanf("%d", &destination);
                add_destination(&elevator, destination);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}