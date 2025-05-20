//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void show_menu();
void show_status();
void add_passengers();
void move_elevator();
void remove_passengers();

// Global variables
int num_floors = 3;
int elevator_pos = 1;
int num_passengers = 0;
int passenger_num[4] = {0};

// Function definitions
void show_menu() {
    printf("Select an option:\n");
    printf("1. Show status\n");
    printf("2. Add passengers\n");
    printf("3. Remove passengers\n");
    printf("4. Move elevator\n");
    printf("5. Exit\n");
}

void show_status() {
    printf("Status: ");
    printf("%d", num_passengers);
    printf(" passengers in elevator\n");
    printf("Elevator position: %d\n", elevator_pos);
}

void add_passengers() {
    int floor, num_to_add;

    printf("Enter the floor (1-3): ");
    scanf("%d", &floor);

    printf("Enter the number of passengers to add: ");
    scanf("%d", &num_to_add);

    for (int i = 0; i < num_to_add; i++) {
        passenger_num[i] = num_passengers + i;
    }

    num_passengers += num_to_add;
}

void remove_passengers() {
    int floor, num_to_remove;

    printf("Enter the floor (1-3): ");
    scanf("%d", &floor);

    printf("Enter the number of passengers to remove: ");
    scanf("%d", &num_to_remove);

    for (int i = 0; i < num_to_remove; i++) {
        passenger_num[i] = 0;
    }

    num_passengers -= num_to_remove;
}

void move_elevator() {
    int new_floor;

    printf("Enter the new floor (1-3): ");
    scanf("%d", &new_floor);

    elevator_pos = new_floor;
}

int main() {
    srand(time(NULL));

    while (1) {
        show_menu();
        int choice;

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                show_status();
                break;
            case 2:
                add_passengers();
                break;
            case 3:
                remove_passengers();
                break;
            case 4:
                move_elevator();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}