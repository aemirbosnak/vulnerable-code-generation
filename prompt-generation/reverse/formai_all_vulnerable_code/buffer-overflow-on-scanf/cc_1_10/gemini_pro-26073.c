//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE 256
#define COMMAND_SIZE 64

int main() {
    // Initialize variables
    char data[DATA_SIZE];
    char command[COMMAND_SIZE];
    int count = 0;
    int word_count = 0;
    int line_count = 0;

    // Display welcome message
    printf("Welcome to the N-Corp Word Count Tool.\n");
    printf("Usage: wct [file name]\n");

    // Get the file name from the user
    printf("Enter file name: ");
    scanf("%s", command);

    // Open the file
    FILE *file = fopen(command, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read the file data into a buffer
    while (fgets(data, DATA_SIZE, file)) {
        // Increase the line count
        line_count++;

        // Tokenize the data into words
        char *token = strtok(data, " ");
        while (token != NULL) {
            // Increase the word count
            word_count++;

            // Get the next token
            token = strtok(NULL, " ");
        }
    }

    // Close the file
    fclose(file);

    // Display the word count
    printf("Word count: %d\n", word_count);

    // Display the line count
    printf("Line count: %d\n", line_count);

    return 0;
}