//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: automated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to summarize a text
char* summarize(char* text, int n) {
    // Split the text into sentences
    char** sentences = (char**)malloc(n * sizeof(char*));
    int num_sentences = 0;
    char* token = strtok(text, ".");
    while (token != NULL) {
        sentences[num_sentences++] = token;
        token = strtok(NULL, ".");
    }

    // Calculate the importance of each sentence
    int* sentence_importance = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        sentence_importance[i] = 0;
        char* word = strtok(sentences[i], " ");
        while (word != NULL) {
            if (strlen(word) > 3) {
                sentence_importance[i]++;
            }
            word = strtok(NULL, " ");
        }
    }

    // Sort the sentences by importance
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sentence_importance[i] < sentence_importance[j]) {
                int temp = sentence_importance[i];
                sentence_importance[i] = sentence_importance[j];
                sentence_importance[j] = temp;

                char* temp_sentence = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = temp_sentence;
            }
        }
    }

    // Generate the summary
    char* summary = (char*)malloc(1000 * sizeof(char));
    int summary_length = 0;
    for (int i = 0; i < n && summary_length < 1000; i++) {
        strcat(summary, sentences[i]);
        strcat(summary, ". ");
        summary_length += strlen(sentences[i]);
    }

    // Free the allocated memory
    free(sentences);
    free(sentence_importance);

    // Return the summary
    return summary;
}

// Main function
int main() {
    // Get the text from the user
    printf("Enter the text to summarize: ");
    char* text = (char*)malloc(1000 * sizeof(char));
    gets(text);

    // Get the number of sentences
    int n = 0;
    char* token = strtok(text, ".");
    while (token != NULL) {
        n++;
        token = strtok(NULL, ".");
    }

    // Summarize the text
    char* summary = summarize(text, n);

    // Print the summary
    printf("The summary is: %s", summary);

    // Free the allocated memory
    free(text);
    free(summary);

    return 0;
}