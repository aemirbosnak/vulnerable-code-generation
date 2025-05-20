//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct {
    int x;
    int y;
} Position;

char maze[MAX_SIZE][MAX_SIZE] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', '#', 'T', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', '#', '#', '#', '#', ' ', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', ' ', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'T', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

void printMaze(Position player) {
    system("clear"); // clear the console (Linux command)
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            if (i == player.x && j == player.y) {
                printf("P "); // Player's position
            } else {
                printf("%c ", maze[i][j]);
            }
        }
        printf("\n");
    }
}

int movePlayer(Position *player, char direction) {
    int newX = player->x;
    int newY = player->y;

    if (direction == 'w') newX--; // Move Up
    else if (direction == 's') newX++; // Move Down
    else if (direction == 'a') newY--; // Move Left
    else if (direction == 'd') newY++; // Move Right

    if (newX < 0 || newX >= MAX_SIZE || newY < 0 || newY >= MAX_SIZE || maze[newX][newY] == '#') {
        printf("You can't move in that direction!\n");
        return 0; // Invalid move
    }
    
    player->x = newX;
    player->y = newY;

    return 1; // Valid move
}

void checkTreasure(Position player) {
    if (maze[player.x][player.y] == 'T') {
        printf("You found a treasure!\n");
        maze[player.x][player.y] = ' '; // Remove treasure after collecting
    }
}

int main() {
    Position player = {1, 1}; // Starting position
    char command;
    
    printf("Welcome to the Maze Adventure Game!\n");
    printf("Commands:\n");
    printf("w: Move Up\n");
    printf("s: Move Down\n");
    printf("a: Move Left\n");
    printf("d: Move Right\n");
    printf("q: Quit the game\n");
    
    while (1) {
        printMaze(player);
        printf("Enter your move: ");
        scanf(" %c", &command);
        
        if (command == 'q') {
            printf("Thanks for playing!\n");
            break;
        }

        if (movePlayer(&player, command)) {
            checkTreasure(player);
        }
    }

    return 0;
}