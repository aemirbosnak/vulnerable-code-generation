//GEMINI-pro DATASET v1.0 Category: File handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Open a file for reading
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    rewind(file);

    // Read the file into a buffer
    char *buffer = malloc(file_size + 1);
    if (buffer == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return EXIT_FAILURE;
    }
    fread(buffer, file_size, 1, file);
    fclose(file);

    // Tokenize the buffer into words
    char *words[100];
    int num_words = 0;
    char *token = strtok(buffer, " ");
    while (token != NULL) {
        words[num_words++] = token;
        token = strtok(NULL, " ");
    }

    // Sort the words
    qsort(words, num_words, sizeof(char *), strcmp);

    // Write the sorted words to a new file
    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        perror("Error opening file");
        free(buffer);
        return EXIT_FAILURE;
    }
    for (int i = 0; i < num_words; i++) {
        fprintf(output_file, "%s\n", words[i]);
    }
    fclose(output_file);

    // Free the buffer
    free(buffer);

    return EXIT_SUCCESS;
}