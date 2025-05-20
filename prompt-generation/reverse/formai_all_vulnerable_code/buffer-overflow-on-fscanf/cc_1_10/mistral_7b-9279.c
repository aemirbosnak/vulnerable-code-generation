//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DICTIONARY_SIZE 20

typedef struct {
    char *english;
    char *alien;
} WordPair;

void load_dictionary(WordPair dictionary[], const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        exit(EXIT_FAILURE);
    }

    int index = 0;
    while (fscanf(file, "%s%s", dictionary[index].english, dictionary[index].alien) != EOF) {
        index++;
    }

    fclose(file);
}

int find_index_by_english_word(const WordPair dictionary[], int size, const char *word) {
    for (int i = 0; i < size; i++) {
        if (strcmp(dictionary[i].english, word) == 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    WordPair dictionary[DICTIONARY_SIZE];
    load_dictionary(dictionary, "dictionary.txt");

    char input_word[50];
    printf("Enter an English word: ");
    scanf("%s", input_word);

    int index = find_index_by_english_word(dictionary, DICTIONARY_SIZE, input_word);

    if (index >= 0) {
        printf("Alien translation of \"%s\": %s\n", input_word, dictionary[index].alien);
    } else {
        printf("Sorry, we don't have a translation for that word.\n");
    }

    return 0;
}