//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int floor;
    bool is_full;
} Elevator;

Elevator elevator[4];
int current_floor = 1;
bool is_running = false;

void enter_elevator() {
    printf("Enter your desired floor: ");
    int floor_input;
    scanf("%d", &floor_input);

    for (int i = 0; i < 4; i++) {
        if (elevator[i].floor == floor_input &&!elevator[i].is_full) {
            elevator[i].is_full = true;
            return;
        }
    }

    elevator[current_floor % 4].is_full = true;
    elevator[current_floor % 4].floor = floor_input;
    current_floor++;
}

void start_elevator() {
    is_running = true;
    printf("Elevator started.\n");
}

void stop_elevator() {
    is_running = false;
    printf("Elevator stopped.\n");
}

void go_up() {
    if (is_running) {
        if (current_floor < 3) {
            current_floor++;
        } else {
            printf("Elevator reached top floor.\n");
        }
    }
}

void go_down() {
    if (is_running) {
        if (current_floor > 1) {
            current_floor--;
        } else {
            printf("Elevator reached bottom floor.\n");
        }
    }
}

void display_status() {
    printf("Current floor: %d\n", current_floor);
    for (int i = 0; i < 4; i++) {
        if (elevator[i].is_full) {
            printf("Floor %d is full.\n", elevator[i].floor);
        } else {
            printf("Floor %d is available.\n", elevator[i].floor);
        }
    }
}

int main() {
    printf("Welcome to the elevator simulation!\n");

    for (int i = 0; i < 4; i++) {
        elevator[i].floor = 1;
        elevator[i].is_full = false;
    }

    printf("Enter '1' to enter the elevator.\n");
    printf("Enter '2' to start the elevator.\n");
    printf("Enter '3' to stop the elevator.\n");
    printf("Enter '4' to go up.\n");
    printf("Enter '5' to go down.\n");
    printf("Enter '6' to display status.\n");

    while (true) {
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            enter_elevator();
        } else if (choice == 2) {
            start_elevator();
        } else if (choice == 3) {
            stop_elevator();
        } else if (choice == 4) {
            go_up();
        } else if (choice == 5) {
            go_down();
        } else if (choice == 6) {
            display_status();
        } else {
            printf("Invalid input.\n");
        }
    }

    return 0;
}