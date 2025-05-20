//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define WINNING_SCORE 100

typedef struct {
    char name[50];
    int score;
} Player;

void initializePlayers(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for Player %d: ", i + 1);
        fgets(players[i].name, sizeof(players[i].name), stdin);
        players[i].name[strcspn(players[i].name, "\n")] = 0; // Remove newline character
        players[i].score = 0;
    }
}

int rollDie() {
    return (rand() % 6) + 1; // Return a number between 1 and 6
}

void takeTurn(Player* player) {
    int roll = rollDie();
    player->score += roll;
    printf("%s rolled a %d! Total score: %d\n", player->name, roll, player->score);
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int numPlayers;

    printf("Welcome to the Dice Rolling Game!\n");
    printf("How many players will be participating? (1-%d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);
    getchar(); // Consume the newline character after scanf

    // Validate number of players
    if (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Please restart the game.\n");
        return 1;
    }

    Player players[MAX_PLAYERS];
    initializePlayers(players, numPlayers);

    int currentPlayerIndex = 0;
    while (1) {
        Player* currentPlayer = &players[currentPlayerIndex];
        printf("\n%s's turn:\n", currentPlayer->name);
        takeTurn(currentPlayer);

        if (currentPlayer->score >= WINNING_SCORE) {
            printf("%s wins with a score of %d!\n", currentPlayer->name, currentPlayer->score);
            break;
        }

        currentPlayerIndex = (currentPlayerIndex + 1) % numPlayers; // Move to the next player
    }

    printf("Game Over! Thanks for playing!\n");
    return 0;
}