//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000
#define LINE_WIDTH 50

// Custom malloc function for debugging purposes
void *my_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed. Size: %ld\n", size);
        exit(EXIT_FAILURE);
    }
    return ptr;
}

// Function to print a given pattern
void print_pattern(int row) {
    int i, j;
    char symbols[] = {'*', 'o', 'x', 'O', 'e', 'E'};
    char *pattern;

    pattern = (char *) my_malloc(sizeof(char) * (LINE_WIDTH + 1));

    for (i = 0; i <= row; i++) {
        for (j = 0; j < LINE_WIDTH; j++) {
            int index = j + (LINE_WIDTH / 2 - i);
            if (index < 0)
                index += LINE_WIDTH;

            pattern[j] = symbols[index % 6];
        }
        pattern[LINE_WIDTH] = '\0';
        printf("%s\n", pattern);
    }

    free(pattern);
}

// Main function
int main() {
    int i, rows;

    printf("Enter the number of rows for the pattern: ");
    scanf("%d", &rows);

    if (rows <= 0 || rows > MAX_SIZE) {
        printf("Invalid number of rows. Exiting...\n");
        exit(EXIT_FAILURE);
    }

    print_pattern(rows);

    return 0;
}