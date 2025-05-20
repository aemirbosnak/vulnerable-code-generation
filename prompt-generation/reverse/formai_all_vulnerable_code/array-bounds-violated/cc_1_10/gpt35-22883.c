//FormAI DATASET v1.0 Category: Word Count Tool ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORD_COUNT 1000

int main()
{
    char input_string[MAX_WORD_LENGTH * MAX_WORD_COUNT]; // Store the input string
    char words[MAX_WORD_COUNT][MAX_WORD_LENGTH]; // Store the individual words
    int word_count = 0; // Count of the number of words
    int c; // Current character
    int i, j; // Loop variables

    // Read the input string
    printf("Enter a string: ");
    fgets(input_string, sizeof(input_string), stdin);

    // Remove the '\n' character from the end of the input string
    input_string[strlen(input_string) - 1] = '\0';

    // Extract the words from the input string
    i = 0;
    j = 0;
    while ((c = input_string[i++]) != '\0') {
        if (c == ' ' || c == '\t') {
            if (j > 0) {
                words[word_count++][j] = '\0';
                j = 0;
            }
        } else {
            words[word_count][j++] = c;
        }
    }
    if (j > 0) {
        words[word_count++][j] = '\0';
    }

    // Display the word count
    printf("Word count: %d\n", word_count);

    // Display the words
    printf("\nWords:\n");
    for (i = 0; i < word_count; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}