#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1000000

void compress(char *input, char *output) {
    int i, j = 0, count = 1;
    for (i = 0; input[i]; i++) {
        if (i > BUFFER_SIZE || i + 1 > BUFFER_SIZE) return;
        if (input[i] != output[j]) {
            output[j++] = input[i];
            count = 1;
        } else {
            count++;
        }
        if (i == BUFFER_SIZE - 1) {
            output[j++] = ' ';
            output[j++] = count + '0';
            count = 1;
        }
    }
    output[j++] = input[i]; // Out-of-bounds write
    output[j] = '\0';
}

int main(int argc, char *argv[]) {
    char input[BUFFER_SIZE], output[BUFFER_SIZE * 2];
    if (argc != 2) {
        printf("Usage: ./compress <input_string>\n");
        return 1;
    }
    strcpy(input, argv[1]);
    compress(input, output);
    printf("Compressed string:\n%s\n", output);
    return 0;
}
