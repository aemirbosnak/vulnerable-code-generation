//Falcon-180B DATASET v1.0 Category: Text processing ; Style: genious
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
    const WordCount *wordCountA = a;
    const WordCount *wordCountB = b;

    return strcmp(wordCountA->word, wordCountB->word);
}

int main() {
    FILE *file;
    char filename[100];
    char line[1000];
    char word[MAX_WORD_LENGTH];
    WordCount wordCounts[MAX_WORDS];
    int numWords = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        char *token = strtok(line, ",.?!;:");

        while (token!= NULL) {
            int i;

            for (i = 0; i < numWords; i++) {
                if (strcmp(wordCounts[i].word, token) == 0) {
                    wordCounts[i].count++;
                    break;
                }
            }

            if (i == numWords) {
                strcpy(word, token);
                strcpy(wordCounts[numWords].word, word);
                wordCounts[numWords].count = 1;
                numWords++;
            }

            token = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);

    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    printf("Word\tCount\n");

    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", wordCounts[i].word, wordCounts[i].count);
    }

    return 0;
}