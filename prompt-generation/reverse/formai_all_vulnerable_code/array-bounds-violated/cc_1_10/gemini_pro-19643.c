//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum word length
#define MAX_WORD_LENGTH 100

// Define the maximum number of words in the dictionary
#define MAX_DICTIONARY_WORDS 10000

// Define the maximum number of suggestions to display
#define MAX_SUGGESTIONS 5

// Create a linked list node to store each word in the dictionary
typedef struct node {
    char word[MAX_WORD_LENGTH];
    struct node *next;
} node;

// Create a linked list to store the dictionary
node *dictionary = NULL;

// Load the dictionary from a file
void load_dictionary(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening dictionary file");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, fp)) {
        // Remove the newline character from the end of the word
        line[strlen(line) - 1] = '\0';

        // Create a new node to store the word
        node *new_node = malloc(sizeof(node));
        strcpy(new_node->word, line);

        // Add the new node to the linked list
        new_node->next = dictionary;
        dictionary = new_node;
    }

    fclose(fp);
}

// Check if a word is in the dictionary
int is_in_dictionary(char *word) {
    node *current = dictionary;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

// Get a list of suggestions for a misspelled word
char **get_suggestions(char *word) {
    // Create an array to store the suggestions
    char **suggestions = malloc(MAX_SUGGESTIONS * sizeof(char *));

    // Iterate over the dictionary and find words that are similar to the misspelled word
    node *current = dictionary;
    int i = 0;
    while (current != NULL && i < MAX_SUGGESTIONS) {
        if (strcmp(current->word, word) != 0 && levenshtein(current->word, word) < 3) {
            suggestions[i] = strdup(current->word);
            i++;
        }
        current = current->next;
    }

    // Return the array of suggestions
    return suggestions;
}

// Calculate the Levenshtein distance between two strings
int levenshtein(char *s1, char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);

    // Create a matrix to store the Levenshtein distances
    int matrix[m + 1][n + 1];

    // Initialize the first row and column of the matrix
    for (int i = 0; i <= m; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        matrix[0][j] = j;
    }

    // Calculate the Levenshtein distances for the rest of the matrix
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            matrix[i][j] = min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + cost);
        }
    }

    // Return the Levenshtein distance
    return matrix[m][n];
}

// Get the minimum of three integers
int min(int a, int b, int c) {
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

// Print the suggestions for a misspelled word
void print_suggestions(char **suggestions) {
    for (int i = 0; i < MAX_SUGGESTIONS; i++) {
        if (suggestions[i] != NULL) {
            printf("%s\n", suggestions[i]);
        }
    }
}

// Free the memory allocated for the suggestions
void free_suggestions(char **suggestions) {
    for (int i = 0; i < MAX_SUGGESTIONS; i++) {
        if (suggestions[i] != NULL) {
            free(suggestions[i]);
        }
    }
    free(suggestions);
}

// Get a word from the user
char *get_word(void) {
    char *word = malloc(MAX_WORD_LENGTH * sizeof(char));
    printf("Enter a word: ");
    scanf("%s", word);
    return word;
}

// Main function
int main(void) {
    // Load the dictionary from a file
    load_dictionary("dictionary.txt");

    // Get a word from the user
    char *word = get_word();

    // Check if the word is in the dictionary
    if (is_in_dictionary(word)) {
        printf("The word is spelled correctly.\n");
    } else {
        // Get a list of suggestions for the misspelled word
        char **suggestions = get_suggestions(word);

        // Print the suggestions
        printf("Did you mean one of these words?\n");
        print_suggestions(suggestions);

        // Free the memory allocated for the suggestions
        free_suggestions(suggestions);
    }

    // Free the memory allocated for the word
    free(word);

    return 0;
}