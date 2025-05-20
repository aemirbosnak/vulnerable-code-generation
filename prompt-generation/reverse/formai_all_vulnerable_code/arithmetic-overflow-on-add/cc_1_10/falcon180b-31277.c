//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readWords(FILE *file, WordFrequency words[]) {
    char ch;
    int i = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[0] = tolower(ch);
            int j = 1;

            while ((ch = fgetc(file))!= EOF && isalnum(ch)) {
                if (j < MAX_WORD_LENGTH - 1) {
                    words[i].word[j] = tolower(ch);
                    j++;
                }
            }

            words[i].word[j] = '\0';
            words[i].count++;
            i++;
        }
    }
}

void printWords(WordFrequency words[], int numWords) {
    printf("Word\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }
}

int compareWords(const void *a, const void *b) {
    WordFrequency *word1 = (WordFrequency *)a;
    WordFrequency *word2 = (WordFrequency *)b;

    return strcmp(word1->word, word2->word);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    readWords(file, words);

    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    printWords(words, numWords);

    fclose(file);

    return 0;
}