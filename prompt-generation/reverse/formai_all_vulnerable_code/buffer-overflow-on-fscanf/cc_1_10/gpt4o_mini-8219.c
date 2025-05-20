//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 1000
#define MAX_SUGGESTIONS 5

// Function prototypes
void load_dictionary(const char *filename, char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH], int *dict_size);
int levenshtein_distance(const char *s1, const char *s2);
void suggest_word(const char *misspelled_word, char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH], int dict_size);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return 1;
    }

    char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int dict_size = 0;
    load_dictionary(argv[1], dictionary, &dict_size);

    FILE *text_file = fopen(argv[2], "r");
    if (text_file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", argv[2]);
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(text_file, "%s", word) == 1) {
        // Normalize word: remove punctuation and convert to lowercase
        char normalized_word[MAX_WORD_LENGTH];
        int j = 0;
        for (int i = 0; word[i] != '\0'; i++) {
            if (isalpha(word[i])) {
                normalized_word[j++] = tolower(word[i]);
            }
        }
        normalized_word[j] = '\0';

        // Check if the normalized word is in the dictionary
        int found = 0;
        for (int i = 0; i < dict_size; i++) {
            if (strcmp(normalized_word, dictionary[i]) == 0) {
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Misspelled word: %s\n", normalized_word);
            suggest_word(normalized_word, dictionary, dict_size);
        }
    }

    fclose(text_file);
    return 0;
}

void load_dictionary(const char *filename, char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH], int *dict_size) {
    FILE *dict_file = fopen(filename, "r");
    if (dict_file == NULL) {
        fprintf(stderr, "Error: Could not open dictionary file %s\n", filename);
        exit(1);
    }

    while (fscanf(dict_file, "%s", dictionary[*dict_size]) == 1) {
        (*dict_size)++;
        if (*dict_size >= MAX_DICTIONARY_SIZE) {
            break;
        }
    }

    fclose(dict_file);
}

int levenshtein_distance(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int **d = malloc((len1 + 1) * sizeof(int*));
    for (int i = 0; i <= len1; i++) {
        d[i] = malloc((len2 + 1) * sizeof(int));
    }

    for (int i = 0; i <= len1; i++) d[i][0] = i;
    for (int j = 0; j <= len2; j++) d[0][j] = j;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = fmin(fmin(d[i - 1][j] + 1, d[i][j - 1] + 1), d[i - 1][j - 1] + cost);
        }
    }

    int distance = d[len1][len2];
    for (int i = 0; i <= len1; i++) free(d[i]);
    free(d);
    
    return distance;
}

void suggest_word(const char *misspelled_word, char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH], int dict_size) {
    char suggestions[MAX_SUGGESTIONS][MAX_WORD_LENGTH];
    int suggestion_count = 0;

    for (int i = 0; i < dict_size && suggestion_count < MAX_SUGGESTIONS; i++) {
        int distance = levenshtein_distance(misspelled_word, dictionary[i]);
        if (distance == 1) {
            strcpy(suggestions[suggestion_count], dictionary[i]);
            suggestion_count++;
        }
    }

    if (suggestion_count > 0) {
        printf("Did you mean: ");
        for (int i = 0; i < suggestion_count; i++) {
            printf("%s ", suggestions[i]);
        }
        printf("\n");
    } else {
        printf("No suggestions available.\n");
    }
}