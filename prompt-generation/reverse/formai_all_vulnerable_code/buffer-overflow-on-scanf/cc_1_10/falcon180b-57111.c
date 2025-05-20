//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define STOP 5

int main() {
    int choice;
    int speed = 0;
    int direction = STOP;

    printf("Welcome to the Sherlock Holmes Remote Control Vehicle Simulation!\n");
    printf("You are in control of a vintage automobile, circa 1895.\n");
    printf("Please select your desired speed (1-5): ");
    scanf("%d", &speed);

    while (1) {
        system("clear");
        printf("Current Speed: %d\n", speed);
        printf("Current Direction: %d\n", direction);

        printf("\n");
        printf("Press 'w' to move forward.\n");
        printf("Press's' to move backward.\n");
        printf("Press 'a' to turn left.\n");
        printf("Press 'd' to turn right.\n");
        printf("Press's' to stop.\n");
        printf("Press any other key to continue...\n");

        choice = getchar();

        if (choice == 'w') {
            direction = UP;
        } else if (choice =='s') {
            direction = DOWN;
        } else if (choice == 'a') {
            direction = LEFT;
        } else if (choice == 'd') {
            direction = RIGHT;
        } else if (choice =='s') {
            direction = STOP;
        }

        if (direction!= STOP) {
            printf("\n");
            printf("You are now %s at %d mph.\n", (direction == UP || direction == RIGHT)? "traveling" : "backing up", speed);
            printf("Press any key to change direction or speed...\n");
        }

        getchar();
    }

    return 0;
}