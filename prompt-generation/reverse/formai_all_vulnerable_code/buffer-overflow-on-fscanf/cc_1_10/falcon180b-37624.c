//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readWords(FILE *file, WordFrequency words[MAX_WORDS]) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        for (int i = 0; i < MAX_WORD_LENGTH; i++) {
            if (word[i] == '\0') {
                strcpy(words[i].word, word);
                words[i].count = 1;
                break;
            }
        }
    }
}

void printWords(WordFrequency words[MAX_WORDS]) {
    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        if (words[i].word[0]!= '\0') {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        exit(2);
    }

    WordFrequency words[MAX_WORDS];
    readWords(file, words);

    fclose(file);

    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int index = rand() % MAX_WORD_LENGTH;
        printf("%s: %d\n", words[index].word, words[index].count);
    }

    return 0;
}