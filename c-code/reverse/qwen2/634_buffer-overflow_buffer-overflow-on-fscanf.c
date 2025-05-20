#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 256

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    WordCount words[1000];
    int word_count = 0;

    while (1) {
        char word[MAX_WORD_LENGTH];
        int result = fscanf(file, "%s", word);
        if (result == EOF) break;
        if (result != 1) continue;

        int found = 0;
        for (int i = 0; i < word_count; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

        if (!found && word_count < 1000) {
            strcpy(words[word_count].word, word);
            words[word_count].count = 1;
            word_count++;
        }
    }

    fclose(file);

    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}
