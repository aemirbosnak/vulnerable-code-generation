//FormAI DATASET v1.0 Category: Compression algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Input string to be compressed
    char str[100];
    printf("Enter the string to be compressed: ");
    fgets(str, 100, stdin);

    // Count the frequency of characters in the string
    int freq[256];
    memset(freq, 0, sizeof(freq));
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        freq[str[i]]++;
    }

    // Create an array to store the distinct characters in the input string
    char chars[256];
    int num_chars = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            chars[num_chars++] = i;
        }
    }

    // Print the original string and the frequency of characters
    printf("\nOriginal string: %s\n", str);
    printf("Frequency of characters:\n");
    for (int i = 0; i < num_chars; i++) {
        printf("%c: %d\n", chars[i], freq[chars[i]]);
    }

    // Sort the distinct characters based on their frequency
    for (int i = 0; i < num_chars - 1; i++) {
        for (int j = i + 1; j < num_chars; j++) {
            if (freq[chars[i]] < freq[chars[j]]) {
                char temp = chars[i];
                chars[i] = chars[j];
                chars[j] = temp;
            }
        }
    }

    // Print the sorted characters based on frequency
    printf("\nSorted characters based on frequency:\n");
    for (int i = 0; i < num_chars; i++) {
        printf("%c\n", chars[i]);
    }

    // Create the compressed string using the sorted characters and frequency
    char compressed[256];
    int cmp_idx = 0;
    for (int i = 0; i < num_chars; i++) {
        int freq_val = freq[chars[i]];
        compressed[cmp_idx++] = chars[i];
        compressed[cmp_idx++] = ':';
        while (freq_val) {
            compressed[cmp_idx++] = (freq_val % 10) + '0';
            freq_val /= 10;
        }
        compressed[cmp_idx++] = ',';
    }
    compressed[cmp_idx - 1] = '\0';

    // Print the compressed string
    printf("\nCompressed string: %s\n", compressed);

    return 0;
}