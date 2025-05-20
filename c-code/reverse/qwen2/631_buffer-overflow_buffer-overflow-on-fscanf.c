#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

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

    WordCount wordCounts[MAX_WORDS] = {0};
    char buffer[MAX_WORD_LENGTH];

    while (fscanf(file, "%s", buffer) != EOF) {
        for (int i = 0; buffer[i]; i++) {
            buffer[i] = tolower(buffer[i]);
        }
        int found = 0;
        for (int i = 0; i < MAX_WORDS; i++) {
            if (strcmp(wordCounts[i].word, buffer) == 0) {
                wordCounts[i].count++;
                found = 1;
                break;
            }
        }
        if (!found && strlen(buffer) > 0) {
            strcpy(wordCounts[wordCounts[0].count].word, buffer);
            wordCounts[wordCounts[0].count].count = 1;
        }
    }

    fclose(file);

    qsort(wordCounts, MAX_WORDS, sizeof(WordCount), compare);

    printf("Word Frequency:\n");
    for (int i = 0; i < MAX_WORDS && wordCounts[i].count > 0; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    return 0;
}
