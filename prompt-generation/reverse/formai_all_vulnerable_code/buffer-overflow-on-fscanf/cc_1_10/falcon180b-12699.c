//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 30

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

void load_dictionary(char *dictionary_file, Word *dictionary) {
    FILE *file = fopen(dictionary_file, "r");
    if (file == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    int word_count = 0;
    while (fscanf(file, "%s", dictionary[word_count].word)!= EOF && word_count < MAX_WORDS) {
        dictionary[word_count].is_correct = true;
        word_count++;
    }

    fclose(file);
}

void check_spelling(char *word, Word *dictionary) {
    int word_length = strlen(word);
    if (word_length > MAX_WORD_LENGTH) {
        printf("Error: word is too long.\n");
        return;
    }

    bool is_correct = false;
    for (int i = 0; i < word_length; i++) {
        char c = toupper(word[i]);
        if (!isalpha(c)) {
            continue;
        }

        int j = 0;
        while (dictionary[j].is_correct && dictionary[j].word[0]!= c) {
            j++;
        }

        if (dictionary[j].word[0] == c) {
            int k = 0;
            while (k < word_length && dictionary[j].word[k] == word[k]) {
                k++;
            }

            if (k == word_length) {
                is_correct = true;
                break;
            }
        }
    }

    if (is_correct) {
        printf("The word is spelled correctly.\n");
    } else {
        printf("The word is spelled incorrectly.\n");
    }
}

int main() {
    Word dictionary[MAX_WORDS];
    load_dictionary("dictionary.txt", dictionary);

    char word[MAX_WORD_LENGTH];
    while (true) {
        printf("Enter a word to check: ");
        fgets(word, MAX_WORD_LENGTH, stdin);

        check_spelling(word, dictionary);
    }

    return 0;
}