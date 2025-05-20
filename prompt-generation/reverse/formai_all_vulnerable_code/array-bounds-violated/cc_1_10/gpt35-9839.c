//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000
#define ALPHA_LEN 256

int main() {

    char input[MAX_LEN];
    char compressed[MAX_LEN];
    char decompressed[MAX_LEN];
    int freq[ALPHA_LEN] = {0};
    int i, j, len, count = 0;

    printf("Enter string to compress: ");
    fgets(input, MAX_LEN, stdin);
    len = strlen(input);

    // Count frequency of each character
    for(i = 0; i < len; i++) {
        freq[input[i]]++;
    }

    // Print character frequency
    printf("\nCharacter Frequency:\n");
    for(i = 0; i < ALPHA_LEN; i++) {
        if(freq[i] > 0) {
            printf("%c: %d\n", i, freq[i]);
        }
    }

    // Compress string
    for(i = 0; i < len; i++) {
        if(freq[input[i]] > 0) {
            compressed[count++] = input[i];
            compressed[count++] = freq[input[i]] + '0';
            freq[input[i]] = 0;
        }
    }
    compressed[count] = '\0';

    // Print compressed string
    printf("\nCompressed String:\n%s\n", compressed);

    // Decompress string
    for(i = 0, j = 0; i < count; i += 2, j++) {
        int k;
        for(k = 0; k < compressed[i+1]-'0'; k++) {
            decompressed[j] = compressed[i];
            j++;
        }
        j--;
    }
    decompressed[j] = '\0';

    // Print decompressed string
    printf("\nDecompressed String:\n%s\n", decompressed);

    return 0;
}