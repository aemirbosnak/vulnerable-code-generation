//FormAI DATASET v1.0 Category: Robot movement control ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to generate random values for robot movements
int randomMovement() {
    srand(time(NULL));
    int value = rand()%5;
    return value;
}

int main() {
    
    int coordinates[2] = {0, 0}; //initial coordinates of the robot
    int move, x, y;
    char direction;
    
    printf("Welcome to the Robot Movement Control Program!\n");
    printf("Starting at coordinates %d, %d\n", coordinates[0], coordinates[1]);
    
    //start loop for robot movements
    for(int i = 1; i <= 10; i++) {
        move = randomMovement();
        switch(move) {
            case 0:
                printf("Movement %d: Move forward\n", i);
                direction = 'N';
                y += 1;
                break;
            case 1:
                printf("Movement %d: Turn left and move forward\n", i);
                direction = 'W';
                x -= 1;
                break;
            case 2:
                printf("Movement %d: Turn right and move forward\n", i);
                direction = 'E';
                x += 1;
                break;
            case 3:
                printf("Movement %d: Move backwards\n", i);
                direction = 'S';
                y -= 1;
                break;
            case 4:
                printf("Movement %d: Stay in place\n", i);
                direction = 'M';
                break;
        }
        
        //print out the coordinates and direction after each movement
        if(move != 4) {
            printf("New coordinates: %d, %d\n", x, y);
            printf("New direction: %c\n", direction);
        } else {
            printf("Coordinates and direction remain the same.\n");
        }
    }
    
    printf("Thank you for using the Robot Movement Control Program!\n");
    
    return 0;
}