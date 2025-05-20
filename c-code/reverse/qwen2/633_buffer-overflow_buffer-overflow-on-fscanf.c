#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 32
#define TOP_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    return ((WordCount *)b)->count - ((WordCount *)a)->count;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    WordCount wordCounts[TOP_WORDS] = {0};
    char buffer[MAX_WORD_LENGTH];

    while (fscanf(file, "%31s", buffer) == 1) {
        for (char *p = buffer; *p; p++) *p = tolower(*p);
        int found = 0;
        for (int i = 0; i < TOP_WORDS; i++) {
            if (strcmp(wordCounts[i].word, buffer) == 0) {
                wordCounts[i].count++;
                found = 1;
                break;
            }
        }
        if (!found && wordCounts[TOP_WORDS - 1].count > 0) {
            strcpy(wordCounts[TOP_WORDS - 1].word, buffer);
            wordCounts[TOP_WORDS - 1].count = 1;
        }
    }

    qsort(wordCounts, TOP_WORDS, sizeof(WordCount), compare);

    fclose(file);

    printf("Top %d most frequent words:\n", TOP_WORDS);
    for (int i = 0; i < TOP_WORDS; i++) {
        if (wordCounts[i].count > 0)
            printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    return 0;
}
