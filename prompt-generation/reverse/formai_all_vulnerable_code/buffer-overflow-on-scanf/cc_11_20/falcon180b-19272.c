//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define MIN_SPEED 1
#define TURN_RATE 5

int main() {
    int speed = MIN_SPEED;
    int turn = 0;
    int move = 0;
    int choice;

    srand(time(NULL));

    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("Use the following keys to control your vehicle:\n");
    printf("1. Increase speed\n");
    printf("2. Decrease speed\n");
    printf("3. Turn left\n");
    printf("4. Turn right\n");
    printf("5. Move forward\n");
    printf("6. Move backward\n");
    printf("7. Stop\n");

    while(1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                speed += rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
                printf("Speed increased to %d\n", speed);
                break;
            case 2:
                speed -= rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
                printf("Speed decreased to %d\n", speed);
                break;
            case 3:
                turn = TURN_RATE;
                move = 0;
                printf("Turning left...\n");
                break;
            case 4:
                turn = -TURN_RATE;
                move = 0;
                printf("Turning right...\n");
                break;
            case 5:
                move = 1;
                printf("Moving forward...\n");
                break;
            case 6:
                move = -1;
                printf("Moving backward...\n");
                break;
            case 7:
                speed = 0;
                move = 0;
                printf("Stopped\n");
                break;
        }

        if(move == 0) {
            printf("Current speed: %d\n", speed);
        } else {
            printf("Moving at %d units per second\n", speed);
        }

        if(turn!= 0) {
            int direction = rand() % 2;

            if(direction == 0) {
                turn = -turn;
            }

            printf("Turning %d degrees per second\n", turn);
        }

        if(move!= 0) {
            int distance = speed * move;

            printf("Moving %d units in the current direction\n", distance);

            if(move > 0) {
                printf("Current position: %d\n", 0);
            } else {
                printf("Current position: -%d\n", 0);
            }
        }

        printf("\n");
    }

    return 0;
}