//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAP_SIZE 10
#define NUM_TREASURES 5
#define MAX_NAME_LEN 20

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    char name[MAX_NAME_LEN];
    Position position;
    int treasures_collected;
} Player;

char map[MAP_SIZE][MAP_SIZE];
Player player;

void initializeMap() {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = '.';
        }
    }
}

void placeTreasures() {
    srand(time(NULL));
    for (int i = 0; i < NUM_TREASURES; ) {
        int x = rand() % MAP_SIZE;
        int y = rand() % MAP_SIZE;
        
        if (map[x][y] == '.') {
            map[x][y] = 'T'; // Treasure
            i++;
        }
    }
}

void printMap() {
    printf("\n");
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (i == player.position.x && j == player.position.y) {
                printf("P "); // Player
            } else {
                printf("%c ", map[i][j]);
            }
        }
        printf("\n");
    }
}

void movePlayer(char direction) {
    int new_x = player.position.x;
    int new_y = player.position.y;

    switch (direction) {
        case 'w': new_x--; break; // Move up
        case 's': new_x++; break; // Move down
        case 'a': new_y--; break; // Move left
        case 'd': new_y++; break; // Move right
        default: printf("Invalid move! Use W/A/S/D to move.\n"); return;
    }

    if (new_x >= 0 && new_x < MAP_SIZE && new_y >= 0 && new_y < MAP_SIZE) {
        player.position.x = new_x;
        player.position.y = new_y;

        if (map[new_x][new_y] == 'T') {
            player.treasures_collected++;
            map[new_x][new_y] = '.'; // Remove treasure from map
            printf("You found a treasure! Total treasures: %d\n", player.treasures_collected);
        }
    } else {
        printf("You can't move outside the map!\n");
    }
}

void displayInstructions() {
    printf("Welcome to the Treasure Hunt Game!\n");
    printf("Instructions:\n");
    printf("1. Move your player using W (up), A (left), S (down), D (right).\n");
    printf("2. Collect treasures (represented by 'T') on the map.\n");
    printf("3. The game ends when all treasures are collected.\n");
}

int main() {
    strcpy(player.name, "Explorer");
    player.position.x = MAP_SIZE / 2;
    player.position.y = MAP_SIZE / 2;
    player.treasures_collected = 0;

    initializeMap();
    placeTreasures();
    displayInstructions();

    while (player.treasures_collected < NUM_TREASURES) {
        printMap();
        printf("Move (W/A/S/D): ");
        char move;
        scanf(" %c", &move);
        movePlayer(move);
    }

    printf("Congratulations, %s! You have collected all the treasures!\n", player.name);
    return 0;
}