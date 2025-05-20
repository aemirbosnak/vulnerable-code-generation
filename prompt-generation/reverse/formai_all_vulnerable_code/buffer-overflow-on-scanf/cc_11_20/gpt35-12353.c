//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>     // for rand() and srand()
#include <time.h>       // for time()

int main() {
    srand(time(NULL));  // seed the random number generator
    
    int posx = 0;       // x position of the RC vehicle
    int posy = 0;       // y position of the RC vehicle
    int dir = 0;        // direction the RC vehicle is facing (0-3, where 0 is north)
    
    printf("Welcome to the RC vehicle simulation!\n");
    
    // while loop to keep the simulation running
    while (1) {
        printf("\nCurrent position: (%d,%d)\n", posx, posy);
        printf("Current direction: ");
        switch (dir) {
            case 0:
                printf("North\n");
                break;
            case 1:
                printf("East\n");
                break;
            case 2:
                printf("South\n");
                break;
            case 3:
                printf("West\n");
                break;
            default:
                printf("Invalid direction\n");
                break;
        }
        
        int option;     // variable to store user's menu choice
        
        // print the menu
        printf("\nMain Menu:\n");
        printf("1. Move Forward\n");
        printf("2. Turn Right\n");
        printf("3. Turn Left\n");
        printf("4. Exit\n\n");
        
        printf("Enter your choice: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:     // move forward
                switch (dir) {
                    case 0:
                        posy += 1;
                        break;
                    case 1:
                        posx += 1;
                        break;
                    case 2:
                        posy -= 1;
                        break;
                    case 3:
                        posx -= 1;
                        break;
                }
                printf("\nMoved forward!\n");
                break;
            case 2:     // turn right
                dir += 1;
                if (dir > 3) {
                    dir = 0;
                }
                printf("\nTurned right!\n");
                break;
            case 3:     // turn left
                dir -= 1;
                if (dir < 0) {
                    dir = 3;
                }
                printf("\nTurned left!\n");
                break;
            case 4:     // exit
                printf("\nExiting simulation. Goodbye!\n");
                exit(0);
            default:    // invalid choice
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
        
        // randomly generate an obstacle and see if the RC vehicle hits it
        int obstacle_x = rand() % 10;
        int obstacle_y = rand() % 10;
        if (posx == obstacle_x && posy == obstacle_y) {
            printf("\nOops, you hit an obstacle at (%d,%d)!\n", obstacle_x, obstacle_y);
            break;
        }
    }
    
    return 0;
}