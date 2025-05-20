//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the main function
int main(int argc, char *argv[]) {

    // Check if the user has provided a text file
    if (argc != 2) {
        printf("Usage: %s <text_file>\n", argv[0]);
        return 1;
    }

    // Open the text file
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Allocate memory for the text
    char *text = malloc(100000);
    if (text == NULL) {
        perror("Error allocating memory");
        return 1;
    }

    // Read the text from the file
    int n = fread(text, 1, 100000, fp);
    if (n == 0) {
        printf("Error reading file");
        return 1;
    }

    // Close the text file
    fclose(fp);

    // Tokenize the text
    char *tokens[10000];
    int num_tokens = 0;
    char *token = strtok(text, " ,.-");
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ,.-");
    }

    // Create a frequency table
    int frequency_table[10000];
    for (int i = 0; i < 10000; i++) {
        frequency_table[i] = 0;
    }
    for (int i = 0; i < num_tokens; i++) {
        frequency_table[i]++;
    }

    // Find the most frequent tokens
    int max_frequency = 0;
    int max_frequency_index = 0;
    for (int i = 0; i < 10000; i++) {
        if (frequency_table[i] > max_frequency) {
            max_frequency = frequency_table[i];
            max_frequency_index = i;
        }
    }

    // Print the most frequent tokens
    printf("The most frequent tokens are:\n");
    for (int i = 0; i < 10; i++) {
        printf("%s %d\n", tokens[i], frequency_table[i]);
    }

    // Free the memory
    free(text);

    return 0;
}