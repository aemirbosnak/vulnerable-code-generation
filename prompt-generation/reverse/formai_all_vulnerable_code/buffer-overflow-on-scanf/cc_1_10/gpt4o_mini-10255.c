//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 5
#define NUM_TREASURES 3

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position position;
    int found;
} Treasure;

typedef struct {
    Position player;
    Treasure treasures[NUM_TREASURES];
    int treasures_found;
} GameState;

void initialize_game(GameState *game) {
    game->player.x = 0;
    game->player.y = 0;
    game->treasures_found = 0;

    // Set up random treasure locations
    for (int i = 0; i < NUM_TREASURES; i++) {
        game->treasures[i].found = 0;
        game->treasures[i].position.x = rand() % GRID_SIZE;
        game->treasures[i].position.y = rand() % GRID_SIZE;

        // Ensure no treasures overlap
        for (int j = 0; j < i; j++) {
            while (game->treasures[i].position.x == game->treasures[j].position.x &&
                   game->treasures[i].position.y == game->treasures[j].position.y) {
                game->treasures[i].position.x = rand() % GRID_SIZE;
                game->treasures[i].position.y = rand() % GRID_SIZE;
            }
        }
    }
}

void display_grid(GameState *game) {
    char grid[GRID_SIZE][GRID_SIZE] = { ' ' };

    // Set player position
    grid[game->player.x][game->player.y] = 'P';

    // Set treasure positions
    for (int i = 0; i < NUM_TREASURES; i++) {
        if (!game->treasures[i].found) {
            grid[game->treasures[i].position.x][game->treasures[i].position.y] = 'T';
        }
    }

    // Display grid
    printf("Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("[%c]", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void move_player(GameState *game, char direction) {
    switch (direction) {
        case 'w': // Move up
            if (game->player.x > 0) game->player.x--;
            break;
        case 's': // Move down
            if (game->player.x < GRID_SIZE - 1) game->player.x++;
            break;
        case 'a': // Move left
            if (game->player.y > 0) game->player.y--;
            break;
        case 'd': // Move right
            if (game->player.y < GRID_SIZE - 1) game->player.y++;
            break;
        default:
            printf("Invalid direction! Use w/a/s/d to move.\n");
            break;
    }
}

void check_for_treasure(GameState *game) {
    for (int i = 0; i < NUM_TREASURES; i++) {
        if (game->player.x == game->treasures[i].position.x &&
            game->player.y == game->treasures[i].position.y &&
            !game->treasures[i].found) {
            game->treasures[i].found = 1;
            game->treasures_found++;
            printf("You found a treasure at (%d, %d)!\n", game->player.x, game->player.y);
            return;
        }
    }
    printf("No treasure found at your current location.\n");
}

int main() {
    srand(time(NULL));
    GameState game;
    initialize_game(&game);
    char command;

    printf("Welcome to the Treasure Hunt Game!\n");
    
    while (game.treasures_found < NUM_TREASURES) {
        display_grid(&game);
        printf("Enter your move (w/a/s/d) or 'q' to quit: ");
        scanf(" %c", &command);

        if (command == 'q') {
            printf("Thanks for playing!\n");
            break;
        }

        move_player(&game, command);
        check_for_treasure(&game);
    }

    if (game.treasures_found == NUM_TREASURES) {
        printf("Congratulations! You found all the treasures!\n");
    }

    return 0;
}