//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *) a;
    WordFrequency *wordB = (WordFrequency *) b;

    if (wordA->frequency > wordB->frequency) {
        return -1;
    } else if (wordA->frequency < wordB->frequency) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE *file;
    char ch;
    int i = 0;
    WordFrequency words[MAX_WORDS];

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[0] = tolower(ch);
            words[i].frequency = 1;
            i++;
        } else if (isalnum(ch)) {
            words[i-1].word[strlen(words[i-1].word)] = tolower(ch);
            words[i-1].frequency++;
        }
    }

    fclose(file);

    qsort(words, i, sizeof(WordFrequency), compareWords);

    for (int j = 0; j < i; j++) {
        printf("%s: %d\n", words[j].word, words[j].frequency);
    }

    return 0;
}