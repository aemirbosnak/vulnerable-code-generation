//FormAI DATASET v1.0 Category: Text processing ; Style: interoperable
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 100

int main() {

    char text[500];
    char words[MAX_NUM_WORDS][MAX_WORD_LENGTH];
    int freq[MAX_NUM_WORDS]; 
    int numWords = 0;

    // Read in text from user
    printf("Enter some text (maximum length 500 characters):\n");
    fgets(text, sizeof(text), stdin);

    // Remove newline character at end of input
    if (text[strlen(text) - 1] == '\n') {
        text[strlen(text) - 1] = '\0';
    }

    // Convert text to lowercase
    for (int i = 0; text[i]; i++) {
        text[i] = tolower(text[i]);
    }

    // Split text into words and count their frequency
    char *word = strtok(text, " ");
    while (word != NULL) {
        int found = 0;

        // Check if word is already in array
        for (int i = 0; i < numWords; i++) {
            if (strcmp(word, words[i]) == 0) {
                freq[i]++;
                found = 1;
                break;
            }
        }

        // Add word to array if it's not already there
        if (!found) {
            strcpy(words[numWords], word);
            freq[numWords] = 1;
            numWords++;
        }

        word = strtok(NULL, " ");
    }

    // Sort words by frequency using bubble sort
    for (int i = 0; i < numWords - 1; i++) {
        for (int j = 0; j < numWords - i - 1; j++) {
            if (freq[j] < freq[j + 1]) {
                int tempFreq = freq[j];
                freq[j] = freq[j + 1];
                freq[j + 1] = tempFreq;

                char tempWord[MAX_WORD_LENGTH];
                strcpy(tempWord, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], tempWord);
            }
        }
    }

    // Print out word frequency table
    printf("\nWord Frequency Table:\n");
    printf("---------------------\n");
    printf("%-20s %s\n", "Word", "Frequency");
    printf("---------------------\n");
    for (int i = 0; i < numWords; i++) {
        printf("%-20s %d\n", words[i], freq[i]);
    }

    return 0;
}