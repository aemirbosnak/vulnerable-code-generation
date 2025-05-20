//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 256
#define MAX_NUM_WORDS 1000

typedef struct {
    char *word;
    int length;
} Word;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    char input[MAX_LINE_LENGTH];
    char *line = NULL;
    size_t lineLength = 0;
    ssize_t read;
    Word *words = NULL;
    int numWords = 0;
    int i;

    printf("Enter a string: ");
    fgets(input, MAX_LINE_LENGTH, stdin);

    line = strdup(input);
    line[strcspn(line, "\n")] = '\0';
    lineLength = strlen(line);

    words = malloc(sizeof(Word) * MAX_NUM_WORDS);

    for (i = 0; i < lineLength; i++) {
        if (isspace(line[i])) {
            if (numWords >= MAX_NUM_WORDS) {
                fprintf(stderr, "Error: Maximum number of words exceeded!\n");
                exit(1);
            }
            words[numWords].word = malloc(sizeof(char) * (i - words[numWords - 1].length + 1));
            strncpy(words[numWords].word, line + words[numWords - 1].length, i - words[numWords - 1].length);
            words[numWords].length = i - words[numWords - 1].length;
            numWords++;
        }
    }

    qsort(words, numWords, sizeof(Word), compareWords);

    for (i = 0; i < numWords; i++) {
        printf("%s\n", words[i].word);
    }

    for (i = 0; i < numWords; i++) {
        free(words[i].word);
    }
    free(words);
    free(line);

    return 0;
}