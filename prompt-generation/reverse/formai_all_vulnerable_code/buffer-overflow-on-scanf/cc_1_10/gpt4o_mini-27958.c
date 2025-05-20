//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 5
#define TREASURE 'T'
#define TRAP 'X'
#define EMPTY '.'
#define PLAYER 'P'
#define MAX_TREASURES 5
#define MAX_TRAPS 5

typedef struct {
    int x;
    int y;
} Player;

char grid[SIZE][SIZE];
Player player;
int treasures_collected = 0;

void initialize_grid() {
    // Fill the grid with empty spaces
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = EMPTY;
        }
    }

    // Place traps
    for (int i = 0; i < MAX_TRAPS;) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (grid[x][y] == EMPTY) {
            grid[x][y] = TRAP;
            i++;
        }
    }

    // Place treasures
    for (int i = 0; i < MAX_TREASURES;) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (grid[x][y] == EMPTY) {
            grid[x][y] = TREASURE;
            i++;
        }
    }
}

void place_player() {
    player.x = rand() % SIZE;
    player.y = rand() % SIZE;
    // Ensure the player does not start on a trap or treasure
    while (grid[player.x][player.y] != EMPTY) {
        player.x = rand() % SIZE;
        player.y = rand() % SIZE;
    }
    
    grid[player.x][player.y] = PLAYER;
}

void display_grid() {
    printf("\nCurrent Grid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == player.x && j == player.y) {
                printf("%c ", PLAYER);
            } else {
                printf("%c ", grid[i][j]);
            }
        }
        printf("\n");
    }
    printf("Treasures Collected: %d\n", treasures_collected);
}

void move_player(char direction) {
    int new_x = player.x;
    int new_y = player.y;

    switch (direction) {
        case 'w': new_x--; break; // Up
        case 's': new_x++; break; // Down
        case 'a': new_y--; break; // Left
        case 'd': new_y++; break; // Right
        default:  printf("Invalid direction. Use 'w', 'a', 's', or 'd'.\n"); return;
    }

    // Check boundaries
    if (new_x < 0 || new_x >= SIZE || new_y < 0 || new_y >= SIZE) {
        printf("You can't move outside the grid!\n");
        return;
    }

    // Update player position
    if (grid[new_x][new_y] == TRAP) {
        printf("You landed on a trap! Game Over.\n");
        exit(0);
    } else if (grid[new_x][new_y] == TREASURE) {
        treasures_collected++;
        printf("You found a treasure! Total treasures: %d\n", treasures_collected);
    }

    // Move the player
    grid[player.x][player.y] = EMPTY;
    player.x = new_x;
    player.y = new_y;
    grid[player.x][player.y] = PLAYER;
    display_grid();
}

int main() {
    srand(time(NULL));
    initialize_grid();
    place_player();
    display_grid();

    char choice;
    printf("Use 'w' to move up, 's' to move down, 'a' to move left, 'd' to move right. Press 'q' to quit the game.\n");

    while (1) {
        printf("Next move: ");
        scanf(" %c", &choice);
        if (choice == 'q') {
            printf("Thanks for playing! You collected %d treasures.\n", treasures_collected);
            break;
        }
        move_player(choice);
    }

    return 0;
}