//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: genious
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// Global variables
char maze[ROWS][COLS];
int playerRow, playerCol;

// Function prototypes
void initMaze();
void printMaze();
bool movePlayer(int, int);

int main()
{
    srand(time(NULL)); // Seed the random number generator
    initMaze(); // Initialize the maze
    printMaze(); // Print the starting maze
    
    while (true)
    {
        // Get the player's desired move direction
        char moveDirection;
        printf("Enter move (w/a/s/d): ");
        scanf(" %c", &moveDirection);
        
        // Move the player in the desired direction
        int moveRow = 0;
        int moveCol = 0;
        switch (moveDirection)
        {
            case 'w':
                moveRow = -1;
                break;
            case 'a':
                moveCol = -1;
                break;
            case 's':
                moveRow = 1;
                break;
            case 'd':
                moveCol = 1;
                break;
            default:
                printf("Invalid move. Try again.\n");
                continue;
        }
        if (movePlayer(moveRow, moveCol) == false)
        {
            printf("You hit a wall. Try again.\n");
            continue;
        }
        printMaze(); // Print the updated maze
        
        // Check if the player has won
        if (playerRow == 0 && playerCol == COLS-1)
        {
            printf("Congratulations, you escaped the haunted house!\n");
            break;
        }
    }
    
    return 0;
}

// Initialize the maze
void initMaze()
{
    // Fill the maze with walls
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            maze[r][c] = '#';
        }
    }
    
    // Carve out the starting and ending positions
    maze[ROWS-1][0] = 'S';
    maze[0][COLS-1] = 'E';
    
    // Create the random maze path
    playerRow = ROWS-1; // Start at the bottom left corner
    playerCol = 0;
    while (playerRow != 0 || playerCol != COLS-1)
    {
        if (playerRow == ROWS-1) // If player is on bottom row
        {
            playerCol++; // Move player right
        }
        else if (playerCol == COLS-1) // If player is on right column
        {
            playerRow--; // Move player up
        }
        else if (rand() % 2 == 0) // Randomly move player either up or right
        {
            playerRow--;
        }
        else
        {
            playerCol++;
        }
        maze[playerRow][playerCol] = ' '; // Remove wall at player's position
    }
}

// Print the maze to the console
void printMaze()
{
    printf("\n");
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            printf("%c ", maze[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}

// Move the player in the desired direction
bool movePlayer(int moveRow, int moveCol)
{
    // Check if move is outside the bounds of the maze
    if ((playerRow + moveRow) < 0 || (playerRow + moveRow) >= ROWS ||
        (playerCol + moveCol) < 0 || (playerCol + moveCol) >= COLS)
    {
        return false;
    }
    // Check if move hits a wall
    if (maze[playerRow + moveRow][playerCol + moveCol] == '#')
    {
        return false;
    }
    // Move the player
    maze[playerRow][playerCol] = ' ';
    playerRow += moveRow;
    playerCol += moveCol;
    maze[playerRow][playerCol] = 'P';
    return true;
}