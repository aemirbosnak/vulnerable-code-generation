//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50 // Maximum word length
#define MAX_WORDS 1000 // Maximum number of words

char *words[MAX_WORDS]; // Array of strings to store words
int frequencies[MAX_WORDS]; // Array to store frequency of each word
int curr_index = 0; // Index into the words array

// Function to add word to arrays or increment frequency if already present
void add_word(char *word) {
    int i, is_new_word = 1;
    for (i = 0; i < curr_index; i++) {
        if (strcmp(word, words[i]) == 0) {
            frequencies[i]++;
            is_new_word = 0;
            break;
        }
    }
    if (is_new_word) {
        words[curr_index] = malloc(MAX_WORD_LENGTH * sizeof(char));
        strcpy(words[curr_index], word);
        frequencies[curr_index++] = 1;
    }
}

// Function to read input file and retrieve words
void read_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }
    char curr_word[MAX_WORD_LENGTH];
    int i, j, len;
    while (fscanf(fp, "%s", curr_word) != EOF) {
        // Convert word to lowercase
        len = strlen(curr_word);
        for (i = 0; i < len; i++) {
            curr_word[i] = tolower(curr_word[i]);
        }
        // Remove punctuation
        for (i = 0, j = 0; curr_word[i] != '\0'; i++) {
            if (isalpha(curr_word[i])) {
                curr_word[j++] = curr_word[i];
            }
        }
        curr_word[j] = '\0';
        // Add word to arrays
        if (strlen(curr_word) > 0) {
            add_word(curr_word);
        }
    }
    fclose(fp);
}

// Function to print word frequency table
void print_table() {
    printf("Word\tFrequency\n");
    int i;
    for (i = 0; i < curr_index; i++) {
        printf("%s\t%d\n", words[i], frequencies[i]);
    }
}

int main() {
    char filename[MAX_WORD_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);
    read_file(filename);
    print_table();
    return 0;
}