//GPT-4o-mini DATASET v1.0 Category: Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 5
#define NUM_TREASURES 3
#define NUM_ENEMIES 2

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position position;
    int treasure;
    int enemy;
} GameState;

void initialize_map(GameState *game);
void display_map(GameState *game);
void move_player(GameState *game);
int check_encounter(GameState *game);
void collect_treasure(GameState *game);
void encounter_enemy(GameState *game);
void display_status(GameState *game);

int main() {
    GameState game;
    srand(time(NULL)); // Seed random number generator

    initialize_map(&game);
    while (1) {
        display_map(&game);
        move_player(&game);
        
        if (check_encounter(&game)) {
            collect_treasure(&game); // Collect treasure if it's there
            encounter_enemy(&game);   // Check for an enemy encounter
        }
        
        display_status(&game);
        
        if (game.treasure >= NUM_TREASURES) {
            printf("Congratulations, you collected all treasures!\n");
            break;
        }
    }

    return 0;
}

void initialize_map(GameState *game) {
    game->position.x = 0;
    game->position.y = 0;
    game->treasure = 0;
    game->enemy = 0;

    // Randomly place treasures
    for (int i = 0; i < NUM_TREASURES; i++) {
        game->treasure += rand() % 5; // Each treasure adds some value
    }
}

void display_map(GameState *game) {
    printf("\nYour current position: (%d, %d)\n", game->position.x, game->position.y);
    printf("Map: \n");
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (i == game->position.x && j == game->position.y)
                printf("[P] "); // Player
            else
                printf("[ ] ");
        }
        printf("\n");
    }
}

void move_player(GameState *game) {
    char move;
    printf("Enter your move (w/a/s/d): ");
    scanf(" %c", &move); // Space before %c to ignore whitespace
    
    switch (move) {
        case 'w':
            if (game->position.x > 0) game->position.x--;
            break;
        case 's':
            if (game->position.x < MAP_SIZE - 1) game->position.x++;
            break;
        case 'a':
            if (game->position.y > 0) game->position.y--;
            break;
        case 'd':
            if (game->position.y < MAP_SIZE - 1) game->position.y++;
            break;
        default:
            printf("Invalid move! Use w/a/s/d.\n");
    }
}

int check_encounter(GameState *game) {
    // Random encounter: 30% chance to encounter treasure or enemy
    if (rand() % 100 < 30) {
        if (rand() % 100 < 50) {
            printf("You found a treasure!\n");
            return 1; // Treasure found
        } else {
            printf("An enemy appeared!\n");
            return 1; // Enemy found
        }
    }
    return 0; // No encounter
}

void collect_treasure(GameState *game) {
    // Collect a treasure
    game->treasure += 1;
    printf("You collected a treasure! Total treasures: %d\n", game->treasure);
}

void encounter_enemy(GameState *game) {
    // Simple enemy logic
    if (rand() % 2 == 0) {
        printf("You escaped the enemy!\n");
    } else {
        printf("You were caught by the enemy! Game over.\n");
        exit(0); // End the game if caught
    }
}

void display_status(GameState *game) {
    printf("You have collected %d treasures!\n", game->treasure);
}