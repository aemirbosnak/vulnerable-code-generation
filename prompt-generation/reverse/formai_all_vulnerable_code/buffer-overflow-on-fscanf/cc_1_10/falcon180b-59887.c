//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 50
#define DICTIONARY_SIZE 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} DictionaryEntry;

DictionaryEntry dictionary[DICTIONARY_SIZE];
int dictionary_size = 0;

void load_dictionary() {
    FILE *file = fopen("dictionary.txt", "r");
    char line[MAX_WORD_LENGTH];

    while (fscanf(file, "%s", line)!= EOF) {
        if (dictionary_size >= DICTIONARY_SIZE) {
            printf("Dictionary is full\n");
            break;
        }

        DictionaryEntry entry;
        strcpy(entry.word, line);
        entry.is_correct = true;
        dictionary[dictionary_size++] = entry;
    }

    fclose(file);
}

bool is_word_in_dictionary(char *word) {
    int i = 0;
    while (i < dictionary_size) {
        if (strcmp(dictionary[i].word, word) == 0) {
            return true;
        }
        i++;
    }
    return false;
}

void suggest_corrections(char *word) {
    int i = 0;
    while (i < dictionary_size) {
        if (strcmp(dictionary[i].word, word) == 0) {
            printf("%s\n", dictionary[i].word);
        } else if (strcasecmp(dictionary[i].word, word) == 0) {
            printf("%s\n", dictionary[i].word);
        }
        i++;
    }
}

int main() {
    load_dictionary();

    char text[100000];
    printf("Enter the text to spell check:\n");
    fgets(text, sizeof(text), stdin);

    char word[MAX_WORD_LENGTH];
    char *token = strtok(text, ",.?!;:");

    while (token!= NULL) {
        strcpy(word, token);
        if (!is_word_in_dictionary(word)) {
            suggest_corrections(word);
        }
        token = strtok(NULL, ",.?!;:");
    }

    return 0;
}