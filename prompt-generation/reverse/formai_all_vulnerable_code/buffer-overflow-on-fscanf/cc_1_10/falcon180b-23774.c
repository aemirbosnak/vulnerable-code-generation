//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 25

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

void read_words(char *filename, Word *words) {
    FILE *file = fopen(filename, "r");
    char word[MAX_WORD_LENGTH] = {0};
    int i = 0;

    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: too many words in file\n");
            exit(1);
        }

        strcpy(words[i].word, word);
        words[i].count = 1;
        i++;
    }

    fclose(file);
}

void sort_words(Word *words) {
    int i, j;
    Word temp;

    for (i = 0; i < MAX_WORDS - 1; i++) {
        for (j = i + 1; j < MAX_WORDS; j++) {
            if (strcmp(words[i].word, words[j].word) > 0) {
                temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void print_words(Word *words) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    Word words[MAX_WORDS];

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    read_words(argv[1], words);
    sort_words(words);
    print_words(words);

    return 0;
}