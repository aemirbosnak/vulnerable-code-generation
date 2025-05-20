#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

// Pseudo Compression Algorithm: Reverse and Duplicate
void compress(char *input, char *output) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        output[i] = input[len - 1 - i];
        if (i % 5 == 0 && i != 0) output[i] = input[i];
    }
}

int main() {
    char input[1024];
    char output[1024];
    printf("Enter a string to compress:\n");
    fgets(input, sizeof(input), stdin);

    compress(input, output);
    printf("Compressed string:\n%s\n", output);
    return 0;
}
