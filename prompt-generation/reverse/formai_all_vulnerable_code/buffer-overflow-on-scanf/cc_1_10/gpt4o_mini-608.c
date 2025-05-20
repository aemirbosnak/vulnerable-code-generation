//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_TURN 20

typedef struct {
    char name[30];
    int score;
} Player;

void initializePlayers(Player players[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter name for Player %d: ", i + 1);
        fgets(players[i].name, sizeof(players[i].name), stdin);
        players[i].name[strcspn(players[i].name, "\n")] = 0; // Remove newline character
        players[i].score = 0;
    }
}

void displayScores(Player players[], int count) {
    printf("\n--- Current Scores ---\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
    printf("-----------------------\n");
}

int rollDice() {
    return (rand() % 6) + 1; // Roll a die (1 to 6)
}

void playTurn(Player *player) {
    int diceValue = rollDice();
    printf("%s rolled a %d!\n", player->name, diceValue);
    player->score += diceValue;
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    int numPlayers;
    printf("Welcome to the Rolling Dice Game!\n");
    printf("How many players? (Max %d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);
    getchar(); // Consume newline character after scanf

    if(numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Please restart the game!\n");
        return 1;
    }

    Player players[MAX_PLAYERS];
    initializePlayers(players, numPlayers);
    
    for (int turn = 1; turn <= MAX_TURN; turn++) {
        printf("\n--- Turn %d ---\n", turn);
        for (int i = 0; i < numPlayers; i++) {
            playTurn(&players[i]);
            displayScores(players, numPlayers);
        }
    }

    // Determine winner
    int highestScore = 0;
    Player winner;
    for (int i = 0; i < numPlayers; i++) {
        if (players[i].score > highestScore) {
            highestScore = players[i].score;
            winner = players[i];
        }
    }

    printf("\n--- Game Over! ---\n");
    printf("The winner is %s with a score of %d!\n", winner.name, winner.score);

    return 0;
}