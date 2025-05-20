//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 10
#define MIN_SPEED 1
#define MAX_DIRECTION 180
#define MIN_DIRECTION 0

typedef struct {
    int speed;
    int direction;
} RCvehicle;

int main() {
    RCvehicle car;
    car.speed = MIN_SPEED;
    car.direction = MIN_DIRECTION;
    
    while (1) {
        // Get user input
        char input;
        printf("Enter a command (a)ccelerate, (d)ecelerate, (t)urn left, (r)urn right, (s)top, or (q)uit\n");
        scanf(" %c", &input);
        
        // Handle input
        switch(input) {
            case 'a':
                if (car.speed < MAX_SPEED) {
                    car.speed++;
                    printf("Speed: %d\n", car.speed);
                } else {
                    printf("Already at maximum speed!\n");
                }
                break;
            case 'd':
                if (car.speed > MIN_SPEED) {
                    car.speed--;
                    printf("Speed: %d\n", car.speed);
                } else {
                    printf("Already at minimum speed!\n");
                }
                break;
            case 't':
                if (car.direction < MAX_DIRECTION) {
                    car.direction++;
                    printf("Direction: %d\n", car.direction);
                } else {
                    printf("Already turned all the way left!\n");
                }
                break;
            case 'r':
                if (car.direction > MIN_DIRECTION) {
                    car.direction--;
                    printf("Direction: %d\n", car.direction);
                } else {
                    printf("Already turned all the way right!\n");
                }
                break;
            case 's':
                car.speed = MIN_SPEED;
                printf("Speed: %d\n", car.speed);
                break;
            case 'q':
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid command!\n");
                break;
        }
    }
    
    return 0;
}