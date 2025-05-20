//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 5
#define MAX_TREASURES 3
#define MAX_TRAPS 3

char grid[GRID_SIZE][GRID_SIZE];
int treasures[MAX_TREASURES][2];
int traps[MAX_TRAPS][2];
int player_x, player_y;

void initializeGrid() {
    for (int i = 0; i < GRID_SIZE; i++)
        for (int j = 0; j < GRID_SIZE; j++)
            grid[i][j] = '.';

    // Set treasures and traps
    for (int i = 0; i < MAX_TREASURES; i++) {
        int x, y;
        do {
            x = rand() % GRID_SIZE;
            y = rand() % GRID_SIZE;
        } while (grid[x][y] != '.');
        grid[x][y] = 'T';  // Place treasure
        treasures[i][0] = x;
        treasures[i][1] = y;
    }

    for (int i = 0; i < MAX_TRAPS; i++) {
        int x, y;
        do {
            x = rand() % GRID_SIZE;
            y = rand() % GRID_SIZE;
        } while (grid[x][y] != '.');
        grid[x][y] = 'X';  // Place trap
        traps[i][0] = x;
        traps[i][1] = y;
    }

    // Set player start position
    player_x = 0;
    player_y = 0;
    grid[player_x][player_y] = 'P';  // Place player
}

void printGrid() {
    printf("\nCurrent Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int movePlayer(char direction) {
    grid[player_x][player_y] = '.';  // Clear current position

    if (direction == 'w' && player_x > 0)       player_x--;
    else if (direction == 's' && player_x < GRID_SIZE - 1) player_x++;
    else if (direction == 'a' && player_y > 0)       player_y--;
    else if (direction == 'd' && player_y < GRID_SIZE - 1) player_y++;

    if (grid[player_x][player_y] == 'T') {
        printf("You've found a treasure!\n");
        grid[player_x][player_y] = 'P';  // Mark player position
        return 1;  // Found treasure
    } else if (grid[player_x][player_y] == 'X') {
        printf("You've hit a trap! Game Over.\n");
        return -1;  // Hit trap
    } else {
        grid[player_x][player_y] = 'P';  // Mark player position
        return 0;  // Just moved
    }
}

int main() {
    srand(time(NULL));
    initializeGrid();

    int treasures_found = 0;
    char input;

    while (treasures_found < MAX_TREASURES) {
        printGrid();
        printf("Move (w/a/s/d): ");
        scanf(" %c", &input);  // Get user input

        int move_result = movePlayer(input);

        if (move_result > 0) {
            treasures_found++;
            printf("Total Treasures Found: %d/%d\n", treasures_found, MAX_TREASURES);
        } else if (move_result < 0) {
            printGrid();
            printf("Game Over! You found %d treasures.\n", treasures_found);
            break;
        }
    }

    if (treasures_found == MAX_TREASURES) {
        printGrid();
        printf("Congratulations! You've found all treasures!\n");
    }

    return 0;
}