//FormAI DATASET v1.0 Category: Robot movement control ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

int main() {
    int current_x = 0, current_y = 0; // starting position
    char direction = 'N'; // starting direction
    int steps;

    printf("Starting position: (%d,%d), facing %c\n", current_x, current_y, direction);

    // get user input for steps
    printf("Enter number of steps: ");
    scanf("%d", &steps);

    for(int i = 1; i <= steps; i++) {
        // randomly generate movement direction (left, right, forward)
        int move = rand() % 3; // possible values: 0, 1, 2

        // handle movement and update position and direction accordingly
        switch(move) {
            case 0:
                // turn left
                switch(direction) {
                    case 'N':
                        direction = 'W';
                        break;
                    case 'E':
                        direction = 'N';
                        break;
                    case 'S':
                        direction = 'E';
                        break;
                    case 'W':
                        direction = 'S';
                        break;
                }
                break;
            case 1:
                // turn right
                switch(direction) {
                    case 'N':
                        direction = 'E';
                        break;
                    case 'E':
                        direction = 'S';
                        break;
                    case 'S':
                        direction = 'W';
                        break;
                    case 'W':
                        direction = 'N';
                        break;
                }
                break;
            case 2:
                // move forward
                switch(direction) {
                    case 'N':
                        current_y++;
                        break;
                    case 'E':
                        current_x++;
                        break;
                    case 'S':
                        current_y--;
                        break;
                    case 'W':
                        current_x--;
                        break;
                }
                break;
        }

        // print current position and direction
        printf("Step %d: moved %s, now at (%d,%d) facing %c\n",
               i,
               (move == 0 ? "left" : (move == 1 ? "right" : "forward")),
               current_x,
               current_y,
               direction);
    }

    return 0;
}