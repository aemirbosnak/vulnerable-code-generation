//Falcon-180B DATASET v1.0 Category: Text processing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    const WordCount *wordA = a;
    const WordCount *wordB = b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    char input[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    FILE *file;
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i;

    printf("Enter the name of the input file: ");
    scanf("%s", input);

    file = fopen(input, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Maximum number of words reached.\n");
            break;
        }

        if (strlen(word) > MAX_WORD_LENGTH) {
            printf("Word is too long.\n");
            continue;
        }

        for (i = 0; i < numWords; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].count++;
                break;
            }
        }

        if (i == numWords) {
            strcpy(words[numWords].word, word);
            words[numWords].count = 1;
            numWords++;
        }
    }

    fclose(file);

    qsort(words, numWords, sizeof(WordCount), compareWords);

    printf("Word\tCount\n");
    for (i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    return 0;
}