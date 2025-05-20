//FormAI DATASET v1.0 Category: Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10  /* The size of the game grid */

/* Function to print the current state of the grid */
void print_grid(char grid[][GRID_SIZE]){
    for(int i=0; i<GRID_SIZE; i++){
        for(int j=0; j<GRID_SIZE; j++){
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

/* Function to get user input and update the grid accordingly */
void update_grid(char grid[][GRID_SIZE]){
    int x, y;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter y: ");
    scanf("%d", &y);

    if(grid[x][y] == '#'){
        printf("Oops, you hit a mine!\n");
        exit(0);
    } else {
        grid[x][y] = '+';
        printf("Good move!\n");
    }
}

int main(){
    char grid[GRID_SIZE][GRID_SIZE];
    int num_of_mines = 10;

    /* Initialize the grid */
    for(int i=0; i<GRID_SIZE; i++){
        for(int j=0; j<GRID_SIZE; j++){
            grid[i][j] = '.';
        }
    }

    /* Add mines randomly to the grid */
    srand(time(NULL));
    for(int i=0; i<num_of_mines; i++){
        int x = rand()%GRID_SIZE;
        int y = rand()%GRID_SIZE;
        grid[x][y] = '#';
    }

    printf("Welcome to the Minefield!\n");
    printf("Try to reach the end without hitting a mine.\n");

    /* Loop to play the game */
    while(1){
        print_grid(grid);
        update_grid(grid);
    }

    return 0;
}