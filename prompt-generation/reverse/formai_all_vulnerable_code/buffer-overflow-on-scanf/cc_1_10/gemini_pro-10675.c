//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a word is in the dictionary
int is_word_in_dict(char *word, char **dict, int num_words) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(word, dict[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to find the closest word in the dictionary to a given word
char *find_closest_word(char *word, char **dict, int num_words) {
    int min_distance = strlen(word);
    char *closest_word = NULL;

    for (int i = 0; i < num_words; i++) {
        int distance = levenshtein_distance(word, dict[i]);
        if (distance < min_distance) {
            min_distance = distance;
            closest_word = dict[i];
        }
    }

    return closest_word;
}

// Function to calculate the Levenshtein distance between two strings
int levenshtein_distance(char *s1, char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);

    // Create a matrix to store the distances
    int matrix[m + 1][n + 1];

    // Initialize the first row and column of the matrix
    for (int i = 0; i <= m; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        matrix[0][j] = j;
    }

    // Calculate the Levenshtein distance
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = min(min(matrix[i - 1][j], matrix[i][j - 1]), matrix[i - 1][j - 1]) + 1;
            }
        }
    }

    // Return the Levenshtein distance
    return matrix[m][n];
}

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

// Main function
int main() {
    // Load the dictionary
    char *dict[] = {"apple", "banana", "cherry", "dog", "elephant", "fish", "grape", "house", "ice cream", "juice"};
    int num_words = sizeof(dict) / sizeof(char *);

    // Get the input word from the user
    char word[100];
    printf("Enter a word: ");
    scanf("%s", word);

    // Check if the word is in the dictionary
    if (is_word_in_dict(word, dict, num_words)) {
        printf("The word is in the dictionary.\n");
    } else {
        printf("The word is not in the dictionary.\n");

        // Find the closest word in the dictionary
        char *closest_word = find_closest_word(word, dict, num_words);

        // Print the closest word
        printf("The closest word in the dictionary is: %s\n", closest_word);
    }

    return 0;
}