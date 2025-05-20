//Falcon2-11B DATASET v1.0 Category: Sentiment analysis tool ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to analyze the sentiment of a given text
int analyzeSentiment(char *text) {
    int sentiment = 0;
    
    // Split the text into individual words
    char *words[100];
    int numWords = 0;
    int wordIndex = 0;
    
    while (text[wordIndex]!= '\0') {
        if (isalpha(text[wordIndex])) {
            words[numWords] = &text[wordIndex];
            numWords++;
        }
        wordIndex++;
    }
    
    numWords--; // Remove the null terminator
    
    // Analyze the sentiment of each word
    for (int i = 0; i < numWords; i++) {
        char *word = words[i];
        
        // Check if the word is positive, negative, or neutral
        if (strlen(word) > 2 &&!isalpha(word[0]) &&!isalpha(word[strlen(word) - 1])) {
            if (strcmp(word, ":)") == 0) {
                sentiment += 1;
            } else if (strcmp(word, ":(") == 0) {
                sentiment -= 1;
            } else {
                sentiment = 0;
            }
        }
    }
    
    // Output the sentiment
    if (sentiment > 0) {
        printf("The sentiment of the text is positive.\n");
    } else if (sentiment < 0) {
        printf("The sentiment of the text is negative.\n");
    } else {
        printf("The sentiment of the text is neutral.\n");
    }
    
    return sentiment;
}

// Function to get the user input
void getUserInput() {
    printf("Enter the text to analyze: ");
    char text[100];
    scanf("%s", text);
    
    // Call the analyzeSentiment function
    int sentiment = analyzeSentiment(text);
    
    // Output the sentiment
    printf("The sentiment of the text is: %d.\n", sentiment);
}

int main() {
    getUserInput();
    
    return 0;
}