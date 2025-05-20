//Code Llama-13B DATASET v1.0 Category: Word Frequency Counter ; Style: realistic
// Word frequency counter example program

#include <stdio.h>
#include <string.h>

// Structure to store word and its frequency
struct word_freq {
    char *word;
    int freq;
};

// Function to compare two structs
int compare_word_freq(const void *a, const void *b) {
    struct word_freq *w1 = (struct word_freq *)a;
    struct word_freq *w2 = (struct word_freq *)b;
    return w2->freq - w1->freq;
}

// Function to get word frequency
void get_word_freq(char *str, struct word_freq *freq) {
    char *token = strtok(str, " ");
    while (token != NULL) {
        int i = 0;
        while (freq[i].word != NULL && strcmp(freq[i].word, token) != 0) {
            i++;
        }
        if (freq[i].word == NULL) {
            freq[i].word = token;
            freq[i].freq = 1;
        } else {
            freq[i].freq++;
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    // Input string
    char str[1000];
    printf("Enter a string: ");
    fgets(str, 1000, stdin);

    // Remove newline character
    str[strlen(str) - 1] = '\0';

    // Get word frequency
    struct word_freq freq[100];
    get_word_freq(str, freq);

    // Sort word frequency
    qsort(freq, 100, sizeof(struct word_freq), compare_word_freq);

    // Print word frequency
    for (int i = 0; i < 100; i++) {
        if (freq[i].word != NULL) {
            printf("%s: %d\n", freq[i].word, freq[i].freq);
        }
    }

    return 0;
}