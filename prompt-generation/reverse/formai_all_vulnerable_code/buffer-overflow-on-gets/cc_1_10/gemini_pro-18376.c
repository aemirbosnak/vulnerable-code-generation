//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Constants
#define MAX_SENTENCE_LENGTH 500
#define MAX_SUMMARY_LENGTH 100

// Function prototypes
void print_sentences(char **sentences, int num_sentences);
int get_num_sentences(char *text);
char **get_sentences(char *text, int num_sentences);
char *summarize_text(char **sentences, int num_sentences);

// Main function
int main() {
    // Get the input text from the user
    char text[5000];
    printf("Enter the text you want to summarize: ");
    gets(text);

    // Get the number of sentences in the text
    int num_sentences = get_num_sentences(text);

    // Get the sentences from the text
    char **sentences = get_sentences(text, num_sentences);

    // Print the sentences
    print_sentences(sentences, num_sentences);

    // Summarize the text
    char *summary = summarize_text(sentences, num_sentences);

    // Print the summary
    printf("\nSummary: %s\n", summary);

    // Free the memory allocated for the sentences and the summary
    for (int i = 0; i < num_sentences; i++) {
        free(sentences[i]);
    }
    free(sentences);
    free(summary);

    return 0;
}

// Function to print the sentences
void print_sentences(char **sentences, int num_sentences) {
    for (int i = 0; i < num_sentences; i++) {
        printf("%s\n", sentences[i]);
    }
}

// Function to get the number of sentences in the text
int get_num_sentences(char *text) {
    int num_sentences = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            num_sentences++;
        }
    }
    return num_sentences;
}

// Function to get the sentences from the text
char **get_sentences(char *text, int num_sentences) {
    char **sentences = malloc(sizeof(char *) * num_sentences);
    int sentence_start = 0;
    int sentence_end = 0;
    int sentence_count = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentence_end = i;
            sentences[sentence_count] = malloc(sizeof(char) * (sentence_end - sentence_start + 1));
            strncpy(sentences[sentence_count], text + sentence_start, sentence_end - sentence_start);
            sentences[sentence_count][sentence_end - sentence_start] = '\0';
            sentence_count++;
            sentence_start = i + 1;
        }
    }
    return sentences;
}

// Function to summarize the text
char *summarize_text(char **sentences, int num_sentences) {
    char *summary = malloc(sizeof(char) * MAX_SUMMARY_LENGTH);
    int summary_length = 0;
    for (int i = 0; i < num_sentences; i++) {
        if (summary_length + strlen(sentences[i]) + 1 < MAX_SUMMARY_LENGTH) {
            strcat(summary, sentences[i]);
            summary_length += strlen(sentences[i]);
            strcat(summary, " ");
            summary_length++;
        } else {
            break;
        }
    }
    if (summary_length > 0) {
        summary[summary_length - 1] = '\0';
    }
    return summary;
}