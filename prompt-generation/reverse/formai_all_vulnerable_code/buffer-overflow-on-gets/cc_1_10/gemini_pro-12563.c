//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a sentence
typedef struct sentence {
    char *text;
    int length;
} sentence_t;

// Structure to store a summary
typedef struct summary {
    sentence_t *sentences;
    int num_sentences;
} summary_t;

// Function to create a new sentence
sentence_t *new_sentence(char *text) {
    sentence_t *sentence = malloc(sizeof(sentence_t));
    sentence->text = strdup(text);
    sentence->length = strlen(text);
    return sentence;
}

// Function to create a new summary
summary_t *new_summary() {
    summary_t *summary = malloc(sizeof(summary_t));
    summary->sentences = NULL;
    summary->num_sentences = 0;
    return summary;
}

// Function to add a sentence to a summary
void add_sentence_to_summary(summary_t *summary, sentence_t *sentence) {
    summary->sentences = realloc(summary->sentences, (summary->num_sentences + 1) * sizeof(sentence_t));
    summary->sentences[summary->num_sentences++] = *sentence;
}

// Function to compare two sentences by length
int compare_sentences(const void *a, const void *b) {
    sentence_t *sentence1 = (sentence_t *)a;
    sentence_t *sentence2 = (sentence_t *)b;
    return sentence1->length - sentence2->length;
}

// Function to summarize a text
summary_t *summarize_text(char *text) {
    // Tokenize the text into sentences
    char *token = strtok(text, ".");
    summary_t *summary = new_summary();
    while (token != NULL) {
        // Create a new sentence and add it to the summary
        sentence_t *sentence = new_sentence(token);
        add_sentence_to_summary(summary, sentence);
        // Get the next token
        token = strtok(NULL, ".");
    }

    // Sort the sentences by length
    qsort(summary->sentences, summary->num_sentences, sizeof(sentence_t), compare_sentences);

    // Return the summary
    return summary;
}

// Function to print a summary
void print_summary(summary_t *summary) {
    for (int i = 0; i < summary->num_sentences; i++) {
        printf("%s", summary->sentences[i].text);
    }
}

// Main function
int main() {
    // Get the text to summarize from the user
    char text[1000];
    printf("Enter the text to summarize: ");
    gets(text);

    // Summarize the text
    summary_t *summary = summarize_text(text);

    // Print the summary
    printf("Summary: ");
    print_summary(summary);

    // Free the memory allocated for the summary
    for (int i = 0; i < summary->num_sentences; i++) {
        free(summary->sentences[i].text);
    }
    free(summary->sentences);
    free(summary);

    return 0;
}