//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_SIZE 50

typedef struct {
    char word[WORD_SIZE];
    int count;
} WordStat;

void toLower(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }
}

int isDelimiter(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

void addWord(WordStat *stats, char *word) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(stats[i].word, word) == 0) {
            stats[i].count++;
            return;
        }
    }

    strcpy(stats[MAX_WORDS - 1].word, word);
    stats[MAX_WORDS - 1].count = 1;

    if (MAX_WORDS == MAX_WORDS - 1) {
        WordStat *newStats = (WordStat *)realloc(stats, sizeof(WordStat) * (MAX_WORDS + 10));
        if (newStats == NULL) {
            printf("Error: Could not allocate memory\n");
            exit(EXIT_FAILURE);
        }
        stats = newStats;
    }
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        return EXIT_FAILURE;
    }

    WordStat stats[MAX_WORDS];
    char word[WORD_SIZE] = "";
    int state = 0;

    while (!feof(file)) {
        int c = fgetc(file);
        if (isDelimiter(c)) {
            if (state == 1) {
                toLower(word);
                addWord(stats, word);
                strcpy(word, "");
                state = 0;
            }
            continue;
        }

        if (state == 0 && isalpha(c)) {
            word[0] = tolower(c);
            strcat(word, "");
            strcat(word, &c + 1);
            state = 1;
            continue;
        }
    }

    if (state == 1) {
        toLower(word);
        addWord(stats, word);
    }

    for (int i = 0; i < MAX_WORDS; i++) {
        if (stats[i].count > 0) {
            printf("%s: %d\n", stats[i].word, stats[i].count);
        }
    }

    fclose(file);
    return EXIT_SUCCESS;
}