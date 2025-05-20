//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

struct word dictionary[MAX_WORDS];
int dictionary_size = 0;

void load_dictionary(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (dictionary_size >= MAX_WORDS) {
            printf("Error: dictionary is full.\n");
            exit(1);
        }

        strcpy(dictionary[dictionary_size].word, word);
        dictionary[dictionary_size].count = 0;
        dictionary_size++;
    }

    fclose(file);
}

int compare_words(const void* a, const void* b) {
    struct word* word1 = (struct word*)a;
    struct word* word2 = (struct word*)b;

    return strcmp(word1->word, word2->word);
}

void spell_check(char* text) {
    int i, j, k;

    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            char word[MAX_WORD_LENGTH];
            int word_length = 0;

            for (j = i; j < strlen(text) && isalpha(text[j]); j++) {
                word[word_length++] = tolower(text[j]);
            }
            word[word_length] = '\0';

            qsort(dictionary, dictionary_size, sizeof(struct word), compare_words);

            for (k = 0; k < dictionary_size; k++) {
                if (strcmp(word, dictionary[k].word) == 0) {
                    break;
                }
            }

            if (k == dictionary_size) {
                printf("Misspelled word: %s\n", word);
            }
        }
    }
}

int main() {
    char text[100000];

    printf("Enter text to spell check: ");
    fgets(text, sizeof(text), stdin);

    load_dictionary("dictionary.txt");
    spell_check(text);

    return 0;
}