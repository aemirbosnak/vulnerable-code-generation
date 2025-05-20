//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to count the number of words in a string
int word_count(char *str) {
    int count = 0;
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalnum(str[i])) {
            if (!in_word) {
                count++;
                in_word = 1;
            }
        } else {
            in_word = 0;
        }
    }

    return count;
}

// Function to count the number of lines in a string
int line_count(char *str) {
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            count++;
        }
    }

    return count;
}

// Function to count the number of characters in a string
int char_count(char *str) {
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        count++;
    }

    return count;
}

// Function to count the number of vowels in a string
int vowel_count(char *str) {
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }

    return count;
}

// Function to count the number of consonants in a string
int consonant_count(char *str) {
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if (isalpha(c) && c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
            count++;
        }
    }

    return count;
}

// Function to count the number of punctuation marks in a string
int punctuation_count(char *str) {
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (ispunct(str[i])) {
            count++;
        }
    }

    return count;
}

// Function to count the number of whitespace characters in a string
int whitespace_count(char *str) {
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            count++;
        }
    }

    return count;
}

// Function to print a histogram of the characters in a string
void char_histogram(char *str) {
    int counts[256] = {0};

    for (int i = 0; str[i] != '\0'; i++) {
        counts[str[i]]++;
    }

    for (int i = 0; i < 256; i++) {
        if (counts[i] > 0) {
            printf("%c: %d\n", i, counts[i]);
        }
    }
}

int main() {
    // Get the input string from the user
    char str[1000];
    printf("Enter a string: ");
    fgets(str, 1000, stdin);

    // Print the results
    printf("Word count: %d\n", word_count(str));
    printf("Line count: %d\n", line_count(str));
    printf("Character count: %d\n", char_count(str));
    printf("Vowel count: %d\n", vowel_count(str));
    printf("Consonant count: %d\n", consonant_count(str));
    printf("Punctuation count: %d\n", punctuation_count(str));
    printf("Whitespace count: %d\n", whitespace_count(str));
    printf("Character histogram:\n");
    char_histogram(str);

    return 0;
}