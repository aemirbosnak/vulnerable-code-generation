//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void countWords(char* str);
void countChars(char* str);
void countLines(char* str);

int main(int argc, char** argv) {
    char* inputStr = NULL;
    size_t len = 0;
    ssize_t read;

    // Read input from standard input
    printf("Enter thy text to be counted: ");
    if ((read = getline(&inputStr, &len, stdin)) == -1) {
        printf("An error occurred while reading input.\n");
        return 1;
    }

    // Remove newline character from input
    if (inputStr[read - 1] == '\n') {
        inputStr[read - 1] = '\0';
    }

    // Count words, characters, and lines
    countWords(inputStr);
    countChars(inputStr);
    countLines(inputStr);

    return 0;
}

// Function to count words in input string
void countWords(char* str) {
    char* word = strtok(str, " ");
    int count = 0;

    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }

    printf("Total words: %d\n", count);
}

// Function to count characters in input string
void countChars(char* str) {
    int count = 0;

    for (int i = 0; str[i]!= '\0'; i++) {
        if (isalnum(str[i])) {
            count++;
        }
    }

    printf("Total characters: %d\n", count);
}

// Function to count lines in input string
void countLines(char* str) {
    int count = 0;

    for (int i = 0; str[i]!= '\0'; i++) {
        if (str[i] == '\n') {
            count++;
        }
    }

    printf("Total lines: %d\n", count);
}