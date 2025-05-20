//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 10
#define MAX_INPUT_LENGTH 1000

typedef struct {
    char name[20];
    int score;
    char input[MAX_INPUT_LENGTH];
} Player;

Player players[MAX_PLAYERS];
int numPlayers;

void init() {
    numPlayers = 0;
    memset(players, 0, sizeof(players));
}

void readPlayerName(Player *player) {
    printf("Enter your name: ");
    scanf("%s", player->name);
}

void readPlayerInput(Player *player) {
    printf("Enter your input: ");
    scanf("%s", player->input);
}

int isPalindrome(const char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i])!= tolower(str[len - i - 1])) {
            return 0;
        }
    }
    return 1;
}

void printScores() {
    printf("Scores:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

int main() {
    init();
    int maxRounds = 5;
    int currentRound = 0;

    while (numPlayers < 2 || currentRound < maxRounds) {
        if (numPlayers < MAX_PLAYERS) {
            Player newPlayer;
            readPlayerName(&newPlayer);
            strcpy(players[numPlayers].name, newPlayer.name);
            numPlayers++;
        }
    }

    while (currentRound < maxRounds) {
        printf("Round %d\n", currentRound + 1);
        for (int i = 0; i < numPlayers; i++) {
            readPlayerInput(&players[i]);
        }

        int maxScore = 0;
        for (int i = 0; i < numPlayers; i++) {
            if (isPalindrome(players[i].input)) {
                players[i].score++;
            }
        }

        printScores();
        currentRound++;
    }

    printf("Game over!\n");
    return 0;
}