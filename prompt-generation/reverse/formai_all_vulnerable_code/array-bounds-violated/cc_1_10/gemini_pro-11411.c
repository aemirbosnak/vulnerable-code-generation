//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_DICTIONARY_SIZE 10000

// Structure to store a word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} Word;

// Function to compare two words
int compare_words(const void *a, const void *b) {
    return strcmp((*(Word *)a).word, (*(Word *)b).word);
}

// Function to check if a word is in the dictionary
int is_word_in_dictionary(char *word, Word *dictionary, int dictionary_size) {
    Word *result = bsearch(word, dictionary, dictionary_size, sizeof(Word), compare_words);
    return result != NULL;
}

// Function to get the frequency of a word in the dictionary
int get_word_frequency(char *word, Word *dictionary, int dictionary_size) {
    Word *result = bsearch(word, dictionary, dictionary_size, sizeof(Word), compare_words);
    return result != NULL ? result->frequency : 0;
}

// Function to load the dictionary from a file
int load_dictionary(char *filename, Word *dictionary, int *dictionary_size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return -1;
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file) != NULL) {
        // Remove the newline character from the line
        line[strlen(line) - 1] = '\0';

        // Add the word to the dictionary
        strcpy(dictionary[*dictionary_size].word, line);
        dictionary[*dictionary_size].frequency = 0;
        (*dictionary_size)++;
    }

    fclose(file);

    return 0;
}

// Function to check the spelling of a word
int check_spelling(char *word, Word *dictionary, int dictionary_size) {
    return is_word_in_dictionary(word, dictionary, dictionary_size);
}

// Function to get the suggestions for a misspelled word
void get_suggestions(char *word, Word *dictionary, int dictionary_size, char **suggestions, int *suggestions_size) {
    *suggestions_size = 0;

    // Check if the word is only one character away from a word in the dictionary
    for (int i = 0; i < dictionary_size; i++) {
        int distance = levenshtein_distance(word, dictionary[i].word);
        if (distance == 1) {
            suggestions[*suggestions_size] = malloc(strlen(dictionary[i].word) + 1);
            strcpy(suggestions[*suggestions_size], dictionary[i].word);
            (*suggestions_size)++;
        }
    }
}

// Function to calculate the Levenshtein distance between two strings
int levenshtein_distance(char *a, char *b) {
    int n = strlen(a);
    int m = strlen(b);

    int d[n + 1][m + 1];

    // Initialize the first row and column of the matrix
    for (int i = 0; i <= n; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        d[0][j] = j;
    }

    // Calculate the rest of the matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int cost = (a[i - 1] == b[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + cost);
        }
    }

    // Return the value in the bottom-right corner of the matrix
    return d[n][m];
}

// Function to find the minimum of three numbers
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
    // Load the dictionary from a file
    Word dictionary[MAX_DICTIONARY_SIZE];
    int dictionary_size = 0;
    if (load_dictionary("dictionary.txt", dictionary, &dictionary_size) != 0) {
        return -1;
    }

    // Sort the dictionary
    qsort(dictionary, dictionary_size, sizeof(Word), compare_words);

    // Get the input word from the user
    char word[MAX_WORD_LENGTH];
    printf("Enter a word to check: ");
    scanf("%s", word);

    // Check the spelling of the word
    if (check_spelling(word, dictionary, dictionary_size)) {
        printf("The word is spelled correctly.\n");
    } else {
        printf("The word is misspelled.\n");

        // Get the suggestions for the misspelled word
        char *suggestions[MAX_WORD_LENGTH];
        int suggestions_size = 0;
        get_suggestions(word, dictionary, dictionary_size, suggestions, &suggestions_size);

        // Print the suggestions
        if (suggestions_size > 0) {
            printf("Suggestions:\n");
            for (int i = 0; i < suggestions_size; i++) {
                printf("%s\n", suggestions[i]);
                free(suggestions[i]);
            }
        } else {
            printf("No suggestions found.\n");
        }
    }

    return 0;
}