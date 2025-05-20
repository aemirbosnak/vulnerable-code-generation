//FormAI DATASET v1.0 Category: Spell checking ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_MISSPELLINGS 100
#define MAX_LINE_LENGTH 200

/* Struct to hold a misspelling */
typedef struct {
    char misspelled[MAX_WORD_LENGTH];
    int line_number;
} Misspelling;

/* Function prototypes */
bool is_letter(char c);
bool is_punctuation(char c);
void remove_punctuation(char *word);
void lowercase_word(char *word);
int binary_search(char word[MAX_WORD_LENGTH], char dictionary[][MAX_WORD_LENGTH], int num_words);
void check_word(char *word, int line_number, char dictionary[][MAX_WORD_LENGTH], int num_words, Misspelling *misspellings, int *num_misspellings);

int main(int argc, char **argv) {
    /* Check if a dictionary file was provided */
    if (argc != 2) {
        printf("Usage: spellcheck dictionary.txt\n");
        return 1;
    }

    /* Open the dictionary file */
    FILE *dict_file = fopen(argv[1], "r");

    /* Check if the dictionary file could be opened */
    if (!dict_file) {
        printf("Could not open dictionary file: %s\n", argv[1]);
        return 1;
    }

    /* Read the dictionary words into an array */
    char dictionary[10000][MAX_WORD_LENGTH];
    int num_words = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, dict_file)) {
        sscanf(line, "%s", dictionary[num_words]);
        num_words++;
    }

    /* Close the dictionary file */
    fclose(dict_file);

    /* Check if the user provided a file to spell check */
    if (argc != 3) {
        printf("Usage: spellcheck dictionary.txt file_to_check.txt\n");
        return 1;
    }

    /* Open the file to spell check */
    FILE *file_to_check = fopen(argv[2], "r");

    /* Check if the file to spell check could be opened */
    if (!file_to_check) {
        printf("Could not open file to check: %s\n", argv[2]);
        return 1;
    }

    /* Initialize the misspellings array */
    Misspelling misspellings[MAX_MISSPELLINGS];
    int num_misspellings = 0;

    /* Start checking each word in the file */
    char word[MAX_WORD_LENGTH];
    int line_number = 1;
    while (fscanf(file_to_check, "%s", word) != EOF) {
        /* Remove any punctuation from the word */
        remove_punctuation(word);

        /* Make the word lowercase */
        lowercase_word(word);

        /* Check the word against the dictionary */
        check_word(word, line_number, dictionary, num_words, misspellings, &num_misspellings);

        /* Check if we've reached the end of a line */
        char next_char = fgetc(file_to_check);
        if (next_char == '\n') {
            line_number++;
        }
        ungetc(next_char, file_to_check);
    }

    /* Close the file to spell check */
    fclose(file_to_check);

    /* Print out the misspelled words */
    printf("Misspelled words:\n");
    for (int i = 0; i < num_misspellings; i++) {
        printf("Line %d: %s\n", misspellings[i].line_number, misspellings[i].misspelled);
    }

    return 0;
}

/* Function to check if a character is a letter */
bool is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

/* Function to check if a character is punctuation */
bool is_punctuation(char c) {
    return c == '.' || c == ',' || c == ':' || c == ';' || c == '?' || c == '!';
}

/* Function to remove punctuation from a word */
void remove_punctuation(char *word) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (is_punctuation(word[i])) {
            memmove(&word[i], &word[i + 1], len - i);
            len--;
            i--;
        }
    }
}

/* Function to lowercase a word */
void lowercase_word(char *word) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            word[i] += ('a' - 'A');
        }
    }
}

/* Binary search function to find a word in the dictionary */
int binary_search(char word[MAX_WORD_LENGTH], char dictionary[][MAX_WORD_LENGTH], int num_words) {
    int low = 0, high = num_words - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(word, dictionary[mid]);
        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

/* Function to check a word against the dictionary */
void check_word(char *word, int line_number, char dictionary[][MAX_WORD_LENGTH], int num_words, Misspelling *misspellings, int *num_misspellings) {
    /* Check if the word is in the dictionary */
    if (binary_search(word, dictionary, num_words) == -1) {
        /* Add the misspelled word to the misspellings array */
        strcpy(misspellings[*num_misspellings].misspelled, word);
        misspellings[*num_misspellings].line_number = line_number;
        (*num_misspellings)++;
    }
}