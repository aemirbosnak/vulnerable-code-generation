//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LEN 50

struct Word {
    char word[WORD_LEN];
    int count;
};

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    struct Word words[MAX_WORDS];
    int num_words = 0;
    char current_word[WORD_LEN];

    while (fscanf(file, " %s", current_word) == 1) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(words[i].word, current_word) == 0) {
                words[i].count++;
                break;
            }
        }

        if (i == num_words) {
            strcpy(words[num_words++].word, current_word);
            words[num_words - 1].count = 1;
        }
    }

    fclose(file);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}