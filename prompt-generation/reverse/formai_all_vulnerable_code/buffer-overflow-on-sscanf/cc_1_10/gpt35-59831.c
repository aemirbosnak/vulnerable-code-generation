//FormAI DATASET v1.0 Category: Robot movement control ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

//Constants for different robot movements
#define FORWARD 1
#define BACKWARD -1
#define LEFT 2
#define RIGHT -2

//Function to simulate robot's movement
void move_robot(int direction, int distance) {
    switch(direction) {
        case FORWARD:
            printf("Moving forward by %d units.\n",distance);
            break;
        case BACKWARD:
            printf("Moving backward by %d units.\n",distance);
            break;
        case LEFT:
            printf("Turning left and moving by %d units.\n",distance);
            break;
        case RIGHT:
            printf("Turning right and moving by %d units.\n",distance);
            break;
        default:
            printf("Invalid input.\n");
    }
}

int main() {
    int direction, distance;
    char input[20];

    printf("Welcome to the Robot Movement Control Program!\n");

    while(1) {
        printf("\nEnter the movement command (e.g. forward 10): ");
        fgets(input, 20, stdin);
        sscanf(input, "%s %d", &direction, &distance);

        //Convert string input to corresponding constant
        if(strcmp(direction, "forward") == 0)
            direction = FORWARD;
        else if(strcmp(direction, "backward") == 0)
            direction = BACKWARD;
        else if(strcmp(direction, "left") == 0)
            direction = LEFT;
        else if(strcmp(direction, "right") == 0)
            direction = RIGHT;
        else {
            printf("\nInvalid direction. Please try again.\n");
            continue;
        }

        //Verify if distance input is valid
        if(distance <= 0)
            printf("\nDistance should be a positive number. Please try again.\n");
        else
            move_robot(direction, distance);
    }

    return 0;
}