//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to summarize a text
char *summarize(char *text, int num_sentences) {
    // Check if the input is valid
    if (text == NULL || num_sentences <= 0) {
        return NULL;
    }

    // Tokenize the text into sentences
    char **sentences = NULL;
    int num_tokens = 0;
    char *token = strtok(text, ".");
    while (token != NULL) {
        sentences = realloc(sentences, (num_tokens + 1) * sizeof(char *));
        sentences[num_tokens] = token;
        num_tokens++;
        token = strtok(NULL, ".");
    }

    // Calculate the number of sentences to include in the summary
    int num_summary_sentences = num_tokens < num_sentences ? num_tokens : num_sentences;

    // Create the summary
    char *summary = malloc(sizeof(char) * 1024);
    int summary_length = 0;
    for (int i = 0; i < num_summary_sentences; i++) {
        int sentence_length = strlen(sentences[i]);
        memcpy(summary + summary_length, sentences[i], sentence_length);
        summary_length += sentence_length;
        summary[summary_length] = ' ';
        summary_length++;
    }

    // Clean up
    free(sentences);

    // Return the summary
    return summary;
}

// Function to get the user input
char *get_user_input() {
    // Get the length of the input
    int length = 0;
    printf("Enter the text to summarize: ");
    scanf("%d", &length);

    // Allocate memory for the input
    char *text = malloc(sizeof(char) * (length + 1));

    // Get the input
    scanf("%s", text);

    // Return the input
    return text;
}

// Function to print the summary
void print_summary(char *summary) {
    // Print the summary
    printf("Summary: %s\n", summary);
}

int main() {
    // Get the user input
    char *text = get_user_input();

    // Summarize the text
    char *summary = summarize(text, 5);

    // Print the summary
    print_summary(summary);

    // Free the memory
    free(text);
    free(summary);

    return 0;
}