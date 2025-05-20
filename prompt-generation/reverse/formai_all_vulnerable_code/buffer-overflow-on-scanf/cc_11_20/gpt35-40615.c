//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int current_floor = 1;
    int target_floor = 1;
    int elevator_direction = 0; // 1 for going up, -1 for going down, 0 for idle
    int elevator_stopped = 1; // 1 for stopped, 0 for moving
    int num_people = 0;
    int max_people = 8;
    printf("Welcome to the medieval elevator!\n");
    printf("The elevator currently on floor %d\n", current_floor);
    while (1) {
        printf("\n");
        if (elevator_stopped) {
            printf("The elevator is currently stopped.\n");
            if (num_people == 0) {
                printf("There are no people in the elevator.\n");
                printf("Waiting for someone to call the elevator...\n");
                int called_floor = rand() % 5 + 1;
                printf("Ding ding! Someone on floor %d needs the elevator!\n", called_floor);
                target_floor = called_floor;
                elevator_direction = (target_floor > current_floor) ? 1 : -1;
                printf("The elevator is now moving %s.\n", (elevator_direction == 1) ? "up" : "down");
                elevator_stopped = 0;
            }
            else {
                printf("There are currently %d people in the elevator.\n", num_people);
                printf("Where would you like to go? ");
                scanf("%d", &target_floor);
                elevator_direction = (target_floor > current_floor) ? 1 : -1;
                printf("The elevator is now moving %s.\n", (elevator_direction == 1) ? "up" : "down");
                elevator_stopped = 0;
            }
        }
        else {
            printf("The elevator is currently moving %s.\n", (elevator_direction == 1) ? "up" : "down");
            if (elevator_direction == 1) {
                current_floor++;
            }
            else {
                current_floor--;
            }
            if (current_floor == target_floor) {
                printf("Ding! You have arrived at floor %d.\n", current_floor);
                elevator_stopped = 1;
                num_people = 0;
            }
            else {
                printf("Passing floor %d...\n", current_floor);
            }
        }
        if (rand() % 5 == 0 && num_people < max_people) {
            printf("Someone else is getting in the elevator!\n");
            num_people++;
        }
    }
    return 0;
}