//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 32
#define MAX_NUM_WORDS 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;
    return strcmp(wc1->word, wc2->word);
}

int main() {
    FILE *file = fopen("logfile.txt", "r");
    if (file == NULL) {
        printf("Error opening log file.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    WordCount words[MAX_NUM_WORDS];
    int numWords = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            if (numWords >= MAX_NUM_WORDS) {
                printf("Warning: maximum number of words reached.\n");
                break;
            }
            strcpy(word, token);
            WordCount *wc = bsearch(word, words, numWords, sizeof(WordCount), compareWords);
            if (wc == NULL) {
                wc = &words[numWords++];
                strcpy(wc->word, word);
                wc->count = 1;
            } else {
                wc->count++;
            }
            token = strtok(NULL, " ");
        }
    }

    qsort(words, numWords, sizeof(WordCount), compareWords);

    printf("Word count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    fclose(file);
    return 0;
}