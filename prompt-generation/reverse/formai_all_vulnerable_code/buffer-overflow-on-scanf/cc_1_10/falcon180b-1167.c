//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;

    return strcmp(wc1->word, wc2->word);
}

int main() {
    FILE *file;
    char line[100];
    char *word;
    WordCount words[MAX_WORDS];
    int numWords = 0;

    printf("Enter the name of the file: ");
    scanf("%s", line);

    file = fopen(line, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        char *token = strtok(line, ",.?!;:");

        while (token!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                break;
            }

            word = strtok(NULL, ",.?!;:");

            if (word!= NULL) {
                strcpy(words[numWords].word, token);
                words[numWords].count = 1;
                numWords++;
            }

            token = word;
        }
    }

    fclose(file);

    qsort(words, numWords, sizeof(WordCount), compareWords);

    printf("Word Count:\n");

    for (int i = 0; i < numWords; i++) {
        if (words[i].count > 1) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }

    return 0;
}