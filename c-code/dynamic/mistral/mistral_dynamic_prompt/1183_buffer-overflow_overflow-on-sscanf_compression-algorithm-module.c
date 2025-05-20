#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256
#define BUFFER_COUNT 4

int compress(char *input, char *output) {
    int count = 0;
    int i = 0;

    if (sscanf(input, "%*[^%c%n]", &i) != 1)
        return 0;

    if (i > BUFFER_SIZE || i < BUFFER_SIZE / 2)
        return 0;

    strncpy(output, input, i);
    count = (int)(i * 0.75);

    for (int j = i; j < BUFFER_SIZE; j++)
        if (output[j] == output[count])
            output[j - count] = output[j];

    return count;
}

int main(int argc, char **argv) {
    char input[BUFFER_COUNT][BUFFER_SIZE];
    char output[BUFFER_SIZE];
    int result;

    for (int i = 1; i < argc; i++) {
        result = compress(argv[i], output);
        if (result > 0) {
            printf("%s compressed to %d bytes: %s\n", argv[i], result, output);
        } else {
            printf("%s is not compressible\n", argv[i]);
        }
    }

    return 0;
}
