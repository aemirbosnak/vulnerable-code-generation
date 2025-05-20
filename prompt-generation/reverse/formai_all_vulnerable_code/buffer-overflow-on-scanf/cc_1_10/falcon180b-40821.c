//Falcon-180B DATASET v1.0 Category: Educational ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64
#define MAX_WORD_COUNT 1000

typedef struct {
    char *word;
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;
    return strcmp(wc1->word, wc2->word);
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int wordCount = 0;
    WordCount *wordList = NULL;
    int i;

    printf("Enter the name of the file to analyze: ");
    scanf("%s", line);

    fp = fopen(line, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *p = line;
        while ((word[0] = *p)!= '\0') {
            if (isalpha(word[0])) {
                int j = 0;
                while (isalpha(word[j]) && j < MAX_WORD_LENGTH - 1) {
                    j++;
                }
                word[j] = '\0';
                for (i = 0; i < wordCount; i++) {
                    if (strcmp(wordList[i].word, word) == 0) {
                        wordList[i].count++;
                        break;
                    }
                }
                if (i == wordCount) {
                    wordList = realloc(wordList, sizeof(WordCount) * (wordCount + 1));
                    wordList[wordCount].word = strdup(word);
                    wordList[wordCount].count = 1;
                    wordCount++;
                }
            }
            p++;
        }
    }

    fclose(fp);

    qsort(wordList, wordCount, sizeof(WordCount), compareWords);

    printf("Word Count:\n");
    for (i = 0; i < wordCount; i++) {
        printf("%s - %d\n", wordList[i].word, wordList[i].count);
    }

    free(wordList);

    return 0;
}