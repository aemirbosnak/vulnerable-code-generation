//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define DICT_FILE "dictionary.txt"

typedef struct {
    char word[MAX_WORD_LENGTH];
    int is_correct;
} Word;

typedef struct {
    Word *words;
    int num_words;
} Dictionary;

int load_dictionary(Dictionary *dict) {
    FILE *fp;
    char line[MAX_WORD_LENGTH];
    Word *word;
    int num_words = 0;

    fp = fopen(DICT_FILE, "r");
    if (fp == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return -1;
    }

    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        word = (Word *) malloc(sizeof(Word));
        strcpy(word->word, line);
        word->is_correct = 1;
        dict->words[num_words++] = *word;
    }

    fclose(fp);
    dict->num_words = num_words;

    return 0;
}

int is_word_correct(Word *word) {
    if (word->is_correct) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char text[1000];
    char word[MAX_WORD_LENGTH];
    int i, j, len;
    Dictionary dict;

    printf("Loading dictionary...\n");
    if (load_dictionary(&dict) == -1) {
        return -1;
    }

    printf("Enter text to spell check: ");
    fgets(text, sizeof(text), stdin);

    i = 0;
    while (text[i]!= '\0') {
        if (isalpha(text[i])) {
            j = i;
            while (isalnum(text[j])) {
                j++;
            }
            len = j - i;

            if (len > 0 && len <= MAX_WORD_LENGTH) {
                strncpy(word, &text[i], len);
                word[len] = '\0';

                if (!is_word_correct(&dict.words[0])) {
                    printf("Possible spelling error: %s\n", word);
                }
            }

            i = j;
        } else {
            i++;
        }
    }

    return 0;
}