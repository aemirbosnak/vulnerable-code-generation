//Falcon-180B DATASET v1.0 Category: Educational ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50
#define MIN_WORD_LEN 3

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} Word;

int compareWords(const void *a, const void *b) {
    Word *wordA = (Word *)a;
    Word *wordB = (Word *)b;
    return strcmp(wordA->word, wordB->word);
}

int main() {
    char input[MAX_WORD_LEN];
    char *word;
    FILE *file;
    Word words[MAX_WORDS];
    int numWords = 0;
    int i;
    time_t start, end;

    printf("Enter the name of the file to be processed: ");
    scanf("%s", input);

    file = fopen(input, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    start = time(NULL);
    while (fscanf(file, "%s", input)!= EOF) {
        word = strtok(input, ",.?!;:");
        while (word!= NULL) {
            numWords++;
            if (numWords > MAX_WORDS) {
                printf("Maximum number of words exceeded.\n");
                exit(1);
            }
            strcpy(words[numWords - 1].word, word);
            words[numWords - 1].count = 1;
            word = strtok(NULL, ",.?!;:");
        }
    }
    fclose(file);

    qsort(words, numWords, sizeof(Word), compareWords);

    printf("Word\tCount\n");
    for (i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    end = time(NULL);
    printf("Time taken: %ld seconds\n", end - start);

    return 0;
}