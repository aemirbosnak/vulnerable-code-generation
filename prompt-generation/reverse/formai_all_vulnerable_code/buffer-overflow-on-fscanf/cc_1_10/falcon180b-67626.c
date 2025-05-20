//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_STRING 1000
#define MAX_WORDS 100
#define MAX_PLAYERS 10

typedef struct {
    char name[20];
    int score;
    int correct;
    int wrong;
} Player;

Player players[MAX_PLAYERS];
char words[MAX_WORDS][MAX_STRING];
int numWords = 0;
int numPlayers = 0;

void generateWords() {
    FILE *file;
    char word[MAX_STRING];
    int i = 0;

    file = fopen("words.txt", "r");

    while (fscanf(file, "%s", word)!= EOF) {
        strcpy(words[i], word);
        i++;
    }

    fclose(file);
}

void askQuestion(int playerId) {
    int wordIndex = rand() % numWords;
    char question[MAX_STRING];
    char answer[MAX_STRING];

    strcpy(answer, words[wordIndex]);
    strcat(answer, " ");

    for (int i = 0; i < strlen(answer); i++) {
        answer[i] = '*';
    }

    printf("Player %d's turn:\n", playerId);
    printf("Word: %s\n", answer);

    fflush(stdout);

    char input[MAX_STRING];
    fgets(input, MAX_STRING, stdin);

    if (strcmp(input, answer) == 0) {
        players[playerId].correct++;
    } else {
        players[playerId].wrong++;
    }
}

void displayScore() {
    printf("\nFinal Scores:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d: %d correct, %d wrong\n", i + 1, players[i].correct, players[i].wrong);
    }
}

int main() {
    srand(time(0));
    generateWords();

    int numRounds = 10;

    for (int i = 0; i < numRounds; i++) {
        for (int j = 0; j < numPlayers; j++) {
            askQuestion(j);
        }
    }

    displayScore();

    return 0;
}