//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of words in a string
int count_words(char *str) {
    int count = 0;
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            in_word = 0;
        } else if (!in_word) {
            count++;
            in_word = 1;
        }
    }

    return count;
}

// Function to count the number of characters in a string
int count_chars(char *str) {
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        count++;
    }

    return count;
}

// Function to count the number of lines in a string
int count_lines(char *str) {
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            count++;
        }
    }

    return count;
}

// Function to print the word count, character count, and line count of a string
void print_counts(char *str) {
    int word_count = count_words(str);
    int char_count = count_chars(str);
    int line_count = count_lines(str);

    printf("Word count: %d\n", word_count);
    printf("Character count: %d\n", char_count);
    printf("Line count: %d\n", line_count);
}

// Main function
int main() {
    // Get the input string from the user
    char str[1000];
    printf("Enter a string: ");
    gets(str);

    // Print the word count, character count, and line count of the string
    print_counts(str);

    return 0;
}