//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICT_SIZE 1000
#define MAX_SUGGESTIONS 5

typedef struct {
    char word[MAX_WORD_LENGTH];
    char suggestions[MAX_SUGGESTIONS][MAX_WORD_LENGTH];
    int suggestion_count;
} SpellCheckResult;

void load_dictionary(const char *filename, char dictionary[MAX_DICT_SIZE][MAX_WORD_LENGTH], int *dict_size);
void to_lowercase(char *str);
int is_in_dictionary(const char *word, char dictionary[MAX_DICT_SIZE][MAX_WORD_LENGTH], int dict_size);
void suggest_words(const char *word, char dictionary[MAX_DICT_SIZE][MAX_WORD_LENGTH], int dict_size, SpellCheckResult *result);
void spell_check_file(const char *filename, char dictionary[MAX_DICT_SIZE][MAX_WORD_LENGTH], int dict_size);
void print_results(SpellCheckResult *results, int count);

int main(int argc, char *argv[]) {
    char dictionary[MAX_DICT_SIZE][MAX_WORD_LENGTH];
    int dict_size = 0;

    if (argc != 3) {
        printf("Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return 1;
    }

    load_dictionary(argv[1], dictionary, &dict_size);
    spell_check_file(argv[2], dictionary, dict_size);

    return 0;
}

void load_dictionary(const char *filename, char dictionary[MAX_DICT_SIZE][MAX_WORD_LENGTH], int *dict_size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open dictionary file");
        exit(1);
    }
    
    while (fscanf(file, "%s", dictionary[*dict_size]) != EOF && *dict_size < MAX_DICT_SIZE) {
        to_lowercase(dictionary[*dict_size]);
        (*dict_size)++;
    }
    fclose(file);
}

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int is_in_dictionary(const char *word, char dictionary[MAX_DICT_SIZE][MAX_WORD_LENGTH], int dict_size) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Found in dictionary
        }
    }
    return 0; // Not found in dictionary
}

void suggest_words(const char *word, char dictionary[MAX_DICT_SIZE][MAX_WORD_LENGTH], int dict_size, SpellCheckResult *result) {
    result->suggestion_count = 0;
    for (int i = 0; i < dict_size && result->suggestion_count < MAX_SUGGESTIONS; i++) {
        if (strncmp(dictionary[i], word, 1) == 0) {
            strcpy(result->suggestions[result->suggestion_count], dictionary[i]);
            result->suggestion_count++;
        }
    }
}

void spell_check_file(const char *filename, char dictionary[MAX_DICT_SIZE][MAX_WORD_LENGTH], int dict_size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open text file");
        exit(1);
    }

    SpellCheckResult results[MAX_DICT_SIZE];
    int result_count = 0;
    char word[MAX_WORD_LENGTH];

    while (fscanf(file, "%s", word) != EOF) {
        to_lowercase(word);
        if (!is_in_dictionary(word, dictionary, dict_size)) {
            strcpy(results[result_count].word, word);
            suggest_words(word, dictionary, dict_size, &results[result_count]);
            result_count++;
        }
    }
    fclose(file);
    
    print_results(results, result_count);
}

void print_results(SpellCheckResult *results, int count) {
    printf("\nMisspelled Words and Suggestions:\n");
    for (int i = 0; i < count; i++) {
        printf("Word: %s\n", results[i].word);
        if (results[i].suggestion_count > 0) {
            printf("Suggestions: ");
            for (int j = 0; j < results[i].suggestion_count; j++) {
                printf("%s ", results[i].suggestions[j]);
            }
            printf("\n");
        } else {
            printf("No suggestions available.\n");
        }
        printf("--------------------------\n");
    }
}