//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 20
#define MIN_FLOORS 5
#define MAX_CAPACITY 10

int current_floor;
int current_capacity;
int direction; // 1 for up, -1 for down
int max_floor;
int min_floor;
int num_people_waiting[MAX_FLOORS];
int num_people_in_elevator;
int elevator_capacity;
int elevator_stopped;
int num_completed_trips;
int num_total_trips;
int time_waiting;

void initialize() {
    printf("Welcome to the Elevator Simulation.\n");
    printf("Enter the total number of floors (between %d and %d): ", MIN_FLOORS, MAX_FLOORS);
    scanf("%d", &max_floor);
    while (max_floor < MIN_FLOORS || max_floor > MAX_FLOORS) {
        printf("Invalid input. Enter the total number of floors (between %d and %d): ", MIN_FLOORS, MAX_FLOORS);
        scanf("%d", &max_floor);
    }
    min_floor = 1;
    printf("Enter the capacity of the elevator (between 1 and %d): ", MAX_CAPACITY);
    scanf("%d", &elevator_capacity);
    while (elevator_capacity < 1 || elevator_capacity > MAX_CAPACITY) {
        printf("Invalid input. Enter the capacity of the elevator (between 1 and %d): ", MAX_CAPACITY);
        scanf("%d", &elevator_capacity);
    }
    current_floor = rand() % max_floor + 1;
    current_capacity = 0;
    direction = 1;
    num_people_in_elevator = 0;
    elevator_stopped = 1;
    num_completed_trips = 0;
    num_total_trips = 0;
    time_waiting = 0;
    for (int i = 0; i < MAX_FLOORS; i++) {
        num_people_waiting[i] = 0;
    }
    printf("Initialization complete.\n");
}

void print_status() {
    printf("Current Floor: %d\n", current_floor);
    printf("Number of people in Elevator: %d\n", num_people_in_elevator);
    printf("Capacity of Elevator: %d\n", elevator_capacity);
    printf("Number of completed trips: %d\n", num_completed_trips);
    printf("Number of total trips: %d\n", num_total_trips);
    printf("Time waiting: %d\n", time_waiting);
    printf("\n");
    printf("People waiting at each floor:\n");
    for (int i = min_floor; i <= max_floor; i++) {
        printf("Floor %d: %d\n", i, num_people_waiting[i-1]);
    }
    printf("\n");
}

void move_elevator() {
    current_floor += direction;
    printf("Elevator is moving %s to floor %d...\n", (direction == 1) ? "up" : "down", current_floor);
    if (current_floor == max_floor) {
        direction = -1;
        printf("Reached top floor. Changing direction to down.\n");
    }
    else if (current_floor == min_floor) {
        direction = 1;
        printf("Reached bottom floor. Changing direction to up.\n");
    }
}

void enter_elevator() {
    if (num_people_waiting[current_floor-1] > 0 && current_capacity < elevator_capacity) {
        num_people_waiting[current_floor-1]--;
        num_people_in_elevator++;
        current_capacity++;
        printf("A person has entered the elevator. Capacity: %d/%d\n", current_capacity, elevator_capacity);
    }
}

void exit_elevator() {
    if (num_people_in_elevator > 0) {
        num_people_in_elevator--;
        current_capacity--;
        printf("A person has exited the elevator. Capacity: %d/%d\n", current_capacity, elevator_capacity);
    }
}

void update_waiting_time() {
    for (int i = min_floor; i <= max_floor; i++) {
        if (num_people_waiting[i-1] > 0) {
            num_total_trips++;
            time_waiting++;
        }
    }
}

int main() {
    srand(time(NULL));
    initialize();
    while (1) {
        print_status();
        if (num_people_in_elevator == 0 && elevator_stopped) {
            update_waiting_time();
        }
        if (num_people_waiting[current_floor-1] > 0 && current_capacity < elevator_capacity) {
            elevator_stopped = 0;
            enter_elevator();
        }
        else if (num_people_in_elevator > 0) {
            elevator_stopped = 0;
            exit_elevator();
        }
        else {
            elevator_stopped = 1;
            move_elevator();
        }
        if (current_capacity == elevator_capacity) {
            num_completed_trips++;
            num_total_trips++;
            time_waiting++;
        }
        if (num_total_trips >= 1000) {
            printf("Simulation complete.\n");
            break;
        }
    }
    return 0;
}