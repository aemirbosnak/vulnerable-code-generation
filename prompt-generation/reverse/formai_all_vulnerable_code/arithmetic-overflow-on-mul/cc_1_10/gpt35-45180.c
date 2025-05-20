//FormAI DATASET v1.0 Category: Compression algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(char *input, char *compressed);
void decompress(char *compressed, char *decompressed);

int main() {
    char input[] = "hello world";
    char compressed[50];
    char decompressed[50];

    printf("Input: %s\n", input);

    compress(input, compressed);

    printf("Compressed: %s\n", compressed);

    decompress(compressed, decompressed);

    printf("Decompressed: %s\n", decompressed);

    return 0;
}

void compress(char *input, char *compressed) {
    int i = 0;
    int count = 1;
    char current = input[0];

    for (i = 1; i < strlen(input); i++) {
        if (input[i] == current) {
            count++;
        } else {
            sprintf(compressed + strlen(compressed), "%c%d", current, count);
            current = input[i];
            count = 1;
        }
    }

    sprintf(compressed + strlen(compressed), "%c%d", current, count);
}

void decompress(char *compressed, char *decompressed) {
    int i = 0;
    int count = 0;
    char current = compressed[0];

    for (i = 1; i < strlen(compressed); i++) {
        if (compressed[i] >= '0' && compressed[i] <= '9') {
            count = count * 10 + compressed[i] - '0';
        } else if (compressed[i] != current) {
            memset(decompressed + strlen(decompressed), current, count);
            current = compressed[i];
            count = 0;
        }
    }

    memset(decompressed + strlen(decompressed), current, count);
}