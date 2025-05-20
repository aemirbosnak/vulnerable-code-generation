//FormAI DATASET v1.0 Category: Text Summarizer ; Style: introspective
/* As a text summarizer chatbot, my goal is to extract the most important information from a given text input.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIM ".,;:!?\n" // Delimiters used for parsing input text

/* Function to calculate the frequency of each word in the given text input */
void calcFreq(char *text, int *freq, int n) {
    char *token;
    int i = 0;

    // Get first word in input text
    token = strtok(text, DELIM);

    // Loop through remaining words in input text
    while (token != NULL) {
        // Check if word has length greater than 1
        if (strlen(token) > 1) {
            // Convert all characters in the word to lowercase
            for (int j = 0; j < strlen(token); j++) {
                token[j] = tolower(token[j]);
            }
            
            // Increment frequency count for the current word
            freq[i]++;
        }

        // Get next word in input text
        token = strtok(NULL, DELIM);
        i++;

        // Check if i exceeds the predefined limit n
        if (i == n) {
            break;
        }
    }
}

/* Function to print the summary of the given text input */
void printSummary(char *text, int *freq, int n) {
    char *token;
    int i = 0;

    printf("---- Text Summary ----\n");

    // Get first word in input text
    token = strtok(text, DELIM);

    // Loop through words in input text and print out selected summary sentences
    while (token != NULL) {
        // Check if word has length greater than 1
        if (strlen(token) > 1) {
            // Convert all characters in the word to lowercase
            for (int j = 0; j < strlen(token); j++) {
                token[j] = tolower(token[j]);
            }
            
            // Print out the sentence containing the current word with a frequency greater than 1
            if (freq[i] > 1) {
                printf("%s ", token);
            } else if (strchr(DELIM, token[strlen(token) - 1]) != NULL) {
                printf("%s", token);    
            }
        }

        // Get next word in input text
        token = strtok(NULL, DELIM);
        i++;
    }

    printf("\n");
}

/* Main program function */
int main() {
    char inputText[1000];
    int wordFreq[100] = {0};
    int summaryWords = 0;

    printf("Enter text to summarize: ");
    fgets(inputText, 1000, stdin);

    // Prompt user for number of words to print in the summary
    printf("Enter number of words to include in summary (must be greater than 0): ");
    scanf("%d", &summaryWords);

    // Calculate frequency of each word in the input text
    calcFreq(inputText, wordFreq, summaryWords);

    // Print out selected summary sentences based on word frequency
    printSummary(inputText, wordFreq, summaryWords);

    return 0;
}