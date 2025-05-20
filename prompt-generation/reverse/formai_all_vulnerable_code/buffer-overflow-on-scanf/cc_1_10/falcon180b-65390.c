//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main() {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    char delimiter;
    int count = 0;

    // Prompt user for input string
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    // Prompt user for delimiter
    printf("Enter a delimiter: ");
    scanf("%c", &delimiter);

    // Remove leading and trailing spaces from input string
    input[strcspn(input, "\n")] = '\0';
    char* token = strtok(input, " ");
    strcpy(input, token);

    // Count number of words in input string
    char* word = strtok(input, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }

    // Reverse each word in input string
    strcpy(output, input);
    char* word_start = strtok(output, " ");
    while (word_start!= NULL) {
        char* word_end = strtok(NULL, " ");
        int word_length = word_end - word_start;
        for (int i = 0; i < word_length / 2; i++) {
            char temp = word_start[i];
            word_start[i] = word_start[word_length - i - 1];
            word_start[word_length - i - 1] = temp;
        }
        word_start = word_end;
    }

    // Replace delimiter with user-defined delimiter
    char* delimiter_start = strtok(output, " ");
    while (delimiter_start!= NULL) {
        char* delimiter_end = strtok(NULL, " ");
        int delimiter_length = delimiter_end - delimiter_start;
        for (int i = 0; i < delimiter_length; i++) {
            delimiter_start[i] = delimiter;
        }
        delimiter_start = delimiter_end;
    }

    // Print reversed and delimited string
    printf("Reversed and delimited string: %s\n", output);

    return 0;
}