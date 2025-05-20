//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to summarize the text
char* summarize(char* text, int num_sentences) {
    // Tokenize the text into sentences
    char* sentences[100];
    int num_tokens = 0;
    char* token = strtok(text, ".");
    while (token != NULL) {
        sentences[num_tokens++] = token;
        token = strtok(NULL, ".");
    }

    // Calculate the average sentence length
    int total_length = 0;
    for (int i = 0; i < num_tokens; i++) {
        total_length += strlen(sentences[i]);
    }
    int avg_length = total_length / num_tokens;

    // Select the most important sentences
    char* summary[10];
    int num_summary_sentences = 0;
    for (int i = 0; i < num_tokens; i++) {
        if (strlen(sentences[i]) > avg_length) {
            summary[num_summary_sentences++] = sentences[i];
        }
    }

    // Concatenate the summary sentences into a single string
    char* summary_text = malloc(1000);
    strcpy(summary_text, summary[0]);
    for (int i = 1; i < num_summary_sentences; i++) {
        strcat(summary_text, ". ");
        strcat(summary_text, summary[i]);
    }

    // Return the summary text
    return summary_text;
}

// Main function
int main() {
    // Get the text from the user
    char text[1000];
    printf("Enter the text: ");
    gets(text);

    // Get the number of sentences in the summary
    int num_sentences;
    printf("Enter the number of sentences in the summary: ");
    scanf("%d", &num_sentences);

    // Summarize the text
    char* summary_text = summarize(text, num_sentences);

    // Print the summary
    printf("Summary: %s", summary_text);

    // Free the allocated memory
    free(summary_text);

    return 0;
}