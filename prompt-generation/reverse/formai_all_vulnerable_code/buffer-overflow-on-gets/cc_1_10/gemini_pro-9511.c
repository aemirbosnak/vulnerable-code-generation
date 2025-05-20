//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to summarize a text
char *summarize(char *text) {
    // Check if the text is empty
    if (text == NULL || strlen(text) == 0) {
        return NULL;
    }

    // Remove all the punctuation marks from the text
    char *newText = (char *)malloc(strlen(text) + 1);
    int i, j = 0;
    for (i = 0; i < strlen(text); i++) {
        if (text[i] != '.' && text[i] != ',' && text[i] != '?' && text[i] != '!' && text[i] != ';' && text[i] != ':') {
            newText[j++] = text[i];
        }
    }
    newText[j] = '\0';

    // Split the text into words
    char **words = (char **)malloc(sizeof(char *) * 100);
    i = 0;
    char *word = strtok(newText, " ");
    while (word != NULL) {
        words[i++] = word;
        word = strtok(NULL, " ");
    }

    // Find the most frequent words in the text
    int *frequencies = (int *)malloc(sizeof(int) * i);
    for (j = 0; j < i; j++) {
        frequencies[j] = 0;
        for (int k = 0; k < i; k++) {
            if (strcmp(words[j], words[k]) == 0) {
                frequencies[j]++;
            }
        }
    }

    // Sort the words by their frequencies
    for (j = 0; j < i - 1; j++) {
        for (int k = j + 1; k < i; k++) {
            if (frequencies[j] < frequencies[k]) {
                int temp = frequencies[j];
                frequencies[j] = frequencies[k];
                frequencies[k] = temp;

                char *temp2 = words[j];
                words[j] = words[k];
                words[k] = temp2;
            }
        }
    }

    // Create the summary
    char *summary = (char *)malloc(100);
    strcpy(summary, "");
    for (j = 0; j < 10; j++) {
        strcat(summary, words[j]);
        strcat(summary, " ");
    }

    // Free the allocated memory
    free(newText);
    free(words);
    free(frequencies);

    return summary;
}

// Main function
int main() {
    // Get the text from the user
    char text[1000];
    printf("Enter the text to be summarized: ");
    gets(text);

    // Summarize the text
    char *summary = summarize(text);

    // Print the summary
    printf("Summary: %s\n", summary);

    return 0;
}