//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: safe
#include <stdio.h>

typedef struct {
    int x;
    int y;
} point;

int main()
{
    int width = 100; // width of the vehicle
    int height = 50; // height of the vehicle
    int speed = 10; // speed of the vehicle

    point position = {0, 0}; // starting position of the vehicle
    point direction = {1, 0}; // starting direction of the vehicle

    printf("Remote Control Vehicle Simulation\n\n");

    while (1) {
        // read input from user
        char input;
        printf("Enter command (L/R/F/B): ");
        scanf("%c", &input);

        // move the vehicle based on user input
        switch (input) {
            case 'L':
                // turn left
                if (direction.x == 0 && direction.y == 1) { // facing up
                    direction.x = -1;
                    direction.y = 0;
                }
                else if (direction.x == -1 && direction.y == 0) { // facing left
                    direction.x = 0;
                    direction.y = -1;
                }
                else if (direction.x == 0 && direction.y == -1) { // facing down
                    direction.x = 1;
                    direction.y = 0;
                }
                else if (direction.x == 1 && direction.y == 0) { // facing right
                    direction.x = 0;
                    direction.y = 1;
                }
                break;
            case 'R':
                // turn right
                if (direction.x == 0 && direction.y == 1) { // facing up
                    direction.x = 1;
                    direction.y = 0;
                }
                else if (direction.x == 1 && direction.y == 0) { // facing right
                    direction.x = 0;
                    direction.y = -1;
                }
                else if (direction.x == 0 && direction.y == -1) { // facing down
                    direction.x = -1;
                    direction.y = 0;
                }
                else if (direction.x == -1 && direction.y == 0) { // facing left
                    direction.x = 0;
                    direction.y = 1;
                }
                break;
            case 'F':
                // move forward
                position.x += direction.x * speed;
                position.y += direction.y * speed;
                break;
            case 'B':
                // move backward
                position.x -= direction.x * speed;
                position.y -= direction.y * speed;
                break;
            default:
                printf("Invalid command\n");
                break;
        }

        // make sure the vehicle stays within the screen area
        if (position.x < 0) {
            position.x = 0;
        }
        else if (position.x > (width - 1)) {
            position.x = width - 1;
        }
        if (position.y < 0) {
            position.y = 0;
        }
        else if (position.y > (height - 1)) {
            position.y = height - 1;
        }

        // draw the screen with the vehicle in its new position
        printf("\033[2J"); // clear screen
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (i == position.y && j == position.x) {
                    // print the vehicle symbol
                    printf("#");
                }
                else {
                    // print empty space
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}