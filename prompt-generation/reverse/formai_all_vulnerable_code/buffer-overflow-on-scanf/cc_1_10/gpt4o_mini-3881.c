//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_FLOORS 10
#define ELEVATOR_CAPACITY 5

typedef struct {
    int current_floor;
    int destination_floor;
    int passengers;
} Elevator;

void init_elevator(Elevator *elevator) {
    elevator->current_floor = 1;
    elevator->destination_floor = 0;
    elevator->passengers = 0;
}

void display_status(Elevator elevator) {
    printf("Current Floor: %d, Destination Floor: %d, Passengers: %d\n",
           elevator.current_floor, elevator.destination_floor, elevator.passengers);
}

void move_elevator(Elevator *elevator) {
    if (elevator->destination_floor == 0) {
        return; // No destination
    }

    while (elevator->current_floor != elevator->destination_floor) {
        display_status(*elevator);
        if (elevator->current_floor < elevator->destination_floor) {
            elevator->current_floor++;
        } else {
            elevator->current_floor--;
        }
        sleep(1); // Simulate time taken to move between floors
    }

    printf("Elevator has arrived at floor %d.\n", elevator->current_floor);
    elevator->destination_floor = 0; // Reset destination
}

void call_elevator(Elevator *elevator, int floor) {
    if (floor < 1 || floor > MAX_FLOORS) {
        printf("Invalid floor. Please choose between 1 and %d.\n", MAX_FLOORS);
        return;
    }
    elevator->destination_floor = floor;
    move_elevator(elevator);
}

void board_passengers(Elevator *elevator, int num_passengers) {
    if (elevator->passengers + num_passengers <= ELEVATOR_CAPACITY) {
        elevator->passengers += num_passengers;
        printf("%d passengers boarded. Total passengers: %d.\n",
               num_passengers, elevator->passengers);
    } else {
        printf("Cannot board %d passengers. Elevator full!\n",
               num_passengers);
    }
}

void alight_passengers(Elevator *elevator, int num_passengers) {
    if (num_passengers <= elevator->passengers) {
        elevator->passengers -= num_passengers;
        printf("%d passengers alighted. Remaining passengers: %d.\n",
               num_passengers, elevator->passengers);
    } else {
        printf("Cannot alight %d passengers. Only %d on board.\n",
               num_passengers, elevator->passengers);
    }
}

int main() {
    Elevator elevator;
    init_elevator(&elevator);
    char command;
    int floor, num_passengers;

    while (true) {
        display_status(elevator);
        printf("Commands:\n");
        printf("c - Call Elevator (to a floor 1-%d)\n", MAX_FLOORS);
        printf("b - Board Passengers (number)\n");
        printf("a - Alight Passengers (number)\n");
        printf("q - Quit\n");
        printf("Choose a command: ");
        
        command = getchar();
        while (getchar() != '\n'); // Consume newline character
        
        switch (command) {
            case 'c':
                printf("Enter floor to call elevator: ");
                scanf("%d", &floor);
                while(getchar() != '\n'); // Consume newline character
                call_elevator(&elevator, floor);
                break;
            case 'b':
                printf("Enter number of passengers to board: ");
                scanf("%d", &num_passengers);
                while(getchar() != '\n'); // Consume newline character
                board_passengers(&elevator, num_passengers);
                break;
            case 'a':
                printf("Enter number of passengers to alight: ");
                scanf("%d", &num_passengers);
                while(getchar() != '\n'); // Consume newline character
                alight_passengers(&elevator, num_passengers);
                break;
            case 'q':
                printf("Exiting elevator simulation.\n");
                exit(0);
            default:
                printf("Invalid command! Please try again.\n");
                break;
        }
    }

    return 0;
}