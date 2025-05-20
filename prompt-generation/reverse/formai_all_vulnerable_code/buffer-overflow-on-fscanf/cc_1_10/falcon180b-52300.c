//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MIN_WORD_LEN 2
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN + 1];
    int count;
} Word;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int isValidWord(const char *word) {
    int len = strlen(word);
    if (len < MIN_WORD_LEN || len > MAX_WORD_LEN) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }
    return 1;
}

void readWords(FILE *file, Word *words) {
    char word[MAX_WORD_LEN + 1];
    while (fscanf(file, "%s", word)!= EOF) {
        if (isValidWord(word)) {
            strcpy(words->word, word);
            words->count++;
        }
    }
}

int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    Word *words = malloc(MAX_WORDS * sizeof(Word));
    int numWords = 0;

    readWords(file, words);

    qsort(words, numWords, sizeof(Word), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s %d\n", words[i].word, words[i].count);
    }

    free(words);
    fclose(file);

    return 0;
}