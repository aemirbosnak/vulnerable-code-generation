//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove stop words from a string
char* removeStopWords(char* str) {
    // Create an array of stop words
    char* stopWords[] = {"a", "an", "the", "and", "or", "but", "for", "nor", "as", "at", "by", "from", "in", "into", "near", "of", "on", "onto", "over", "through", "to", "toward", "under", "up", "upon", "with", "without"};

    // Create a new string to store the result
    char* result = malloc(strlen(str) + 1);

    // Copy the first word from the original string to the result string
    int i = 0;
    int j = 0;
    while (str[i] != ' ' && str[i] != '\0') {
        result[j++] = str[i++];
    }

    // Iterate over the remaining words in the original string
    while (str[i] != '\0') {
        // If the current word is not a stop word, copy it to the result string
        int isStopWord = 0;
        for (int k = 0; k < sizeof(stopWords) / sizeof(char*); k++) {
            if (strcmp(str + i, stopWords[k]) == 0) {
                isStopWord = 1;
                break;
            }
        }
        if (!isStopWord) {
            result[j++] = ' ';
            while (str[i] != ' ' && str[i] != '\0') {
                result[j++] = str[i++];
            }
        }

        // Skip the whitespace characters
        while (str[i] == ' ') {
            i++;
        }
    }

    // Add a null terminator to the end of the result string
    result[j] = '\0';

    // Return the result string
    return result;
}

// Function to summarize a text
char* summarizeText(char* text) {
    // Remove stop words from the text
    char* cleanedText = removeStopWords(text);

    // Create an array of sentences
    char* sentences[100];
    int numSentences = 0;
    char* sentence = strtok(cleanedText, ".");
    while (sentence != NULL) {
        sentences[numSentences++] = sentence;
        sentence = strtok(NULL, ".");
    }

    // Create a new string to store the summary
    char* summary = malloc(strlen(text) / 2 + 1);

    // Iterate over the sentences and add the most important ones to the summary
    for (int i = 0; i < numSentences; i++) {
        // Calculate the importance of the sentence
        int importance = 0;
        char* word = strtok(sentences[i], " ");
        while (word != NULL) {
            if (strlen(word) > 3) {
                importance++;
            }
            word = strtok(NULL, " ");
        }

        // Add the sentence to the summary if it is important enough
        if (importance > 2) {
            strcat(summary, sentences[i]);
            strcat(summary, ". ");
        }
    }

    // Add a null terminator to the end of the summary string
    summary[strlen(summary)] = '\0';

    // Return the summary string
    return summary;
}

// Main function
int main() {
    // Get the input text from the user
    char* text = malloc(1000);
    printf("Enter the text to be summarized: ");
    gets(text);

    // Summarize the text
    char* summary = summarizeText(text);

    // Print the summary
    printf("Summary: %s\n", summary);

    // Free the allocated memory
    free(text);
    free(summary);

    return 0;
}