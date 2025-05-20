//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define TREASURES 3
#define TRAPS 2

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position treasures[TREASURES];
    Position traps[TRAPS];
    Position player;
    int treasures_found;
} GameState;

// Function declarations
void initialize_game(GameState *game);
void print_grid(const GameState *game);
int move_player(GameState *game, char direction);
int check_win(const GameState *game);
int check_loss(const GameState *game);

int main() {
    GameState game;
    char direction;
    
    initialize_game(&game);

    printf("Welcome to the Treasure Hunt!\n");
    printf("You need to find %d treasures while avoiding %d traps.\n", TREASURES, TRAPS);
    
    while (1) {
        print_grid(&game);
        printf("Enter your move (w/a/s/d) or q to quit: ");
        scanf(" %c", &direction);

        if (direction == 'q') {
            printf("Thanks for playing!\n");
            break;
        }

        if (move_player(&game, direction)) {
            if (check_win(&game)) {
                printf("Congratulations! You've found all the treasures!\n");
                break;
            }
            if (check_loss(&game)) {
                printf("Game Over! You fell into a trap.\n");
                break;
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}

void initialize_game(GameState *game) {
    srand(time(NULL));

    game->player.x = 0;
    game->player.y = 0;
    game->treasures_found = 0;

    for (int i = 0; i < TREASURES; i++) {
        do {
            game->treasures[i].x = rand() % SIZE;
            game->treasures[i].y = rand() % SIZE;
        } while ((game->treasures[i].x == 0 && game->treasures[i].y == 0) || 
                 (i > 0 && (game->treasures[i].x == game->treasures[i - 1].x && 
                             game->treasures[i].y == game->treasures[i - 1].y)));
    }

    for (int j = 0; j < TRAPS; j++) {
        do {
            game->traps[j].x = rand() % SIZE;
            game->traps[j].y = rand() % SIZE;
        } while ((game->traps[j].x == 0 && game->traps[j].y == 0) || 
                 (j > 0 && (game->traps[j].x == game->traps[j - 1].x && 
                             game->traps[j].y == game->traps[j - 1].y)));
    }
}

void print_grid(const GameState *game) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == game->player.x && j == game->player.y) {
                printf(" P ");
            } else {
                int found = 0;
                for (int k = 0; k < TREASURES; k++) {
                    if (i == game->treasures[k].x && j == game->treasures[k].y) {
                        printf(" T ");
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    for (int l = 0; l < TRAPS; l++) {
                        if (i == game->traps[l].x && j == game->traps[l].y) {
                            printf(" X ");
                            found = 1;
                            break;
                        }
                    }
                }
                if (!found) {
                    printf(" . ");
                }
            }
        }
        printf("\n");
    }
}

int move_player(GameState *game, char direction) {
    Position new_position = game->player;
    
    switch (direction) {
        case 'w': new_position.x--; break; // Move up
        case 's': new_position.x++; break; // Move down
        case 'a': new_position.y--; break; // Move left
        case 'd': new_position.y++; break; // Move right
        default: return 0; // Invalid move
    }
    
    // Check boundaries
    if (new_position.x < 0 || new_position.x >= SIZE ||
        new_position.y < 0 || new_position.y >= SIZE) {
        return 0; // Invalid move
    }
    
    game->player = new_position;
    
    // Check if player found a treasure
    for (int i = 0; i < TREASURES; i++) {
        if (game->player.x == game->treasures[i].x && game->player.y == game->treasures[i].y) {
            game->treasures_found++;
            return 1;
        }
    }
    
    return 1; // Valid move
}

int check_win(const GameState *game) {
    return game->treasures_found == TREASURES;
}

int check_loss(const GameState *game) {
    for (int i = 0; i < TRAPS; i++) {
        if (game->player.x == game->traps[i].x && game->player.y == game->traps[i].y) {
            return 1; // Player fell into a trap
        }
    }
    return 0; // Player is not lost
}