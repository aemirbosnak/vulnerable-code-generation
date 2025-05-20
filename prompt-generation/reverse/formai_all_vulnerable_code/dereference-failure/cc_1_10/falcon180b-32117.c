//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to split a line into words
void split_line(char* line, char** words) {
    int num_words = 0;
    char* word = strtok(line, " ");
    while (word!= NULL) {
        words[num_words++] = word;
        word = strtok(NULL, " ");
    }
}

// Function to count the frequency of each word
void count_words(char** words, int num_words, int* word_counts) {
    for (int i = 0; i < num_words; i++) {
        word_counts[strlen(words[i])]++;
    }
}

// Function to print the word frequency table
void print_word_counts(int* word_counts, int max_word_length) {
    printf("Word Length\tFrequency\n");
    for (int i = 1; i <= max_word_length; i++) {
        if (word_counts[i] > 0) {
            printf("%d\t\t%d\n", i, word_counts[i]);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file '%s'.\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char* words[100];
    int word_counts[MAX_LINE_LENGTH] = {0};

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        split_line(line, words);
        count_words(words, strlen(line), word_counts);
    }

    fclose(file);
    print_word_counts(word_counts, strlen(line));

    return 0;
}