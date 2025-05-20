//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: Ada Lovelace
// Augusta Ada King, Countess of Lovelace, the world's first computer programmer, 1815-1852.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of a line of text.
#define MAX_LINE_LENGTH 1024

// Define the number of words to be searched for.
#define NUM_WORDS 5

// Define the words to be searched for.
char *words[NUM_WORDS] = {"Ada", "Lovelace", "computer", "programmer", "1843"};

// Define the function to count the number of occurrences of a word in a line of text.
int count_word_occurrences(char *line, char *word) {
    int count = 0;
    char *p = line;
    while ((p = strstr(p, word)) != NULL) {
        count++;
        p++;
    }
    return count;
}

// Define the function to print the number of occurrences of each word in a line of text.
void print_word_occurrences(char *line) {
    for (int i = 0; i < NUM_WORDS; i++) {
        int count = count_word_occurrences(line, words[i]);
        printf("%s: %d\n", words[i], count);
    }
}

// Define the main function.
int main() {
    // Get the input text from the user.
    char line[MAX_LINE_LENGTH];
    printf("Enter a line of text: ");
    fgets(line, MAX_LINE_LENGTH, stdin);

    // Remove the newline character from the end of the line.
    line[strlen(line) - 1] = '\0';

    // Convert the line to lowercase.
    for (int i = 0; i < strlen(line); i++) {
        line[i] = tolower(line[i]);
    }

    // Print the number of occurrences of each word in the line.
    print_word_occurrences(line);

    return 0;
}