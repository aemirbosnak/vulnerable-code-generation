//FormAI DATASET v1.0 Category: Game ; Style: genious
#include <stdio.h>
#include <stdlib.h>

int main() {

    int mapSize = 8;
    char map[8][8] = {
        {'#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', '#', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', '#', '#', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#'}};
    // Initialize the map
    
    int playerPosX = 1, playerPosY = 7;
    // Starting position of player
    
    while (1) {
        system("cls"); // Clear the console
        for (int i = 0; i < mapSize; i++) {
            for (int j = 0; j < mapSize; j++) {
                if (i == playerPosY && j == playerPosX) {
                    printf("P"); // Print player
                } else {
                    printf("%c", map[i][j]); // Print wall or empty space
                }
            }
            printf("\n");
        }
        int dx = 0, dy = 0;
        char input = getchar(); // Get player input
        switch (input) {
            case 'W':
            case 'w':
                dy = -1; // Move player up
                break;
            case 'S':
            case 's':
                dy = 1; // Move player down
                break;
            case 'A':
            case 'a':
                dx = -1; // Move player left
                break;
            case 'D':
            case 'd':
                dx = 1; // Move player right
                break;
            default:
                break;
        }
        if (map[playerPosY + dy][playerPosX + dx] != '#') {
            playerPosY += dy;
            playerPosX += dx; // Update player position
        }
    }

    return 0;
}