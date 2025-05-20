//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

void load_dictionary(Word *dict) {
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    int num_words = 0;
    while (fscanf(fp, "%s %d", dict[num_words].word, &dict[num_words].is_correct) == 2) {
        num_words++;
        if (num_words >= MAX_WORDS) {
            printf("Error: dictionary file too large.\n");
            exit(1);
        }
    }

    fclose(fp);
}

int main() {
    Word dict[MAX_WORDS];
    load_dictionary(dict);

    char text[MAX_WORD_LENGTH];
    printf("Enter text to spell check:\n");
    fgets(text, MAX_WORD_LENGTH, stdin);

    char *word = strtok(text, " ");
    while (word!= NULL) {
        bool is_correct = false;
        for (int i = 0; i < MAX_WORDS; i++) {
            if (strcmp(dict[i].word, word) == 0) {
                is_correct = dict[i].is_correct;
                break;
            }
        }

        if (!is_correct) {
            printf("%s is not a valid word.\n", word);
        }

        word = strtok(NULL, " ");
    }

    return 0;
}