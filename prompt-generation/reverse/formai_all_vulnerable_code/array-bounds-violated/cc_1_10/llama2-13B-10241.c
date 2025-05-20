//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_PATTERN_LENGTH 100
#define MAX_NUMBER_OF_PATTERNS 10

// Structure to store a pattern and its corresponding number
typedef struct {
    char pattern[MAX_PATTERN_LENGTH];
    int number;
} pattern_t;

// Array to store all the patterns
pattern_t patterns[MAX_NUMBER_OF_PATTERNS];

// Function to generate a random pattern
void generate_pattern(pattern_t *pattern) {
    int i, j;
    for (i = 0; i < MAX_PATTERN_LENGTH; i++) {
        // Generate a random character
        char c = 'a' + (rand() % 26);
        // Add the character to the pattern
        pattern->pattern[i] = c;
        // If the character is a vowel, increase the chance of the next character being a consonant
        if (c == 'e' || c == 'a' || c == 'i' || c == 'o' || c == 'u') {
            j = i + 1;
            while (j < MAX_PATTERN_LENGTH && patterns[j].pattern[j] != ' ') {
                j++;
            }
            if (j < MAX_PATTERN_LENGTH) {
                // Increase the chance of the next character being a consonant
                patterns[j].pattern[j] = 'c' + (rand() % 26);
            }
        }
    }
    // Assign a unique number to the pattern
    pattern->number = rand() % 100;
}

// Function to print the patterns
void print_patterns(void) {
    int i;
    for (i = 0; i < MAX_NUMBER_OF_PATTERNS; i++) {
        printf("%d: %s\n", i, patterns[i].pattern);
    }
}

int main(void) {
    // Initialize the patterns and their corresponding numbers
    for (int i = 0; i < MAX_NUMBER_OF_PATTERNS; i++) {
        generate_pattern(&patterns[i]);
    }
    // Print the patterns
    print_patterns();
    return 0;
}