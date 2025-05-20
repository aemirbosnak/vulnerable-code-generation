//Falcon-180B DATASET v1.0 Category: Mortgage Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 10

struct Player {
    char name[20];
    int score;
};

struct Round {
    int questionDifficulty;
    int questionType;
    char question[100];
    char answer[100];
};

void startGame() {
    int numPlayers;
    printf("How many players will be playing? ");
    scanf("%d", &numPlayers);

    struct Player players[MAX_PLAYERS];
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    for (int round = 1; round <= MAX_ROUNDS; round++) {
        struct Round currentRound;
        currentRound.questionDifficulty = rand() % 3 + 1; // 1-3, easy to hard
        currentRound.questionType = rand() % 2; // 0-1, multiple choice or true/false
        if (currentRound.questionType == 0) {
            sprintf(currentRound.question, "What is the capital of France? ");
            strcpy(currentRound.answer, "Paris");
        } else {
            sprintf(currentRound.question, "The Great Barrier Reef is located in which country? ");
            strcpy(currentRound.answer, "Australia");
        }

        for (int i = 0; i < numPlayers; i++) {
            printf("%s, your question is: %s\n", players[i].name, currentRound.question);
            char answer[100];
            scanf("%s", answer);

            if (strcmp(answer, currentRound.answer) == 0) {
                players[i].score++;
            }
        }

        printf("\n");
    }

    for (int i = 0; i < numPlayers; i++) {
        printf("%s has a score of %d\n", players[i].name, players[i].score);
    }
}

int main() {
    startGame();
    return 0;
}