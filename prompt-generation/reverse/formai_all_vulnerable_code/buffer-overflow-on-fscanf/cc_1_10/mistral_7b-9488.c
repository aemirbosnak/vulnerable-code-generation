//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LEN 50

typedef struct {
    char word[WORD_LEN];
    int count;
} Word;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int isDelimiter(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

int main(int argc, char **argv) {
    if (argc != 2) {
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
    char word[WORD_LEN];

    while (fscanf(file, " %s", word) != EOF) {
        toLowerCase(word);
        int found = 0;

        for (int i = 0; i < num_words; i++) {
            if (strncmp(words[i].word, word, strlen(word)) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strncpy(words[num_words].word, word, WORD_LEN);
            words[num_words].count = 1;
            num_words++;
        }
    }

    fclose(file);

    printf("Word count:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}