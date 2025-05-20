//Falcon-180B DATASET v1.0 Category: Text processing ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;

    if (wc1->count > wc2->count) {
        return -1;
    } else if (wc1->count < wc2->count) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char input[MAX_WORD_LENGTH];
    FILE *inputFile;
    char ch;
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while ((ch = fgetc(inputFile))!= EOF) {
        if (isalpha(ch)) {
            input[0] = tolower(ch);
            input[1] = '\0';
            numWords++;

            for (i = 0; i < numWords - 1; i++) {
                if (strcmp(words[i].word, input) == 0) {
                    words[i].count++;
                    break;
                }
            }

            if (i == numWords - 1) {
                strcpy(words[numWords - 1].word, input);
                words[numWords - 1].count = 1;
            }
        }
    }

    fclose(inputFile);

    qsort(words, numWords, sizeof(WordCount), compareWords);

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}