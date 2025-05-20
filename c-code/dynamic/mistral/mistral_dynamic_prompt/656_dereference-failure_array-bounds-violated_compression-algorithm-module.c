#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void compress(char *input, char *output) {
    int length = strlen(input);
    int buffer[10];

    for (int i = 0; i < length; i++) {
        if (buffer[(input[i] - 'A')]++ > 1) {
            output[i] = 'a' + buffer[(input[i] - 'A')] - 2;
            buffer[(output[i] - 'a')] = 1;
        } else {
            output[i] = input[i];
        }
    }

    output[length] = '\0';
}

int main() {
    char input[256], output[256];
    printf("Enter a string to compress:\n");
    fgets(input, 256, stdin);
    compress(input, output);
    printf("Compressed string: %s\n", output);
    return 0;
}
