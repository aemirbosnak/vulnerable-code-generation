//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void startGame();
void displayMenu();
void movePlayer(int direction);
void generateMaze();
void printMaze();
int checkWin();

int main() {
    srand(time(NULL));
    startGame();
    return 0;
}

// Start the game
void startGame() {
    int playerX = 0, playerY = 0;
    int maze[10][10];
    generateMaze(maze);
    while (1) {
        system("clear");
        printMaze(maze);
        displayMenu();
        int choice;
        scanf("%d", &choice);
        movePlayer(choice);
        if (checkWin(playerX, playerY)) {
            printf("Congratulations, you've won the game!");
            break;
        }
    }
}

// Display the menu
void displayMenu() {
    printf("\n");
    printf("Choose a direction:\n");
    printf("1. Up\n");
    printf("2. Down\n");
    printf("3. Left\n");
    printf("4. Right\n");
}

// Move the player
void movePlayer(int direction) {
    int playerX = 0, playerY = 0;
    int maze[10][10];
    switch (direction) {
        case 1:
            if (playerY > 0 && maze[playerX][playerY - 1]!= 1) {
                playerY--;
            }
            break;
        case 2:
            if (playerY < 9 && maze[playerX][playerY + 1]!= 1) {
                playerY++;
            }
            break;
        case 3:
            if (playerX > 0 && maze[playerX - 1][playerY]!= 1) {
                playerX--;
            }
            break;
        case 4:
            if (playerX < 9 && maze[playerX + 1][playerY]!= 1) {
                playerX++;
            }
            break;
    }
}

// Generate the maze
void generateMaze(int maze[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            maze[i][j] = rand() % 2;
        }
    }
}

// Print the maze
void printMaze(int maze[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (maze[i][j] == 0) {
                printf("  ");
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
}

// Check if the player has won
int checkWin(int playerX, int playerY) {
    if (playerX == 9 && playerY == 9) {
        return 1;
    }
    return 0;
}