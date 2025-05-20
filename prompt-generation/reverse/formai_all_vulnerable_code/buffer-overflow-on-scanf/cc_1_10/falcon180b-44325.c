//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

// Function to split a string into words
void split_string(char *string, char *words[]) {
    int i = 0;
    char *word = strtok(string, " ");
    while (word!= NULL) {
        words[i] = word;
        i++;
        word = strtok(NULL, " ");
    }
    words[i] = NULL;
}

// Function to count the frequency of each word
void count_words(char *words[], int n, int freq[]) {
    for (int i = 0; i < n; i++) {
        freq[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                freq[i]++;
            }
        }
    }
}

// Function to print the frequency of each word
void print_freq(char *words[], int n, int freq[]) {
    for (int i = 0; i < n; i++) {
        printf("%s: %d\n", words[i], freq[i]);
    }
}

int main() {
    char input_string[1000];
    printf("Enter a string: ");
    scanf("%s", input_string);

    char words[MAX_WORD_LENGTH][MAX_WORD_LENGTH];
    int freq[MAX_WORD_LENGTH];

    split_string(input_string, words);
    count_words(words, MAX_WORD_LENGTH, freq);
    print_freq(words, MAX_WORD_LENGTH, freq);

    return 0;
}