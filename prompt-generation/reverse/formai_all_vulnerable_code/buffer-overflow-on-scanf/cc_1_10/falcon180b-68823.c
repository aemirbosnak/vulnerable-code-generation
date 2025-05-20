//Falcon-180B DATASET v1.0 Category: Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 10
#define MAX_PLAYERS 4

typedef struct {
    char name[20];
    int score;
} Player;

typedef struct {
    char word[MAX_WORD_LENGTH+1];
    bool found;
} Word;

void init(Word words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        words[i].found = false;
    }
}

void generateWords(char words[][MAX_WORD_LENGTH+1], int numWords) {
    FILE *file = fopen("words.txt", "r");
    if (!file) {
        printf("Error opening file.\n");
        exit(1);
    }
    int count = 0;
    while (fscanf(file, "%s", words[count])!= EOF) {
        count++;
        if (count >= numWords) {
            break;
        }
    }
    fclose(file);
}

int main() {
    srand(time(NULL));
    int numPlayers, numWords;
    printf("Enter number of players: ");
    scanf("%d", &numPlayers);
    printf("Enter number of words: ");
    scanf("%d", &numWords);
    if (numPlayers < 1 || numPlayers > MAX_PLAYERS || numWords < 1 || numWords > MAX_WORDS) {
        printf("Invalid input.\n");
        return 1;
    }
    char word[MAX_WORD_LENGTH+1];
    Word words[numWords];
    init(words, numWords);
    generateWords(word, numWords);
    Player players[numPlayers];
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter player name: ");
        scanf("%s", players[i].name);
    }
    int currentPlayer = 0;
    bool gameOver = false;
    while (!gameOver) {
        printf("Player %s's turn.\n", players[currentPlayer].name);
        printf("Enter a word: ");
        scanf("%s", word);
        int wordLen = strlen(word);
        word[wordLen] = '\0';
        for (int i = 0; i < numWords; i++) {
            if (strcmp(word, words[i].word) == 0 &&!words[i].found) {
                printf("Correct!\n");
                players[currentPlayer].score++;
                words[i].found = true;
            }
        }
        if (!gameOver) {
            currentPlayer = (currentPlayer + 1) % numPlayers;
        }
    }
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %s's score: %d\n", players[i].name, players[i].score);
    }
    return 0;
}