//Code Llama-13B DATASET v1.0 Category: Compression algorithms ; Style: calm
/*
 * Compression Algorithm
 *
 * This program takes a string as input and compresses it using a custom compression algorithm.
 * The algorithm works by finding repeating sequences of characters and replacing them with a single character and the number of times the sequence appears.
 * For example, the string "aaaabbbccc" would be compressed to "a4b3c3".
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Compression function
char *compress(char *str) {
    char *compressed = malloc(strlen(str) * sizeof(char));
    int i = 0, j = 0;

    while (str[i]) {
        int count = 1;
        while (str[i + 1] == str[i]) {
            count++;
            i++;
        }

        if (count == 1) {
            compressed[j++] = str[i];
        } else {
            compressed[j++] = str[i];
            compressed[j++] = count + '0';
        }

        i++;
    }

    compressed[j] = '\0';
    return compressed;
}

// Decompression function
char *decompress(char *compressed) {
    char *decompressed = malloc(strlen(compressed) * sizeof(char));
    int i = 0, j = 0;

    while (compressed[i]) {
        if (compressed[i + 1] >= '0' && compressed[i + 1] <= '9') {
            int count = compressed[i + 1] - '0';
            decompressed[j++] = compressed[i];
            i += 2;
            while (count--) {
                decompressed[j++] = compressed[i];
            }
        } else {
            decompressed[j++] = compressed[i++];
        }
    }

    decompressed[j] = '\0';
    return decompressed;
}

int main() {
    char *str = "aaaabbbccc";
    char *compressed = compress(str);
    printf("Compressed string: %s\n", compressed);
    char *decompressed = decompress(compressed);
    printf("Decompressed string: %s\n", decompressed);
    return 0;
}