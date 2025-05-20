//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: visionary
// Visionary Text Processing Program

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_LENGTH 1000

typedef struct {
    char letter;
    int frequency;
} word_t;

void sort_words(word_t words[], int size);
void print_top_words(word_t words[], int size);

int main() {
    word_t words[MAX_LENGTH];
    int word_count = 0;
    int i;

    // Generate a list of words from a file
    printf("Enter file name: ");
    char file_name[50];
    scanf("%s", file_name);
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", file_name);
        return 1;
    }
    char line[100];
    while (fgets(line, 100, file) != NULL) {
        word_count++;
        words[word_count - 1].letter = line[0];
        words[word_count - 1].frequency = 1;
    }
    fclose(file);

    // Sort the list of words by frequency
    sort_words(words, word_count);

    // Print the top words
    print_top_words(words, word_count);

    return 0;
}

void sort_words(word_t words[], int size) {
    int i, j, min_index;
    word_t temp;

    // Bubble sort algorithm
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (words[j].frequency < words[j + 1].frequency) {
                temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

void print_top_words(word_t words[], int size) {
    int i;

    // Print the top words
    for (i = 0; i < size; i++) {
        printf("%c: %d\n", words[i].letter, words[i].frequency);
    }
}