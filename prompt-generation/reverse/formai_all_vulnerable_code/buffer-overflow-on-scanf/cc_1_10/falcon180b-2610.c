//Falcon-180B DATASET v1.0 Category: Data mining ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 20
#define MIN_WORD_LENGTH 3

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;
    return strcmp(wordA->word, wordB->word);
}

void printWordFrequencies(WordFrequency *wordFrequencies, int numWords) {
    printf("Word Frequencies:\n");
    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }
}

int main() {
    FILE *file;
    char filename[100];
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *word = NULL;
    WordFrequency wordFrequencies[MAX_WORDS];
    int numWords = 0;
    time_t start, end;

    printf("Enter the name of the text file to analyze: ");
    scanf("%s", filename);

    start = time(NULL);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return 1;
    }

    while ((read = getline(&line, &len, file))!= -1) {
        word = strtok(line, ",.?!;:\"'");
        while (word!= NULL) {
            if (strlen(word) >= MIN_WORD_LENGTH && strlen(word) <= MAX_WORD_LENGTH) {
                for (int i = 0; i < numWords; i++) {
                    if (strcmp(word, wordFrequencies[i].word) == 0) {
                        wordFrequencies[i].count++;
                        break;
                    }
                }
                if (numWords < MAX_WORDS) {
                    strcpy(wordFrequencies[numWords].word, word);
                    wordFrequencies[numWords].count = 1;
                    numWords++;
                }
            }
            word = strtok(NULL, ",.?!;:\"'");
        }
    }

    fclose(file);
    free(line);

    end = time(NULL);
    printf("Analysis complete in %ld seconds.\n", end - start);

    printWordFrequencies(wordFrequencies, numWords);

    return 0;
}