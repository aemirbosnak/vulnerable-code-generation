#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int compare(const void *a, const void *b) {
    return ((Word *)b)->count - ((Word *)a)->count;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (!input) {
        perror("Failed to open input file");
        return 1;
    }

    Word words[MAX_WORDS] = {0};
    int word_count = 0;

    char buffer[MAX_WORD_LENGTH + 1];
    while (fscanf(input, "%s", buffer) == 1) {
        int found = 0;
        for (int i = 0; i < word_count; i++) {
            if (strcmp(words[i].word, buffer) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }
        if (!found && word_count < MAX_WORDS) {
            strcpy(words[word_count].word, buffer);
            words[word_count].count++;
            word_count++;
        }
    }

    fclose(input);

    qsort(words, word_count, sizeof(Word), compare);

    FILE *output = fopen(argv[2], "w");
    if (!output) {
        perror("Failed to open output file");
        return 1;
    }

    for (int i = 0; i < word_count; i++) {
        fprintf(output, "%s %d\n", words[i].word, words[i].count);
    }

    fclose(output);

    return 0;
}
