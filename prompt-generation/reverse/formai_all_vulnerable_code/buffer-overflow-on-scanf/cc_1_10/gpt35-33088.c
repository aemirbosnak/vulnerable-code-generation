//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MIN_FLOORS 5

void delay(int seconds) {
    int milli_seconds = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds) {}
}

int main() {
    srand(time(NULL));
    int num_of_floors = (rand() % (MAX_FLOORS - MIN_FLOORS + 1)) + MIN_FLOORS; // random number of floors between 5-10
    printf("Welcome to the Elevator Simulation Program!\n");
    printf("There are %d floors in this building.\n\n", num_of_floors);

    int current_floor = 1; // elevator starts at the ground floor
    int desired_floor;
    int direction; // 1 for up, -1 for down
    int floors_passed = 0;
    int stop_requested = 0;

    while (1) {
        printf("The elevator is currently on floor %d.\n", current_floor);
        printf("Where would you like to go? (Enter floor number or type 'stop' to exit)\n");
        if (scanf("%d", &desired_floor) != 1) {
            printf("Invalid input! Please enter a floor number or type 'stop' to exit.\n");
            continue;
        }
        if (desired_floor == current_floor) {
            printf("You are already on that floor!\n");
            continue;
        }
        if (desired_floor < 1 || desired_floor > num_of_floors) {
            printf("Invalid input! This building has %d floors. Please enter a valid floor number or type 'stop' to exit.\n", num_of_floors);
            continue;
        }
        direction = (desired_floor > current_floor) ? 1 : -1;
        printf("Going %s to floor %d...\n", (direction == 1) ? "up" : "down", desired_floor);
        delay(1);
        while (current_floor != desired_floor) {
            current_floor += direction;
            floors_passed++;
            printf("Passing floor %d...\n", current_floor);
            if (stop_requested) {
                printf("Stopping on floor %d as requested...\n", current_floor);
                stop_requested = 0;
            }
        }
        printf("You have reached floor %d!\n", current_floor);
        printf("You passed %d floors on this trip.\n", floors_passed);
        floors_passed = 0;
        printf("Would you like to go to another floor? (y/n)\n");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'n' || choice == 'N') {
            printf("Thank you for using the Elevator Simulation Program!\n");
            break;
        } else if (choice == 'y' || choice == 'Y') {
            printf("Please enter the floor number you wish to go to:\n");
            continue;
        }
        printf("Invalid input! Program will now terminate.\n");
        break;
    }

    return 0;
}