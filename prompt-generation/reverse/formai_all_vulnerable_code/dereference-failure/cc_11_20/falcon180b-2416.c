//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    char *str = "AABCDABACADABBCABABCC";
    int n = strlen(str);
    int *freq = calloc(256, sizeof(int));
    int *prefix_count = calloc(MAX_SIZE, sizeof(int));
    int max_len = 0;
    int start = 0;

    // Count the frequency of each character
    for (int i = 0; i < n; i++) {
        freq[str[i]]++;
    }

    // Build the prefix count array
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (freq[str[i]] > 0) {
            prefix_count[j++] = freq[str[i]];
        }
    }

    // Build the suffix count array
    j = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (freq[str[i]] > 0) {
            prefix_count[j++] = freq[str[i]];
        }
    }

    // Build the prefix count array in reverse order
    for (int i = j - 1; i >= 0; i--) {
        prefix_count[i] += prefix_count[i + 1];
    }

    // Find the maximum length of a substring with all characters in the prefix count array
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < 256; j++) {
            if (freq[j] > 0 && str[i] == j) {
                count++;
            }
        }
        if (count == 256) {
            max_len = i + 1;
            break;
        }
    }

    // Find the longest substring with all characters in the prefix count array
    start = 0;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < 256; j++) {
            if (freq[j] > 0 && str[i] == j) {
                count++;
            }
        }
        if (count == 256) {
            int len = i + 1;
            if (len > max_len) {
                max_len = len;
                start = i - max_len + 1;
            }
        }
    }

    // Print the longest substring
    printf("Longest substring: ");
    for (int i = start; i < start + max_len; i++) {
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}