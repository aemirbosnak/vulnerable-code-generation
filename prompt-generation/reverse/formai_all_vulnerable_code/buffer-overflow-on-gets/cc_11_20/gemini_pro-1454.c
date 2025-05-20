//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Create an array of strings to hold the stop words
    char *stop_words[] = {"a", "an", "the", "and", "or", "but", "for", "nor", "yet", "so", "too"};

    // Get the input sentence from the user
    char sentence[1000];
    printf("Enter a sentence: ");
    gets(sentence);

    // Tokenize the sentence into words
    char *words[100];
    int num_words = 0;
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        words[num_words++] = token;
        token = strtok(NULL, " ");
    }

    // Remove the stop words from the list of words
    int num_stop_words = sizeof(stop_words) / sizeof(char *);
    for (int i = 0; i < num_words; i++) {
        for (int j = 0; j < num_stop_words; j++) {
            if (strcmp(words[i], stop_words[j]) == 0) {
                words[i] = NULL;
                break;
            }
        }
    }

    // Count the number of positive and negative words in the sentence
    int num_positive_words = 0;
    int num_negative_words = 0;
    for (int i = 0; i < num_words; i++) {
        if (words[i] != NULL) {
            if (strcmp(words[i], "good") == 0 || strcmp(words[i], "great") == 0 || strcmp(words[i], "excellent") == 0) {
                num_positive_words++;
            } else if (strcmp(words[i], "bad") == 0 || strcmp(words[i], "terrible") == 0 || strcmp(words[i], "horrible") == 0) {
                num_negative_words++;
            }
        }
    }

    // Print the results
    if (num_positive_words > num_negative_words) {
        printf("The sentence is positive.\n");
    } else if (num_positive_words < num_negative_words) {
        printf("The sentence is negative.\n");
    } else {
        printf("The sentence is neutral.\n");
    }

    return 0;
}