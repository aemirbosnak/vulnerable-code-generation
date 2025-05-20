//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    FILE *file;
    char filename[50];
    char ch;
    char word[MAX_WORD_LEN];
    WordCount words[MAX_WORDS];
    int numWords = 0;

    printf("Enter the name of the file to read: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            word[0] = tolower(ch);
            int i = 1;

            while ((ch = fgetc(file))!= EOF && isalnum(ch)) {
                if (i < MAX_WORD_LEN) {
                    word[i++] = tolower(ch);
                }
            }

            word[i] = '\0';

            bool found = false;

            for (int j = 0; j < numWords; j++) {
                if (strcmp(word, words[j].word) == 0) {
                    words[j].count++;
                    found = true;
                    break;
                }
            }

            if (!found) {
                if (numWords == MAX_WORDS) {
                    printf("Error: too many unique words.\n");
                    fclose(file);
                    return 1;
                }

                strcpy(words[numWords].word, word);
                words[numWords].count = 1;
                numWords++;
            }
        }
    }

    fclose(file);

    qsort(words, numWords, sizeof(WordCount), compareWords);

    printf("Word count:\n");

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}