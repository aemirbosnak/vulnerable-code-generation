//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;
    return wc2->count - wc1->count; // Sort in descending order of frequency
}

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

void process_file(const char *input_file, const char *output_file) {
    FILE *file = fopen(input_file, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", input_file);
        exit(1);
    }

    WordCount wordCounts[MAX_WORDS] = {0};
    int wordCountIndex = 0;
    char word[MAX_WORD_LENGTH];

    while (fscanf(file, "%s", word) != EOF) {
        to_lowercase(word);
        int found = 0;

        // Check if the word is already counted
        for (int i = 0; i < wordCountIndex; i++) {
            if (strcmp(wordCounts[i].word, word) == 0) {
                wordCounts[i].count++;
                found = 1;
                break;
            }
        }

        // If not found, add to the list
        if (!found && wordCountIndex < MAX_WORDS) {
            strcpy(wordCounts[wordCountIndex].word, word);
            wordCounts[wordCountIndex].count = 1;
            wordCountIndex++;
        }
    }

    fclose(file);

    // Sort wordCounts based on their frequency
    qsort(wordCounts, wordCountIndex, sizeof(WordCount), compare);

    // Write results to the output file
    FILE *output = fopen(output_file, "w");
    if (!output) {
        fprintf(stderr, "Could not open file %s for writing\n", output_file);
        exit(1);
    }

    fprintf(output, "Word Frequency Count:\n");
    for (int i = 0; i < wordCountIndex; i++) {
        fprintf(output, "%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    fclose(output);
}

void print_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s <input_file> <output_file>\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return 1;
    }

    process_file(argv[1], argv[2]);

    printf("Word frequency count has been written to %s\n", argv[2]);
    return 0;
}