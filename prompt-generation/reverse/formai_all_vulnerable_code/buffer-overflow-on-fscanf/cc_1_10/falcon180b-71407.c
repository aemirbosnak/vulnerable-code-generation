//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20
#define DICTIONARY_FILE "dictionary.txt"

struct word {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
};

bool load_dictionary(struct word dictionary[MAX_WORDS]) {
    FILE *file = fopen(DICTIONARY_FILE, "r");

    if (file == NULL) {
        printf("Error: could not open dictionary file.\n");
        return false;
    }

    int count = 0;

    while (count < MAX_WORDS && fscanf(file, "%s %s", dictionary[count].english, dictionary[count].alien)!= EOF) {
        count++;
    }

    fclose(file);

    return true;
}

int main() {
    struct word dictionary[MAX_WORDS];

    if (!load_dictionary(dictionary)) {
        return 1;
    }

    char input[MAX_WORD_LENGTH];
    printf("Enter a word to translate: ");
    fgets(input, MAX_WORD_LENGTH, stdin);

    input[strcspn(input, "\n")] = '\0';

    struct word *word = NULL;

    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(dictionary[i].english, input) == 0) {
            word = &dictionary[i];
            break;
        }
    }

    if (word == NULL) {
        printf("Word not found in dictionary.\n");
    } else {
        printf("Alien translation: %s\n", word->alien);
    }

    return 0;
}