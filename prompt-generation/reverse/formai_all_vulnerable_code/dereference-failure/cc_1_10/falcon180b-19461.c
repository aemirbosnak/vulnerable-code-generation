//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    int n, i, j;
    char *input, *output;
    int *prefix_lengths;

    // Read input string
    printf("Enter a string (maximum %d characters): ", MAX_SIZE);
    scanf("%s", input);
    n = strlen(input);

    // Initialize prefix lengths
    prefix_lengths = (int *) malloc(n * sizeof(int));
    memset(prefix_lengths, 0, n * sizeof(int));

    // Compute prefix lengths
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            if (i == j) {
                prefix_lengths[j] = 1;
            } else if (input[i] == input[j]) {
                prefix_lengths[j] = prefix_lengths[i] + 1;
            }
        }
    }

    // Compute longest common prefix
    int max_length = 0;
    for (i = 0; i < n; i++) {
        if (prefix_lengths[i] > max_length) {
            max_length = prefix_lengths[i];
        }
    }

    // Output longest common prefix
    output = (char *) malloc(max_length + 1);
    strncpy(output, input, max_length);
    output[max_length] = '\0';
    printf("Longest common prefix: %s\n", output);

    // Free memory
    free(prefix_lengths);
    free(output);

    return 0;
}