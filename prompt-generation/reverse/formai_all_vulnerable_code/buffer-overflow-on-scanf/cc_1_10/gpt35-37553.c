//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: beginner-friendly
#include <stdio.h>

int main() {
    //initialize drone's position
    int x = 0;
    int y = 0;
    int z = 0;

    //user input
    char move;
    int distance;

    //loop for continuous control
    while(1) {
        printf("Current position: (%d, %d, %d)\n", x, y, z);
        printf("Enter a command (u = up, d = down, f = forward, b = backward, l = left, r = right, q = quit): ");
        scanf(" %c", &move);

        if(move == 'q') {
            break; //exit loop and end program
        }

        printf("Enter distance: ");
        scanf("%d", &distance);

        switch(move) {
            case 'u':
                z += distance; //move up
                break;
            case 'd':
                z -= distance; //move down
                break;
            case 'f':
                y += distance; //move forward
                break;
            case 'b':
                y -= distance; //move backward
                break;
            case 'l':
                x -= distance; //move left
                break;
            case 'r':
                x += distance; //move right
                break;
            default:
                printf("Invalid command!\n");
                break;
        }
    }

    printf("Final position: (%d, %d, %d)\n", x, y, z);
    printf("Drone has landed.\n");

    return 0;
}