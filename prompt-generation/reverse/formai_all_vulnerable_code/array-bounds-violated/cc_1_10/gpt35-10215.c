//FormAI DATASET v1.0 Category: Spell checking ; Style: Ken Thompson
#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_DICT_WORDS 10000

/**
 * A simple spell checking program in C.
 * Reads the dictionary from a file and checks for spelling errors in input text.
 * Words in dictionary file must be in lowercase with one word per line.
 * The input text is read from stdin and the misspelled words are printed to stdout.
 */

char dictionary[MAX_DICT_WORDS][MAX_WORD_LEN];
int dict_size = 0;

/**
 * Read the dictionary file and store the words in the dictionary array
 */
void read_dictionary(char *dict_file) {
    FILE *fp;
    fp = fopen(dict_file, "r");
    if (fp == NULL) {
        fprintf(stderr, "Could not open dictionary file\n");
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fgets(word, MAX_WORD_LEN, fp) != NULL) {
        // Convert the word to lowercase
        int i = 0;
        while (word[i] != '\0') {
            word[i] = tolower(word[i]);
            i++;
        }
        // Remove newline character
        word[i-1] = '\0';

        // Add word to dictionary
        strncpy(dictionary[dict_size], word, MAX_WORD_LEN);
        dict_size++;
    }
    fclose(fp);
}

/**
 * Search the dictionary for a given word.
 * Returns 1 if the word is found, else 0.
 */
int search_dictionary(char *word) {
    int i;
    for (i=0; i<dict_size; i++) {
        if (strcmp(dictionary[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}

/**
 * Check the spelling of a given word
 * Returns 1 if the word is spelled correctly, else 0
 */
int check_spelling(char *word) {
    // Convert the word to lowercase
    int i = 0;
    while (word[i] != '\0') {
        word[i] = tolower(word[i]);
        i++;
    }

    if (search_dictionary(word)) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * Read input from stdin and check the spelling of each word.
 * Output the misspelled words to stdout.
 */
void spell_check() {
    char word[MAX_WORD_LEN];
    while (scanf("%s", word) != EOF) {
        if (!check_spelling(word)) {
            printf("%s\n", word);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: spell_check <dictionary_file>\n");
        exit(1);
    }

    // Read the dictionary into the dictionary array
    read_dictionary(argv[1]);

    // Check the spelling of the input text
    spell_check();

    return 0;
}