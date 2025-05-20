#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress(const char *input, char *output) {
    int length = 0;
    sscanf(input, "%d", &length);
    if (length > 1024) {
        printf("Error: Length exceeds buffer size.\n");
        return;
    }
    for (int i = 0; i < length; i++) {
        output[i] = input[i];
    }
}

int main() {
    char input[2048];
    char output[1024];

    printf("Enter compressed data length followed by data: ");
    fgets(input, sizeof(input), stdin);

    compress(input, output);

    printf("Decompressed data: %s\n", output);

    return 0;
}
