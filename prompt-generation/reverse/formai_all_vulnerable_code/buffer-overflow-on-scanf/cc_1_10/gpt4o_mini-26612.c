//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 5
#define MAX_OBSTACLES 5

typedef struct {
    int x;
    int y;
} Position;

char grid[GRID_SIZE][GRID_SIZE];
Position player = {0, 0};
Position destination = {GRID_SIZE - 1, GRID_SIZE - 1};

void initializeGrid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '.';
        }
    }

    // Place obstacles
    int obstacles = 0;
    while (obstacles < MAX_OBSTACLES) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        if ((x != player.x || y != player.y) && (x != destination.x || y != destination.y) && grid[x][y] == '.') {
            grid[x][y] = '#'; // obstacle
            obstacles++;
        }
    }

    // Mark player and destination
    grid[player.x][player.y] = 'P';
    grid[destination.x][destination.y] = 'D';
}

void printGrid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(Position newPos) {
    return (newPos.x >= 0 && newPos.x < GRID_SIZE && newPos.y >= 0 && newPos.y < GRID_SIZE) && (grid[newPos.x][newPos.y] != '#');
}

void makeMove(char direction) {
    Position newPos = player;

    switch (direction) {
        case 'w': newPos.x--; break; // up
        case 's': newPos.x++; break; // down
        case 'a': newPos.y--; break; // left
        case 'd': newPos.y++; break; // right
        default: printf("Invalid move! Use w (up), a (left), s (down), d (right).\n"); return;
    }

    if (isValidMove(newPos)) {
        grid[player.x][player.y] = '.'; // clear old position
        player = newPos;
        grid[player.x][player.y] = 'P'; // update new position
    } else {
        printf("Blocked! Can't move there.\n");
    }
}

int checkVictory() {
    return (player.x == destination.x && player.y == destination.y);
}

int main() {
    srand(time(0)); // seed random number generator
    initializeGrid();
    
    while (1) {
        printf("\nCurrent Position: (%d, %d)\n", player.x, player.y);
        printGrid();
        
        if (checkVictory()) {
            printf("Congratulations! You've reached the destination!\n");
            break;
        }

        char move;
        printf("Enter your move (w/a/s/d): ");
        scanf(" %c", &move);
        makeMove(move);
    }

    return 0;
}