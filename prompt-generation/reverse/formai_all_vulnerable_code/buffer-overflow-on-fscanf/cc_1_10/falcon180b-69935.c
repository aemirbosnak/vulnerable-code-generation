//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

bool compareWords(const void *a, const void *b) {
    struct WordFrequency *wordA = (struct WordFrequency *)a;
    struct WordFrequency *wordB = (struct WordFrequency *)b;

    if (wordA->frequency > wordB->frequency) {
        return true;
    } else if (wordA->frequency == wordB->frequency) {
        return strcmp(wordA->word, wordB->word) > 0;
    } else {
        return false;
    }
}

void countWords(FILE *file, struct WordFrequency *wordFrequencies, int numWords) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF && i < numWords) {
        int length = strlen(word);
        if (length > 0 && isalpha(word[0])) {
            for (int j = 0; j < length; j++) {
                word[j] = tolower(word[j]);
            }
            for (int k = 0; k < i; k++) {
                if (strcmp(word, wordFrequencies[k].word) == 0) {
                    wordFrequencies[k].frequency++;
                    break;
                }
            }
        }
        i++;
    }

    qsort(wordFrequencies, numWords, sizeof(struct WordFrequency), compareWords);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    int numWords = 0;
    char ch;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            numWords++;
        }
    }

    struct WordFrequency wordFrequencies[MAX_WORDS];
    countWords(file, wordFrequencies, numWords);

    printf("Word frequency:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }

    fclose(file);
    return 0;
}