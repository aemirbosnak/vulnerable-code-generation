//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define struct for word frequency
typedef struct {
    char *word;
    int count;
} word_frequency;

int main(int argc, char *argv[]) {

    // Open input file and check for errors
    FILE *infile;
    if (argc < 2) {
        printf("Usage: wordcount <filename>\n");
        exit(1);
    }
    infile = fopen(argv[1], "r");
    if (!infile) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Define initial size for array of word frequencies
    int capacity = 10;

    // Allocate memory for array
    word_frequency *arr = malloc(capacity * sizeof(word_frequency));

    // Initialize array
    int i;
    for (i = 0; i < capacity; i++) {
        arr[i].word = NULL;
        arr[i].count = 0;
    }

    // Read file line by line
    char line[100];
    while (fgets(line, 100, infile)) {

        // Tokenize line
        char *token = strtok(line, " \n");

        while (token) {

            // Convert token to lowercase
            int j;
            for (j = 0; j < strlen(token); j++) {
                token[j] = tolower(token[j]);
            }

            // Search for token in array
            int found = 0;
            for (j = 0; j < capacity; j++) {
                if (arr[j].word && strcmp(arr[j].word, token) == 0) {
                    // Increment frequency count
                    arr[j].count++;
                    found = 1;
                    break;
                }
            }

            // Add new word to array if not already present
            if (!found) {
                // Check if array needs to be resized
                if (i == capacity) {
                    capacity *= 2;
                    arr = realloc(arr, capacity * sizeof(word_frequency));
                    for (j = i; j < capacity; j++) {
                        arr[j].word = NULL;
                        arr[j].count = 0;
                    }
                }
                // Add new word to array
                arr[i].word = malloc(strlen(token) + 1);
                strcpy(arr[i].word, token);
                arr[i].count = 1;
                i++;
            }

            // Get next token
            token = strtok(NULL, " \n");
        }
    }

    // Print word frequencies
    for (i = 0; i < capacity; i++) {
        if (arr[i].word) {
            printf("%s\t%d\n", arr[i].word, arr[i].count);
        }
    }

    // Free memory
    for (i = 0; i < capacity; i++) {
        if (arr[i].word) {
            free(arr[i].word);
        }
    }
    free(arr);

    // Close file
    fclose(infile);

    return 0;
}