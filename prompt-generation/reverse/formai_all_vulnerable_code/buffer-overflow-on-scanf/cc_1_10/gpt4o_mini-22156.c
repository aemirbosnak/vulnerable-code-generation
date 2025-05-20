//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TREASURES 10
#define MAX_TRAPS 5
#define CAVE_SIZE 10

typedef struct {
    int treasures;
    int traps;
    int player_position;
} GameState;

void initialize_game(GameState *game) {
    game->treasures = MAX_TREASURES;
    game->traps = MAX_TRAPS;
    game->player_position = 0;
}

void display_intro() {
    printf("Welcome to Cave Explorer!\n");
    printf("You will explore a cave filled with treasures and traps.\n");
    printf("Your goal is to collect treasures and find the exit!\n");
    printf("Good luck!\n");
}

void display_cave(GameState *game) {
    printf("You are at position: %d\n", game->player_position);
    printf("Treasures left: %d\n", game->treasures);
    printf("Traps left: %d\n", game->traps);
    printf("----------\n");
    for (int i = 0; i < CAVE_SIZE; i++) {
        if (i == game->player_position) {
            printf("[P] ");
        } else if (rand() % 10 < 2 && game->traps > 0) { // 20% chance to put a trap
            printf("[X] "); // Trap
            game->traps--;
        } else if (rand() % 10 < 5 && game->treasures > 0) { // 50% chance to put a treasure
            printf("[T] "); // Treasure
            game->treasures--;
        } else {
            printf("[ ] "); // Empty space
        }
    }
    printf("\n");
}

int check_event(GameState *game) {
    // Random events based on player position
    if (rand() % 10 < 2) { // 20% chance of finding treasure
        game->treasures--;
        printf("You found a treasure at position %d!\n", game->player_position);
        return 1; // Treasure found
    } else if (rand() % 10 < 1) { // 10% chance of falling in a trap
        printf("Oh no! You fell into a trap at position %d!\n", game->player_position);
        return -1; // Trap triggered
    }
    return 0; // Nothing happens
}

void move_player(GameState *game, int direction) {
    if (direction == 1 && game->player_position < CAVE_SIZE - 1) {
        game->player_position++;
    } else if (direction == -1 && game->player_position > 0) {
        game->player_position--;
    }
}

int main() {
    srand(time(0)); // Seed for random number generation
    GameState game;
    initialize_game(&game);
    display_intro();

    char command;
    while (game.treasures > 0 && game.traps > 0 && game.player_position < CAVE_SIZE) {
        display_cave(&game);
        printf("Enter 'd' to move right, 'a' to move left, or 'q' to quit: ");
        scanf(" %c", &command);

        if (command == 'q') {
            printf("Thanks for playing! You exited the game.\n");
            break;
        }

        if (command == 'd') {
            move_player(&game, 1);
        } else if (command == 'a') {
            move_player(&game, -1);
        }

        int event = check_event(&game);
        if (event == -1) {
            printf("Game Over! You fell into a trap.\n");
            break;
        }
    }

    if (game.treasures == 0) {
        printf("Congratulations! You collected all treasures and escaped the cave!\n");
    } else if (game.player_position >= CAVE_SIZE) {
        printf("You reached the end of the cave!\n");
    }

    return 0;
}