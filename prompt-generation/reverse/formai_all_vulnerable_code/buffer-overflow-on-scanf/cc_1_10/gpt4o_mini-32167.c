//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_DICE 2
#define MAX_SIDES 6

typedef struct {
    char name[30];
    int position;
    int score;
} Player;

void initializePlayers(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter the name of Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].position = 0; // Starting position
        players[i].score = 0; // Initial score
    }
}

void displayPlayerStats(Player players[], int numPlayers) {
    printf("\nPlayer Stats:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s - Position: %d, Score: %d\n", 
            players[i].name, players[i].position, players[i].score);
    }
}

int rollDice(int numDice, int numSides) {
    int total = 0;
    for(int i = 0; i < numDice; i++) {
        total += (rand() % numSides) + 1; // Generate dice roll
    }
    return total;
}

void movePlayer(Player *player, int roll) {
    player->position += roll;
    if (player->position > 30) { // Assuming game ends at position 30
        player->position = 30;
    }
    player->score += roll; // Add roll to score
}

int main() {
    srand(time(NULL)); // Seed random number generator
    Player players[MAX_PLAYERS];
    int numPlayers;

    printf("Welcome to the Dice Adventure Game!\n");
    printf("How many players (2 to %d)? ", MAX_PLAYERS);
    scanf("%d", &numPlayers);

    // Player Initialization
    if (numPlayers < 2 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting.\n");
        return 1;
    }
    initializePlayers(players, numPlayers);

    int currentPlayerIndex = 0;
    while (1) {
        Player *currentPlayer = &players[currentPlayerIndex];

        printf("\n%s's turn!\n", currentPlayer->name);
        int roll = rollDice(MAX_DICE, MAX_SIDES);
        printf("%s rolled a total of: %d\n", currentPlayer->name, roll);
        
        movePlayer(currentPlayer, roll);
        displayPlayerStats(players, numPlayers);

        if (currentPlayer->position >= 30) {
            printf("%s has reached the finish line with a score of: %d!\n", 
                        currentPlayer->name, currentPlayer->score);
            printf("Congratulations %s, you win!\n", currentPlayer->name);
            break;
        }

        // Move to the next player
        currentPlayerIndex = (currentPlayerIndex + 1) % numPlayers;
    }

    return 0;
}