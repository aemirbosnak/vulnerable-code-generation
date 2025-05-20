//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to summarize a text
void summarize(char *text, int length) {
    // Check if the text is valid
    if (text == NULL || length <= 0) {
        printf("Invalid text or length.\n");
        return;
    }

    // Allocate memory for the summary
    char *summary = malloc(length / 5 + 1);
    if (summary == NULL) {
        printf("Could not allocate memory for the summary.\n");
        return;
    }

    // Initialize the summary
    summary[0] = '\0';

    // Split the text into sentences
    char *sentences[100];
    int num_sentences = 0;
    char *sentence = strtok(text, ".");
    while (sentence != NULL) {
        sentences[num_sentences++] = sentence;
        sentence = strtok(NULL, ".");
    }

    // Rank the sentences by their importance
    int ranks[num_sentences];
    for (int i = 0; i < num_sentences; i++) {
        ranks[i] = rank(sentences[i]);
    }

    // Select the top-ranked sentences for the summary
    int num_summary_sentences = length / 50;
    for (int i = 0; i < num_summary_sentences; i++) {
        int max_rank = -1;
        int max_rank_index = -1;
        for (int j = 0; j < num_sentences; j++) {
            if (ranks[j] > max_rank) {
                max_rank = ranks[j];
                max_rank_index = j;
            }
        }
        strcat(summary, sentences[max_rank_index]);
        strcat(summary, ". ");
        ranks[max_rank_index] = -1;
    }

    // Print the summary
    printf("Summary:\n%s\n", summary);

    // Free the allocated memory
    free(summary);
}

// Function to rank a sentence based on its importance
int rank(char *sentence) {
    // Check if the sentence is valid
    if (sentence == NULL || strlen(sentence) == 0) {
        return 0;
    }

    // Count the number of words in the sentence
    int num_words = 0;
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        num_words++;
        word = strtok(NULL, " ");
    }

    // Count the number of important words in the sentence
    int num_important_words = 0;
    for (int i = 0; i < num_words; i++) {
        if (is_important_word(word)) {
            num_important_words++;
        }
        word = strtok(NULL, " ");
    }

    // Return the rank of the sentence
    return num_important_words / num_words;
}

// Function to check if a word is important
int is_important_word(char *word) {
    // Check if the word is a noun, verb, or adjective
    if (strcmp(word, "the") == 0 || strcmp(word, "is") == 0 || strcmp(word, "a") == 0) {
        return 0;
    }

    // Check if the word is in the list of important words
    char *important_words[] = {"Sherlock", "Holmes", "Watson", "crime", "mystery", "detective"};
    for (int i = 0; i < sizeof(important_words) / sizeof(char *); i++) {
        if (strcmp(word, important_words[i]) == 0) {
            return 1;
        }
    }

    // Return 0 if the word is not important
    return 0;
}

// Main function
int main() {
    // Get the text from the user
    char text[1000];
    printf("Enter the text to summarize: ");
    scanf("%s", text);

    // Summarize the text
    summarize(text, strlen(text));

    return 0;
}