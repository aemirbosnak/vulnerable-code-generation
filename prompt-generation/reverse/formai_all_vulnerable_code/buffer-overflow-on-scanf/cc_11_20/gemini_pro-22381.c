//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main(void) {
    // Initialize variables
    char buffer[MAX_BUFFER_SIZE];
    int i, j, k;
    int n, m;

    // Get input from the user
    printf("Enter two integers, n and m: ");
    scanf("%d %d", &n, &m);

    // Check if n and m are valid
    if (n < 1 || n > MAX_BUFFER_SIZE || m < 1 || m > MAX_BUFFER_SIZE) {
        printf("Invalid input. n and m must be between 1 and %d.\n", MAX_BUFFER_SIZE);
        return 1;
    }

    // Generate a random string of length n
    for (i = 0; i < n; i++) {
        buffer[i] = 'a' + rand() % 26;
    }
    buffer[n] = '\0';

    // Print the original string
    printf("Original string: %s\n", buffer);

    // Encode the string using Shannon's method
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (buffer[i] == buffer[j]) {
                buffer[j] = (buffer[j] + 1) % 26 + 'a';
            }
        }
    }

    // Print the encoded string
    printf("Encoded string: %s\n", buffer);

    // Decode the string using Shannon's method
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (buffer[i] == buffer[j]) {
                buffer[j] = (buffer[j] - 1 + 26) % 26 + 'a';
            }
        }
    }

    // Print the decoded string
    printf("Decoded string: %s\n", buffer);

    return 0;
}