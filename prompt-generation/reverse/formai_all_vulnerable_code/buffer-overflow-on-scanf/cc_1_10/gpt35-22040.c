//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: calm
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
  
// Function to calculate sentiment score of a given tweet 
int calcSentimentScore(char* tweet) 
{ 
    int i, sentimentScore = 0; 
    int tweetLength = strlen(tweet); 
  
    for (i = 0; i < tweetLength; i++) { 
  
        // If current character is a positive word 
        if (strcmp(&tweet[i], "awesome") == 0 
            || strcmp(&tweet[i], "amazing") == 0 
            || strcmp(&tweet[i], "great") == 0 
            || strcmp(&tweet[i], "good") == 0) { 
  
            sentimentScore++; 
        } 
        
        // If current character is a negative word 
        else if (strcmp(&tweet[i], "hate") == 0 
                || strcmp(&tweet[i], "dislike") == 0 
                || strcmp(&tweet[i], "terrible") == 0 
                || strcmp(&tweet[i], "awful") == 0 
                || strcmp(&tweet[i], "bad") == 0) { 
  
            sentimentScore--; 
        } 
    } 
  
    return sentimentScore; 
} 
  
// Program to test the sentiment analysis tool 
int main() 
{ 
    char tweet[1000]; 
  
    printf("Enter your tweet:\n"); 
    scanf("%[^\n]", tweet); 
  
    int sentimentScore = calcSentimentScore(tweet); 
  
    if (sentimentScore > 0) 
        printf("\nThe sentiment score of the tweet is positive."); 
  
    else if (sentimentScore < 0) 
        printf("\nThe sentiment score of the tweet is negative."); 
  
    else
        printf("\nThe sentiment score of the tweet is neutral."); 
  
    return 0; 
}