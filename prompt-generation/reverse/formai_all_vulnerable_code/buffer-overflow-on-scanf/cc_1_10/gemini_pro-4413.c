//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize the dictionary
const char *dictionary[] = {
    "aardvark", "abacus", "abbey", "abdomen", "aberrant", "aberration", "abet", "abeyance", "abhor", "abhorrence"
};

// Check if a word is in the dictionary
int is_valid_word(const char *word) {
    for (int i = 0; i < sizeof(dictionary) / sizeof(char *); i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Print a list of suggestions for a misspelled word
void print_suggestions(const char *word) {
    for (int i = 0; i < sizeof(dictionary) / sizeof(char *); i++) {
        int distance = levenshtein_distance(word, dictionary[i]);
        if (distance <= 2) {
            printf("%s (%d)\n", dictionary[i], distance);
        }
    }
}

// Calculate the Levenshtein distance between two strings
int levenshtein_distance(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int matrix[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = fmin(fmin(matrix[i - 1][j], matrix[i][j - 1]), matrix[i - 1][j - 1]) + 1;
            }
        }
    }

    return matrix[len1][len2];
}

// Get a word from the user
char *get_word() {
    char *word = malloc(100);
    printf("Enter a word: ");
    scanf("%s", word);
    return word;
}

// Main function
int main() {
    char *word = get_word();

    if (is_valid_word(word)) {
        printf("The word is spelled correctly.\n");
    } else {
        printf("The word is misspelled.\n");
        printf("Suggestions:\n");
        print_suggestions(word);
    }

    free(word);
    return 0;
}