//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

struct word dictionary[MAX_WORDS];
int num_words;

void load_dictionary(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < num_words && strcmp(dictionary[i].word, word)!= 0; i++) {
            // do nothing
        }
        if (i == num_words) {
            strcpy(dictionary[num_words].word, word);
            num_words++;
        }
        dictionary[i].count++;
    }

    fclose(fp);
}

void suggest_corrections(char* word) {
    int i, j, k, len;
    char* correct_word = NULL;
    int max_count = 0;

    for (i = 0; i < num_words; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            correct_word = dictionary[i].word;
            break;
        }
    }

    if (correct_word == NULL) {
        printf("Unknown word: %s\n", word);
        return;
    }

    for (i = 0; i < num_words; i++) {
        if (strcmp(dictionary[i].word, correct_word) == 0) {
            max_count = dictionary[i].count;
            break;
        }
    }

    for (j = 0; j < num_words; j++) {
        if (strcmp(dictionary[j].word, correct_word)!= 0 && dictionary[j].count == max_count) {
            printf("%s (%d occurrences)\n", dictionary[j].word, dictionary[j].count);
        }
    }
}

int main() {
    char word[MAX_WORD_LENGTH];

    load_dictionary("dictionary.txt");

    while (1) {
        printf("Enter a word to check: ");
        scanf("%s", word);

        suggest_corrections(word);
    }

    return 0;
}