//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("Welcome to PARANOIA - The Terminal Based Game.\n\n");
    printf("In this game, you find yourself in a dark, deserted maze. Your objective is to find the exit.\n");
    printf("However, beware of the monsters lurking in the maze. If you encounter one, you will lose the game.\n");
    printf("Good luck!\n\n");

    // Initialize random seed
    srand(time(0));

    // Maze size
    int maze[5][5];

    // Initialize maze
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            maze[i][j] = rand() % 2; // 0 is an empty space, 1 is a monster
        }
    }

    // Starting position
    int x = 0;
    int y = 0;

    // Display maze
    printf("Maze:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == x && j == y) {
                printf("# ");
            } else if (maze[i][j] == 0) {
                printf(". ");
            } else {
                printf("M ");
            }
        }
        printf("\n");
    }

    // Main game loop
    while (x != 4 || y != 4) {
        // Display options
        printf("\nOptions:\n");
        printf("1. Move up\n");
        printf("2. Move down\n");
        printf("3. Move left\n");
        printf("4. Move right\n");
        printf("Choose an option: ");

        // Get user input
        int choice;
        scanf("%d", &choice);

        // Move player
        switch (choice) {
            case 1:
                if (x > 0) {
                    x--;
                }
                break;
            case 2:
                if (x < 4) {
                    x++;
                }
                break;
            case 3:
                if (y > 0) {
                    y--;
                }
                break;
            case 4:
                if (y < 4) {
                    y++;
                }
                break;
            default:
                printf("Invalid input.\n");
                break;
        }

        // Display maze
        printf("Maze:\n");
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (i == x && j == y) {
                    printf("# ");
                } else if (maze[i][j] == 0) {
                    printf(". ");
                } else {
                    printf("M ");
                }
            }
            printf("\n");
        }

        // Check for monster
        if (maze[x][y] == 1) {
            printf("You encountered a monster! You lose.\n");
            return 0;
        }
    }

    printf("Congratulations! You found the exit.\n");
    return 0;
}