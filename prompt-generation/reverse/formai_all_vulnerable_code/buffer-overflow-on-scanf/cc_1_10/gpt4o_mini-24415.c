//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define GRID_SIZE 20

char grid[GRID_SIZE][GRID_SIZE];

// Function declarations
void initGrid();
void printGrid();
void drawLine(int x1, int y1, int x2, int y2);
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3);
void getPlayerInput(int playerId);
void welcomeMessage();

int main() {
    int numPlayers;

    welcomeMessage();

    printf("Enter the number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);
    
    if (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    initGrid();

    for (int i = 0; i < numPlayers; ++i) {
        getPlayerInput(i + 1);
        printGrid();
    }

    return 0;
}

void initGrid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '.';
        }
    }
}

void printGrid() {
    printf("\nCurrent Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        if (x1 >= 0 && x1 < GRID_SIZE && y1 >= 0 && y1 < GRID_SIZE) {
            grid[y1][x1] = '#';
        }
        if (x1 == x2 && y1 == y2) break;
        int err2 = err * 2;
        if (err2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (err2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    drawLine(x1, y1, x2, y2);
    drawLine(x2, y2, x3, y3);
    drawLine(x3, y3, x1, y1);
}

void getPlayerInput(int playerId) {
    int shapeChoice;
    printf("Player %d, choose a shape to draw (1: Line, 2: Triangle): ", playerId);
    scanf("%d", &shapeChoice);
    
    if (shapeChoice == 1) {
        int x1, y1, x2, y2;
        printf("Enter coordinates for the line (x1 y1 x2 y2): ");
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        drawLine(x1, y1, x2, y2);
    } else if (shapeChoice == 2) {
        int x1, y1, x2, y2, x3, y3;
        printf("Enter coordinates for the triangle (x1 y1 x2 y2 x3 y3): ");
        scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
        drawTriangle(x1, y1, x2, y2, x3, y3);
    } else {
        printf("Invalid choice. Try again.\n");
        --playerId; // To retry for the same player
    }
}

void welcomeMessage() {
    printf("Welcome to the Geometric Drawing Game!\n");
    printf("You will draw shapes on a grid. Have fun!\n");
}