//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void add_word(char *word) {
    WordCount *wc = (WordCount *)malloc(sizeof(WordCount));
    strcpy(wc->word, word);
    wc->count = 1;
}

void count_words(char *filename) {
    FILE *file;
    char word[MAX_WORD_LENGTH];
    WordCount *words = (WordCount *)malloc(MAX_WORDS * sizeof(WordCount));
    int num_words = 0;
    int i;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        if (strlen(word) > 0 && isalpha(word[0])) {
            for (i = 0; i < num_words; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                add_word(word);
                num_words++;
            }
        }
    }

    fclose(file);

    printf("Total words: %d\n", num_words);

    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    free(words);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    count_words(argv[1]);

    return 0;
}