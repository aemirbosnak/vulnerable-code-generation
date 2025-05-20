//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void loadWords(char *filename, WordFrequency *words) {
    FILE *file = fopen(filename, "r");
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: too many words in file!\n");
            exit(1);
        }

        strcpy(words[i].word, word);
        words[i].frequency = 0;
        i++;
    }

    fclose(file);
}

void countWords(char *filename, WordFrequency *words) {
    FILE *file = fopen(filename, "r");
    char word[MAX_WORD_LENGTH];
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].word[0] == '\0') {
            break;
        }
    }

    while (fscanf(file, "%s", word)!= EOF) {
        int j;

        for (j = 0; j < i; j++) {
            if (strcmp(word, words[j].word) == 0) {
                words[j].frequency++;
                break;
            }
        }

        if (j == i) {
            if (strcmp(word, "")!= 0) {
                strcpy(words[i].word, word);
                words[i].frequency = 1;
                i++;
            }
        }
    }

    fclose(file);
}

void printWords(WordFrequency *words) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].word[0]!= '\0') {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main(int argc, char **argv) {
    WordFrequency words[MAX_WORDS];

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    loadWords(argv[1], words);
    countWords(argv[1], words);
    printWords(words);

    return 0;
}