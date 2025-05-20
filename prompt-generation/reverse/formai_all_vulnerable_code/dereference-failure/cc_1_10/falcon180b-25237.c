//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wordA = (WordCount *)a;
    WordCount *wordB = (WordCount *)b;

    return strcmp(wordA->word, wordB->word);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    int numWords = 0;
    WordCount *wordCounts = (WordCount *)malloc(sizeof(WordCount) * MAX_NUM_WORDS);

    while ((read = getline(&line, &len, file))!= -1) {
        if (numWords >= MAX_NUM_WORDS) {
            printf("Reached maximum number of words (%d)\n", MAX_NUM_WORDS);
            break;
        }

        char *wordStart = line;
        while ((wordStart = strpbrk(wordStart, ",.?!;:-_\"'"))!= NULL) {
            *wordStart = '\0';
            if (strlen(wordStart) > 0) {
                if (numWords >= MAX_NUM_WORDS) {
                    printf("Reached maximum number of words (%d)\n", MAX_NUM_WORDS);
                    break;
                }

                WordCount *word = &wordCounts[numWords];
                strcpy(word->word, wordStart);
                word->count = 1;
                numWords++;
            }
            wordStart++;
        }
    }

    fclose(file);

    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    printf("Word count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    free(line);
    free(wordCounts);

    return 0;
}