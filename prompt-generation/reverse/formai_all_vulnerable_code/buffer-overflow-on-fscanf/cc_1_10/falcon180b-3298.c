//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000 // maximum number of words to store
#define MAX_WORD_LENGTH 20 // maximum length of a word

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

Word dictionary[MAX_WORDS]; // our dictionary of words
int num_words = 0; // number of words in the dictionary

void load_dictionary(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open dictionary file '%s'\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Error: dictionary is full\n");
            exit(1);
        }

        strcpy(dictionary[num_words].word, word);
        dictionary[num_words].is_correct = true;
        num_words++;
    }

    fclose(file);
}

bool is_word(const char* word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            return true;
        }
    }

    return false;
}

void suggest_corrections(const char* word) {
    char corrected_word[MAX_WORD_LENGTH];
    int corrected_word_length = 0;

    for (int i = 0; i < strlen(word); i++) {
        char c = tolower(word[i]);

        if (isalpha(c)) {
            corrected_word[corrected_word_length] = c;
            corrected_word_length++;
        }
    }

    corrected_word[corrected_word_length] = '\0';

    if (is_word(corrected_word)) {
        printf("Did you mean: %s\n", corrected_word);
    }
}

int main() {
    load_dictionary("dictionary.txt");

    char sentence[1000];
    printf("Enter a sentence to spell check: ");
    fgets(sentence, 1000, stdin);

    char word[MAX_WORD_LENGTH];
    char* token = strtok(sentence, ",.?!;:");

    while (token!= NULL) {
        strcpy(word, token);
        if (!is_word(word)) {
            suggest_corrections(word);
        }

        token = strtok(NULL, ",.?!;:");
    }

    return 0;
}