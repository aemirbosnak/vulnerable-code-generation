//FormAI DATASET v1.0 Category: Word Count Tool ; Style: thoughtful
#include <stdio.h>
#include <string.h>

// function prototypes
int countWords(char* str);

int main() {
    // input string
    char str[1000];

    printf("Enter a sentence: ");
    // read string from user
    fgets(str, 1000, stdin);

    // remove newline character at the end of string
    str[strlen(str) - 1] = '\0';

    // call countWords function to count words in the sentence
    int numWords = countWords(str);

    printf("Number of words in sentence: %d", numWords);

    return 0;
}

int countWords(char* str) {
    int numWords = 0;
    int wordStarted = 0;

    // loop through characters in the string
    for (int i = 0; i < strlen(str); i++) {
        // check if current character is a space, tab, or newline
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            // if a word was started, increment word count
            if (wordStarted == 1) {
                numWords++;
                wordStarted = 0;
            }
        } else {
            // start of a new word
            if (wordStarted == 0) {
                wordStarted = 1;
            }
        }
    }

    // if the last character of the string is not a space, tab, or newline, increment word count
    if (wordStarted == 1) {
        numWords++;
    }

    return numWords;
}