//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_FILE "dictionary.txt"

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

void load_dictionary(Word *dictionary) {
    FILE *file = fopen(DICTIONARY_FILE, "r");
    if (!file) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", line)!= EOF) {
        strcpy(dictionary->word, line);
        dictionary->is_correct = true;
        dictionary++;
    }

    fclose(file);
}

void check_spelling(char *text, Word *dictionary) {
    char *word = strtok(text, " ");
    while (word!= NULL) {
        bool is_correct = false;
        Word *dictionary_word = dictionary;
        while (dictionary_word->word[0]!= '\0') {
            if (strcmp(word, dictionary_word->word) == 0) {
                is_correct = true;
                break;
            }
            dictionary_word++;
        }

        if (!is_correct) {
            printf("Possible spelling mistake: %s\n", word);
        }

        word = strtok(NULL, " ");
    }
}

int main() {
    Word dictionary[1000];
    load_dictionary(dictionary);

    char text[] = "The quick brown fox jumps over the lazy dog. ";
    check_spelling(text, dictionary);

    return 0;
}