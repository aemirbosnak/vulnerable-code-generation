//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove stop words from a string
char *remove_stop_words(char *str) {
    char *stop_words[] = {"a", "an", "and", "are", "as", "at", "be", "been", "being", "but", "by", "can", "could", "did", "do", "does", "doing", "for", "from", "have", "has", "had", "having", "he", "her", "hers", "him", "his", "how", "i", "if", "in", "into", "is", "it", "its", "me", "my", "myself", "of", "on", "or", "our", "ours", "out", "over", "she", "should", "so", "some", "than", "that", "the", "their", "theirs", "them", "then", "there", "these", "they", "this", "to", "too", "under", "up", "us", "we", "were", "what", "when", "where", "which", "who", "whom", "why", "will", "with", "would"};
    int num_stop_words = sizeof(stop_words) / sizeof(stop_words[0]);

    // Create a new string to store the result
    char *result = malloc(strlen(str) + 1);

    // Copy the first word from the original string to the result string
    char *word = strtok(str, " ");
    strcpy(result, word);

    // Loop through the remaining words in the original string
    while ((word = strtok(NULL, " ")) != NULL) {
        // Check if the current word is a stop word
        int is_stop_word = 0;
        for (int i = 0; i < num_stop_words; i++) {
            if (strcmp(word, stop_words[i]) == 0) {
                is_stop_word = 1;
                break;
            }
        }

        // If the current word is not a stop word, add it to the result string
        if (!is_stop_word) {
            strcat(result, " ");
            strcat(result, word);
        }
    }

    // Return the result string
    return result;
}

// Function to summarize a text
char *summarize_text(char *text) {
    // Remove stop words from the text
    char *cleaned_text = remove_stop_words(text);

    // Create a new string to store the summary
    char *summary = malloc(strlen(cleaned_text) + 1);

    // Copy the first sentence from the cleaned text to the summary
    char *sentence = strtok(cleaned_text, ".");
    strcpy(summary, sentence);

    // Loop through the remaining sentences in the cleaned text
    while ((sentence = strtok(NULL, ".")) != NULL) {
        // Check if the current sentence is longer than the previous sentence
        if (strlen(sentence) > strlen(summary)) {
            // If the current sentence is longer, replace the summary with the current sentence
            strcpy(summary, sentence);
        }
    }

    // Return the summary
    return summary;
}

int main() {
    // Get the text to be summarized from the user
    char *text = malloc(1000);
    printf("Enter the text to be summarized: ");
    gets(text);

    // Summarize the text
    char *summary = summarize_text(text);

    // Print the summary
    printf("Summary: %s", summary);

    // Free the allocated memory
    free(text);
    free(summary);

    return 0;
}