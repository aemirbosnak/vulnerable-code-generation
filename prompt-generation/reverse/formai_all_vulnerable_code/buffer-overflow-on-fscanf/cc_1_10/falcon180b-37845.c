//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50
#define MIN_WORD_LENGTH 3

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} word_t;

word_t words[MAX_WORDS];
int num_words = 0;

void load_dictionary(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (strlen(word) >= MIN_WORD_LENGTH && strlen(word) <= MAX_WORD_LENGTH) {
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
    fclose(file);
}

bool is_word(char *word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(word, words[i].word) == 0) {
            return true;
        }
    }
    return false;
}

void spell_check(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }
    char line[1000];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (!is_word(word)) {
                printf("Misspelled word: %s\n", word);
            }
            word = strtok(NULL, ",.?!;:");
        }
    }
    fclose(file);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <dictionary> <file>\n", argv[0]);
        exit(1);
    }
    load_dictionary(argv[1]);
    spell_check(argv[2]);
    return 0;
}