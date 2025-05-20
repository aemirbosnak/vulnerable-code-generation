//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordFrequency;

void readWords(char* filename, WordFrequency* words) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == MAX_WORDS) {
            printf("Warning: Maximum number of words reached\n");
        }
    }

    fclose(file);
}

void printWords(WordFrequency* words) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    memset(words, 0, sizeof(WordFrequency) * MAX_WORDS);

    readWords(argv[1], words);
    printWords(words);

    return 0;
}