//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 1000000
#define HASH_FUNCTION(word) (hash(word) % MAX_DICTIONARY_SIZE)

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} DictionaryEntry;

DictionaryEntry dictionary[MAX_DICTIONARY_SIZE];

unsigned int hash(char* word) {
    unsigned int hash = 0;
    while (*word) {
        hash = (hash << 2) + (*word);
        word++;
    }
    return hash;
}

void load_dictionary(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    DictionaryEntry entry;
    int count = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (count >= MAX_DICTIONARY_SIZE) {
            printf("Error: dictionary is full.\n");
            exit(1);
        }

        strcpy(entry.word, word);
        entry.is_correct = true;
        dictionary[count++] = entry;
    }

    fclose(file);
}

bool check_spelling(char* word) {
    unsigned int index = HASH_FUNCTION(word);

    for (int i = index; i < MAX_DICTIONARY_SIZE; i += HASH_FUNCTION(word)) {
        if (strcmp(dictionary[i].word, word) == 0) {
            return true;
        }
    }

    return false;
}

int main() {
    load_dictionary("dictionary.txt");

    char input[MAX_WORD_LENGTH];
    while (fgets(input, MAX_WORD_LENGTH, stdin)!= NULL) {
        char* word = strtok(input, ",.?!;:");

        while (word!= NULL) {
            if (check_spelling(word)) {
                printf("%s\n", word);
            } else {
                printf("%s\n", word);
            }

            word = strtok(NULL, ",.?!;:");
        }
    }

    return 0;
}