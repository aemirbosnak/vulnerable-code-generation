//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define BOARD_SIZE 10
#define MAX_TURN 20

typedef struct {
    char *name;
    int position;
} Player;

typedef struct {
    char *description;
    int effect;
} Space;

Space board[BOARD_SIZE];

void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i].description = (char *)malloc(50 * sizeof(char));
        sprintf(board[i].description, "Space %d: A vivid dream lingers...", i + 1);
        board[i].effect = (rand() % 3) - 1; // -1: set back, 0: stay, 1: move ahead
    }
}

void displayBoard() {
    printf("\n=== The Surrealistic Dreamscape ===\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%s (Effect: %d)\n", board[i].description, board[i].effect);
    }
}

void displayPlayers(Player players[], int playerCount) {
    printf("\nCurrent Player Positions:\n");
    for (int i = 0; i < playerCount; i++) {
        printf("%s is at position %d.\n", players[i].name, players[i].position);
    }
}

void updatePosition(Player *player) {
    int roll = (rand() % 6) + 1; // Roll a die
    printf("%s rolled a %d!\n", player->name, roll);
    player->position += roll;

    // Loop back to the beginning if exceeded
    if (player->position >= BOARD_SIZE) {
        player->position = 0;
        printf("%s has looped back to the start!\n", player->name);
    }

    // Apply effect of the space they're on
    int effect = board[player->position].effect;
    if (effect == 1) {
        printf("%s moves ahead through the dreamscape!\n", player->name);
        player->position++;
        if (player->position >= BOARD_SIZE) {
            player->position = 0;
        }
    } else if (effect == -1) {
        printf("%s drifts back into the abyss!\n", player->name);
        player->position--;
        if (player->position < 0) {
            player->position = BOARD_SIZE - 1;
        }
    }
}

int main() {
    srand(time(NULL));

    printf("=== Welcome to the Surrealistic Table Game ===\n");
    
    Player players[MAX_PLAYERS];
    int playerCount = 0;

    printf("Enter number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);
    if (playerCount > MAX_PLAYERS || playerCount < 1) {
        printf("Invalid number of players!\n");
        return 1;
    }

    for (int i = 0; i < playerCount; i++) {
        players[i].position = 0;
        players[i].name = (char *)malloc(20 * sizeof(char));
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
    }

    initializeBoard();
    displayBoard();

    for (int turn = 0; turn < MAX_TURN; turn++) {
        printf("\n--- Turn %d ---\n", turn + 1);
        for (int i = 0; i < playerCount; i++) {
            displayPlayers(players, playerCount);
            updatePosition(&players[i]);
        }
    }

    printf("\nThe surreal journey ends...\n");
    for (int i = 0; i < playerCount; i++) {
        free(players[i].name);
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        free(board[i].description);
    }
    
    return 0;
}