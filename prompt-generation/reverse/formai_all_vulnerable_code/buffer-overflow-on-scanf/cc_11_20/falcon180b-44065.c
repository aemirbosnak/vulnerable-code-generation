//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define STOP 5
#define FORWARD 6
#define BACKWARD 7
#define TURNRIGHT 8
#define TURNLEFT 9
#define SPEED 10

int main() {
    int choice;
    int speed = 0;
    int turn = 0;
    int direction = 0;

    srand(time(NULL));

    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == UP) {
            printf("Vehicle is moving forward.\n");
        }
        else if(choice == DOWN) {
            printf("Vehicle is moving backward.\n");
        }
        else if(choice == LEFT) {
            printf("Vehicle is turning left.\n");
        }
        else if(choice == RIGHT) {
            printf("Vehicle is turning right.\n");
        }
        else if(choice == STOP) {
            printf("Vehicle has stopped.\n");
        }
        else if(choice == FORWARD) {
            printf("Vehicle is moving forward with speed: ");
            scanf("%d", &speed);
            printf("Vehicle is moving forward with speed: %d\n", speed);
        }
        else if(choice == BACKWARD) {
            printf("Vehicle is moving backward with speed: ");
            scanf("%d", &speed);
            printf("Vehicle is moving backward with speed: %d\n", speed);
        }
        else if(choice == TURNRIGHT) {
            printf("Vehicle is turning right with speed: ");
            scanf("%d", &speed);
            printf("Vehicle is turning right with speed: %d\n", speed);
        }
        else if(choice == TURNLEFT) {
            printf("Vehicle is turning left with speed: ");
            scanf("%d", &speed);
            printf("Vehicle is turning left with speed: %d\n", speed);
        }
        else if(choice == SPEED) {
            printf("Enter the speed: ");
            scanf("%d", &speed);
            printf("Vehicle is moving forward with speed: %d\n", speed);
        }
        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}