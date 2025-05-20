//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000
#define SUMMARY_LENGTH 10

// Structure to hold word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

// Function to compare two WordFrequency structures for sorting
int compare(const void *a, const void *b) {
    WordFrequency *wf1 = (WordFrequency *)a;
    WordFrequency *wf2 = (WordFrequency *)b;
    return wf2->frequency - wf1->frequency; // Descending order
}

// Function to clean and normalize a word
void clean_word(char *word) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        word[i] = tolower(word[i]); // Convert to lowercase
        if (!isalnum(word[i])) { // Remove non-alphanumeric characters
            word[i] = '\0';
        }
    }
}

// Main summarization function
void summarize_text(FILE *file) {
    WordFrequency words[MAX_WORDS] = {0}; // Array to hold words and their frequencies
    char current_word[MAX_WORD_LENGTH];
    int word_count = 0;

    // Read words from the file
    while (fscanf(file, "%s", current_word) != EOF) {
        clean_word(current_word);

        // Check if the word is valid and not empty
        if (strlen(current_word) > 0) {
            int found = 0;
            for (int i = 0; i < word_count; i++) {
                if (strcmp(words[i].word, current_word) == 0) {
                    words[i].frequency++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strncpy(words[word_count].word, current_word, MAX_WORD_LENGTH);
                words[word_count].frequency = 1;
                word_count++;
            }
        }
    }

    // Sort words based on frequency
    qsort(words, word_count, sizeof(WordFrequency), compare);

    // Print the summary of the most frequent words
    printf("Text Summary:\n");
    for (int i = 0; i < SUMMARY_LENGTH && i < word_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <textfile>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    summarize_text(file);
    fclose(file);

    return 0;
}