//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1024
#define MAX_DICTIONARY_SIZE 10000
#define MAX_WRONG_WORDS 1000

// Function declarations
void to_lowercase(char *str);
int load_dictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH]);
int check_spelling(FILE *file, char dictionary[][MAX_WORD_LENGTH], int dict_size);
void separate_words(const char *line, char words[][MAX_WORD_LENGTH], int *word_count);
int is_word_in_dictionary(const char *word, char dictionary[][MAX_WORD_LENGTH], int dict_size);

int main() {
    char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH];
    char filename[100];
    int dictionary_size;

    printf("What is the name of the dictionary file? ");
    scanf("%s", filename);

    dictionary_size = load_dictionary(filename, dictionary);
    if (dictionary_size == -1) {
        printf("Error loading dictionary. Please check the file and try again.\n");
        return EXIT_FAILURE;
    }

    printf("Loaded dictionary with %d words.\n", dictionary_size);
    
    printf("Now, enter the filename of the text to spell check: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s for reading.\n", filename);
        return EXIT_FAILURE;
    }

    int misspelled_count = check_spelling(file, dictionary, dictionary_size);
    fclose(file);
    
    printf("Spell checking completed. Found %d misspelled words.\n", misspelled_count);
    
    return EXIT_SUCCESS;
}

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char) str[i]);
    }
}

int load_dictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return -1;
    }

    int count = 0;
    while (fgets(dictionary[count], MAX_WORD_LENGTH, file) != NULL && count < MAX_DICTIONARY_SIZE) {
        dictionary[count][strcspn(dictionary[count], "\n")] = 0; // Remove newline
        to_lowercase(dictionary[count]);
        count++;
    }

    fclose(file);
    return count;
}

int check_spelling(FILE *file, char dictionary[][MAX_WORD_LENGTH], int dict_size) {
    char line[MAX_LINE_LENGTH];
    char words[MAX_WRONG_WORDS][MAX_WORD_LENGTH];
    int misspelled_count = 0;

    while (fgets(line, sizeof(line), file)) {
        int word_count = 0;
        separate_words(line, words, &word_count);

        for (int i = 0; i < word_count; i++) {
            if (!is_word_in_dictionary(words[i], dictionary, dict_size)) {
                printf("Misspelled: %s\n", words[i]);
                misspelled_count++;
            }
        }
    }

    return misspelled_count;
}

void separate_words(const char *line, char words[][MAX_WORD_LENGTH], int *word_count) {
    const char *delimiters = " ,.;:!?\n";
    char *token;
    char *line_copy = strdup(line);

    token = strtok(line_copy, delimiters);
    *word_count = 0;

    while (token != NULL) {
        to_lowercase(token);
        strncpy(words[*word_count], token, MAX_WORD_LENGTH);
        (*word_count)++;
        token = strtok(NULL, delimiters);
    }

    free(line_copy);
}

int is_word_in_dictionary(const char *word, char dictionary[][MAX_WORD_LENGTH], int dict_size) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Word is found
        }
    }
    return 0; // Word not found
}