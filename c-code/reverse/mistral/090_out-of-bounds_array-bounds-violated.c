#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define BUFFER_SIZE 2048

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    char word[MAX_WORD_LENGTH];
    int word_count = 0;
    int word_frequencies[MAX_WORD_LENGTH];

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(buffer, BUFFER_SIZE, file)) {
        int i = 0;
        for (; i < MAX_WORD_LENGTH && isalpha(buffer[i]); ++i) {
            word[i] = tolower(buffer[i]);
        }
        word[i] = '\0';
        ++word_count;
        word_frequencies[word_count]++;
    }

    for (int i = 1; i <= word_count; ++i) {
        printf("%s: %d\n", word, word_frequencies[i]);
    }

    fclose(file);
    return 0;
}
