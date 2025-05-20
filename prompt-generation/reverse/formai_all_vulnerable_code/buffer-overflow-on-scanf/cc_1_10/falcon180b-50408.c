//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define FORWARD 4
#define BACKWARD 5
#define STOP 6

int main() {
    int choice;
    char input[10];
    int speed = 10;
    int direction = FORWARD;
    printf("Welcome to Remote Control Vehicle Simulator!\n");
    printf("Enter your choice:\n");
    printf("1. Forward\n");
    printf("2. Backward\n");
    printf("3. Left\n");
    printf("4. Right\n");
    printf("5. Stop\n");
    scanf("%s", input);
    while(strcmp(input, "stop")!= 0) {
        switch(atoi(input)) {
            case 1:
                printf("Vehicle is moving forward.\n");
                break;
            case 2:
                printf("Vehicle is moving backward.\n");
                break;
            case 3:
                printf("Vehicle is turning left.\n");
                break;
            case 4:
                printf("Vehicle is turning right.\n");
                break;
            case 5:
                printf("Vehicle is stopped.\n");
                break;
            default:
                printf("Invalid input. Please try again.\n");
        }
        printf("Enter your choice:\n");
        scanf("%s", input);
    }
    return 0;
}