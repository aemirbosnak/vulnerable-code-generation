//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int freq;
} WordFreq;

int compareWords(const void *a, const void *b) {
    const WordFreq *word1 = a;
    const WordFreq *word2 = b;
    return strcmp(word1->word, word2->word);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }

    WordFreq words[MAX_WORDS];
    int numWords = 0;

    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Error: too many words in file\n");
            fclose(file);
            return 1;
        }

        WordFreq *found = bsearch(&(WordFreq){.word = word}, words, numWords, sizeof(WordFreq), compareWords);
        if (!found) {
            strcpy(found->word, word);
            found->freq = 1;
            numWords++;
        } else {
            found->freq++;
        }
    }

    fclose(file);

    qsort(words, numWords, sizeof(WordFreq), compareWords);

    printf("Word frequencies:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].freq);
    }

    return 0;
}