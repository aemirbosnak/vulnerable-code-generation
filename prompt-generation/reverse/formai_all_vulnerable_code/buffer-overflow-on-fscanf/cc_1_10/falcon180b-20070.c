//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_FILE "dictionary.txt"

struct word {
    char *word;
    bool is_correct;
};

void load_dictionary(struct word *dictionary, int *size);
bool check_word(struct word *dictionary, int size, char *word);

int main() {
    struct word dictionary[MAX_WORD_LENGTH];
    int dictionary_size = 0;
    load_dictionary(dictionary, &dictionary_size);

    char text[MAX_WORD_LENGTH];
    while (fgets(text, MAX_WORD_LENGTH, stdin)!= NULL) {
        char *word = strtok(text, ",.!?;:");
        while (word!= NULL) {
            if (check_word(dictionary, dictionary_size, word)) {
                printf("%s\n", word);
            } else {
                printf("Possible spelling mistake: %s\n", word);
            }
            word = strtok(NULL, ",.!?;:");
        }
    }

    return 0;
}

void load_dictionary(struct word *dictionary, int *size) {
    FILE *file = fopen(DICTIONARY_FILE, "r");
    if (file == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        dictionary[*size].word = strdup(word);
        dictionary[*size].is_correct = true;
        (*size)++;
    }

    fclose(file);
}

bool check_word(struct word *dictionary, int size, char *word) {
    for (int i = 0; i < size; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            return true;
        }
    }
    return false;
}