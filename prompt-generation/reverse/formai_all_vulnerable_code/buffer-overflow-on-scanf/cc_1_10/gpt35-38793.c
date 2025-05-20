//FormAI DATASET v1.0 Category: Spell checking ; Style: Claude Shannon
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 20 // Maximum length of a word
#define NUM_LETTERS 26 // Number of letters in the alphabet

int main() {
    char dictionary[NUM_LETTERS][MAX_WORD_LENGTH] = { // Example dictionary
        "apple", "banana", "cherry", "date",
        "egg", "fig", "grape", "honey", "indigo",
        "juice", "kiwi", "lemon", "melon",
        "nectar", "orange", "pear", "quince",
        "raspberry", "strawberry", "tangerine",
        "umbrella", "violet", "watermelon", "xylophone",
        "yellow", "zebra"
    };
    int num_words = sizeof(dictionary) / sizeof(dictionary[0]); // Number of words in the dictionary

    char input_word[MAX_WORD_LENGTH]; // User input word
    printf("Enter a word to check its spelling: ");
    scanf("%s", input_word);

    // Convert user input word to lowercase for case-insensitive comparison
    for (int i = 0; input_word[i]; i++) {
        input_word[i] = tolower(input_word[i]);
    }

    int found = 0; // Flag to indicate if the word was found in the dictionary
    for (int i = 0; i < num_words; i++) {
        // Check if the dictionary word matches the user input word
        if (strcmp(dictionary[i], input_word) == 0) {
            found = 1; // Match found, set flag to true
            break;
        }
    }

    // Output result
    if (found) {
        printf("The word is spelled correctly.\n");
    } else {
        printf("The word is spelled incorrectly.\n");
        // Suggest alternative spellings
        printf("Did you mean:");
        for (int i = 0; i < num_words; i++) {
            // Calculate Levenshtein distance between dictionary word and user input word
            int dist = levenshtein_distance(dictionary[i], input_word);
            if (dist <= 2) { // Only suggest if distance is less than or equal to 2
                printf(" %s", dictionary[i]);
            }
        }
        printf("?\n");
    }

    return 0;
}

/**
 * Calculates the Levenshtein distance between two strings.
 * Code adapted from: https://en.wikipedia.org/wiki/Levenshtein_distance#Iterative_with_two_matrix_rows
 */
int levenshtein_distance(char *s, char *t) {
    int m = strlen(s);
    int n = strlen(t);
    int d[2][n + 1];
    for (int j = 0; j <= n; j++) {
        d[0][j] = j;
    }
    for (int i = 1; i <= m; i++) {
        d[i % 2][0] = i;
        for (int j = 1; j <= n; j++) {
            int cost = (s[i - 1] == t[j - 1]) ? 0 : 1;
            d[i % 2][j] = minimum(
                d[(i - 1) % 2][j] + 1,          // deletion
                d[i % 2][j - 1] + 1,            // insertion
                d[(i - 1) % 2][j - 1] + cost    // substitution
            );
        }
    }
    return d[m % 2][n];
}

/**
 * Returns the minimum of three integers.
 */
int minimum(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}