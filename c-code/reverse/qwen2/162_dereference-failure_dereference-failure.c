#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORDS 10000

typedef struct {
    char *word;
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

    FILE *output = fopen(argv[2], "w");
    if (!output) {
        perror("Error opening output file");
        fclose(input);
        return 1;
    }

    Word words[MAX_WORDS];
    int word_count = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), input)) {
        char *token = strtok(line, " \n\t.,;:!?");
        while (token) {
            int found = 0;
            for (int i = 0; i < word_count; i++) {
                if (strcmp(words[i].word, token) == 0) {
                    words[i].count++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                if (word_count >= MAX_WORDS) {
                    fprintf(stderr, "Too many unique words\n");
                    fclose(input);
                    fclose(output);
                    return 1;
                }
                words[word_count].word = strdup(token);
                words[word_count].count = 1;
                word_count++;
            }
            token = strtok(NULL, " \n\t.,;:!?");
        }
    }

    qsort(words, word_count, sizeof(Word), compare);

    for (int i = 0; i < word_count; i++) {
        fprintf(output, "%s %d\n", words[i].word, words[i].count);
        free(words[i].word);
    }

    fclose(input);
    fclose(output);

    return 0;
}
