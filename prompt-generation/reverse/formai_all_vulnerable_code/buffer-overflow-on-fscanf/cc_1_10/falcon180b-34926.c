//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct word_t {
    char word[MAX_WORD_LENGTH];
    int count;
} word_t;

word_t words[MAX_WORDS];
int num_words = 0;

void read_words(FILE *file) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        word[strcspn(word, "\n")] = '\0'; // remove newline character
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == num_words) {
            strcpy(words[num_words].word, word);
            words[num_words].count = 1;
            num_words++;
        }
    }
}

void spell_check(FILE *file) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        word[strcspn(word, "\n")] = '\0'; // remove newline character
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(word, words[i].word) == 0) {
                printf("%s: %d\n", word, words[i].count);
                break;
            }
        }
        if (i == num_words) {
            printf("%s: 0\n", word);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return 1;
    }
    FILE *dict_file = fopen(argv[1], "r");
    if (dict_file == NULL) {
        printf("Error: could not open dictionary file.\n");
        return 1;
    }
    read_words(dict_file);
    fclose(dict_file);

    FILE *text_file = fopen(argv[2], "r");
    if (text_file == NULL) {
        printf("Error: could not open text file.\n");
        return 1;
    }
    spell_check(text_file);
    fclose(text_file);

    return 0;
}