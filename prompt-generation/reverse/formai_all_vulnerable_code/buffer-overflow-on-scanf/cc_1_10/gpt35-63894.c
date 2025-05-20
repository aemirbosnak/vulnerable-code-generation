//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD 100
#define MAX_WORDS 1000

// function prototypes
int compare(const void *p, const void *q);
void print_words(char *words[], int freq[], int n);

int main() {
    char word[MAX_WORD]; // buffer to store the word being read
    char *words[MAX_WORDS]; // array of pointers to words
    int freq[MAX_WORDS]; // array of word frequencies
    int n = 0; // number of unique words

    // read input from the user
    printf("Enter text: ");
    while (scanf("%s", word) == 1) {
        // convert word to lowercase
        int len = strlen(word);
        for (int i = 0; i < len; i++) {
            word[i] = tolower(word[i]);
        }

        // check if word is already in array
        int i;
        for (i = 0; i < n; i++) {
            if (strcmp(words[i], word) == 0) {
                freq[i]++;
                break;
            }
        }

        // if word is not in array, add it
        if (i == n) {
            words[n] = strdup(word);
            freq[n] = 1;
            n++;
        }
    }

    // sort words array in descending order of frequency
    qsort(words, n, sizeof(char *), compare);

    // print results
    print_words(words, freq, n);

    // free memory allocated on heap
    for (int i = 0; i < n; i++) {
        free(words[i]);
    }

    return 0;
}

// comparator function for qsort
int compare(const void *p, const void *q) {
    int freq1 = *((int *) p + 1);
    int freq2 = *((int *) q + 1);
    return freq2 - freq1;
}

// helper function to print words and their frequencies
void print_words(char *words[], int freq[], int n) {
    printf("Word\t\tFrequency\n");
    for (int i = 0; i < n; i++) {
        printf("%-15s%d\n", words[i], freq[i]);
    }
}