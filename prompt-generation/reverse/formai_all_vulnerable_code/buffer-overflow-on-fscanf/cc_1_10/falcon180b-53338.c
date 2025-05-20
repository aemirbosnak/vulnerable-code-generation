//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;
    return strcmp(wc1->word, wc2->word);
}

void readWordsFromFile(FILE *file, WordCount *wordCounts) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < MAX_WORD_LENGTH && word[i]!= '\0'; i++) {
            word[i] = tolower(word[i]);
        }
        int index = 0;
        while (index < MAX_WORDS && wordCounts[index].count > 0) {
            index++;
        }
        if (index < MAX_WORDS) {
            strcpy(wordCounts[index].word, word);
            wordCounts[index].count = 1;
        } else {
            printf("Max word count reached!\n");
        }
    }
}

void printWordCounts(WordCount *wordCounts) {
    qsort(wordCounts, MAX_WORDS, sizeof(WordCount), compare);
    printf("Word\tCount\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        if (wordCounts[i].count > 0) {
            printf("%s\t%d\n", wordCounts[i].word, wordCounts[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    WordCount wordCounts[MAX_WORDS];
    readWordsFromFile(file, wordCounts);
    fclose(file);
    printWordCounts(wordCounts);
    return 0;
}