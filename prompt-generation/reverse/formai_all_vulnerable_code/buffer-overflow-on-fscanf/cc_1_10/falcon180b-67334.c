//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH + 1];
    int count;
};

void read_file(FILE *fp, struct word *words) {
    char word[MAX_WORD_LENGTH + 1];
    int i = 0;

    while (fscanf(fp, "%s", word)!= EOF) {
        if (strlen(word) > 0 && isalpha(word[0])) {
            for (int j = 0; j < strlen(word); j++) {
                word[j] = tolower(word[j]);
            }
            if (i >= MAX_WORDS) {
                printf("Error: too many words.\n");
                exit(1);
            }
            strcpy(words[i].word, word);
            words[i].count = 1;
            i++;
        }
    }
}

void count_words(struct word *words, int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(words[i].word, "a") == 0) {
            printf("Possible spelling mistake: 'a'\n");
        } else if (strcmp(words[i].word, "an") == 0) {
            printf("Possible spelling mistake: 'an'\n");
        } else if (strcmp(words[i].word, "the") == 0) {
            printf("Possible spelling mistake: 'the'\n");
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: cannot open file.\n");
        exit(1);
    }

    struct word words[MAX_WORDS];
    read_file(fp, words);

    count_words(words, MAX_WORDS);

    fclose(fp);
    return 0;
}