//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_X 10
#define MAX_Y 10

// moves the vehicle based on user input
void move_vehicle(int *vehicle_x, int *vehicle_y, char direction) {
    switch(direction) {
        case 'U':
            (*vehicle_y)++;
            break;
        case 'D':
            (*vehicle_y)--;
            break;
        case 'L':
            (*vehicle_x)--;
            break;
        case 'R':
            (*vehicle_x)++;
            break;
        default:
            break;
    }
}

int main() {
    int vehicle_x = MAX_X / 2;
    int vehicle_y = MAX_Y / 2;
    char grid[MAX_Y][MAX_X];
    bool running = true;
    char input;

    // initialize the grid with empty space
    for(int y=0; y<MAX_Y; y++) {
        for(int x=0; x<MAX_X; x++) {
            grid[y][x] = '-';
        }
    }

    // place the vehicle in the center of the grid
    grid[vehicle_y][vehicle_x] = 'O';

    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("Use the Up, Down, Left and Right arrow keys to move the vehicle.\n");
    printf("Press Q to quit the program.\n");
    
    while(running) {
        printf("\n");
        
        // print the grid with the vehicle
        for(int y=0; y<MAX_Y; y++) {
            for(int x=0; x<MAX_X; x++) {
                printf("%c ", grid[y][x]);
            }
            printf("\n");
        }
        
        printf("\n");

        // get user input
        input = getchar();

        // clear the input buffer
        while(getchar() != '\n');

        switch(input) {
            case 'U':
            case 'D':
            case 'L':
            case 'R':
                // move the vehicle and update the grid
                move_vehicle(&vehicle_x, &vehicle_y, input);

                if(vehicle_x >= 0 && vehicle_x < MAX_X && vehicle_y >= 0 && vehicle_y < MAX_Y) {
                    grid[vehicle_y][vehicle_x] = 'O';
                }

                // clear the previous position of the vehicle
                if(input == 'U' && vehicle_y < MAX_Y-1) {
                    grid[vehicle_y+1][vehicle_x] = '-';
                } else if(input == 'D' && vehicle_y > 0) {
                    grid[vehicle_y-1][vehicle_x] = '-';
                } else if(input == 'L' && vehicle_x < MAX_X-1) {
                    grid[vehicle_y][vehicle_x+1] = '-';
                } else if(input == 'R' && vehicle_x > 0) {
                    grid[vehicle_y][vehicle_x-1] = '-';
                }
                break;
            case 'Q':
                running = false;
                break;
            default:
                break;
        }

        //wait for 1000 microseconds to slow down the program
        usleep(1000);
    }
    
    return 0;
}