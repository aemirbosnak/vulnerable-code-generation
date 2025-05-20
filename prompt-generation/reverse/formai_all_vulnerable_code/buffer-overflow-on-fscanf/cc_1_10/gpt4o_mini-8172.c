//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_SUGGESTIONS 5
#define DICTIONARY_SIZE 10000

// Function prototypes
int load_dictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH]);
int levenshtein_distance(const char *s1, const char *s2);
void suggest_corrections(char *misspelled_word, char dictionary[][MAX_WORD_LENGTH], int dict_size);

int main() {
    char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH];
    char input_word[MAX_WORD_LENGTH];
    int dict_size;

    dict_size = load_dictionary("dictionary.txt", dictionary);
    if (dict_size == 0) {
        fprintf(stderr, "Could not load the dictionary.\n");
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        fprintf(stderr, "Could not open input file.\n");
        return EXIT_FAILURE;
    }

    while (fscanf(input_file, "%s", input_word) != EOF) {
        // Convert to lowercase
        for (int i = 0; input_word[i]; i++) {
            input_word[i] = tolower(input_word[i]);
        }

        // Check against dictionary
        int found = 0;
        for (int j = 0; j < dict_size; j++) {
            if (strcmp(input_word, dictionary[j]) == 0) {
                found = 1;
                break;
            }
        }

        // If not found, suggest corrections
        if (!found) {
            printf("Misspelled: %s\n", input_word);
            suggest_corrections(input_word, dictionary, dict_size);
        }
    }

    fclose(input_file);
    return EXIT_SUCCESS;
}

// Load the dictionary from a file
int load_dictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return 0;
    }

    int count = 0;
    while (count < DICTIONARY_SIZE && fscanf(file, "%s", dictionary[count]) == 1) {
        count++;
    }

    fclose(file);
    return count;
}

// Calculate the Levenshtein distance between two strings
int levenshtein_distance(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int matrix[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++)
        matrix[i][0] = i;
    for (int j = 0; j <= len2; j++)
        matrix[0][j] = j;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            matrix[i][j] = fmin(fmin(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1), matrix[i - 1][j - 1] + cost);
        }
    }

    return matrix[len1][len2];
}

// Suggest potential corrections for a misspelled word
void suggest_corrections(char *misspelled_word, char dictionary[][MAX_WORD_LENGTH], int dict_size) {
    char suggestions[MAX_SUGGESTIONS][MAX_WORD_LENGTH];
    int suggestion_count = 0;

    for (int i = 0; i < dict_size && suggestion_count < MAX_SUGGESTIONS; i++) {
        if (levenshtein_distance(misspelled_word, dictionary[i]) <= 2) {
            strcpy(suggestions[suggestion_count++], dictionary[i]);
        }
    }

    if (suggestion_count > 0) {
        printf("Suggestions: ");
        for (int i = 0; i < suggestion_count; i++) {
            printf("%s ", suggestions[i]);
        }
        printf("\n");
    } else {
        printf("No suggestions available.\n");
    }
}