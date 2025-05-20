//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
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
    FILE *file;
    char ch;
    int i = 0;
    int numWords = 0;
    WordCount words[MAX_NUM_WORDS];

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while ((ch = fgetc(file))!= EOF) {
        if (isspace(ch)) {
            // end of word
            words[i].word[strlen(words[i].word) - 1] = '\0'; // remove trailing space
            numWords++;
            i++;
        } else if (numWords < MAX_NUM_WORDS) {
            // add character to current word
            strncat(words[i].word, &ch, 1);
        } else {
            // ignore word
            continue;
        }
    }

    fclose(file);

    // count frequency of words
    for (i = 0; i < numWords; i++) {
        words[i].count = 1;
    }

    for (i = 1; i < numWords; i++) {
        if (strcmp(words[i - 1].word, words[i].word) == 0) {
            words[i - 1].count++;
        }
    }

    // sort words by frequency
    qsort(words, numWords, sizeof(WordCount), compareWords);

    // print word count
    printf("Word count:\n");
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}