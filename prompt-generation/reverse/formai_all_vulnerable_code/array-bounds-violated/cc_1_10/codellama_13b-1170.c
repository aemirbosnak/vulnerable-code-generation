//Code Llama-13B DATASET v1.0 Category: Word Frequency Counter ; Style: intelligent
// Word Frequency Counter Example Program
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store the word and its frequency
struct word_freq {
    char word[50];
    int freq;
};

// Function to count the frequency of each word in a given string
void count_word_freq(char *str, struct word_freq *word_freq_arr) {
    int i, j, count;
    char *word;

    // Split the string into words
    word = strtok(str, " ");

    // Loop through each word and count its frequency
    while (word != NULL) {
        count = 0;
        for (i = 0; i < strlen(str); i++) {
            if (str[i] == ' ' || str[i] == '\0') {
                if (count > 0) {
                    // Increment the frequency of the word
                    word_freq_arr[j].freq++;
                }
                count = 0;
            } else {
                count++;
            }
        }
        // Store the word and its frequency in the array
        strcpy(word_freq_arr[j].word, word);
        j++;
        // Get the next word
        word = strtok(NULL, " ");
    }
}

// Function to print the word frequency array
void print_word_freq_arr(struct word_freq *word_freq_arr, int size) {
    int i;

    // Print the frequency of each word
    for (i = 0; i < size; i++) {
        printf("%s : %d\n", word_freq_arr[i].word, word_freq_arr[i].freq);
    }
}

int main() {
    char str[100];
    struct word_freq word_freq_arr[10];
    int i, size;

    // Get the input string from the user
    printf("Enter a string: ");
    fgets(str, 100, stdin);

    // Remove the newline character from the end of the string
    str[strlen(str) - 1] = '\0';

    // Count the frequency of each word in the string
    count_word_freq(str, word_freq_arr);

    // Get the size of the array
    size = sizeof(word_freq_arr) / sizeof(word_freq_arr[0]);

    // Print the frequency of each word
    print_word_freq_arr(word_freq_arr, size);

    return 0;
}