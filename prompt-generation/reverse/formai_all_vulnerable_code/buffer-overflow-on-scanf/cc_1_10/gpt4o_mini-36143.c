//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 1000
#define MAX_LENGTH 1000
#define SUMMARY_LENGTH 200

// Function to calculate the frequency of each word in the text
void calculate_word_frequency(char *lines[], int line_count, int *word_freq, char **unique_words, int *unique_count) {
    for (int i = 0; i < line_count; ++i) {
        char *token = strtok(lines[i], " ,.!?;:\"\n");
        while (token != NULL) {
            int found = 0;
            // Normalize the word to lower case for standardization
            for (int j = 0; token[j]; j++) {
                token[j] = tolower(token[j]);
            }
            // Check if the word is already in unique_words
            for (int j = 0; j < *unique_count; ++j) {
                if (strcmp(unique_words[j], token) == 0) {
                    word_freq[j]++;
                    found = 1;
                    break;
                }
            }
            // If not found, add it to the list
            if (!found) {
                unique_words[*unique_count] = strdup(token);
                word_freq[*unique_count] = 1;
                (*unique_count)++;
            }
            token = strtok(NULL, " ,.!?;:\"\n");
        }
    }
}

// Function to generate a summary from the text
void generate_summary(char *lines[], int line_count) {
    int word_freq[MAX_LENGTH] = {0};
    char *unique_words[MAX_LENGTH];
    int unique_count = 0;

    // Calculate word frequency
    calculate_word_frequency(lines, line_count, word_freq, unique_words, &unique_count);

    // Sort unique words by frequency (simple bubble sort for demonstration)
    for (int i = 0; i < unique_count - 1; i++) {
        for (int j = 0; j < unique_count - i - 1; j++) {
            if (word_freq[j] < word_freq[j + 1]) {
                int temp_freq = word_freq[j];
                char *temp_word = unique_words[j];
                word_freq[j] = word_freq[j + 1];
                unique_words[j] = unique_words[j + 1];
                word_freq[j + 1] = temp_freq;
                unique_words[j + 1] = temp_word;
            }
        }
    }

    // Create a summary sentence
    printf("\n--- Summary ---\n");
    for (int i = 0; i < unique_count && i < 10; ++i) {
        printf("%s (%d)\n", unique_words[i], word_freq[i]);
    }

    // Free memory allocated by strdup
    for (int i = 0; i < unique_count; ++i) {
        free(unique_words[i]);
    }
}

int main() {
    char *lines[MAX_LINES];
    int line_count = 0;

    printf("Welcome to the Exciting C Text Summarizer!\n");
    printf("Please provide the text file to summarize:\n");

    // Get file name from user and read the file
    char filename[MAX_LENGTH];
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    // Read lines from the file
    char buffer[MAX_LENGTH];
    while (fgets(buffer, MAX_LENGTH, file) && line_count < MAX_LINES) {
        lines[line_count] = strdup(buffer);
        line_count++;
    }
    fclose(file);

    // Generate summary
    generate_summary(lines, line_count);

    // Free allocated memory for lines
    for (int i = 0; i < line_count; ++i) {
        free(lines[i]);
    }

    printf("\nSummary generation complete! Thank you for using the C Text Summarizer!\n");
    return 0;
}