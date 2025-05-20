//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to summarize a text
char* summarize(char* text, int num_sentences) {
    // Check if the input is valid
    if (text == NULL || num_sentences <= 0) {
        return NULL;
    }

    // Tokenize the text into sentences
    char** sentences = malloc(sizeof(char*) * num_sentences);
    int num_tokens = 0;
    char* token = strtok(text, ".");
    while (token != NULL && num_tokens < num_sentences) {
        sentences[num_tokens++] = token;
        token = strtok(NULL, ".");
    }

    // Select the most important sentences
    int* scores = malloc(sizeof(int) * num_tokens);
    for (int i = 0; i < num_tokens; i++) {
        scores[i] = 0;
        char* sentence = sentences[i];
        int num_words = 0;
        char* word = strtok(sentence, " ");
        while (word != NULL) {
            num_words++;
            word = strtok(NULL, " ");
        }
        scores[i] += num_words;
        for (int j = 0; j < strlen(sentence); j++) {
            if (sentence[j] == '.' || sentence[j] == '!' || sentence[j] == '?') {
                scores[i] += 1;
            }
        }
    }

    // Sort the sentences by their importance scores
    for (int i = 0; i < num_tokens; i++) {
        for (int j = i + 1; j < num_tokens; j++) {
            if (scores[i] < scores[j]) {
                int temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
                char* temp_sentence = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = temp_sentence;
            }
        }
    }

    // Concatenate the most important sentences into a summary
    char* summary = malloc(sizeof(char) * 1024);
    strcpy(summary, "");
    for (int i = 0; i < num_sentences; i++) {
        strcat(summary, sentences[i]);
        strcat(summary, ". ");
    }

    // Free the allocated memory
    free(sentences);
    free(scores);

    // Return the summary
    return summary;
}

// Main function
int main() {
    // Get the input text from the user
    printf("Enter the text to be summarized: ");
    char* text = malloc(sizeof(char) * 1024);
    gets(text);

    // Get the number of sentences to include in the summary
    printf("Enter the number of sentences to include in the summary: ");
    int num_sentences;
    scanf("%d", &num_sentences);

    // Summarize the text
    char* summary = summarize(text, num_sentences);

    // Print the summary
    printf("Summary: %s\n", summary);

    // Free the allocated memory
    free(summary);

    return 0;
}