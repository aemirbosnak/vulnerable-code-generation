//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void initializeWordFrequency(WordFrequency *wordFrequency) {
    memset(wordFrequency, 0, sizeof(WordFrequency));
}

void addWord(WordFrequency *wordFrequency, char *word) {
    int i;
    for (i = 0; i < MAX_WORD_LENGTH; i++) {
        if (word[i] == '\0') {
            strncpy(wordFrequency->word, word, i);
            wordFrequency->count++;
            return;
        }
    }
}

void printWordFrequency(WordFrequency *wordFrequency) {
    int i;
    for (i = 0; i < MAX_WORD_LENGTH; i++) {
        if (wordFrequency->word[i]!= '\0') {
            printf("%s : %d\n", wordFrequency->word, wordFrequency->count);
        }
    }
}

int main() {
    FILE *file;
    char sentence[MAX_SENTENCE_LENGTH];
    char word[MAX_WORD_LENGTH];
    WordFrequency wordFrequency[MAX_WORDS];
    int numWords = 0;

    initializeWordFrequency(wordFrequency);

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(file, "%s", sentence)!= EOF) {
        char *token = strtok(sentence, ",.?!;:");
        while (token!= NULL) {
            strcpy(word, token);
            addWord(wordFrequency, word);
            token = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);

    printf("Word frequency:\n");
    for (int i = 0; i < numWords; i++) {
        printWordFrequency(wordFrequency + i);
    }

    return 0;
}