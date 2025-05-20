//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char input[100];
    char compressed[100];
    char decompressed[100];

    // Get input string from user
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Compress data using LZW algorithm
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    int o = 0;
    int p = 0;
    int q = 0;
    int r = 0;
    int s = 0;
    int t = 0;
    int u = 0;
    int v = 0;
    int w = 0;
    int x = 0;
    int y = 0;
    int z = 0;
    int *dictionary = (int *)malloc(sizeof(int) * 256);
    int dictionarySize = 0;

    // Initialize dictionary with first character of input string
    dictionary[input[0]] = i;
    i++;
    dictionarySize++;

    // Iterate through input string
    for (int j = 0; j < strlen(input); j++) {
        // Compare current character with characters in dictionary
        for (int k = 0; k < dictionarySize; k++) {
            if (input[j] == dictionary[k]) {
                // Update index of current character in dictionary
                dictionary[k] = j + 1;
                break;
            }
        }

        // No match found, add current character to dictionary
        if (k == dictionarySize) {
            dictionary[j + 1] = k;
            k++;
            dictionarySize++;
        }
    }

    // Compress input string
    for (int j = 0; j < strlen(input); j++) {
        if (j % 100 == 0) {
            printf("%d%% complete\r", j / 100);
        }
        if (input[j] == '\n') {
            break;
        }
    }

    // Decompress compressed data
    for (int i = 0; i < strlen(compressed); i++) {
        if (compressed[i] == '1') {
            if (decompressed[i] == '\n') {
                break;
            }
            decompressed[i] = input[j];
        }
    }

    // Print compressed and decompressed data
    printf("Compressed data: %s\n", compressed);
    printf("Decompressed data: %s\n", decompressed);

    // Free memory used by dictionary
    free(dictionary);

    return 0;
}