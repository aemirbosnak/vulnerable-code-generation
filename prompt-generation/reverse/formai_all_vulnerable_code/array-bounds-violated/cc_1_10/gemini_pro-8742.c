//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

// Create a new word
Word* new_word(char* word) {
    Word* w = malloc(sizeof(Word));
    strcpy(w->word, word);
    w->count = 1;
    return w;
}

// Compare two words
int compare_words(const void* a, const void* b) {
    Word* w1 = (Word*)a;
    Word* w2 = (Word*)b;
    return strcmp(w1->word, w2->word);
}

// Check if a word is in the dictionary
int in_dictionary(char* word, Word* dictionary, int size) {
    Word* w = new_word(word);
    int result = bsearch(w, dictionary, size, sizeof(Word), compare_words);
    free(w);
    return result != NULL;
}

// Load the dictionary into memory
Word* load_dictionary(char* filename, int* size) {
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        return NULL;
    }

    char line[MAX_WORD_LENGTH];
    Word* dictionary = malloc(sizeof(Word) * MAX_WORDS);
    int i = 0;
    while (fgets(line, MAX_WORD_LENGTH, f) != NULL) {
        line[strlen(line) - 1] = '\0'; // Remove the newline character
        Word* w = new_word(line);
        dictionary[i++] = *w;
    }

    fclose(f);

    qsort(dictionary, i, sizeof(Word), compare_words);

    *size = i;

    return dictionary;
}

// Check the spelling of a word
int check_spelling(char* word, Word* dictionary, int size) {
    return in_dictionary(word, dictionary, size);
}

// Get a word from the user
char* get_word() {
    char* word = malloc(MAX_WORD_LENGTH);
    scanf("%s", word);
    return word;
}

// Print a message
void print_message(char* message) {
    printf("%s\n", message);
}

// Main function
int main() {
    int size;
    Word* dictionary = load_dictionary("dictionary.txt", &size);

    if (dictionary == NULL) {
        print_message("Error loading dictionary");
        return 1;
    }

    char* word = get_word();

    while (strcmp(word, "quit") != 0) {
        if (check_spelling(word, dictionary, size)) {
            print_message("Correct spelling");
        } else {
            print_message("Incorrect spelling");
        }

        word = get_word();
    }

    free(dictionary);
    return 0;
}