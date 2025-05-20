//Falcon-180B DATASET v1.0 Category: Educational ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} Word;

int compareWords(const void* a, const void* b) {
    const Word* wordA = (const Word*) a;
    const Word* wordB = (const Word*) b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    char input[MAX_WORD_LEN];
    char filename[MAX_WORD_LEN];
    FILE* file;
    Word words[MAX_WORDS];
    int numWords = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(file, "%s", input)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Maximum number of words reached.\n");
            break;
        }

        int len = strlen(input);
        if (len > MAX_WORD_LEN) {
            printf("Word too long: %s\n", input);
            continue;
        }

        Word* word = &words[numWords++];
        strcpy(word->word, input);
        word->count = 1;
    }

    fclose(file);

    qsort(words, numWords, sizeof(Word), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s %d\n", words[i].word, words[i].count);
    }

    return 0;
}