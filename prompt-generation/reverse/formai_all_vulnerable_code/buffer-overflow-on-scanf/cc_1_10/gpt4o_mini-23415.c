//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 5
#define TREASURE 'T'
#define MONSTER 'M'
#define EMPTY '.'
#define PLAYER 'P'
#define ESC '-'
#define MAX_MOVES 10

char grid[GRID_SIZE][GRID_SIZE];
int player_x, player_y;

void initialize_grid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = EMPTY;
        }
    }
    // Place the treasure at a random location
    int treasure_x = rand() % GRID_SIZE;
    int treasure_y = rand() % GRID_SIZE;
    grid[treasure_x][treasure_y] = TREASURE;

    // Place some monsters
    for (int i = 0; i < 3; i++) {
        int monster_x, monster_y;
        do {
            monster_x = rand() % GRID_SIZE;
            monster_y = rand() % GRID_SIZE;
        } while(grid[monster_x][monster_y] != EMPTY); 
        grid[monster_x][monster_y] = MONSTER;
    }
}

void print_grid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == player_x && j == player_y) {
                printf("%c ", PLAYER);
            } else {
                printf("%c ", grid[i][j]);
            }
        }
        printf("\n");
    }
}

int check_encounter() {
    if (grid[player_x][player_y] == TREASURE) {
        printf("Congratulations! You found the treasure!\n");
        return 1;
    } else if (grid[player_x][player_y] == MONSTER) {
        printf("Oh no! You encountered a monster!\n");
        return -1;
    }
    return 0;
}

void move_player(char direction) {
    int new_x = player_x;
    int new_y = player_y;

    switch (direction) {
        case 'w': new_x--; break; // move up
        case 's': new_x++; break; // move down
        case 'a': new_y--; break; // move left
        case 'd': new_y++; break; // move right
        default: printf("Invalid move! Use w, a, s, d.\n"); return;
    }

    // Check bounds
    if (new_x < 0 || new_x >= GRID_SIZE || new_y < 0 || new_y >= GRID_SIZE) {
        printf("You can't move outside the dungeon!\n");
        return;
    }
        
    player_x = new_x;
    player_y = new_y;

    int encounter_result = check_encounter();
    if (encounter_result == 1) {
        exit(0); // Game won
    } else if (encounter_result == -1) {
        exit(0); // Game lost
    }
}

int main() {
    srand(time(NULL));
    initialize_grid();
    
    player_x = 0; // Starting position
    player_y = 0;

    char move;
    int moves_count = 0;

    printf("Welcome to the Mystery Dungeon Adventure!\n");
    printf("Use 'w' to move up, 's' to move down, 'a' to move left, 'd' to move right.\n");
    printf("Your objective is to find the treasure 'T' while avoiding monsters 'M'.\n");
    
    while (moves_count < MAX_MOVES) {
        print_grid();
        printf("Make your move (w/a/s/d): ");
        scanf(" %c", &move);
        
        move_player(move);
        moves_count++;

        printf("Moves left: %d\n", MAX_MOVES - moves_count);

        if (moves_count == MAX_MOVES) {
            printf("You've run out of moves! Game over.\n");
        }
    }

    return 0;
}