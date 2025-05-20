//Falcon-180B DATASET v1.0 Category: Text processing ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int compareWords(const void *a, const void *b) {
    const Word *wordA = a;
    const Word *wordB = b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    char input[MAX_WORD_LENGTH];
    char filename[MAX_WORD_LENGTH];
    FILE *file;
    Word words[MAX_WORDS];
    int numWords = 0;

    printf("Enter the name of the file you want to process:\n");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    while (fscanf(file, "%s", input)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Maximum number of words reached\n");
            break;
        }

        Word *word = &words[numWords];
        strcpy(word->word, input);
        word->count = 1;

        numWords++;
    }

    fclose(file);

    qsort(words, numWords, sizeof(Word), compareWords);

    printf("Sorted word count:\n");

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}