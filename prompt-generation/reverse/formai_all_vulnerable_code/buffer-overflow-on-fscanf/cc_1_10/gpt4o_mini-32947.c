//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

// Function to read text from a file and count word frequencies
int read_file_and_count_words(const char *filename, WordFrequency *word_freq) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return 0;
    }

    char buffer[MAX_WORD_LENGTH];
    int word_count = 0;

    // Initialize word frequencies
    while (fscanf(file, "%s", buffer) == 1) {
        // Convert to lowercase and remove punctuation
        for (int i = 0; buffer[i]; i++) {
            buffer[i] = tolower(buffer[i]);
        }

        // Check if it's a valid word
        if (isalpha(buffer[0])) {
            int found = 0;
            for (int i = 0; i < word_count; i++) {
                if (strcmp(word_freq[i].word, buffer) == 0) {
                    word_freq[i].frequency++;
                    found = 1;
                    break;
                }
            }

            if (!found && word_count < MAX_WORDS) {
                strcpy(word_freq[word_count].word, buffer);
                word_freq[word_count].frequency = 1;
                word_count++;
            }
        }
    }

    fclose(file);
    return word_count;
}

// Function to sort the word frequencies in descending order
int compare(const void *a, const void *b) {
    return ((WordFrequency *)b)->frequency - ((WordFrequency *)a)->frequency;
}

// Function to print the summarized word frequencies
void print_summary(WordFrequency *word_freq, int count) {
    printf("\n--- Text Summary ---\n");
    for (int i = 0; i < count && i < 10; i++) { // Printing top 10 words
        printf("%s: %d\n", word_freq[i].word, word_freq[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    WordFrequency word_freq[MAX_WORDS];
    int word_count = read_file_and_count_words(argv[1], word_freq);
    
    if (word_count == 0) {
        printf("No words found or error reading the file.\n");
        return 1;
    }

    // Sort the word frequencies
    qsort(word_freq, word_count, sizeof(WordFrequency), compare);

    // Print summary
    print_summary(word_freq, word_count);

    return 0;
}