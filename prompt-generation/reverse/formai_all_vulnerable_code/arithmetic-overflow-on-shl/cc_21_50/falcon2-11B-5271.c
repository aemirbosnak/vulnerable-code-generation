//Falcon2-11B DATASET v1.0 Category: Pac-Man Game Clone ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24
#define NUM_PACMAN_POSITIONS 7
#define NUM_GHOST_POSITIONS 4
#define PACMAN_CHAR '@'
#define GHOST_CHAR 'O'
#define WALL_CHAR '#'
#define FOOD_CHAR '.'
#define GHOST_MOVE_TIME 1000
#define GHOST_MOVE_SPEED 2
#define FOOD_POSITION 3

int main() {
    int screen[SCREEN_HEIGHT];
    int pacman_position = 0;
    int ghost_positions[NUM_GHOST_POSITIONS] = {0, 1, 2, 3};
    int food_position = FOOD_POSITION;
    int i, j, k;

    // Initialize screen with walls
    for (i = 0; i < SCREEN_HEIGHT; i++) {
        for (j = 0; j < SCREEN_WIDTH; j++) {
            screen[i] = screen[i] | (1 << j);
        }
    }

    // Initialize pacman and ghosts
    for (i = 0; i < NUM_PACMAN_POSITIONS; i++) {
        screen[pacman_position] = screen[pacman_position] | (1 << i);
    }
    for (i = 0; i < NUM_GHOST_POSITIONS; i++) {
        screen[ghost_positions[i]] = screen[ghost_positions[i]] | (1 << i);
    }

    // Initialize food
    screen[food_position] = screen[food_position] | (1 << FOOD_POSITION);

    // Set pacman and ghost positions
    for (i = 0; i < NUM_PACMAN_POSITIONS; i++) {
        if (pacman_position == i) {
            screen[i] = screen[i] | (1 << PACMAN_CHAR);
        }
    }
    for (i = 0; i < NUM_GHOST_POSITIONS; i++) {
        if (ghost_positions[i] == i) {
            screen[i] = screen[i] | (1 << GHOST_CHAR);
        }
    }

    // Set food position
    screen[food_position] = screen[food_position] | (1 << FOOD_CHAR);

    // Set ghost positions
    for (i = 0; i < NUM_GHOST_POSITIONS; i++) {
        screen[ghost_positions[i]] = screen[ghost_positions[i]] | (1 << GHOST_CHAR);
    }

    // Set walls
    for (i = 0; i < SCREEN_HEIGHT; i++) {
        for (j = 0; j < SCREEN_WIDTH; j++) {
            screen[i] = screen[i] | (1 << j);
        }
    }

    // Display initial screen
    for (i = 0; i < SCREEN_HEIGHT; i++) {
        for (j = 0; j < SCREEN_WIDTH; j++) {
            printf("%c", screen[i] & (1 << j)? WALL_CHAR : screen[i] & (1 << FOOD_POSITION)? FOOD_CHAR : screen[i] & (1 << PACMAN_CHAR)? PACMAN_CHAR : GHOST_CHAR);
        }
        printf("\n");
    }

    // Main game loop
    srand(time(NULL));
    int ghost_move_time = 0;
    int ghost_move_direction = 1;
    while (1) {
        // Move ghosts
        for (i = 0; i < NUM_GHOST_POSITIONS; i++) {
            if (ghost_move_time == 0) {
                ghost_move_direction = rand() % 4;
                ghost_move_time = GHOST_MOVE_TIME;
            }
            k = ghost_positions[i] + ghost_move_direction;
            if (k >= 0 && k < NUM_GHOST_POSITIONS) {
                ghost_positions[i] = k;
            } else {
                ghost_move_time = 0;
            }
        }

        // Move pacman
        k = pacman_position + (rand() % 4);
        if (k >= 0 && k < NUM_PACMAN_POSITIONS) {
            pacman_position = k;
        } else {
            break;
        }

        // Move food
        k = food_position + (rand() % 4);
        if (k >= 0 && k < NUM_PACMAN_POSITIONS) {
            food_position = k;
        } else {
            screen[food_position] = screen[food_position] & (~(1 << FOOD_POSITION));
        }

        // Update screen
        for (i = 0; i < SCREEN_HEIGHT; i++) {
            for (j = 0; j < SCREEN_WIDTH; j++) {
                screen[i] = screen[i] & (~(1 << j));
            }
        }
        for (i = 0; i < SCREEN_HEIGHT; i++) {
            for (j = 0; j < SCREEN_WIDTH; j++) {
                screen[i] = screen[i] | (1 << j);
            }
        }
        screen[pacman_position] = screen[pacman_position] | (1 << PACMAN_CHAR);
        screen[food_position] = screen[food_position] | (1 << FOOD_CHAR);
        for (i = 0; i < NUM_GHOST_POSITIONS; i++) {
            screen[ghost_positions[i]] = screen[ghost_positions[i]] | (1 << GHOST_CHAR);
        }

        // Display updated screen
        for (i = 0; i < SCREEN_HEIGHT; i++) {
            for (j = 0; j < SCREEN_WIDTH; j++) {
                printf("%c", screen[i] & (1 << j)? WALL_CHAR : screen[i] & (1 << FOOD_POSITION)? FOOD_CHAR : screen[i] & (1 << PACMAN_CHAR)? PACMAN_CHAR : GHOST_CHAR);
            }
            printf("\n");
        }
    }

    return 0;
}