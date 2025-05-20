//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Read the input text file
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // Read the file contents into a buffer
    char *buffer = malloc(file_size + 1);
    if (buffer == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return EXIT_FAILURE;
    }
    fread(buffer, file_size, 1, file);
    fclose(file);

    // Tokenize the text into words
    char *tokens[1000];
    int num_tokens = 0;
    char *token = strtok(buffer, " ");
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }

    // Count the number of occurrences of each word
    int counts[1000];
    for (int i = 0; i < num_tokens; i++) {
        counts[i] = 0;
        for (int j = 0; j < num_tokens; j++) {
            if (strcmp(tokens[i], tokens[j]) == 0) {
                counts[i]++;
            }
        }
    }

    // Sort the words by their frequency
    for (int i = 0; i < num_tokens - 1; i++) {
        for (int j = i + 1; j < num_tokens; j++) {
            if (counts[i] < counts[j]) {
                char *temp = tokens[i];
                tokens[i] = tokens[j];
                tokens[j] = temp;
                int temp_count = counts[i];
                counts[i] = counts[j];
                counts[j] = temp_count;
            }
        }
    }

    // Print the top 10 most frequent words
    printf("Top 10 most frequent words:\n");
    for (int i = 0; i < 10; i++) {
        printf("%s: %d\n", tokens[i], counts[i]);
    }

    // Free the allocated memory
    free(buffer);

    return EXIT_SUCCESS;
}