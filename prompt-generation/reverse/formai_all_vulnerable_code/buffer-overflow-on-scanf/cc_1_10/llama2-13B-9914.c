//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_CHARS 5

// Function to print a pattern
void print_pattern(int size, char background, char foreground, char *pattern) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                // Background character
                printf("%c", background);
            } else {
                // Foreground character
                printf("%c", foreground);
            }
        }
        printf("\n");
    }
}

int main() {
    int size, i;
    char background, foreground;
    char *pattern;

    // Get the pattern size and characters
    printf("Enter the pattern size (1-100): ");
    scanf("%d", &size);
    printf("Enter the background character (a-z): ");
    scanf(" %c", &background);
    printf("Enter the foreground character (a-z): ");
    scanf(" %c", &foreground);

    // Allocate memory for the pattern array
    pattern = malloc(size * sizeof(char));
    if (pattern == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Read the pattern characters from the user
    for (i = 0; i < size; i++) {
        printf("Enter the %dth character (a-z): ", i + 1);
        scanf(" %c", &pattern[i]);
    }

    // Print the pattern
    print_pattern(size, background, foreground, pattern);

    // Free the memory
    free(pattern);

    return 0;
}