//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to determine the sentiment of a sentence
void determineSentiment(char sentence[]) {
    // Creating an array of positive and negative words for comparison
    char positiveWords[5][15] = {"happy", "good", "love", "excited", "great"};
    char negativeWords[5][15] = {"sad", "bad", "hate", "disgusted", "terrible"};

    int positiveCount = 0;
    int negativeCount = 0;

    // Break the sentence into words for comparison
    char *word = strtok(sentence, " ");

    // Loop through each word in the sentence
    while(word != NULL) {
        // Compare the word with the positive and negative word arrays
        for(int i = 0; i < 5; i++) {
            if(strcmp(word, positiveWords[i]) == 0) {
                positiveCount++;
                break;
            }
            else if(strcmp(word, negativeWords[i]) == 0) {
                negativeCount++;
                break;
            }
        }

        // Move to the next word in the sentence
        word = strtok(NULL, " ");
    }

    // Determine the overall sentiment of the sentence based on positive and negative word counts
    if(positiveCount > negativeCount) {
        printf("The sentiment of the sentence is Positive\n");
    }
    else if(negativeCount > positiveCount) {
        printf("The sentiment of the sentence is Negative\n");
    }
    else {
        printf("The sentiment of the sentence is Neutral\n");
    }
}

int main() {
    // Prompt the user to enter a sentence for sentiment analysis
    char sentence[100];
    printf("Enter a sentence for sentiment analysis: ");
    gets(sentence);

    determineSentiment(sentence);

    return 0;
}