//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024
#define MAX_WORD_SIZE 50

typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;

    return strcmp(wc1->word, wc2->word);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide a log file as an argument.\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    char line[MAX_LINE];
    WordCount *word_counts = NULL;
    int num_word_counts = 0;

    while (fgets(line, MAX_LINE, fp)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            WordCount *wc = (WordCount *) malloc(sizeof(WordCount));
            strncpy(wc->word, word, MAX_WORD_SIZE);
            wc->count = 1;

            int i;
            for (i = 0; i < num_word_counts; i++) {
                if (strcmp(wc->word, word_counts[i].word) == 0) {
                    word_counts[i].count++;
                    free(wc);
                    break;
                }
            }

            if (i == num_word_counts) {
                word_counts = (WordCount *) realloc(word_counts, sizeof(WordCount) * (num_word_counts + 1));
                memcpy(&word_counts[num_word_counts], wc, sizeof(WordCount));
                num_word_counts++;
            }

            word = strtok(NULL, " ");
        }
    }

    qsort(word_counts, num_word_counts, sizeof(WordCount), compareWords);

    printf("Word Count:\n");
    for (int i = 0; i < num_word_counts; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    fclose(fp);
    free(word_counts);

    return 0;
}