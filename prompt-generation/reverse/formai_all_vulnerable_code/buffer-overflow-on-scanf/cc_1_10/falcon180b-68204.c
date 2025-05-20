//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORD_COUNT 1000

// Function to count the frequency of each word in the given text
void countWordFrequency(char *text) {
    int wordCount = 0;
    char word[MAX_WORD_LENGTH];
    int wordLength = 0;
    int i = 0;
    int j = 0;

    // Initialize the frequency array with zeros
    int frequency[26] = {0};

    // Loop through each character in the text
    while (text[i]!= '\0') {
        // Check if the character is a letter
        if (isalpha(text[i])) {
            // Convert the character to lowercase
            text[i] = tolower(text[i]);

            // Check if the word has reached the maximum length
            if (wordLength >= MAX_WORD_LENGTH) {
                // If yes, add the word to the frequency array and reset the word
                for (j = 0; j < strlen(word); j++) {
                    frequency[(int)word[j] - 97]++;
                }
                wordLength = 0;
            }

            // Add the current character to the word
            strncat(word, &text[i], 1);
            wordLength++;
        } else {
            // If the character is not a letter, reset the word
            wordLength = 0;
        }

        i++;
    }

    // Add the last word to the frequency array
    for (j = 0; j < strlen(word); j++) {
        frequency[(int)word[j] - 97]++;
    }

    // Print the frequency of each word
    for (i = 0; i < 26; i++) {
        printf("%c: %d\n", i + 97, frequency[i]);
    }
}

int main() {
    char text[1000];

    // Get the input text from the user
    printf("Enter the text: ");
    scanf("%s", text);

    // Count the frequency of each word in the text
    countWordFrequency(text);

    return 0;
}