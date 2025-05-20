//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    const WordCount *wordA = a;
    const WordCount *wordB = b;

    return strcmp(wordA->word, wordB->word);
}

void countWords(char *text, int textLength, WordCount *wordCounts, int numWords) {
    char word[MAX_WORD_LENGTH];
    int wordLength;
    int i;

    for (i = 0; i < numWords; i++) {
        wordCounts[i].count = 0;
    }

    for (i = 0; i < textLength; i++) {
        if (isspace(text[i])) {
            word[wordLength] = '\0';
            wordLength = 0;
        } else {
            if (wordLength >= MAX_WORD_LENGTH - 1) {
                break;
            }
            word[wordLength++] = tolower(text[i]);
        }
    }

    if (wordLength > 0) {
        word[wordLength] = '\0';
        qsort(wordCounts, numWords, sizeof(WordCount), compareWords);
    }
}

void printWordCounts(WordCount *wordCounts, int numWords) {
    int i;

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main(int argc, char **argv) {
    FILE *file;
    char *text;
    int textLength;
    WordCount wordCounts[MAX_WORDS];
    int numWords;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    textLength = ftell(file);
    fseek(file, 0, SEEK_SET);

    text = malloc(textLength + 1);
    if (text == NULL) {
        printf("Out of memory\n");
        fclose(file);
        return 1;
    }

    fread(text, 1, textLength, file);
    text[textLength] = '\0';
    fclose(file);

    countWords(text, textLength, wordCounts, MAX_WORDS);
    numWords = MAX_WORDS;

    printWordCounts(wordCounts, numWords);

    free(text);

    return 0;
}