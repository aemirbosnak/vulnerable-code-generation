//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 10
#define COLS 10
#define BOMB_COUNT 10

int generate_bomb(int seed){
    srand(seed);
    return rand() % 10;
}

int main(){
    int bombs[10];
    int i, j, row, col, bomb_x, bomb_y, bomb_placed = 0;
    char grid[ROWS][COLS];
    
    
    // Set initial values of grid to untouched state
    for(i=0; i<ROWS; i++){
        for(j=0; j<COLS; j++){
            grid[i][j] = '.';
        }
    }

    // Generate bomb locations
    srand(time(0));
    for(i=0; i<BOMB_COUNT; i++){
        bomb_x = generate_bomb(rand());
        bomb_y = generate_bomb(rand());

        // Check if a bomb is already placed in the same location
        if(grid[bomb_x][bomb_y] == '*'){
            i--;
            continue;
        }

        bombs[i] = 10 * bomb_x + bomb_y; // Save the bomb position in bombs array
        grid[bomb_x][bomb_y] = '*'; // Update the grid with the bomb position
        bomb_placed++;
    }

    while(1){
        printf(" ");

        // Print the column numbers
        for(i=0; i<COLS; i++){
            printf("%d ", i);
        }
        printf("\n");

        // Print the grid with row numbers
        for(i=0; i<ROWS; i++){
            printf("%d ", i);

            for(j=0; j<COLS; j++){
                printf("%c ", grid[i][j]);
            }

            printf("\n");
        }

        // Get user input
        printf("Enter row and column: ");
        scanf("%d%d", &row, &col);

        if(grid[row][col] == '*'){
            printf("Bomb hit! Game over.\n");
            break;
        }

        printf("You missed the bomb. Try again.\n");
        grid[row][col] = 'X';

        // Check if all bombs are found
        if(bomb_placed == BOMB_COUNT){
            printf("Congratulations! You found all the bombs.\n");
            break;
        }
    }

    return 0;
}