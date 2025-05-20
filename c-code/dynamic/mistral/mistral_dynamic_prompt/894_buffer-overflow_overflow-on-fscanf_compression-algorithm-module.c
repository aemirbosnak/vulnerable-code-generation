#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void compress(char *input, char *output) {
    int i, j = 0;
    char tmp[BUFFER_SIZE];

    for (i = 0; input[i] != '\0'; i++) {
        if (j >= BUFFER_SIZE - 1) {
            printf("Warning: Buffer overflow detected in compress function.\n");
            return;
        }

        if (i > 0 && input[i] == input[i - 1]) {
            tmp[j++] = input[i];
        } else {
            tmp[j++] = input[i];
            if (j > 0) {
                output[i / 8] |= (1 << (i % 8));
                if ((i % 8) == 7) {
                    output[i / 8 + 1] = tmp[0];
                }
                memset(tmp, 0, sizeof(tmp));
            }
        }
    }

    if (j > 0) {
        output[i / 8] |= (1 << (i % 8));
        if ((i % 8) == 7) {
            output[i / 8 + 1] = tmp[0];
        }
    }
}

int main(int argc, char *argv[]) {
    char input[1024], output[1024];
    FILE *file;
    int i;

    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 2;
    }

    fgets(input, sizeof(input), file);
    fclose(file);

    compress(input, output);

    printf("Compressed data: %s\n", output);

    return 0;
}
