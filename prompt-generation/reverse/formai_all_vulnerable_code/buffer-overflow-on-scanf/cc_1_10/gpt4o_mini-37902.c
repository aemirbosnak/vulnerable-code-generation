//GPT-4o-mini DATASET v1.0 Category: Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define TREASURE 'T'
#define PIT 'P'
#define EMPTY '.'
#define PLAYER 'P'

typedef struct {
    int x;
    int y;
} Position;

void initializeMaze(char maze[SIZE][SIZE], Position *player);
void displayMaze(char maze[SIZE][SIZE], Position player);
int isValidMove(int x, int y);
void movePlayer(char maze[SIZE][SIZE], Position *player, char direction);

int main() {
    char maze[SIZE][SIZE];
    Position player;
    char command;
    
    srand(time(NULL));
    initializeMaze(maze, &player);
    
    printf("Welcome to the Maze Game! Navigate to collect treasures (T) and avoid pits (P).\n");
    
    while(1) {
        displayMaze(maze, player);
        printf("Enter direction (w/a/s/d) to move, or q to quit: ");
        scanf(" %c", &command);

        if (command == 'q') {
            printf("Thanks for playing! Goodbye!\n");
            break;
        } else {
            movePlayer(maze, &player, command);
            
            // Check for treasure or pit at the new position
            if (maze[player.x][player.y] == TREASURE) {
                printf("You found a treasure! Congratulations!\n");
                maze[player.x][player.y] = EMPTY; // Remove treasure from maze
            } else if (maze[player.x][player.y] == PIT) {
                printf("Oh no! You fell into a pit! Game Over!\n");
                break;
            }
        }
    }
    return 0;
}

void initializeMaze(char maze[SIZE][SIZE], Position *player) {
    // Fill the maze with empty spaces
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            maze[i][j] = EMPTY;
        }
    }

    // Randomly place treasures and pits in the maze
    int numTreasures = 3;
    int numPits = 2;

    while (numTreasures > 0) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (maze[x][y] == EMPTY) {
            maze[x][y] = TREASURE;
            numTreasures--;
        }
    }

    while (numPits > 0) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (maze[x][y] == EMPTY) {
            maze[x][y] = PIT;
            numPits--;
        }
    }

    // Place player in the starting position
    player->x = 0;
    player->y = 0;
    maze[player->x][player->y] = PLAYER;
}

void displayMaze(char maze[SIZE][SIZE], Position player) {
    printf("\nMaze:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == player.x && j == player.y) {
                printf("%c ", PLAYER);
            } else {
                printf("%c ", maze[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int isValidMove(int x, int y) {
    return (x >= 0 && x < SIZE && y >= 0 && y < SIZE);
}

void movePlayer(char maze[SIZE][SIZE], Position *player, char direction) {
    int newX = player->x;
    int newY = player->y;

    if (direction == 'w') newX--;
    else if (direction == 's') newX++;
    else if (direction == 'a') newY--;
    else if (direction == 'd') newY++;

    if (isValidMove(newX, newY)) {
        // Update player's position
        player->x = newX;
        player->y = newY;
    } else {
        printf("Invalid move! You hit the wall.\n");
    }
}