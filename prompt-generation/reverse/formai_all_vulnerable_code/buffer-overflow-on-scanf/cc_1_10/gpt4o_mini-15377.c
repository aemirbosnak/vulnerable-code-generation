//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROLLS 3
#define MAX_SCORES 10
#define TARGET_SCORE 100

typedef struct {
    char name[50];
    int totalScore;
    int rounds[MAX_SCORES];
} Player;

void initializePlayers(Player players[], int count);
void displayScores(Player players[], int count);
void rollDice(Player *player, int rollCount);
void playGame(Player players[], int playerCount);
int checkWinner(Player players[], int count);

int main() {
    int playerCount;
    Player players[MAX_PLAYERS];

    printf("Welcome to the Dice Roll Game!\n");

    while (1) {
        printf("Enter number of players (2 - 4): ");
        scanf("%d", &playerCount);
        if (playerCount >= 2 && playerCount <= MAX_PLAYERS) {
            break;
        } else {
            printf("Invalid number of players. Please try again.\n");
        }
    }

    initializePlayers(players, playerCount);
    playGame(players, playerCount);

    return 0;
}

void initializePlayers(Player players[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter name of Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].totalScore = 0;
        for (int j = 0; j < MAX_SCORES; j++) {
            players[i].rounds[j] = 0;
        }
    }
}

void displayScores(Player players[], int count) {
    printf("\nScores:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: Total Score = %d\n", players[i].name, players[i].totalScore);
    }
    printf("\n");
}

void rollDice(Player *player, int rollCount) {
    srand(time(NULL));
    int roundScore = 0;
    printf("%s, it's your turn to roll the dice!\n", player->name);

    for (int i = 0; i < rollCount; i++) {
        int dice = (rand() % 6) + 1;
        roundScore += dice;
        printf("Roll %d: You rolled a %d\n", i + 1, dice);
    }

    player->rounds[player->totalScore / TARGET_SCORE] = roundScore;
    player->totalScore += roundScore;
    printf("%s's score this round: %d\n", player->name, roundScore);
}

void playGame(Player players[], int playerCount) {
    int round = 1;

    while (1) {
        printf("\n--- Round %d ---\n", round);
        for (int i = 0; i < playerCount; i++) {
            rollDice(&players[i], MAX_ROLLS);
            displayScores(players, playerCount);
            int winnerIndex = checkWinner(players, playerCount);
            if (winnerIndex != -1) {
                printf("Congratulations, %s! You've won the game with a score of %d!\n", players[winnerIndex].name, players[winnerIndex].totalScore);
                return;
            }
        }
        round++;
    }
}

int checkWinner(Player players[], int count) {
    for (int i = 0; i < count; i++) {
        if (players[i].totalScore >= TARGET_SCORE) {
            return i;
        }
    }
    return -1;
}