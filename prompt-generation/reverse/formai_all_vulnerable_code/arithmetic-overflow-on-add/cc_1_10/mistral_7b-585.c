//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
    int count;
} Word;

void get_next_word(char line[], char word[]) {
    int i = 0, j = 0;
    for (i = 0; line[i] != '\0' && line[i] != ' '; i++) {
        word[j++] = line[i];
    }
    word[j] = '\0';

    while (line[i] == ' ') i++;
}

void increment_count(Word words[], char word[]) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].count++;
            return;
        }
    }

    for (i = MAX_WORDS - 1; i >= 0; i--) {
        if (words[i].count == 0) {
            strcpy(words[i].word, word);
            words[i].count = 1;
            return;
        }
    }

    Word new_word;
    new_word.count = 1;
    strcpy(new_word.word, word);
    words[MAX_WORDS - 1] = new_word;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[1000], word[WORD_LENGTH];
    Word words[MAX_WORDS];

    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)) {
        char current_word[WORD_LENGTH];
        get_next_word(line, current_word);
        increment_count(words, current_word);
    }

    fclose(fp);

    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }

    return 0;
}