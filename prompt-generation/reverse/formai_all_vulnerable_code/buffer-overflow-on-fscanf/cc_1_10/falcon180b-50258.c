//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 10000
#define MAX_SUGGESTIONS 5

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} DictionaryEntry;

void load_dictionary(DictionaryEntry dictionary[], int *dictionary_size) {
    FILE *file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s", dictionary[count].word)!= EOF) {
        dictionary[count].is_correct = true;
        count++;
    }

    *dictionary_size = count;

    fclose(file);
}

void spell_check(char *word, DictionaryEntry dictionary[], int dictionary_size, int *suggestion_count) {
    int i = 0;
    while (i < dictionary_size && strcmp(word, dictionary[i].word)!= 0) {
        i++;
    }

    if (i == dictionary_size) {
        printf("Did you mean:\n");
        int j = 0;
        while (j < MAX_SUGGESTIONS && i < dictionary_size) {
            printf("%s\n", dictionary[i].word);
            i++;
            j++;
        }
        *suggestion_count = j;
    } else {
        printf("No suggestions.\n");
        *suggestion_count = 0;
    }
}

int main() {
    DictionaryEntry dictionary[MAX_DICTIONARY_SIZE];
    int dictionary_size = 0;

    load_dictionary(dictionary, &dictionary_size);

    char word[MAX_WORD_LENGTH];
    while (true) {
        printf("Enter a word to check: ");
        fgets(word, MAX_WORD_LENGTH, stdin);

        int suggestion_count = 0;
        spell_check(word, dictionary, dictionary_size, &suggestion_count);

        if (suggestion_count > 0) {
            printf("\n");
        }
    }

    return 0;
}