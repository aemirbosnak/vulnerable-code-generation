//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} Word;

void read_file(FILE *file, Word *words) {
    char word[MAX_WORD_LEN];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Too many words in file.\n");
            exit(1);
        }

        words[i].word[0] = tolower(word[0]);
        strcpy(&words[i].word[1], &word[1]);
        words[i].count = 1;
        i++;
    }
}

void translate(Word *words, int num_words) {
    int i, j;
    char *p;

    for (i = 0; i < num_words; i++) {
        for (j = i + 1; j < num_words; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].count += words[j].count;
                words[j].count = 0;
            }
        }
    }

    for (i = 0; i < num_words; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    FILE *file;
    Word words[MAX_WORDS];
    int num_words = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    read_file(file, words);
    fclose(file);

    translate(words, num_words);

    return 0;
}