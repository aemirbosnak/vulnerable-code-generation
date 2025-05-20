//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;

    return strcmp(wordA->word, wordB->word);
}

void readWords(char *filename, WordFrequency *words, int *wordCount) {
    FILE *file;
    char line[100];
    char word[MAX_WORD_LENGTH];
    int index = 0;

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        int i = 0;
        while (line[i]!= '\0') {
            if (isalpha(line[i])) {
                strncat(word, &line[i], 1);
            }
            i++;
        }

        if (strlen(word) > 0) {
            if (index >= MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                break;
            }

            strcpy(words[index].word, word);
            words[index].frequency = 1;
            index++;
        }
    }

    fclose(file);

    *wordCount = index;
}

void countWordFrequencies(WordFrequency *words, int wordCount) {
    qsort(words, wordCount, sizeof(WordFrequency), compareWords);
}

void printWordFrequencies(WordFrequency *words, int wordCount) {
    int i;

    for (i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    char filename[100];
    WordFrequency words[MAX_WORDS];
    int wordCount;

    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    readWords(filename, words, &wordCount);
    countWordFrequencies(words, wordCount);
    printWordFrequencies(words, wordCount);

    return 0;
}