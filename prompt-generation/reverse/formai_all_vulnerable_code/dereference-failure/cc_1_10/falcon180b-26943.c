//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    char ch;
    int in_word = 0;
    char word[MAX_WORD_LENGTH];
    WordCount word_counts[MAX_WORDS];
    int num_words = 0;

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            in_word = 1;
            word[0] = tolower(ch);
            word[1] = '\0';
        } else if (in_word) {
            strcat(word, &ch);
            if (strlen(word) >= MAX_WORD_LENGTH) {
                printf("Warning: word '%s' truncated\n", word);
                word[MAX_WORD_LENGTH - 1] = '\0';
            }
            in_word = 0;
        }
    }

    if (in_word) {
        strcat(word, " ");
        if (strlen(word) >= MAX_WORD_LENGTH) {
            printf("Warning: word '%s' truncated\n", word);
            word[MAX_WORD_LENGTH - 1] = '\0';
        }
        in_word = 0;
    }

    fclose(fp);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    return 0;
}