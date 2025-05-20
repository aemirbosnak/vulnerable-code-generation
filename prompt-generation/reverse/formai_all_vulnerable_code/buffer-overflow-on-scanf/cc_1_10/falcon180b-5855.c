//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_PLAYERS 10
#define MAX_CONSPIRACIES 100
#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char name[MAX_PLAYERS];
    int score;
} Player;

typedef struct {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int numWords;
} ConspiracyTheory;

void generateConspiracyTheory(ConspiracyTheory *theory) {
    srand(time(NULL));
    int numWords = rand() % MAX_WORDS + 1;
    for (int i = 0; i < numWords; i++) {
        int wordLength = rand() % MAX_WORD_LENGTH + 1;
        char word[MAX_WORD_LENGTH];
        for (int j = 0; j < wordLength; j++) {
            word[j] = rand() % 26 + 'a';
        }
        word[wordLength] = '\0';
        strcpy(theory->words[i], word);
    }
    theory->numWords = numWords;
}

void printConspiracyTheory(ConspiracyTheory *theory) {
    printf("The conspiracy theory is:\n");
    for (int i = 0; i < theory->numWords; i++) {
        printf("%s ", theory->words[i]);
    }
    printf("\n");
}

void main() {
    int numPlayers;
    printf("Enter the number of players (1-10): ");
    scanf("%d", &numPlayers);
    if (numPlayers < 1 || numPlayers > 10) {
        printf("Invalid number of players.\n");
        return;
    }

    Player players[MAX_PLAYERS];
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter the name of player %d: ", i+1);
        scanf("%s", players[i].name);
    }

    int numConspiracies;
    printf("Enter the number of conspiracies (1-100): ");
    scanf("%d", &numConspiracies);
    if (numConspiracies < 1 || numConspiracies > 100) {
        printf("Invalid number of conspiracies.\n");
        return;
    }

    ConspiracyTheory conspiracies[MAX_CONSPIRACIES];
    for (int i = 0; i < numConspiracies; i++) {
        generateConspiracyTheory(&conspiracies[i]);
    }

    int numTheoriesPerPlayer = numConspiracies / numPlayers;
    int numTheoriesLeft = numConspiracies % numPlayers;

    for (int i = 0; i < numPlayers; i++) {
        int numTheories = numTheoriesPerPlayer + (i < numTheoriesLeft? 1 : 0);
        printf("Player %s has %d conspiracy theories:\n", players[i].name, numTheories);
        for (int j = 0; j < numTheories; j++) {
            int theoryIndex = (i * numTheoriesPerPlayer) + j;
            printConspiracyTheory(&conspiracies[theoryIndex]);
        }
        printf("\n");
    }

    return;
}