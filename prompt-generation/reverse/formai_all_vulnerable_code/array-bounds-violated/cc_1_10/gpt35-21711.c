//FormAI DATASET v1.0 Category: Word Count Tool ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 30
#define MAX_NUM_WORDS 1000

// Function to count the number of occurrences of each word in a string
void countWords(char *string, int numWords, char words[][MAX_WORD_LENGTH], int wordCount[]) {
    int i, j, k = 0;
    char word[MAX_WORD_LENGTH];
    int seen;

    // Loop through each word in the string
    for (i = 0; i < numWords; i++) {
        // Copy the current word into a temporary variable
        j = 0;
        while (string[k] != ' ' && string[k] != '\0') {
            word[j] = string[k];
            j++;
            k++;
        }
        word[j] = '\0';

        // Check if we've already seen this word
        seen = 0;
        for (j = 0; j < i; j++) {
            if (strcmp(words[j], word) == 0) {
                seen = 1;
                break;
            }
        }

        // If we haven't seen this word, add it to the list
        if (!seen) {
            strcpy(words[i], word);
            wordCount[i] = 1;
        }
        // If we have seen this word, increment its count
        else {
            wordCount[j]++;
        }

        // Skip over any additional spaces in the string
        while (string[k] == ' ') {
            k++;
        }

        // Break out of the loop if we've reached the end of the string
        if (string[k] == '\0') {
            break;
        }
    }
}

int main() {
    char string[1000];
    printf("Enter a string to count the number of words in it: ");
    fgets(string, sizeof(string), stdin);

    // Remove any trailing newline character from the input string
    if (string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }

    // Convert the string to lowercase
    int i;
    for (i = 0; i < strlen(string); i++) {
        string[i] = tolower(string[i]);
    }

    // Tokenize the input string into individual words
    int numWords = 0;
    char words[MAX_NUM_WORDS][MAX_WORD_LENGTH];
    int wordCount[MAX_NUM_WORDS] = {0};
    char *token = strtok(string, " ");
    while (token != NULL && numWords < MAX_NUM_WORDS) {
        strcpy(words[numWords], token);
        numWords++;
        token = strtok(NULL, " ");
    }

    // Count the number of occurrences of each word
    countWords(string, numWords, words, wordCount);

    // Print out the results
    printf("Word count:\n");
    for (i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i], wordCount[i]);
    }

    return 0;
}