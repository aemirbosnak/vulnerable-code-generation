//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sleep() function

#define MAX_FLOORS 20
#define MAX_ELEVATORS 4
#define MAX_CAPACITY 10

int floor_queue1[MAX_FLOORS], floor_queue2[MAX_FLOORS], floor_queue3[MAX_FLOORS], floor_queue4[MAX_FLOORS], floor_queue5[MAX_FLOORS]; // stores requests on each floor
int queue_top1 = -1, queue_top2 = -1, queue_top3 = -1, queue_top4 = -1, queue_top5 = -1; // top of each floor queue
int current_floor1 = 0, current_floor2 = 0, current_floor3 = 0, current_floor4 = 0, current_floor5 = 0; // current floor of each elevator
int elevator_capacity[MAX_ELEVATORS] = {0, 0, 0, 0}; // passengers in each elevator
int direction1 = 1, direction2 = 1, direction3 = 1, direction4 = 1, direction5 = 1; // direction of each elevator (1 for up, -1 for down)
int floor_count1 = 0, floor_count2 = 0, floor_count3 = 0, floor_count4 = 0, floor_count5 = 0; // counts the number of floors traveled by each elevator
int total_floors = 0, total_passengers = 0; // tracks total number of floors traveled and passengers transported
int time_delay = 1; // time taken for the elevator to travel one floor

void move_elevator(int elevator) {
    if (elevator == 1) {
        while (queue_top1 >= 0) {
            if (current_floor1 == floor_queue1[queue_top1]) {
                // unload passengers
                printf("Elevator 1 arrived at floor %d.\n", current_floor1);
                sleep(1);
                int old_capacity = elevator_capacity[0], i;
                for (i = 0; i < old_capacity; i++) { // loop over passengers and unload those who want to get off at the current floor
                    if (elevator_capacity[i] == current_floor1) {
                        printf("Passenger %d exits elevator 1 at floor %d.\n", i+1, current_floor1);
                        elevator_capacity[i] = -1; // assign a value of -1 to show that the passenger has left the elevator
                    }
                }
                // remove requests from the current floor
                queue_top1--;
                printf("Elevator 1 doors closing.\n\n");
                sleep(1);
            }
            else if (current_floor1 < floor_queue1[queue_top1]) { // elevator is still traveling up
                current_floor1++;
                floor_count1++;
                printf("Elevator 1 traveling up, currently at floor %d.\n", current_floor1);
                sleep(time_delay);
            } else { // elevator is still traveling down
                current_floor1--;
                floor_count1++;
                printf("Elevator 1 traveling down, currently at floor %d.\n", current_floor1);
                sleep(time_delay);
            }
        }
        direction1 = -1 * direction1; // change direction once all requests have been serviced
    } else if (elevator == 2) {
        // similar movements for other elevators
    }
    // add similar blocks for elevators 3, 4, and 5
    printf("Elevator %d has traveled a total of %d floors.\n", elevator, floor_count1);
    total_floors += floor_count1;
    floor_count1 = 0; // reset floor count for next trip
}

void add_request(int floor) {
    int chosen_elevator = -1, i;
    int min_distance = MAX_FLOORS; // initialize distance to maximum possible value
    for (i = 0; i < MAX_ELEVATORS; i++) {
        if (elevator_capacity[i] < MAX_CAPACITY && (direction1 == 1 || (direction1 == -1 && current_floor1 >= floor))) { // check if elevator has space and is going in the right direction
            int distance = abs(floor - current_floor1);
            if (distance < min_distance) { // check if elevator is closer than previous best option
                min_distance = distance;
                chosen_elevator = i;
            }
        }
    }
    if (chosen_elevator == -1) { // no elevator available
        printf("No elevators are available at the moment. Please try again later.\n");
        return;
    }
    if (chosen_elevator == 0) {
        queue_top1++;
        floor_queue1[queue_top1] = floor;
        printf("Request for floor %d added to elevator 1.\n", floor);
    } else if (chosen_elevator == 1) {
        // similar code for other elevators
    }
    // increment passenger count and add floor request to chosen elevator
    total_passengers++;
    elevator_capacity[chosen_elevator]++;
}

int main() {
    int choice, floor;
    while (1) {
        printf("Please select your operation:\n");
        printf("1. Add a floor request\n");
        printf("2. Move elevators\n");
        printf("3. Display elevator status\n");
        printf("4. Quit program\n");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter the floor you want to go to:\n");
            scanf("%d", &floor);
            if (floor > MAX_FLOORS || floor < 1) {
                printf("Invalid floor number. Please try again.\n");
                continue;
            }
            add_request(floor);
        } else if (choice == 2) {
            move_elevator(1);
            move_elevator(2);
            move_elevator(3);
            move_elevator(4);
            move_elevator(5);
        } else if (choice == 3) {
            printf("Elevator 1 is currently at floor %d and has %d passengers. The elevator is traveling %s.\n", current_floor1, elevator_capacity[0], (direction1 == 1) ? "up" : "down");
            // add similar code for elevators 2, 3, 4, and 5
        } else if (choice == 4) {
            printf("Total floors traveled: %d\n", total_floors);
            printf("Total passengers transported: %d\n", total_passengers);
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}