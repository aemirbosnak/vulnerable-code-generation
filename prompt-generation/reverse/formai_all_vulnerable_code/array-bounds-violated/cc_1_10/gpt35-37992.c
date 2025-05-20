//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: safe
#include <stdio.h>
#include <string.h>

// Function to determine sentiment score of a sentence
int getSentiment(char sentence[]) {
    int sentiment = 0;
    char word[50];
    int len = strlen(sentence);
    
    // Split sentence into words
    int index = 0;
    for (int i = 0; i < len; i++) {
        if (sentence[i] == ' ') {
            word[index] = '\0';
            index = 0;
            
            // Check if word is positive, negative, or neutral
            if (strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "awesome") == 0) {
                sentiment++;
            } else if (strcmp(word, "bad") == 0 || strcmp(word, "terrible") == 0 || strcmp(word, "awful") == 0) {
                sentiment--;
            }
        } else {
            word[index] = sentence[i];
            index++;
        }
    }
    
    // Check sentiment of last word in sentence after loop has ended
    word[index] = '\0';
    if (strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "awesome") == 0) {
        sentiment++;
    } else if (strcmp(word, "bad") == 0 || strcmp(word, "terrible") == 0 || strcmp(word, "awful") == 0) {
        sentiment--;
    }
    
    return sentiment;
}

// Main function to test sentiment analysis tool
int main() {
    char sentence[100];
    
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    
    // Remove newline character from end of string if present
    if (sentence[strlen(sentence) - 1] == '\n') {
        sentence[strlen(sentence) - 1] = '\0';
    }
    
    int sentimentScore = getSentiment(sentence);
    
    if (sentimentScore > 0) {
        printf("\nOverall sentiment of sentence is positive.");
    } else if (sentimentScore < 0) {
        printf("\nOverall sentiment of sentence is negative.");
    } else {
        printf("\nOverall sentiment of sentence is neutral.");
    }
    
    return 0;
}