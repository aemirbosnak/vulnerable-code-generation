//Code Llama-13B DATASET v1.0 Category: Elevator Simulation ; Style: paranoid
/* Elevator Simulation in a Paranoid Style */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_FLOORS 10
#define MAX_PASSEGERS 5
#define MAX_DIRECTIONS 3
#define MAX_COMMANDS 5

typedef struct {
    int floor;
    int direction;
} Passenger;

Passenger passengers[MAX_PASSEGERS];
int current_floor = 1;
int num_passengers = 0;
int direction = 1;

void print_menu() {
    printf("--- Elevator Simulation ---\n");
    printf("1. Take passenger to floor\n");
    printf("2. Go to next floor\n");
    printf("3. Go to previous floor\n");
    printf("4. Print current floor\n");
    printf("5. Print passenger list\n");
    printf("6. Quit\n");
}

void take_passenger_to_floor() {
    int floor;
    printf("Enter floor: ");
    scanf("%d", &floor);
    passengers[num_passengers].floor = floor;
    passengers[num_passengers].direction = direction;
    num_passengers++;
}

void go_to_next_floor() {
    if (direction == 1) {
        current_floor++;
    } else {
        current_floor--;
    }
}

void go_to_previous_floor() {
    if (direction == 1) {
        current_floor--;
    } else {
        current_floor++;
    }
}

void print_current_floor() {
    printf("Current floor: %d\n", current_floor);
}

void print_passenger_list() {
    printf("Passenger list:\n");
    for (int i = 0; i < num_passengers; i++) {
        printf("Floor: %d, Direction: %d\n", passengers[i].floor, passengers[i].direction);
    }
}

void quit() {
    printf("Thank you for using the elevator simulation!\n");
    exit(0);
}

int main() {
    srand(time(NULL));
    int command;
    while (1) {
        print_menu();
        printf("Enter command: ");
        scanf("%d", &command);
        switch (command) {
            case 1:
                take_passenger_to_floor();
                break;
            case 2:
                go_to_next_floor();
                break;
            case 3:
                go_to_previous_floor();
                break;
            case 4:
                print_current_floor();
                break;
            case 5:
                print_passenger_list();
                break;
            case 6:
                quit();
                break;
            default:
                printf("Invalid command\n");
                break;
        }
    }
    return 0;
}