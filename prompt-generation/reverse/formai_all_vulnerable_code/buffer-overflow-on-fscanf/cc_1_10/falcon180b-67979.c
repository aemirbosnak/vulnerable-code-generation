//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 64
#define MAX_NUM_WORDS 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    WordCount *wordA = (WordCount *) a;
    WordCount *wordB = (WordCount *) b;

    if (wordA->count > wordB->count) {
        return -1;
    } else if (wordA->count < wordB->count) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE *file;
    char word[MAX_WORD_LENGTH];
    int numWords = 0;
    WordCount words[MAX_NUM_WORDS];

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: input file not found.\n");
        return 1;
    }

    while (fscanf(file, "%s", word)!= EOF) {
        if (numWords >= MAX_NUM_WORDS) {
            printf("Error: maximum number of words reached.\n");
            fclose(file);
            return 1;
        }

        int length = strlen(word);
        if (length > MAX_WORD_LENGTH) {
            printf("Error: word length exceeds maximum limit.\n");
            fclose(file);
            return 1;
        }

        bool found = false;
        for (int i = 0; i < numWords; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].count++;
                found = true;
                break;
            }
        }

        if (!found) {
            strcpy(words[numWords].word, word);
            words[numWords].count = 1;
            numWords++;
        }
    }

    fclose(file);

    qsort(words, numWords, sizeof(WordCount), compare);

    printf("Word\tCount\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    return 0;
}