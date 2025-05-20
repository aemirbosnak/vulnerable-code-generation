//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: medieval
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

// Function to count words, sentences and paragraphs
void countWords(FILE* file) {
    int ch;
    int wordCount = 0;
    int sentenceCount = 0;
    int paragraphCount = 0;

    // Loop through each character in the file
    while ((ch = fgetc(file))!= EOF) {
        // Check if the character is a whitespace
        if (isspace(ch)) {
            // Increment word count if the previous character was not a whitespace
            if (!isspace(fgetc(file))) {
                wordCount++;
            }
            // Check if the whitespace is a newline character
            if (ch == '\n') {
                // Increment sentence and paragraph count
                sentenceCount++;
                paragraphCount++;
            }
        }
    }

    // Print the results
    printf("Total words: %d\n", wordCount);
    printf("Total sentences: %d\n", sentenceCount);
    printf("Total paragraphs: %d\n", paragraphCount);
}

int main() {
    FILE* file;
    char filename[100];

    // Ask the user for the filename
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file in read mode
    file = fopen(filename, "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Count words, sentences and paragraphs
    countWords(file);

    // Close the file
    fclose(file);

    return 0;
}