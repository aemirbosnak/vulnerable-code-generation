//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;
    return strcmp(wc1->word, wc2->word);
}

int main(int argc, char *argv[]) {
    FILE *dictFile;
    char dictWord[MAX_WORD_LEN];
    char inputWord[MAX_WORD_LEN];
    char line[MAX_WORD_LEN];
    WordCount wordCounts[MAX_WORDS];
    int numWords = 0;
    int i, j;

    dictFile = fopen("dict.txt", "r");
    if (dictFile == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return 1;
    }

    while (fscanf(dictFile, "%s", dictWord)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Error: Dictionary is too large.\n");
            return 1;
        }
        strcpy(wordCounts[numWords].word, dictWord);
        wordCounts[numWords].count = 0;
        numWords++;
    }

    fclose(dictFile);

    printf("Enter text to spell check:\n");
    while (fgets(line, MAX_WORD_LEN, stdin)!= NULL) {
        i = 0;
        while ((i < strlen(line)) && (isspace(line[i]))) {
            i++;
        }
        j = 0;
        while ((i < strlen(line)) && (!isspace(line[i]))) {
            inputWord[j] = tolower(line[i]);
            i++;
            j++;
        }
        inputWord[j] = '\0';

        qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

        int found = 0;
        for (i = 0; i < numWords; i++) {
            if (strcmp(wordCounts[i].word, inputWord) == 0) {
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Possible spelling error: %s\n", inputWord);
        }
    }

    return 0;
}