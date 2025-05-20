//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PATTERN_LENGTH 100
#define MAX_ROWS 100

// Function to print a given pattern
void print_pattern(char pattern[], int rows) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < strlen(pattern); j++) {
            printf("%c", pattern[j]);
        }
        printf("\n");
    }
}

// Function to generate a pattern
void generate_pattern(char pattern[], int rows) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < strlen(pattern); j++) {
            pattern[j] = '*';
        }
        pattern[strlen(pattern)] = '\0';
    }
}

int main() {
    char pattern[MAX_PATTERN_LENGTH];
    int rows;

    // Get the pattern length from the user
    printf("Enter the pattern length: ");
    scanf("%d", &rows);

    // Get the pattern from the user
    printf("Enter the pattern: ");
    scanf("%s", pattern);

    // Generate the pattern
    generate_pattern(pattern, rows);

    // Print the pattern
    printf("The pattern is:\n");
    print_pattern(pattern, rows);

    return 0;
}