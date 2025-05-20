//Code Llama-13B DATASET v1.0 Category: Compression algorithms ; Style: rigorous
/*
 * Example C Compression Algorithm
 *
 * This algorithm compresses a string by replacing repeated characters with a
 * single character and a count of the number of times it appears.
 *
 * For example, the string "aaabbbccc" would be compressed to "a3b3c3".
 */

#include <stdio.h>
#include <string.h>

// Function to compress a string
char* compress(char* str) {
    int i, j, count;
    char* compressed = malloc(strlen(str) * sizeof(char));
    compressed[0] = str[0];
    count = 1;
    for (i = 1, j = 1; i < strlen(str); i++) {
        if (str[i] == str[i - 1]) {
            count++;
        } else {
            compressed[j++] = count + '0';
            compressed[j++] = str[i];
            count = 1;
        }
    }
    compressed[j++] = count + '0';
    compressed[j] = '\0';
    return compressed;
}

// Function to decompress a string
char* decompress(char* compressed) {
    int i, j, count;
    char* str = malloc(strlen(compressed) * sizeof(char));
    str[0] = compressed[0];
    for (i = 1, j = 1; i < strlen(compressed); i++) {
        if (compressed[i] >= '0' && compressed[i] <= '9') {
            count = compressed[i] - '0';
            while (count-- > 0) {
                str[j++] = compressed[i - 1];
            }
        } else {
            str[j++] = compressed[i];
        }
    }
    str[j] = '\0';
    return str;
}

int main() {
    char* str = "aaabbbccc";
    char* compressed = compress(str);
    printf("Compressed string: %s\n", compressed);
    char* decompressed = decompress(compressed);
    printf("Decompressed string: %s\n", decompressed);
    return 0;
}