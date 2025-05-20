//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The main function
int main(int argc, char **argv) {
    // Check if the user provided a filename
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    // Read the file into a string
    char *text = NULL;
    size_t len = 0;
    getline(&text, &len, file);
    fclose(file);

    // Remove newlines from the text
    char *ptr = text;
    while (*ptr != '\0') {
        if (*ptr == '\n' || *ptr == '\r') {
           *ptr = ' ';
        }
        ptr++;
    }

    // Tokenize the text into words
    char *words[1000];
    int num_words = 0;
    char *token = strtok(text, " ");
    while (token != NULL) {
        words[num_words++] = token;
        token = strtok(NULL, " ");
    }

    // Create a frequency table of the words
    int frequencies[1000];
    memset(frequencies, 0, sizeof(frequencies));
    for (int i = 0; i < num_words; i++) {
        frequencies[i]++;
    }

    // Sort the frequency table
    for (int i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (frequencies[i] < frequencies[j]) {
                int temp = frequencies[i];
                frequencies[i] = frequencies[j];
                frequencies[j] = temp;
                char *temp2 = words[i];
                words[i] = words[j];
                words[j] = temp2;
            }
        }
    }

    // Print the top 10 most frequent words
    printf("The top 10 most frequent words are:\n");
    for (int i = 0; i < 10; i++) {
        printf("%s (%d)\n", words[i], frequencies[i]);
    }

    // Free the allocated memory
    free(text);
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }

    return 0;
}