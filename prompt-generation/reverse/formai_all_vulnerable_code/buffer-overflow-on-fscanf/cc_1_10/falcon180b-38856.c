//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

void load_dictionary(Word dictionary[MAX_WORDS]) {
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s", dictionary[count].word)!= EOF) {
        dictionary[count].is_correct = true;
        count++;
    }

    fclose(fp);
}

bool is_word_correct(Word dictionary[MAX_WORDS], char word[MAX_WORD_LENGTH]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            return dictionary[i].is_correct;
        }
    }

    return false;
}

void correct_word(char word[MAX_WORD_LENGTH], bool is_correct) {
    if (is_correct) {
        printf("%s is spelled correctly.\n", word);
    } else {
        printf("%s is spelled incorrectly.\n", word);
    }
}

int main() {
    Word dictionary[MAX_WORDS];
    load_dictionary(dictionary);

    char input[MAX_WORD_LENGTH];
    while (fgets(input, MAX_WORD_LENGTH, stdin)!= NULL) {
        char word[MAX_WORD_LENGTH];
        strcpy(word, input);

        bool is_correct = is_word_correct(dictionary, word);
        correct_word(word, is_correct);
    }

    return 0;
}