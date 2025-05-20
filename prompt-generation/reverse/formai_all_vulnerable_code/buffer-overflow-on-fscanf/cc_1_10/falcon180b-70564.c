//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    int numWords = 0;
    WordFrequency words[MAX_WORDS];
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Maximum number of words reached.\n");
            break;
        }
        int len = strlen(word);
        if (len >= MAX_WORD_LENGTH) {
            printf("Word too long.\n");
            continue;
        }
        strcpy(words[numWords].word, word);
        words[numWords].frequency = 1;
        numWords++;
    }

    fclose(file);

    int numPlayers;
    printf("Enter number of players: ");
    scanf("%d", &numPlayers);

    int playerFreq[numPlayers];
    for (int i = 0; i < numPlayers; i++) {
        playerFreq[i] = 0;
    }

    int totalWords = 0;
    for (int i = 0; i < numWords; i++) {
        totalWords += words[i].frequency;
    }

    int wordsPerPlayer = totalWords / numPlayers;
    int remainder = totalWords % numPlayers;

    for (int i = 0; i < numWords; i++) {
        int player = i % numPlayers;
        playerFreq[player] += words[i].frequency;
        if (playerFreq[player] >= wordsPerPlayer + (remainder > 0 && i < remainder)) {
            printf("Player %d wins!\n", player + 1);
            return 0;
        }
    }

    printf("Tie game.\n");
    return 0;
}