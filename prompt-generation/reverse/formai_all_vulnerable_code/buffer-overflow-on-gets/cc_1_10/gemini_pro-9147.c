//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a word and its frequency
typedef struct word_freq {
    char *word;
    int freq;
} word_freq;

// Function to compare two word_freq structures by frequency
int compare_freq(const void *a, const void *b) {
    const word_freq *word_freq_a = (const word_freq *)a;
    const word_freq *word_freq_b = (const word_freq *)b;
    return word_freq_b->freq - word_freq_a->freq;
}

// Function to count the frequency of each word in a string
word_freq *count_word_freq(char *str) {
    // Allocate memory for the array of word_freq structures
    word_freq *word_freq_array = malloc(sizeof(word_freq) * 1000);
    if (word_freq_array == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // Initialize the array of word_freq structures
    for (int i = 0; i < 1000; i++) {
        word_freq_array[i].word = NULL;
        word_freq_array[i].freq = 0;
    }

    // Tokenize the string into words
    char *token = strtok(str, " ");
    while (token != NULL) {
        // Find the index of the word in the array of word_freq structures
        int index = -1;
        for (int i = 0; i < 1000; i++) {
            if (strcmp(word_freq_array[i].word, token) == 0) {
                index = i;
                break;
            }
        }

        // If the word is not found in the array, add it to the array
        if (index == -1) {
            index = 0;
            while (word_freq_array[index].word != NULL) {
                index++;
            }
            word_freq_array[index].word = malloc(strlen(token) + 1);
            if (word_freq_array[index].word == NULL) {
                perror("malloc");
                exit(EXIT_FAILURE);
            }
            strcpy(word_freq_array[index].word, token);
        }

        // Increment the frequency of the word
        word_freq_array[index].freq++;

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Sort the array of word_freq structures by frequency
    qsort(word_freq_array, 1000, sizeof(word_freq), compare_freq);

    // Return the array of word_freq structures
    return word_freq_array;
}

// Function to print the array of word_freq structures
void print_word_freq(word_freq *word_freq_array) {
    for (int i = 0; i < 1000; i++) {
        if (word_freq_array[i].word != NULL) {
            printf("%s: %d\n", word_freq_array[i].word, word_freq_array[i].freq);
        }
    }
}

// Function to free the memory allocated for the array of word_freq structures
void free_word_freq(word_freq *word_freq_array) {
    for (int i = 0; i < 1000; i++) {
        if (word_freq_array[i].word != NULL) {
            free(word_freq_array[i].word);
        }
    }
    free(word_freq_array);
}

int main() {
    // Get the input string from the user
    char str[1000];
    printf("Enter a string: ");
    gets(str);

    // Count the frequency of each word in the string
    word_freq *word_freq_array = count_word_freq(str);

    // Print the frequency of each word
    print_word_freq(word_freq_array);

    // Free the memory allocated for the array of word_freq structures
    free_word_freq(word_freq_array);

    return 0;
}