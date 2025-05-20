//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wordA = (WordCount*)a;
    WordCount *wordB = (WordCount*)b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int numWords = 0;
    WordCount words[MAX_WORDS];

    file = fopen("example.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while ((read = getline(&line, &len, file))!= -1) {
        char *wordStart = line;
        char *wordEnd;

        while ((wordEnd = strpbrk(wordStart, ",.!?;:\"'"))!= NULL) {
            *wordEnd = '\0';
            wordStart = wordEnd + 1;

            if (numWords >= MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                exit(1);
            }

            strcpy(words[numWords].word, wordStart);
            words[numWords].count = 1;
            numWords++;
        }

        if (numWords >= MAX_WORDS) {
            printf("Maximum number of words reached.\n");
            exit(1);
        }

        strcpy(words[numWords].word, wordStart);
        words[numWords].count = 1;
        numWords++;
    }

    qsort(words, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    free(line);
    fclose(file);

    return 0;
}