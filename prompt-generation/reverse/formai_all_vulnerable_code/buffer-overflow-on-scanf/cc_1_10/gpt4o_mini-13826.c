//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define MAX_CAPACITY 5

typedef struct {
    int current_floor;
    int target_floor;
    int passengers;
} Elevator;

void display_status(Elevator *elevator) {
    printf("Elevator is currently on floor %d.\n", elevator->current_floor);
    printf("Target floor: %d\n", elevator->target_floor);
    printf("Current number of passengers: %d\n", elevator->passengers);
    printf("\n");
}

void move_elevator(Elevator *elevator) {
    while (elevator->current_floor != elevator->target_floor) {
        if (elevator->current_floor < elevator->target_floor) {
            printf("Moving up from floor %d to %d...\n", elevator->current_floor, elevator->current_floor + 1);
            elevator->current_floor++;
        } else {
            printf("Moving down from floor %d to %d...\n", elevator->current_floor, elevator->current_floor - 1);
            elevator->current_floor--;
        }
        sleep(1);
    }
}

bool add_passenger(Elevator *elevator) {
    if (elevator->passengers < MAX_CAPACITY) {
        elevator->passengers++;
        printf("One passenger entered the elevator. Current passengers: %d\n", elevator->passengers);
        return true;
    } else {
        printf("Elevator is at full capacity. Cannot add more passengers!\n");
        return false;
    }
}

void remove_passenger(Elevator *elevator) {
    if (elevator->passengers > 0) {
        elevator->passengers--;
        printf("One passenger exited the elevator. Current passengers: %d\n", elevator->passengers);
    } else {
        printf("No passengers to remove! Elevator is empty.\n");
    }
}

void interact_with_elevator(Elevator *elevator) {
    char choice;
    
    printf("Welcome to the Fantastical Elevator! Choose an option:\n");
    printf("1: Add Passenger\n");
    printf("2: Remove Passenger\n");
    printf("3: Set Target Floor\n");
    printf("4: Move Elevator\n");
    printf("5: Display Status\n");
    printf("q: Quit\n");

    while (true) {
        printf("Enter your choice: ");
        choice = getchar();
        // Clear the input buffer
        while (getchar() != '\n');

        switch (choice) {
            case '1':
                add_passenger(elevator);
                break;
            case '2':
                remove_passenger(elevator);
                break;
            case '3':
                printf("Enter target floor (0-%d): ", MAX_FLOORS - 1);
                scanf("%d", &elevator->target_floor);
                // Clear the input buffer
                while (getchar() != '\n');
                if (elevator->target_floor < 0 || elevator->target_floor >= MAX_FLOORS) {
                    printf("Invalid floor!\n");
                    elevator->target_floor = elevator->current_floor; // Reset to current floor
                }
                break;
            case '4':
                move_elevator(elevator);
                break;
            case '5':
                display_status(elevator);
                break;
            case 'q':
                printf("Thank you for using the Fantastical Elevator!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("\n");
    }
}

int main() {
    Elevator elevator = {0, 0, 0};
    interact_with_elevator(&elevator);
    
    return 0;
}