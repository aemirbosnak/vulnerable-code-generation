//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

void readWords(FILE* file, Word words[MAX_WORDS]) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Too many words!\n");
            exit(1);
        }

        words[i].word[0] = tolower(word[0]);
        strcpy(words[i].word + 1, word + 1);
        words[i].count = 1;
        i++;
    }
}

void printWords(Word words[MAX_WORDS]) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    Word words[MAX_WORDS];
    readWords(file, words);
    fclose(file);

    printWords(words);

    return 0;
}