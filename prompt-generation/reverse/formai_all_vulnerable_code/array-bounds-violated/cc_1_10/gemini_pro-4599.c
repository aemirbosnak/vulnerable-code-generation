//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

// Declare the dictionary
char *dictionary[MAX_WORDS];
int dictionary_size = 0;

// Load the dictionary from a file
void load_dictionary(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening dictionary file '%s'\n", filename);
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)) {
        // Remove the newline character from the end of the line
        line[strlen(line) - 1] = '\0';

        // Add the word to the dictionary
        dictionary[dictionary_size++] = strdup(line);
    }

    fclose(file);
}

// Check if a word is in the dictionary
int is_in_dictionary(char *word) {
    for (int i = 0; i < dictionary_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

// Get the closest word in the dictionary to the given word
char *get_closest_word(char *word) {
    int min_distance = -1;
    char *closest_word = NULL;

    for (int i = 0; i < dictionary_size; i++) {
        int distance = levenshtein(word, dictionary[i]);
        if (distance < min_distance || min_distance == -1) {
            min_distance = distance;
            closest_word = dictionary[i];
        }
    }

    return closest_word;
}

// Calculate the Levenshtein distance between two strings
int levenshtein(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // Create a matrix to store the distances
    int matrix[len1 + 1][len2 + 1];

    // Initialize the first row and column of the matrix
    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    // Calculate the distances
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            matrix[i][j] = min(matrix[i - 1][j] + 1,  // Deletion
                                matrix[i][j - 1] + 1,  // Insertion
                                matrix[i - 1][j - 1] + cost);  // Substitution
        }
    }

    // Return the distance
    return matrix[len1][len2];
}

// Get the minimum of three integers
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

// Get a word from the user
char *get_word() {
    char *word = malloc(MAX_WORD_LENGTH);
    if (word == NULL) {
        fprintf(stderr, "Error allocating memory for word\n");
        exit(1);
    }

    printf("Enter a word: ");
    scanf("%s", word);

    return word;
}

// Print the closest word in the dictionary to the given word
void print_closest_word(char *word) {
    char *closest_word = get_closest_word(word);
    if (closest_word == NULL) {
        printf("No closest word found\n");
    } else {
        printf("The closest word in the dictionary to '%s' is '%s'\n", word, closest_word);
    }
}

// Free the memory allocated for the dictionary
void free_dictionary() {
    for (int i = 0; i < dictionary_size; i++) {
        free(dictionary[i]);
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <dictionary_file>\n", argv[0]);
        exit(1);
    }

    // Load the dictionary
    load_dictionary(argv[1]);

    // Get a word from the user
    char *word = get_word();

    // Check if the word is in the dictionary
    if (is_in_dictionary(word)) {
        printf("The word '%s' is in the dictionary\n", word);
    } else {
        // Print the closest word in the dictionary to the given word
        print_closest_word(word);
    }

    // Free the memory allocated for the word
    free(word);

    // Free the memory allocated for the dictionary
    free_dictionary();

    return 0;
}