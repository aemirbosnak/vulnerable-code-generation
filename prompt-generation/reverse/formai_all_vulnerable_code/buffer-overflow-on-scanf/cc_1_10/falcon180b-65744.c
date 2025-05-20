//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 100000

// Struct to store word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

// Function to compare two strings (case insensitive)
int compareStrings(const void *a, const void *b) {
    char *str1 = (char *)a;
    char *str2 = (char *)b;

    while (*str1 && *str2) {
        if (tolower(*str1)!= tolower(*str2)) {
            return tolower(*str1) - tolower(*str2);
        }
        str1++;
        str2++;
    }

    if (*str1) {
        return 1;
    } else if (*str2) {
        return -1;
    } else {
        return 0;
    }
}

// Function to load words from a file into an array
void loadWords(char *filename, WordFrequency *words, int *numWords) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_NUM_WORDS) {
            printf("Maximum number of words exceeded.\n");
            exit(1);
        }

        strcpy(words[i].word, word);
        words[i].frequency = 1;
        i++;
    }

    fclose(file);

    *numWords = i;
}

// Function to print the top n most frequent words
void printTopWords(WordFrequency *words, int numWords, int n) {
    qsort(words, numWords, sizeof(WordFrequency), compareStrings);

    printf("Top %d most frequent words:\n", n);

    for (int i = 0; i < n && i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    char filename[100];
    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    WordFrequency words[MAX_NUM_WORDS];
    int numWords;

    loadWords(filename, words, &numWords);

    int n;
    printf("Enter the number of top words to print: ");
    scanf("%d", &n);

    printTopWords(words, numWords, n);

    return 0;
}