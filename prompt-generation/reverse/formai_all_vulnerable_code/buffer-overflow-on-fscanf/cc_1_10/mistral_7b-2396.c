//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct Word {
    char str[WORD_LENGTH];
    int count;
} Word;

bool is_word_starts_with_c(char *str) {
    if (str[0] >= 'C' && str[0] <= 'Z')
        return true;
    return false;
}

int main(int argc, char *argv[]) {
    Word word_list[MAX_WORDS];
    int num_words = 0;

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char word[WORD_LENGTH];
    while (fscanf(fp, "%s", word) == 1) {
        if (is_word_starts_with_c(word)) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(word_list[i].str, word) == 0) {
                    word_list[i].count++;
                    break;
                }
            }

            if (i == num_words) {
                if (num_words >= MAX_WORDS) {
                    printf("Maximum number of words reached.\n");
                    return 1;
                }

                strcpy(word_list[num_words].str, word);
                word_list[num_words].count = 1;
                num_words++;
            }
        }
    }

    fclose(fp);

    printf("\nWords starting with 'C' and their frequencies:\n");
    for (int i = 0; i < num_words; i++) {
        if (is_word_starts_with_c(word_list[i].str))
            printf("%s : %d\n", word_list[i].str, word_list[i].count);
    }

    return 0;
}