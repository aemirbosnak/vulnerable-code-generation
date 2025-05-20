//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int length;
} Word;

int compareWords(const void *a, const void *b) {
    const Word *wordA = (const Word *)a;
    const Word *wordB = (const Word *)b;
    return strcmp(wordA->word, wordB->word);
}

void readWords(char *filename, Word words[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word)!= EOF) {
        int length = strlen(word);
        if (length > MAX_WORD_LEN) {
            printf("Word %s is too long, ignoring\n", word);
            continue;
        }
        strcpy(words[length].word, word);
        words[length].length = length;
    }
    fclose(file);
}

void printWords(Word words[], int n) {
    qsort(words, n, sizeof(Word), compareWords);
    for (int i = 0; i < n; i++) {
        printf("%s (%d)\n", words[i].word, words[i].length);
    }
}

int main() {
    char filename[MAX_WORD_LEN];
    printf("Enter the name of the file: ");
    scanf("%s", filename);
    Word words[MAX_WORDS];
    readWords(filename, words);
    int numWords = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].length == 0) {
            break;
        }
        numWords++;
    }
    printf("Number of words in the file: %d\n", numWords);
    printWords(words, numWords);
    return 0;
}