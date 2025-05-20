//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define BUFFER_SIZE 1024

void compress(char *input, int length, char *output) {
    int i, j, k;
    int count = 0;
    char c;
    char prev = 0;
    char curr = 0;
    char next = 0;

    for (i = 0; i < length; i++) {
        c = input[i];

        if (c == prev) {
            count++;
            if (count > 2) {
                output[j] = (char)((prev << 2) + (count - 1));
                j++;
                count = 1;
            }
        } else {
            count = 1;
        }

        prev = c;
        curr = c;
        next = input[i + 1];
    }

    if (count > 0) {
        output[j] = (char)((prev << 2) + (count - 1));
        j++;
    }

    output[j] = 0;
}

int main() {
    char input[] = "Hello World!";
    char output[BUFFER_SIZE];
    int length = strlen(input);

    compress(input, length, output);

    printf("Compressed string: %s\n", output);

    return 0;
}