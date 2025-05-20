//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to summarize text using the frequency of words.
char* summarize_text(char* text, int num_sentences) {
    // Create an array of pointers to store the words in the text.
    char** words = malloc(sizeof(char*) * 1000);
    int num_words = 0;

    // Tokenize the text into words.
    char* token = strtok(text, " ");
    while (token != NULL) {
        words[num_words++] = token;
        token = strtok(NULL, " ");
    }

    // Create an array to store the frequency of each word.
    int* word_freq = malloc(sizeof(int) * num_words);
    for (int i = 0; i < num_words; i++) {
        word_freq[i] = 0;
    }

    // Count the frequency of each word.
    for (int i = 0; i < num_words; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                word_freq[i]++;
            }
        }
    }

    // Find the top num_sentences sentences with the highest frequency of words.
    char** sentences = malloc(sizeof(char*) * num_sentences);
    int* sentence_freq = malloc(sizeof(int) * num_sentences);
    for (int i = 0; i < num_sentences; i++) {
        sentences[i] = NULL;
        sentence_freq[i] = 0;
    }

    for (int i = 0; i < num_words; i++) {
        if (word_freq[i] > sentence_freq[num_sentences - 1]) {
            for (int j = num_sentences - 1; j > 0; j--) {
                if (sentence_freq[j] < sentence_freq[j - 1]) {
                    sentences[j] = sentences[j - 1];
                    sentence_freq[j] = sentence_freq[j - 1];
                }
            }
            sentences[0] = words[i];
            sentence_freq[0] = word_freq[i];
        }
    }

    // Join the top sentences into a single string.
    char* summary = malloc(sizeof(char) * 1000);
    int summary_length = 0;
    for (int i = 0; i < num_sentences; i++) {
        if (sentences[i] != NULL) {
            strcat(summary, sentences[i]);
            strcat(summary, " ");
            summary_length += strlen(sentences[i]) + 1;
        }
    }

    // Free the allocated memory.
    free(words);
    free(word_freq);
    free(sentences);
    free(sentence_freq);

    // Return the summary.
    return summary;
}

// Main function.
int main() {
    // Get the text from the user.
    char text[1000];
    printf("Enter the text to summarize: ");
    scanf("%s", text);

    // Get the number of sentences in the summary.
    int num_sentences;
    printf("Enter the number of sentences in the summary: ");
    scanf("%d", &num_sentences);

    // Summarize the text.
    char* summary = summarize_text(text, num_sentences);

    // Print the summary.
    printf("Summary: %s", summary);

    // Free the allocated memory.
    free(summary);

    return 0;
}