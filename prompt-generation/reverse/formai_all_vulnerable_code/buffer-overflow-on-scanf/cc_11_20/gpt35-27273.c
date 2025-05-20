//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 10                      // Define the size of the grid
#define UP 'w'                            // Define character inputs for movement
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define QUIT 'q'

int main()
{
    char grid[GRID_SIZE][GRID_SIZE];      // Declare variables for the grid and the vehicle's position
    int xpos = 0, ypos = 0;
    
    for (int i = 0; i < GRID_SIZE; i++) { // Set all values of the grid to be empty (a space character)
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = ' ';
        }
    }
    
    grid[xpos][ypos] = 'X';               // Place the vehicle at the starting position
    
    printf("Welcome to the C Remote Control Vehicle Simulation!\n\n"
           "Use the following controls to maneuver the vehicle across the grid:\n"
           "w - move up\n"
           "s - move down\n"
           "a - move left\n"
           "d - move right\n\n"
           "Input 'q' to quit the program.\n\n");
    
    while (1) {                           // Loop until the user quits
        for (int i = 0; i < GRID_SIZE; i++) { // Print out the current state of the grid
            for (int j = 0; j < GRID_SIZE; j++) {
                printf("%c ", grid[i][j]);
            }
            printf("\n");
        }
        
        char input;
        scanf(" %c", &input);             // Get user input
        
        if (input == QUIT) { 
            printf("Thanks for using the C Remote Control Vehicle Simulation!\n"); 
            exit(0);                       // Quit the program if the user specifies
        }
        
        if (input == UP) {                 // Move the vehicle based on user input
            if (xpos > 0) {
                grid[xpos][ypos] = ' ';
                xpos--;
                grid[xpos][ypos] = 'X';
            }
        }
        else if (input == DOWN) {
            if (xpos < GRID_SIZE - 1) {
                grid[xpos][ypos] = ' ';
                xpos++;
                grid[xpos][ypos] = 'X';
            }
        }
        else if (input == LEFT) {
            if (ypos > 0) {
                grid[xpos][ypos] = ' ';
                ypos--;
                grid[xpos][ypos] = 'X';
            }
        }
        else if (input == RIGHT) {
            if (ypos < GRID_SIZE - 1) {
                grid[xpos][ypos] = ' ';
                ypos++;
                grid[xpos][ypos] = 'X';
            }
        }
    }

    return 0;
}