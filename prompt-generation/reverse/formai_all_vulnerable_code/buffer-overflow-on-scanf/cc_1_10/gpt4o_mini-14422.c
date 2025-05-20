//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1024
#define POSITIVE_WORDS_COUNT 5
#define NEGATIVE_WORDS_COUNT 5

// Function to check if a word is in the array
int is_word_in_list(const char *word, const char *word_list[], int list_size) {
    for (int i = 0; i < list_size; i++) {
        if (strcmp(word, word_list[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Main function
int main() {
    const char *positive_words[POSITIVE_WORDS_COUNT] = {
        "happy", "good", "excellent", "joy", "love"
    };

    const char *negative_words[NEGATIVE_WORDS_COUNT] = {
        "sad", "bad", "terrible", "hate", "anger"
    };

    char filename[100];
    printf("Enter the filename to analyze sentiment: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    int positive_count = 0, negative_count = 0;

    // Read each line of the file
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, " \n");
        while (token != NULL) {
            // Convert token to lowercase for case-insensitive comparison
            for (int i = 0; token[i]; i++) {
                token[i] = tolower(token[i]);
            }

            // Check if the word is positive or negative
            if (is_word_in_list(token, positive_words, POSITIVE_WORDS_COUNT)) {
                positive_count++;
            } else if (is_word_in_list(token, negative_words, NEGATIVE_WORDS_COUNT)) {
                negative_count++;
            }

            token = strtok(NULL, " \n");
        }
    }

    fclose(file);

    printf("Sentiment Analysis Result:\n");
    printf("Positive Words Count: %d\n", positive_count);
    printf("Negative Words Count: %d\n", negative_count);

    if (positive_count > negative_count) {
        printf("Overall Sentiment: Positive\n");
    } else if (negative_count > positive_count) {
        printf("Overall Sentiment: Negative\n");
    } else {
        printf("Overall Sentiment: Neutral\n");
    }

    return EXIT_SUCCESS;
}