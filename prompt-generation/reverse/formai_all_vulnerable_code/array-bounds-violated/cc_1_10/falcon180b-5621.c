//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    WordFrequency words[MAX_WORDS];
    int numWords = 0;
    int i;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        int inWord = 0;
        char *ptr = line;
        while (*ptr!= '\0') {
            if (isalnum(*ptr)) {
                inWord = 1;
            } else if (inWord) {
                inWord = 0;
                word[i] = '\0';
                strcpy(words[numWords].word, word);
                words[numWords].count = 1;
                numWords++;
                i = 0;
            }
            ptr++;
        }
        if (inWord) {
            word[i] = '\0';
            strcpy(words[numWords].word, word);
            words[numWords].count = 1;
            numWords++;
        }
    }

    fclose(file);

    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    printf("Word\t\tFrequency\n");
    for (i = 0; i < numWords; i++) {
        printf("%s\t\t%d\n", words[i].word, words[i].count);
    }

    return 0;
}