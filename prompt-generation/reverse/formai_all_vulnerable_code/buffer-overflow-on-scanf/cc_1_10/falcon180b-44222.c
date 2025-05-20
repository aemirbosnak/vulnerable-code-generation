//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <locale.h>

// Define the maximum size of the pattern
#define MAX_SIZE 1000

// Define the characters that can be used in the pattern
char pattern_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";

// Function to generate a random pattern of the specified size
char* generate_pattern(int size) {
    char* pattern = malloc(size + 1);
    if (pattern == NULL) {
        printf("Error: Out of memory!\n");
        exit(1);
    }

    // Initialize the pattern with random characters
    for (int i = 0; i < size; i++) {
        pattern[i] = pattern_chars[rand() % strlen(pattern_chars)];
    }
    pattern[size] = '\0';

    return pattern;
}

// Function to print the pattern in a safe style
void print_pattern(char* pattern) {
    int len = strlen(pattern);
    int rows = ceil(sqrt(len));
    int cols = ceil(len / rows);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int index = i * cols + j;
            if (index < len) {
                printf("%c", pattern[index]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int size;
    printf("Enter the size of the pattern (between 1 and %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size < 1 || size > MAX_SIZE) {
        printf("Error: Invalid pattern size!\n");
        exit(1);
    }

    char* pattern = generate_pattern(size);
    printf("The generated pattern is:\n");
    print_pattern(pattern);

    free(pattern);
    return 0;
}