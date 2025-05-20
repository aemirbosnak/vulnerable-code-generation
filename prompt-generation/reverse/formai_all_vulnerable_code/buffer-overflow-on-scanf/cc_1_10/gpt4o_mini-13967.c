//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_TURNS 20
#define BOARD_SIZE 10

typedef struct {
    int id;
    int position;
    char name[50];
} Player;

void initializePlayers(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        players[i].id = i + 1;
        players[i].position = 0; // Start at the beginning of the board
        printf("Enter name for Player %d: ", players[i].id);
        scanf("%s", players[i].name);
    }
}

void displayBoard(const Player players[], int numPlayers) {
    printf("\nCurrent Board: ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        int playerFound = 0;
        for (int j = 0; j < numPlayers; j++) {
            if (players[j].position == i) {
                printf("[ %s ] ", players[j].name);
                playerFound = 1;
                break;
            }
        }
        if (!playerFound) {
            printf("[   ] ");
        }
    }
    printf("\n");
}

void movePlayer(Player *player) {
    int diceRoll = rand() % 6 + 1; // Roll a dice (1 to 6)
    printf("%s rolled a %d\n", player->name, diceRoll);
    player->position += diceRoll;
    if (player->position >= BOARD_SIZE) {
        printf("%s has reached the end of the board!\n", player->name);
        player->position = BOARD_SIZE - 1; // Stay at the last position
    }
}

int checkWinner(const Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        if (players[i].position == BOARD_SIZE - 1) {
            return i; // Return the index of the winner
        }
    }
    return -1; // No winner yet
}

void playGame(int numPlayers) {
    Player players[MAX_PLAYERS];
    initializePlayers(players, numPlayers);
    srand(time(NULL)); // Seed for random number generation

    for (int turn = 1; turn <= MAX_TURNS; turn++) {
        printf("\n--- Turn %d ---\n", turn);
        for (int i = 0; i < numPlayers; i++) {
            movePlayer(&players[i]);
            displayBoard(players, numPlayers);
            int winner = checkWinner(players, numPlayers);
            if (winner != -1) {
                printf("Congratulations! %s wins the game!\n", players[winner].name);
                return; // Game ends on a win
            }
        }
    }
    printf("Game over! No more turns left.\n");
}

int main() {
    int numPlayers;
    printf("Welcome to the Table Game!\n");
    do {
        printf("Enter number of players (2 to %d): ", MAX_PLAYERS);
        scanf("%d", &numPlayers);
    } while (numPlayers < 2 || numPlayers > MAX_PLAYERS);

    playGame(numPlayers);

    return 0;
}