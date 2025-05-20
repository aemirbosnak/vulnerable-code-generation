//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 100
#define MAX_LINE_LEN 1000
#define MAX_FILE_NAME_LEN 100

typedef struct {
    char word[MAX_WORD_LEN + 1];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;
    return strcmp(wc1->word, wc2->word);
}

int countWords(char *line, WordCount *wordCounts, int numWords) {
    char *word = strtok(line, " \t\n\r\f\v,.?!;:");
    while (word!= NULL) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(wordCounts[i].word, word) == 0) {
                wordCounts[i].count++;
                break;
            }
        }
        if (i == numWords) {
            if (numWords == MAX_WORD_LEN) {
                printf("Error: Maximum number of words reached.\n");
                return 1;
            }
            strcpy(wordCounts[numWords].word, word);
            wordCounts[numWords].count = 1;
            numWords++;
        }
        word = strtok(NULL, " \t\n\r\f\v,.?!;:");
    }
    return 0;
}

int main(int argc, char *argv[]) {
    FILE *file;
    char fileName[MAX_FILE_NAME_LEN];
    char line[MAX_LINE_LEN];
    int numWords = 0;
    WordCount wordCounts[MAX_WORD_LEN];

    printf("Enter the name of the file to count words in: ");
    scanf("%s", fileName);

    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LEN, file)!= NULL) {
        countWords(line, wordCounts, numWords);
    }

    fclose(file);

    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    printf("Word count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    return 0;
}