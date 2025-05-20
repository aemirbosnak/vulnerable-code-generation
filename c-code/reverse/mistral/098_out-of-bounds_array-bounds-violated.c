#include <stdint.h>
#include <stddef.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    int word_count = 0;
    int words[MAX_WORD_LENGTH];
    int current_word = 0;

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
        for (int i = 0; buffer[i]; ++i) {
            if (buffer[i] == ' ' || buffer[i] == '\n') {
                words[current_word]++;
                if (++current_word >= MAX_WORD_LENGTH) {
                    break;
                }
            }
        }
    }

    fclose(file);

    for (int i = 0; i < current_word; ++i) {
        printf("Word %d: %d\n", i, words[i]);
    }

    return 0;
}
