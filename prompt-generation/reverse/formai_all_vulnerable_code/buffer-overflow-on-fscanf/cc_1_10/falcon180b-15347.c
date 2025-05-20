//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    WordCount* wordA = (WordCount*)a;
    WordCount* wordB = (WordCount*)b;

    if (wordA->count > wordB->count) {
        return -1;
    } else if (wordA->count < wordB->count) {
        return 1;
    } else {
        return 0;
    }
}

void readWords(char* filename, WordCount* words) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
            }
        }
        strcpy(words[i].word, word);
        words[i].count++;
    }

    fclose(file);
}

void printTopWords(WordCount* words, int numWords) {
    qsort(words, MAX_WORDS, sizeof(WordCount), compareWords);

    printf("Top %d words:\n", numWords);
    for (int i = 0; i < numWords && i < MAX_WORDS; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <num_words>\n", argv[0]);
        exit(1);
    }

    char* filename = argv[1];
    int numWords = atoi(argv[2]);

    WordCount words[MAX_WORDS];
    readWords(filename, words);

    printTopWords(words, numWords);

    return 0;
}