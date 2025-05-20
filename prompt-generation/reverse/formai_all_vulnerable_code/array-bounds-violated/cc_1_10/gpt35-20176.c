//FormAI DATASET v1.0 Category: Compression algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

int main() {
    char original_str[MAX_LEN+1];
    char compressed_str[MAX_LEN+1];
    int freq[MAX_LEN+1];
    int compress_idx = 0;
    int orig_idx = 0;
    int i, j, len;

    printf("Enter a string to compress: ");
    fgets(original_str, MAX_LEN, stdin);

    len = strlen(original_str);

    // Count frequencies of characters in the original string
    memset(freq, 0, sizeof(freq));
    for (i = 0; i < len; i++) {
        freq[(int)original_str[i]]++;
    }

    // Write the compressed string using characters and frequency counts
    while (orig_idx < len) {
        compressed_str[compress_idx++] = original_str[orig_idx];

        int count = 1;
        for (j = orig_idx+1; j < len && original_str[j] == original_str[orig_idx]; j++) {
            count++;
        }

        if (count > 1) {
            char count_str[5];
            snprintf(count_str, sizeof(count_str), "%d", count);
            int count_len = strlen(count_str);
            for (i = 0; i < count_len; i++) {
                compressed_str[compress_idx++] = count_str[i];
            }
        }

        orig_idx += count;
    }

    compressed_str[compress_idx] = '\0';

    printf("Compressed string: %s\n", compressed_str);

    return 0;
}