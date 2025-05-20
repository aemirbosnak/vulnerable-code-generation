//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;

    return strcmp(wc1->word, wc2->word);
}

void printWordCounts(WordCount *wordCounts, int numWords) {
    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    WordCount wordCounts[1000];
    int numWords = 0;

    file = fopen("logfile.txt", "r");

    if (file == NULL) {
        printf("Error: Unable to open log file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *word = strtok(line, " ");

        while (word!= NULL) {
            int wordLength = strlen(word);

            if (wordLength > MAX_WORD_LENGTH) {
                printf("Warning: Word '%s' is too long and will be truncated.\n", word);
                wordLength = MAX_WORD_LENGTH - 1;
            }

            strncpy(wordCounts[numWords].word, word, wordLength);
            wordCounts[numWords].word[wordLength] = '\0';
            wordCounts[numWords].count++;
            numWords++;

            word = strtok(NULL, " ");
        }
    }

    fclose(file);

    printWordCounts(wordCounts, numWords);

    return 0;
}