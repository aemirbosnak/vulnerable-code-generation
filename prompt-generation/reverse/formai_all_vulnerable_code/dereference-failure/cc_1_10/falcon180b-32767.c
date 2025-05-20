//Falcon-180B DATASET v1.0 Category: Text processing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *word;
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;

    return strcmp(wc1->word, wc2->word);
}

void printWordCounts(WordCount *counts, int numWords) {
    qsort(counts, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        WordCount *wc = &counts[i];

        printf("%s: %d\n", wc->word, wc->count);
    }
}

int isWord(char *line, int start, int end) {
    while (start < end) {
        if (!isalpha(line[start])) {
            return 0;
        }

        start++;
    }

    return 1;
}

void countWords(char *line, WordCount *counts, int numWords) {
    int start = 0;
    int end = 0;

    while (end < strlen(line)) {
        if (isWord(line, start, end)) {
            WordCount *wc = &counts[numWords];

            strncpy(wc->word, &line[start], MAX_WORD_LENGTH);
            wc->word[MAX_WORD_LENGTH - 1] = '\0';
            wc->count = 1;

            numWords++;
        } else {
            end++;
        }
    }
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    WordCount counts[MAX_LINE_LENGTH];
    int numWords = 0;

    file = fopen("example.txt", "r");

    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        countWords(line, counts, numWords);
    }

    fclose(file);

    printWordCounts(counts, numWords);

    return 0;
}