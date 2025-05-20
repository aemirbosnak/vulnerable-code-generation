//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int floors = 5;
    int current_floor = 0;
    int people = 0;
    int directions[3] = {1, 0, -1};
    int direction_count[3] = {0, 0, 0};
    int open_doors[3] = {0, 0, 0};

    srand(time(0));

    while (people < 10) {
        int choice;
        printf("What floor would you like to go to? (0-4): ");
        scanf("%d", &choice);
        if (choice > 4) {
            printf("Invalid floor choice. Please try again.\n");
            continue;
        }
        current_floor = choice;
        if (current_floor == 0) {
            printf("The elevator opens on the ground floor.\n");
        } else if (current_floor == 1) {
            printf("The elevator opens on the first floor.\n");
        } else if (current_floor == 2) {
            printf("The elevator opens on the second floor.\n");
        } else if (current_floor == 3) {
            printf("The elevator opens on the third floor.\n");
        } else {
            printf("The elevator opens on the fourth floor.\n");
        }
        printf("The elevator is currently on floor %d.\n", current_floor);

        int random_floor = (rand() % 5) + 1;
        printf("A person gets in the elevator and presses the button for floor %d.\n", random_floor);
        current_floor = random_floor;
        printf("The elevator opens on floor %d.\n", current_floor);

        if (current_floor == 0) {
            printf("The elevator opens on the ground floor.\n");
        } else if (current_floor == 1) {
            printf("The elevator opens on the first floor.\n");
        } else if (current_floor == 2) {
            printf("The elevator opens on the second floor.\n");
        } else if (current_floor == 3) {
            printf("The elevator opens on the third floor.\n");
        } else {
            printf("The elevator opens on the fourth floor.\n");
        }
        printf("The elevator is currently on floor %d.\n", current_floor);

        int direction = rand() % 3;
        int button_pressed = rand() % 3;
        printf("The elevator moves up %d floors and opens on floor %d.\n", directions[direction], current_floor + directions[direction]);
        current_floor += directions[direction];
        printf("The elevator is currently on floor %d.\n", current_floor);

        if (current_floor == 0) {
            printf("The elevator opens on the ground floor.\n");
        } else if (current_floor == 1) {
            printf("The elevator opens on the first floor.\n");
        } else if (current_floor == 2) {
            printf("The elevator opens on the second floor.\n");
        } else if (current_floor == 3) {
            printf("The elevator opens on the third floor.\n");
        } else {
            printf("The elevator opens on the fourth floor.\n");
        }
        printf("The elevator is currently on floor %d.\n", current_floor);

        if (button_pressed == 0) {
            open_doors[0] = 1;
        } else if (button_pressed == 1) {
            open_doors[1] = 1;
        } else {
            open_doors[2] = 1;
        }
        printf("The elevator opens on floor %d.\n", current_floor);

        if (current_floor == 0) {
            printf("The elevator opens on the ground floor.\n");
        } else if (current_floor == 1) {
            printf("The elevator opens on the first floor.\n");
        } else if (current_floor == 2) {
            printf("The elevator opens on the second floor.\n");
        } else if (current_floor == 3) {
            printf("The elevator opens on the third floor.\n");
        } else {
            printf("The elevator opens on the fourth floor.\n");
        }
        printf("The elevator is currently on floor %d.\n", current_floor);

        if (current_floor == 0) {
            printf("The elevator opens on the ground floor.\n");
        } else if (current_floor == 1) {
            printf("The elevator opens on the first floor.\n");
        } else if (current_floor == 2) {
            printf("The elevator opens on the second floor.\n");
        } else if (current_floor == 3) {
            printf("The elevator opens on the third floor.\n");
        } else {
            printf("The elevator opens on the fourth floor.\n");
        }
        printf("The elevator is currently on floor %d.\n", current_floor);

        int door = open_doors[0] + open_doors[1] + open_doors[2];
        if (door == 1) {
            printf("A person gets off the elevator on floor %d.\n", current_floor);
            people--;
        } else if (door == 2) {
            printf("A person gets off the elevator on floor %d.\n", current_floor);
            people--;
        } else if (door == 3) {
            printf("A person gets off the elevator on floor %d.\n", current_floor);
            people--;
        }

        if (people == 0) {
            break;
        }
    }

    printf("Thank you for riding the elevator!\n");
    return 0;
}