//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct Word {
    char word[WORD_LENGTH];
    int count;
} Word;

void toLower(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i]))
            str[i] = tolower(str[i]);
    }
}

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

    Word words[MAX_WORDS];
    int num_words = 0;

    char word[WORD_LENGTH];
    while (fscanf(file, " %s", word) != EOF) {
        toLower(word);

        for (int i = 0; i < num_words; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].count++;
                break;
            }
        }

        for (int i = num_words; i > 0 && strcmp(words[i - 1].word, word) == 0; i--) {
            words[i].word[0] = '\0';
        }

        strcpy(words[num_words++].word, word);
        words[num_words - 1].count = 1;
    }

    fclose(file);

    printf("\nWord count:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}