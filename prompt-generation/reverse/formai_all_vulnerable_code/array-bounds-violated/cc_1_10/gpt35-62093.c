//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sentimentAnalysis(char *text) {
    int total_score = 0;
    char words[1024][1024];
    char *word = strtok(text, " ");
    int word_count = 0;
    
    // Splitting the text into words and storing each word into an array
    while (word != NULL) {
        strcpy(words[word_count], word);
        word_count++;
        word = strtok(NULL, " ");
    }
    
    // Evaluating the sentiment score of each word and adding it to total score
    for (int i = 0; i < word_count; i++) {
        char *current_word = words[i];
        int score = 0;
        
        // Assigning sentiment scores to each word
        if (strcmp(current_word, "good") == 0) {
            score = 1;
        } else if (strcmp(current_word, "bad") == 0) {
            score = -1;
        } else if (strcmp(current_word, "happy") == 0) {
            score = 1;
        } else if (strcmp(current_word, "sad") == 0) {
            score = -1;
        } else if (strcmp(current_word, "love") == 0) {
            score = 2;
        } else if (strcmp(current_word, "hate") == 0) {
            score = -2;
        }
        
        total_score += score; // Adding the sentiment score of each word to total score
    }
    
    return total_score;
}

int main() {
    char text[1024];
    
    printf("Enter a sentence for sentiment analysis: \n");
    fgets(text, 1024, stdin);
    
    // Removing the new line character from the end of text
    if (text[strlen(text) - 1] == '\n') {
        text[strlen(text) - 1] = '\0';
    }
    
    int sentiment = sentimentAnalysis(text);
    
    // Determining the sentiment of the sentence based on total score
    if (sentiment > 0) {
        printf("Sentiment: Positive\n");
    } else if (sentiment < 0) {
        printf("Sentiment: Negative\n");
    } else {
        printf("Sentiment: Neutral\n");
    }
    
    return 0;
}