//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int x = 0, y = 0; // initial coordinates of the vehicle
    int direction = 0; // initial direction of the vehicle, 0 is North, 1 is East, 2 is South, 3 is West
    char command; // the input command from the user
    srand(time(NULL)); // initialize random seed
    
    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("The vehicle starts at (%d, %d) facing North.\n", x, y);
    
    while (1) {
        printf("Enter the command (f for forward, l for turn left, r for turn right, q for quit): ");
        scanf(" %c", &command); // space before %c to consume previous new line character
        
        switch (command) {
            case 'f':
                switch (direction) {
                    case 0:
                        y++;
                        break;
                    case 1:
                        x++;
                        break;
                    case 2:
                        y--;
                        break;
                    case 3:
                        x--;
                        break;
                    default:
                        break;
                }
                printf("Moved forward to (%d, %d)\n", x, y);
                break;
            case 'l':
                direction = (direction - 1 + 4) % 4; // turn left
                printf("Turned left, now facing ");
                switch (direction) {
                    case 0:
                        printf("North.\n");
                        break;
                    case 1:
                        printf("East.\n");
                        break;
                    case 2:
                        printf("South.\n");
                        break;
                    case 3:
                        printf("West.\n");
                        break;
                    default:
                        break;
                }
                break;
            case 'r':
                direction = (direction + 1) % 4; // turn right
                printf("Turned right, now facing ");
                switch (direction) {
                    case 0:
                        printf("North.\n");
                        break;
                    case 1:
                        printf("East.\n");
                        break;
                    case 2:
                        printf("South.\n");
                        break;
                    case 3:
                        printf("West.\n");
                        break;
                    default:
                        break;
                }
                break;
            case 'q':
                printf("Quitting...\n");
                exit(0);
            default:
                printf("Invalid command! Please try again.\n");
                break;
        }
        
        // randomly introduce an obstacle and halt the vehicle
        if (rand() % 10 == 0) {
            printf("Obstacle detected at (%d, %d)! Halted.\n", x, y);
            // reset to the previous position and direction
            switch (command) {
                case 'f':
                    switch (direction) {
                        case 0:
                            y--;
                            break;
                        case 1:
                            x--;
                            break;
                        case 2:
                            y++;
                            break;
                        case 3:
                            x++;
                            break;
                        default:
                            break;
                    }
                    break;
                case 'l':
                    direction = (direction + 1) % 4; // turn right to undo the previous left turn
                    break;
                case 'r':
                    direction = (direction - 1 + 4) % 4; // turn left to undo the previous right turn
                    break;
                default:
                    break;
            }
        }
    }
    
    return 0;
}