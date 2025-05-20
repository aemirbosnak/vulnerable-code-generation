//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: introspective
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// define our constants
#define MAX_WORD_LENGTH 50
#define MAX_WORDS 10000

// define global variables
char words[MAX_WORDS][MAX_WORD_LENGTH];
int freq[MAX_WORDS];

// declare function prototypes
void get_word(char* word);
void lower_case(char* word);
void add_word(char* word);
int compare_words(const void* a, const void* b);
void print_top_words(int num_words);

// start main function
int main(void) {
    printf("Enter text, press Ctrl-D when finished:\n");

    // initialize variables
    char word[MAX_WORD_LENGTH];
    bool word_complete = false;

    // get words from input
    while (scanf("%s", word) != EOF) {
        lower_case(word);
        add_word(word);
    }

    // sort words by frequency 
    qsort(freq, MAX_WORDS, sizeof(int), compare_words);

    // print top 10 most frequent words
    print_top_words(10);

    return 0;
}

// get_word function to handle punctuation and hyphens
void get_word(char* word) {
    char c;
    int i = 0;
    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            word[i] = c;
            i++;
        }
        else if (c == '\'' || c == '-') {
            if (i > 0) {
                word[i] = c;
                i++;
            }
        }
        else {
            if (i > 0) {
                word[i] = '\0';
                return;
            }
        }
    }
}

// convert word to lower case
void lower_case(char* word) {
    int i = 0;
    while (word[i]) {
        word[i] = tolower(word[i]);
        i++;
    }
}

// add word to our list of words and update its frequency
void add_word(char* word) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i], word) == 0) {
            freq[i]++;
            return;
        }
        else if (freq[i] == 0) {
            strcpy(words[i], word);
            freq[i]++;
            return;
        }
    }
    printf("Error: exceeded maximum number of words.\n");
    exit(1);
}

// custom comparison function for qsort
int compare_words(const void* a, const void* b) {
    const int* x = (const int*) a;
    const int* y = (const int*) b;
    return *y - *x;
}

// print the top num_words most frequent words
void print_top_words(int num_words) {
    printf("Top %d words:\n", num_words);
    int i;
    for (i = 0; i < num_words; i++) {
        if (freq[i] > 0) {
            printf("%12s: %5d\n", words[i], freq[i]);
        }
    }
}