//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold a sentence
typedef struct sentence {
    char *text;
    int length;
} sentence_t;

// Function to compare two sentences by length
int compare_sentences(const void *a, const void *b) {
    const sentence_t *sa = (const sentence_t *)a;
    const sentence_t *sb = (const sentence_t *)b;
    return sa->length - sb->length;
}

// Function to summarize a text
char *summarize_text(char *text, int num_sentences) {
    // Split the text into sentences
    char **sentences = NULL;
    int num_sentences_found = 0;
    char *sentence_start = text;
    while (*sentence_start != '\0') {
        char *sentence_end = strchr(sentence_start, '.');
        if (sentence_end != NULL) {
            int sentence_length = sentence_end - sentence_start + 1;
            sentences = realloc(sentences, (num_sentences_found + 1) * sizeof(char *));
            sentences[num_sentences_found] = malloc(sentence_length);
            strncpy(sentences[num_sentences_found], sentence_start, sentence_length);
            sentences[num_sentences_found][sentence_length - 1] = '\0';
            num_sentences_found++;
            sentence_start = sentence_end + 1;
        } else {
            break;
        }
    }

    // Sort the sentences by length
    qsort(sentences, num_sentences_found, sizeof(sentence_t), compare_sentences);

    // Create the summary
    char *summary = malloc(1);
    summary[0] = '\0';
    for (int i = 0; i < num_sentences && i < num_sentences_found; i++) {
        char *sentence = sentences[i];
        int sentence_length = strlen(sentence);
        summary = realloc(summary, strlen(summary) + sentence_length + 2);
        strcat(summary, sentence);
        strcat(summary, ". ");
    }

    // Free the sentences
    for (int i = 0; i < num_sentences_found; i++) {
        free(sentences[i]);
    }
    free(sentences);

    // Return the summary
    return summary;
}

// Main function
int main() {
    // Get the text from the user
    char *text = NULL;
    size_t text_size = 0;
    getline(&text, &text_size, stdin);

    // Get the number of sentences to include in the summary
    int num_sentences;
    printf("Enter the number of sentences to include in the summary: ");
    scanf("%d", &num_sentences);

    // Summarize the text
    char *summary = summarize_text(text, num_sentences);

    // Print the summary
    printf("Summary: %s\n", summary);

    // Free the summary
    free(summary);

    return 0;
}