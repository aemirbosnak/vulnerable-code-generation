//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *word1 = (WordCount *)a;
    WordCount *word2 = (WordCount *)b;

    return strcmp(word1->word, word2->word);
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *text;
    long fileSize;
    int i, j, numWords;
    WordCount words[MAX_WORDS];

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    fileSize = ftell(file);
    rewind(file);

    text = malloc(fileSize + 1);
    if (text == NULL) {
        printf("Memory error.\n");
        return 1;
    }

    fread(text, fileSize, 1, file);
    text[fileSize] = '\0';

    numWords = 0;
    for (i = 0; i < fileSize; i++) {
        if (isspace(text[i])) {
            text[i] = '\0';
            strcpy(words[numWords].word, &text[i]);
            numWords++;
        }
    }

    qsort(words, numWords, sizeof(WordCount), compareWords);

    printf("Word Count:\n");
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    free(text);
    fclose(file);

    return 0;
}