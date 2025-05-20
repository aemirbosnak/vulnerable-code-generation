//Code Llama-13B DATASET v1.0 Category: Sentiment analysis tool ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 100

struct Sentiment {
    char word[MAX_SENTENCE_LENGTH];
    int score;
};

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    int i, j, k;

    // Initialize the sentiment array
    struct Sentiment sentiments[] = {
        {"good", 1},
        {"bad", -1},
        {"happy", 1},
        {"sad", -1},
        {"excited", 1},
        {"scared", -1},
        {"angry", -1},
        {"surprised", 1},
        {"confused", -1}
    };

    // Prompt the user to enter a sentence
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    // Remove the newline character from the end of the sentence
    sentence[strcspn(sentence, "\n")] = '\0';

    // Iterate through the sentence and find the sentiment of each word
    for (i = 0; i < strlen(sentence); i++) {
        for (j = 0; j < sizeof(sentiments) / sizeof(sentiments[0]); j++) {
            if (strcmp(sentence[i], sentiments[j].word) == 0) {
                // If the word is found in the sentiment array, add its score to the total
                printf("The sentiment of %s is %d\n", sentence[i], sentiments[j].score);
                break;
            }
        }
    }

    // Calculate the overall sentiment of the sentence
    int total_score = 0;
    for (k = 0; k < strlen(sentence); k++) {
        total_score += sentiments[k].score;
    }

    // Print the overall sentiment of the sentence
    printf("The overall sentiment of the sentence is %d\n", total_score);

    return 0;
}