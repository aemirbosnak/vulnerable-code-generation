//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: peaceful
// LogAnalyzer.c - A peaceful log analysis program

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOG_LENGTH 1024
#define MAX_WORDS 100

typedef struct {
    char *word;
    int count;
} word_t;

int main() {
    // Load the log file
    FILE *log_file = fopen("log.txt", "r");
    if (log_file == NULL) {
        printf("Error: Could not open log file\n");
        return 1;
    }

    // Create an array to store the words and their counts
    word_t *words = malloc(MAX_WORDS * sizeof(word_t));
    if (words == NULL) {
        printf("Error: Could not allocate memory for word array\n");
        fclose(log_file);
        return 1;
    }

    // Read the log file line by line
    char line[MAX_LOG_LENGTH];
    while (fgets(line, MAX_LOG_LENGTH, log_file) != NULL) {
        // Tokenize the line into words
        char *token = strtok(line, " ");
        while (token != NULL && token != line) {
            // Check if the word is already in the array
            int i = 0;
            while (i < MAX_WORDS && words[i].word != NULL) {
                if (strcmp(words[i].word, token) == 0) {
                    // Increment the count for the word
                    words[i].count++;
                    break;
                }
                i++;
            }
            if (i == MAX_WORDS) {
                // Add a new word to the array
                words = realloc(words, (i + 1) * sizeof(word_t));
                words[i].word = token;
                words[i].count = 1;
            }
            token = strtok(NULL, " ");
        }
    }

    // Print the log analysis
    printf("Log Analysis:\n");
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].word != NULL) {
            printf("%d occurrences of %s\n", words[i].count, words[i].word);
        }
    }

    // Free the memory
    free(words);

    return 0;
}