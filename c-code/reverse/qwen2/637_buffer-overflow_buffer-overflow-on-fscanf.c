#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 256
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
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    WordCount wordCounts[TOP_WORDS] = {0};
    char buffer[MAX_WORD_LENGTH];

    while (fscanf(file, "%s", buffer) == 1) {
        for (int i = 0; i < TOP_WORDS; i++) {
            if (strcmp(wordCounts[i].word, buffer) == 0) {
                wordCounts[i].count++;
                goto next_word;
            }
        }
        for (int i = 0; i < TOP_WORDS; i++) {
            if (wordCounts[i].count == 0) {
                strcpy(wordCounts[i].word, buffer);
                wordCounts[i].count = 1;
                goto next_word;
            }
        }
        qsort(wordCounts, TOP_WORDS, sizeof(WordCount), compare);
next_word:
        continue;
    }

    fclose(file);

    printf("Top %d words:\n", TOP_WORDS);
    for (int i = 0; i < TOP_WORDS && wordCounts[i].count > 0; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    return EXIT_SUCCESS;
}
