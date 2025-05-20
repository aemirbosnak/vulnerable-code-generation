//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 2
#define TARGET_SCORE 30
#define DICE_SIDES 6

typedef struct {
    char name[50];
    int score;
    int penalty;
} Player;

void initializePlayers(Player players[], int num) {
    for (int i = 0; i < num; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
        players[i].penalty = 0;
    }
}

int rollDice() {
    return (rand() % DICE_SIDES) + 1;
}

void applyPenalty(Player *player) {
    int penalty = (rand() % 5) + 1; // Random penalty between 1 and 5
    player->penalty += penalty;
    printf("%s received a penalty of %d points!\n", player->name, penalty);
}

int main() {
    srand(time(NULL)); // Initialize random number generator
    Player players[MAX_PLAYERS];
    
    initializePlayers(players, MAX_PLAYERS);
    
    int currentPlayerIndex = 0;
    int gameOngoing = 1;

    while (gameOngoing) {
        Player *currentPlayer = &players[currentPlayerIndex];
        printf("\n%s's turn! Current Score: %d (Penalty: %d)\n", currentPlayer->name, currentPlayer->score, currentPlayer->penalty);
        
        printf("Press Enter to roll the dice...");
        getchar(); // Wait for the user to press Enter

        int roll = rollDice();
        printf("%s rolled a %d\n", currentPlayer->name, roll);

        if (roll == 6) {
            applyPenalty(currentPlayer);
        } else {
            currentPlayer->score += roll;
            printf("%s's score after roll: %d\n", currentPlayer->name, currentPlayer->score);
        }

        if (currentPlayer->score >= TARGET_SCORE) {
            printf("%s has reached the target score of %d! %s wins!\n", currentPlayer->name, TARGET_SCORE, currentPlayer->name);
            gameOngoing = 0;
            break;
        }
        
        currentPlayerIndex = (currentPlayerIndex + 1) % MAX_PLAYERS; // Switch player
    }

    printf("Final Scores:\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("%s: %d (Penalty: %d)\n", players[i].name, players[i].score, players[i].penalty);
    }

    return 0;
}