//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

void load_dictionary(char *filename, Word *dictionary) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    int num_words = 0;
    while (fscanf(fp, "%s", dictionary[num_words].word)!= EOF) {
        dictionary[num_words].is_correct = true;
        num_words++;
        if (num_words >= MAX_WORDS) {
            printf("Warning: dictionary truncated.\n");
            break;
        }
    }

    fclose(fp);
}

void check_spelling(char *text, Word *dictionary) {
    int i, j;
    bool in_word = false;
    char word[MAX_WORD_LENGTH];
    word[0] = '\0';

    for (i = 0; text[i]!= '\0'; i++) {
        if (isalnum(text[i])) {
            if (!in_word) {
                in_word = true;
                strncat(word, &text[i], 1);
            } else {
                strncat(word, &text[i], 1);
            }
        } else {
            in_word = false;

            j = 0;
            while (dictionary[j].is_correct &&
                   strcmp(word, dictionary[j].word)!= 0) {
                j++;
                if (j >= MAX_WORDS) {
                    printf("Misspelled word: %s\n", word);
                    break;
                }
            }

            if (dictionary[j].is_correct) {
                printf("Correct word: %s\n", word);
            }

            word[0] = '\0';
        }
    }

    if (in_word) {
        printf("Misspelled word: %s\n", word);
    }
}

int main() {
    Word dictionary[MAX_WORDS];
    load_dictionary("dictionary.txt", dictionary);

    char text[1000];
    printf("Enter text to check spelling:\n");
    fgets(text, sizeof(text), stdin);

    check_spelling(text, dictionary);

    return 0;
}