//Falcon-180B DATASET v1.0 Category: Text processing ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000
#define MAX_NUM_WORDS 1000

// Function to split a line of text into words
void split_line(char* line, char** words) {
    int num_words = 0;
    char* word = strtok(line, " ");
    while (word!= NULL) {
        words[num_words] = word;
        num_words++;
        word = strtok(NULL, " ");
    }
}

// Function to count the frequency of each word
void count_words(char** words, int num_words, int* word_counts) {
    for (int i = 0; i < num_words; i++) {
        int word_index = 0;
        while (word_index < MAX_NUM_WORDS && strcmp(words[i], words[word_index])!= 0) {
            word_index++;
        }
        if (word_index == MAX_NUM_WORDS) {
            printf("Warning: Word \"%s\" not counted due to limit of %d words.\n", words[i], MAX_NUM_WORDS);
        } else {
            word_counts[word_index]++;
        }
    }
}

// Function to sort words by frequency
void sort_words(int* word_counts, char** words, int num_words) {
    for (int i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (word_counts[i] < word_counts[j]) {
                int temp_count = word_counts[i];
                word_counts[i] = word_counts[j];
                word_counts[j] = temp_count;
                char* temp_word = words[i];
                words[i] = words[j];
                words[j] = temp_word;
            }
        }
    }
}

int main() {
    FILE* input_file;
    char line[MAX_LINE_LENGTH];
    char** words = malloc(MAX_NUM_WORDS * sizeof(char*));
    int num_words = 0;
    int* word_counts = malloc(MAX_NUM_WORDS * sizeof(int));
    memset(word_counts, 0, MAX_NUM_WORDS * sizeof(int));

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        split_line(line, words);
        count_words(words, num_words, word_counts);
        num_words = 0;
    }

    fclose(input_file);
    sort_words(word_counts, words, num_words);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i], word_counts[i]);
    }

    free(words);
    free(word_counts);

    return 0;
}