//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} Word;

int compareWords(const void* a, const void* b) {
    const Word* wordA = (const Word*)a;
    const Word* wordB = (const Word*)b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    Word* words = malloc(MAX_WORDS * sizeof(Word));
    int numWords = 0;

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        int length = strlen(line);
        for (int i = 0; i < length; i++) {
            if (isalpha(line[i])) {
                line[i] = tolower(line[i]);
            } else {
                line[i] = '\0';
            }
        }

        int wordLength = strlen(line);
        if (wordLength > 0) {
            Word* newWord = realloc(words, (numWords+1) * sizeof(Word));
            if (newWord == NULL) {
                printf("Error: could not allocate memory for new word.\n");
                return 1;
            }
            words = newWord;

            strcpy(words[numWords].word, line);
            words[numWords].frequency = 1;
            numWords++;
        }
    }

    fclose(file);

    qsort(words, numWords, sizeof(Word), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }

    free(words);

    return 0;
}