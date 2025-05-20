//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 1000
#define MAX_CONSPIRACY_WORDS 100
#define WORD_LIST_FILE "word_list.txt"

typedef struct {
    char *word;
    int count;
} WordCount;

void readWordList(WordCount *wordCounts, int maxWords) {
    FILE *file = fopen(WORD_LIST_FILE, "r");
    if (file == NULL) {
        printf("Error reading word list file.\n");
        exit(1);
    }

    int numWords = 0;
    while (fscanf(file, "%s", wordCounts[numWords].word)!= EOF) {
        numWords++;
        if (numWords >= maxWords) {
            break;
        }
    }

    fclose(file);
}

char *generateConspiracy(WordCount *wordCounts, int maxWords, int maxLength) {
    char *conspiracy = malloc(maxLength * sizeof(char));
    int pos = 0;

    srand(time(NULL));
    int wordIndex = rand() % maxWords;
    strncat(conspiracy, wordCounts[wordIndex].word, pos < maxLength? pos + 1 : maxLength - 1);
    pos += strlen(wordCounts[wordIndex].word);

    while (pos < maxLength - 1) {
        wordIndex = rand() % maxWords;
        while (wordCounts[wordIndex].count == 0) {
            wordIndex = rand() % maxWords;
        }
        strncat(conspiracy, " ", pos < maxLength - 2? pos + 1 : maxLength - 2);
        strncat(conspiracy, wordCounts[wordIndex].word, pos < maxLength - 1? pos + 1 : maxLength - 1);
        pos += strlen(wordCounts[wordIndex].word) + 1;
        wordCounts[wordIndex].count--;
    }

    conspiracy[pos] = '\0';
    return conspiracy;
}

int main() {
    WordCount wordCounts[MAX_CONSPIRACY_WORDS];
    readWordList(wordCounts, MAX_CONSPIRACY_WORDS);

    int maxLength = MAX_CONSPIRACY_LENGTH;
    char *conspiracy = generateConspiracy(wordCounts, MAX_CONSPIRACY_WORDS, maxLength);

    printf("Random conspiracy theory: %s\n", conspiracy);

    free(conspiracy);
    return 0;
}