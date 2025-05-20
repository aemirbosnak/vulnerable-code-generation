//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64
#define MAX_NUM_WORDS 1000

// Struct to hold word frequency data
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

// Function to compare two WordFrequency structs
int compare_word_frequency(const void* a, const void* b) {
    const WordFrequency* wf1 = a;
    const WordFrequency* wf2 = b;
    if (wf1->frequency > wf2->frequency) {
        return -1;
    } else if (wf1->frequency < wf2->frequency) {
        return 1;
    } else {
        return 0;
    }
}

// Function to read in log file and count word frequencies
void count_word_frequencies(FILE* log_file, WordFrequency* word_frequencies, int num_words) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, log_file)!= NULL) {
        char* word = strtok(line, " ");
        while (word!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(word, word_frequencies[i].word) == 0) {
                    word_frequencies[i].frequency++;
                    break;
                }
            }
            if (i == num_words) {
                if (num_words >= MAX_NUM_WORDS) {
                    printf("Error: Too many unique words in log file.\n");
                    exit(1);
                }
                strcpy(word_frequencies[num_words].word, word);
                word_frequencies[num_words].frequency = 1;
                num_words++;
            }
            word = strtok(NULL, " ");
        }
    }
}

// Function to sort WordFrequency structs by frequency
void sort_word_frequencies(WordFrequency* word_frequencies, int num_words) {
    qsort(word_frequencies, num_words, sizeof(WordFrequency), compare_word_frequency);
}

// Function to print top N most frequent words
void print_top_n_words(WordFrequency* word_frequencies, int num_words, int n) {
    printf("Top %d most frequent words:\n", n);
    int i;
    for (i = 0; i < n && i < num_words; i++) {
        printf("%s: %d\n", word_frequencies[i].word, word_frequencies[i].frequency);
    }
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <log_file> <num_words>\n", argv[0]);
        return 1;
    }

    FILE* log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        return 1;
    }

    int num_words = atoi(argv[2]);
    WordFrequency* word_frequencies = malloc(num_words * sizeof(WordFrequency));
    if (word_frequencies == NULL) {
        printf("Error: Could not allocate memory for word frequencies.\n");
        fclose(log_file);
        return 1;
    }

    count_word_frequencies(log_file, word_frequencies, num_words);
    sort_word_frequencies(word_frequencies, num_words);
    print_top_n_words(word_frequencies, num_words, 10);

    free(word_frequencies);
    fclose(log_file);
    return 0;
}