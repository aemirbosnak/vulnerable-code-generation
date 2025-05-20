//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_POINTS 21

typedef struct {
    char name[50];
    int score;
} Player;

void printScores(Player players[], int playerCount) {
    printf("\nScores:\n");
    for (int i = 0; i < playerCount; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

int rollDice() {
    return rand() % 6 + 1;
}

int takeTurn(Player *player) {
    int total = 0;
    int rolled;

    printf("%s's turn:\n", player->name);
    while (1) {
        rolled = rollDice();
        total += rolled;
        printf("Rolled: %d, Total: %d\n", rolled, total);

        if (total > MAX_POINTS) {
            printf("%s busts!\n", player->name);
            return 0;
        }
        
        char choice;
        printf("Continue rolling? (y/n): ");
        scanf(" %c", &choice);
        
        if (choice == 'n') {
            break;
        }
    }
    
    player->score += total;
    return player->score;
}

void resetScores(Player players[], int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        players[i].score = 0;
    }
}

int main() {
    srand(time(NULL));
    
    Player players[MAX_PLAYERS];
    int playerCount;

    printf("Enter the number of players (2-4): ");
    scanf("%d", &playerCount);
    
    while (playerCount < 2 || playerCount > MAX_PLAYERS) {
        printf("Invalid number of players. Please enter a number between 2 and 4: ");
        scanf("%d", &playerCount);
    }

    for (int i = 0; i < playerCount; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    int round = 1;
    while (1) {
        printf("\n--- Round %d ---\n", round);
        
        for (int i = 0; i < playerCount; i++) {
            if (takeTurn(&players[i]) >= MAX_POINTS) {
                printf("%s wins!\n", players[i].name);
                return 0;
            }
        }
        
        printScores(players, playerCount);
        round++;

        char continueGame;
        printf("Continue to next round? (y/n): ");
        scanf(" %c", &continueGame);
        
        if (continueGame == 'n') {
            break;
        }

        resetScores(players, playerCount);
    }

    printf("\nFinal Scores:\n");
    printScores(players, playerCount);
    
    return 0;
}