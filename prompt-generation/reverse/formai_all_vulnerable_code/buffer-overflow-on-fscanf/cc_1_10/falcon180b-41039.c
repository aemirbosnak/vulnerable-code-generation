//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define POSITIVE_SCORE 1
#define NEGATIVE_SCORE -1
#define NEUTRAL_SCORE 0

typedef struct {
    char word[MAX_WORD_LENGTH];
    int score;
} WordScore;

void loadDictionary(char *filename, WordScore *dictionary) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    int numWords = 0;
    while (fscanf(file, "%s %d\n", dictionary[numWords].word, &dictionary[numWords].score)!= EOF) {
        numWords++;
    }

    fclose(file);
}

int classifySentence(char *sentence, WordScore *dictionary) {
    int numWords = 0;
    int totalScore = 0;

    char word[MAX_WORD_LENGTH];
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        strcpy(word, token);
        token = strtok(NULL, " ");

        bool found = false;
        for (int i = 0; i < numWords; i++) {
            if (strcmp(word, dictionary[i].word) == 0) {
                totalScore += dictionary[i].score;
                found = true;
                break;
            }
        }

        if (!found) {
            numWords++;
            strcpy(dictionary[numWords].word, word);
            dictionary[numWords].score = NEUTRAL_SCORE;
        }
    }

    if (totalScore > 0) {
        return POSITIVE_SCORE;
    } else if (totalScore < 0) {
        return NEGATIVE_SCORE;
    } else {
        return NEUTRAL_SCORE;
    }
}

int main() {
    WordScore dictionary[MAX_WORDS];
    loadDictionary("dictionary.txt", dictionary);

    char sentence[1000];
    while (fgets(sentence, sizeof(sentence), stdin)!= NULL) {
        int score = classifySentence(sentence, dictionary);
        printf("Sentiment score: %d\n", score);
    }

    return 0;
}