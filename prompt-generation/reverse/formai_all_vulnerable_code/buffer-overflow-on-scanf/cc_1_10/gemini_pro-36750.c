//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold word and its count
typedef struct {
    char *word;
    int count;
} WordCount;

// Function to compare two WordCount structures by word
int compareWords(const void *a, const void *b) {
    const WordCount *w1 = (const WordCount *)a;
    const WordCount *w2 = (const WordCount *)b;
    return strcmp(w1->word, w2->word);
}

// Function to count the number of words in a string
int countWords(const char *str) {
    int count = 0;
    const char *p = str;
    while (*p) {
        if (*p == ' ') {
            count++;
        }
        p++;
    }
    count++;
    return count;
}

// Function to create an array of WordCount structures from a string
WordCount *createWordCountArray(const char *str) {
    int numWords = countWords(str);
    WordCount *array = malloc(sizeof(WordCount) * numWords);
    if (!array) {
        return NULL;
    }
    const char *p = str;
    int i = 0;
    while (*p) {
        if (*p == ' ') {
            array[i].word = malloc(strlen(p) + 1);
            if (!array[i].word) {
                free(array);
                return NULL;
            }
            strcpy(array[i].word, p);
            array[i].count = 1;
            i++;
        }
        p++;
    }
    array[i].word = malloc(strlen(p) + 1);
    if (!array[i].word) {
        free(array);
        return NULL;
    }
    strcpy(array[i].word, p);
    array[i].count = 1;
    return array;
}

// Function to free the memory allocated for an array of WordCount structures
void freeWordCountArray(WordCount *array, int numWords) {
    for (int i = 0; i < numWords; i++) {
        free(array[i].word);
    }
    free(array);
}

// Function to print the top n words in a string
void printTopWords(const char *str, int n) {
    WordCount *array = createWordCountArray(str);
    if (!array) {
        return;
    }
    int numWords = countWords(str);
    qsort(array, numWords, sizeof(WordCount), compareWords);
    for (int i = 0; i < n && i < numWords; i++) {
        printf("%s: %d\n", array[i].word, array[i].count);
    }
    freeWordCountArray(array, numWords);
}

int main() {
    // Get the input string from the user
    char str[256];
    printf("Enter a string: ");
    fgets(str, 256, stdin);

    // Get the number of top words to print
    int n;
    printf("Enter the number of top words to print: ");
    scanf("%d", &n);

    // Print the top n words in the string
    printTopWords(str, n);

    return 0;
}