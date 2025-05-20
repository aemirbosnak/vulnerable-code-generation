//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_GAMES 3
#define MAX_QUESTIONS 10

typedef struct {
    char name[50];
    int score;
} Player;

void shuffleArray(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        j = rand() % n;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void displayScore(Player players[], int n) {
    int i;
    printf("Scoreboard:\n");
    printf("Name\tScore\n");
    for (i = 0; i < n; i++) {
        printf("%s\t%d\n", players[i].name, players[i].score);
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int nPlayers, i, j, choice, correctAnswers[MAX_PLAYERS], totalQuestions, score;
    char answer[50];
    char questions[MAX_QUESTIONS][100];

    // Initialize random seed
    srand(time(NULL));

    // Initialize players
    nPlayers = 0;
    while (nPlayers < MAX_PLAYERS) {
        printf("Enter player name: ");
        scanf("%s", players[nPlayers].name);
        nPlayers++;
    }

    // Shuffle questions
    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("Enter question %d: ", i+1);
        scanf("%s", questions[i]);
    }
    shuffleArray(questions, MAX_QUESTIONS);

    // Play game
    for (i = 0; i < MAX_GAMES; i++) {
        totalQuestions = 0;
        printf("\nGame %d:\n", i+1);
        while (totalQuestions < MAX_QUESTIONS) {
            printf("Question %d: %s\n", totalQuestions+1, questions[totalQuestions]);
            printf("Enter your answer: ");
            scanf("%s", answer);
            if (strcmp(answer, questions[totalQuestions]) == 0) {
                correctAnswers[0]++;
            }
            totalQuestions++;
        }
        for (j = 1; j < nPlayers; j++) {
            correctAnswers[j] = 0;
        }
        printf("\nScores:\n");
        for (j = 0; j < nPlayers; j++) {
            printf("%s: %d\n", players[j].name, correctAnswers[j]);
        }
        score = correctAnswers[0];
        for (j = 1; j < nPlayers; j++) {
            if (correctAnswers[j] > score) {
                score = correctAnswers[j];
            }
        }
        printf("\nMinimum score to win: %d\n", score);
    }

    return 0;
}