//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN + 1];
    int count;
} Word;

Word dictionary[MAX_WORDS];
int num_words = 0;

// Load the dictionary from a file
int load_dictionary(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    char line[MAX_WORD_LEN + 1];
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Remove the newline character
        line[strlen(line) - 1] = '\0';

        // Copy the word into the dictionary
        strcpy(dictionary[num_words].word, line);
        dictionary[num_words].count = 0;

        num_words++;
    }

    fclose(fp);

    return 0;
}

// Check if a word is in the dictionary
int is_in_dictionary(const char *word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            return 1;
        }
    }

    return 0;
}

// Spell check a document
int spell_check(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    char word[MAX_WORD_LEN + 1];
    while (fscanf(fp, "%s", word) != EOF) {
        // Remove punctuation marks
        int len = strlen(word);
        for (int i = 0; i < len; i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
                break;
            }
        }

        // Convert the word to lowercase
        for (int i = 0; i < len; i++) {
            word[i] = tolower(word[i]);
        }

        // Check if the word is in the dictionary
        if (!is_in_dictionary(word)) {
            printf("**%s** is not in the dictionary\n", word);
        }
    }

    fclose(fp);

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <dictionary_file> <document_file>\n", argv[0]);
        return -1;
    }

    // Load the dictionary
    if (load_dictionary(argv[1]) != 0) {
        printf("Error: could not load the dictionary\n");
        return -1;
    }

    // Spell check the document
    if (spell_check(argv[2]) != 0) {
        printf("Error: could not spell check the document\n");
        return -1;
    }

    printf("Spell check complete!\n");

    return 0;
}