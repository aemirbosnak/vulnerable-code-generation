//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cyberpunk-style text summarizer
int main(int argc, char **argv) {
    // Check if the user provided a text file
    if (argc < 2) {
        printf("Usage: %s <text file>\n", argv[0]);
        return 1;
    }

    // Open the text file
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    // Read the text file into a string
    char *text = NULL;
    long len;
    fseek(fp, 0, SEEK_END);
    len = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    text = malloc(len + 1);
    fread(text, 1, len, fp);
    fclose(fp);

    // Tokenize the text
    char **tokens = malloc(sizeof(char *) * 100);
    int num_tokens = 0;
    char *token = strtok(text, " ");
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }

    // Create a frequency table
    int *freq = malloc(sizeof(int) * num_tokens);
    memset(freq, 0, sizeof(int) * num_tokens);
    for (int i = 0; i < num_tokens; i++) {
        for (int j = 0; j < num_tokens; j++) {
            if (strcmp(tokens[i], tokens[j]) == 0) {
                freq[i]++;
            }
        }
    }

    // Sort the frequency table
    for (int i = 0; i < num_tokens; i++) {
        for (int j = i + 1; j < num_tokens; j++) {
            if (freq[i] < freq[j]) {
                int temp = freq[i];
                freq[i] = freq[j];
                freq[j] = temp;

                char *temp2 = tokens[i];
                tokens[i] = tokens[j];
                tokens[j] = temp2;
            }
        }
    }

    // Print the summary
    printf("Summary:\n");
    for (int i = 0; i < 10; i++) {
        printf("%s: %d\n", tokens[i], freq[i]);
    }

    // Free the memory
    free(text);
    free(tokens);
    free(freq);

    return 0;
}