#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 1024
#define MAX_WORDS 10000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} Word;

int compare(const void *a, const void *b) {
    return ((Word *)b)->count - ((Word *)a)->count;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input.txt output.txt\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (!input) {
        perror("Error opening input file");
        return 1;
    }

    Word words[MAX_WORDS] = {0};
    char buffer[MAX_WORD_LEN];

    while (fscanf(input, "%s", buffer) == 1) {
        int found = 0;
        for (int i = 0; i < MAX_WORDS; i++) {
            if (strcmp(words[i].word, buffer) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }
        if (!found && strlen(buffer) > 0) {
            strcpy(words[words[0].count++].word, buffer);
        }
    }

    fclose(input);

    qsort(words, words[0].count, sizeof(Word), compare);

    FILE *output = fopen(argv[2], "w");
    if (!output) {
        perror("Error opening output file");
        return 1;
    }

    for (int i = 0; i < words[0].count; i++) {
        fprintf(output, "%s %d\n", words[i].word, words[i].count);
    }

    fclose(output);

    return 0;
}
