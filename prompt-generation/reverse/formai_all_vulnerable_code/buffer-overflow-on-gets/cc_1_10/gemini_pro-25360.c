//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: statistical
// Statistical Word Count Tool

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare function prototypes
int count_words(const char *str);
void print_statistics(int word_count, int character_count, int line_count);

int main() {
    // Get the input string from the user
    char str[1000];
    printf("Enter a string: ");
    gets(str);

    // Count the words, characters, and lines in the string
    int word_count = count_words(str);
    int character_count = strlen(str);
    int line_count = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            line_count++;
        }
    }

    // Print the statistics
    print_statistics(word_count, character_count, line_count);

    return 0;
}

// Function to count the number of words in a string
int count_words(const char *str) {
    int word_count = 0;
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            in_word = 0;
        } else if (!in_word) {
            word_count++;
            in_word = 1;
        }
    }

    return word_count;
}

// Function to print the statistics
void print_statistics(int word_count, int character_count, int line_count) {
    printf("\nStatistical Analysis:\n");
    printf("Number of words: %d\n", word_count);
    printf("Number of characters: %d\n", character_count);
    printf("Number of lines: %d\n", line_count);
}