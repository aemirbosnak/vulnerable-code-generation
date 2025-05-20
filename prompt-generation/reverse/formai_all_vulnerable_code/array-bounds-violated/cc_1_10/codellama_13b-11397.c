//Code Llama-13B DATASET v1.0 Category: Word Frequency Counter ; Style: curious
// C Word Frequency Counter

#include <stdio.h>
#include <string.h>

int main() {
    char line[100];
    char word[100];
    int word_count = 0;
    int word_length = 0;
    int i = 0;
    int j = 0;

    // Read a line of text
    fgets(line, 100, stdin);

    // Remove trailing newline character
    line[strlen(line) - 1] = '\0';

    // Split the line into words
    while (line[i] != '\0') {
        // Find the beginning of the next word
        while (line[i] == ' ') {
            i++;
        }

        // Find the end of the word
        j = i;
        while (line[j] != ' ' && line[j] != '\0') {
            j++;
        }

        // Copy the word into a separate array
        int k = 0;
        while (i < j) {
            word[k] = line[i];
            i++;
            k++;
        }
        word[k] = '\0';

        // Increment the word count
        word_count++;
    }

    // Print the word count
    printf("The word count is: %d\n", word_count);

    return 0;
}