//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: artistic
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readWords(FILE *file, WordFrequency words[MAX_WORDS]) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (strlen(word) <= MAX_WORD_LENGTH) {
            for (int i = 0; i < strlen(word); i++) {
                word[i] = tolower(word[i]);
            }
            int found = false;
            for (int i = 0; i < MAX_WORDS; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                strcpy(words[0].word, word);
                words[0].count++;
            }
        }
    }
}

void sortWords(WordFrequency words[MAX_WORDS]) {
    for (int i = 0; i < MAX_WORDS - 1; i++) {
        for (int j = i + 1; j < MAX_WORDS; j++) {
            if (words[i].count < words[j].count) {
                WordFrequency temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void printWords(WordFrequency words[MAX_WORDS]) {
    printf("Top 10 most frequent words:\n");
    for (int i = 0; i < 10; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    readWords(file, words);

    fclose(file);

    sortWords(words);

    printWords(words);

    return 0;
}