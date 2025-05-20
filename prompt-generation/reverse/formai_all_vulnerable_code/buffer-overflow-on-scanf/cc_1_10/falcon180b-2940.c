//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: portable
#include <stdio.h>

#define LENGTH 10 // length of the vehicle
#define WIDTH 5 // width of the vehicle
#define SPEED 2 // speed of the vehicle

void drawVehicle() {
    printf("Vehicle:");
    for(int i=0; i<LENGTH; i++) {
        printf("-");
    }
    printf("\n");
}

void moveVehicle() {
    printf("Vehicle is moving...\n");
    for(int i=0; i<SPEED; i++) {
        printf("\b"); // move the vehicle backwards by one position
        printf("-"); // draw the vehicle in the new position
    }
}

void turnLeft() {
    printf("Vehicle is turning left...\n");
    printf("Vehicle:");
    for(int i=0; i<LENGTH; i++) {
        if(i == 0 || i == LENGTH-1) {
            printf("-");
        } else if(i == 3) {
            printf("/");
        } else if(i == 7) {
            printf("\\");
        } else {
            printf(" ");
        }
    }
    printf("\n");
}

void turnRight() {
    printf("Vehicle is turning right...\n");
    printf("Vehicle:");
    for(int i=0; i<LENGTH; i++) {
        if(i == 0 || i == LENGTH-1) {
            printf("-");
        } else if(i == 3) {
            printf("\\");
        } else if(i == 7) {
            printf("/");
        } else {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    printf("Remote Control Vehicle Simulation\n");
    printf("Commands:\n");
    printf("1. Move forward\n");
    printf("2. Turn left\n");
    printf("3. Turn right\n");
    printf("4. Stop\n");

    int choice;
    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: // move forward
                moveVehicle();
                break;
            case 2: // turn left
                turnLeft();
                break;
            case 3: // turn right
                turnRight();
                break;
            case 4: // stop
                printf("Vehicle stopped.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}