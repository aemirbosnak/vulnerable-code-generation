//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdbool.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 5

int floors[MAX_FLOORS];
int passengers[MAX_PASSENGERS];
int current_floor = 0;
bool moving = false;

void display_status() {
    printf("Current floor: %d\n", current_floor);
    printf("Number of passengers: %d\n", count_passengers());
    printf("Moving: %s\n", moving? "true" : "false");
}

int count_passengers() {
    int count = 0;
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        if (passengers[i]!= 0) {
            count++;
        }
    }
    return count;
}

void add_passenger() {
    int new_passenger = 1;
    printf("Adding a passenger...\n");
    printf("Number of passengers: %d\n", count_passengers());
    printf("Press any key to continue...");
    getchar();
    passengers[current_floor] = new_passenger;
}

void move_up() {
    if (current_floor < MAX_FLOORS - 1) {
        current_floor++;
        moving = true;
    }
}

void move_down() {
    if (current_floor > 0) {
        current_floor--;
        moving = true;
    }
}

void elevator_simulation() {
    printf("Welcome to the Elevator Simulation!\n");
    printf("Please enter the number of floors in the building: ");
    int num_floors;
    scanf("%d", &num_floors);

    for (int i = 0; i < num_floors; i++) {
        floors[i] = i + 1;
    }

    printf("Please enter the number of passengers: ");
    int num_passengers;
    scanf("%d", &num_passengers);

    for (int i = 0; i < num_passengers; i++) {
        passengers[i] = 0;
    }

    while (moving == false) {
        display_status();
        printf("Press '1' to go up, '2' to go down, or '3' to stop: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                move_up();
                break;
            case 2:
                move_down();
                break;
            case 3:
                moving = false;
                break;
            default:
                printf("Invalid choice. Press any key to continue...");
                getchar();
        }
    }

    printf("All passengers have reached their desired floors.\n");
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        if (passengers[i]!= 0) {
            printf("Passenger %d is on floor %d.\n", i + 1, floors[i]);
        }
    }
}

int main() {
    elevator_simulation();
    return 0;
}