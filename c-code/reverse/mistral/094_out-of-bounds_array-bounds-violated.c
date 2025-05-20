#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define WORD_SIZE 64

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    char word[WORD_SIZE];
    int word_count[256];
    int i, len;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    while ((len = fread(buffer, sizeof(char), BUFFER_SIZE, file)) > 0) {
        for (i = 0; i < len; ++i) {
            if (buffer[i] == ' ' || buffer[i] == '\n' || buffer[i] == '\t') {
                buffer[i] = '\0';
                if (i > WORD_SIZE - 1) {
                    printf("Buffer overflow detected\n");
                    return 1;
                }
                ++word_count[(int)buffer[i - 1]];

                i += strlen(buffer + i) - 1;
                if (i >= len) break;
            }
        }
    }

    fclose(file);

    for (i = 0; i < 256; ++i) {
        if (word_count[i])
            printf("%c: %d\n", i, word_count[i]);
    }

    return 0;
}
