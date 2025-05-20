//Falcon2-11B DATASET v1.0 Category: Sentiment analysis tool ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int main()
{
    // Initialize the random number generator
    srand(time(NULL));
    
    // Define the sentiment analysis functions
    int analyzeSentiment(char* sentence);
    
    // Get the user input
    char sentence[100];
    printf("Enter a sentence: ");
    scanf("%s", sentence);
    
    // Analyze the sentiment of the sentence
    int sentiment = analyzeSentiment(sentence);
    
    // Print the sentiment score
    if (sentiment < 0) {
        printf("The sentiment of the sentence is negative.\n");
    } else if (sentiment > 0) {
        printf("The sentiment of the sentence is positive.\n");
    } else {
        printf("The sentiment of the sentence is neutral.\n");
    }
    
    // Print the sentiment score in percentage
    int sentimentPercentage = (int)((sentiment / 10.0) * 100);
    printf("The sentiment score is %d%%.\n", sentimentPercentage);
    
    return 0;
}
// Analyze the sentiment of a sentence
int analyzeSentiment(char* sentence)
{
    // Define the sentiment dictionary
    char* sentimentDictionary[] = {"happy", "sad", "angry", "fearful", "surprised", "disgusted", "neutral"};
    int sentimentScore = 0;
    
    // Check each word in the sentence against the sentiment dictionary
    int i = 0;
    int j = 0;
    while (sentence[i]!= '\0') {
        while (sentimentDictionary[j]!= '\0') {
            if (strncmp(sentence + i, sentimentDictionary[j], strlen(sentimentDictionary[j])) == 0) {
                sentimentScore++;
                break;
            }
            j++;
        }
        i++;
    }
    
    // Return the sentiment score
    return sentimentScore;
}