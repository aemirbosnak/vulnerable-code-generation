//FormAI DATASET v1.0 Category: Spell checking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 50
#define DICT_SIZE 100000
#define WORDS_SIZE 1000000

// Structure for a dictionary word
typedef struct Word {
    char word[MAX_WORD_LENGTH];
    int frequency;
} Word;

// Function to compare two words
int compare_words(const void *a, const void *b) {
    Word *word_a = (Word *) a;
    Word *word_b = (Word *) b;

    return strcmp(word_a->word, word_b->word);
}

// Binary search to find a word in dictionary
bool binary_search(Word *dictionary, char *word, int dict_size) {
    int left = 0;
    int right = dict_size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (strcmp(dictionary[mid].word, word) == 0) {
            return true;
        } else if (strcmp(dictionary[mid].word, word) < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}

int main() {
    // Read dictionary words
    char dict_word[MAX_WORD_LENGTH];
    int dict_size = 0;
    Word *dictionary = (Word *) malloc(sizeof(Word) * DICT_SIZE);

    FILE *dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Error opening dictionary file\n");
        return 1;
    }

    while (fscanf(dict_file, "%s", dict_word) != EOF) {
        strcpy(dictionary[dict_size].word, dict_word);
        dictionary[dict_size].frequency = 0;
        dict_size++;
    }

    // Sort the dictionary
    qsort(dictionary, dict_size, sizeof(Word), compare_words);

    // Read words to be spell-checked
    char words[WORDS_SIZE];
    FILE *words_file = fopen("words.txt", "r");
    if (words_file == NULL) {
        printf("Error opening words file\n");
        return 1;
    }

    fread(words, sizeof(char), WORDS_SIZE, words_file);

    // Tokenize the words and spell-check
    char *word = strtok(words, " ,.!?\n");

    while (word != NULL) {
        // Convert word to lowercase
        for (int i = 0; word[i] != '\0'; i++) {
            word[i] = tolower(word[i]);
        }

        // Check if word is in dictionary
        if (binary_search(dictionary, word, dict_size)) {
            printf("%s is spelled correctly\n", word);
        } else {
            printf("%s is spelled incorrectly\n", word);
        }

        word = strtok(NULL, " ,.!?\n");
    }

    // Free memory
    free(dictionary);

    return 0;
}