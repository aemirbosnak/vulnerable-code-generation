//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: decentralized
#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[1000]; // variable to store the user input text
    int positiveCount = 0, negativeCount = 0; // to keep track of positive and negative words count
    int sentimentValue = 0; // unique sentiment value(positive/negative/neutral)
    
    // Positive and Negative words array
    char positiveWords[][20] = {"good", "great", "excellent", "happy", "love", "like", "pros", "win"};
    char negativeWords[][20] = {"bad", "poor", "terrible", "sad", "hate", "dislike", "cons", "lose"};
    
    printf("Enter your sentence:\n");
    gets(sentence); // getting the user input sentence
    
    char* word = strtok(sentence, " "); // breaking the sentence into words

    while (word != NULL) // iterating over all the words in the sentence
    {
        int positiveFlag = 0, negativeFlag = 0; // flags to track if a positive/negative word is found
        
        // checking if the current word is positive
        for (int i = 0; i < 8; i++)
        {
            if (strcmp(word, positiveWords[i]) == 0)
            {
                positiveCount++; // incrementing positive count
                positiveFlag = 1; // setting the positive flag
                break;
            }
        }
        
        // checking if the current word is negative
        for (int i = 0; i < 8; i++)
        {
            if (strcmp(word, negativeWords[i]) == 0)
            {
                negativeCount++; // incrementing negative count
                negativeFlag = 1; // setting the negative flag
                break;
            }
        }
        
        // updating the sentiment value based on the positive/negative flags
        if (positiveFlag == 1 && negativeFlag == 0)
            sentimentValue += 1;
        else if (positiveFlag == 0 && negativeFlag == 1)
            sentimentValue -= 1;
        
        word = strtok(NULL, " "); // getting next word in the sentence
    }
    
    // final sentiment analysis based on positive/negative count and sentiment value
    if (positiveCount == 0 && negativeCount == 0)
        printf("Sentiment: Neutral\n");
    else if (positiveCount > negativeCount && sentimentValue > 0)
        printf("Sentiment: Highly Positive\n");
    else if (positiveCount > negativeCount && sentimentValue < 0)
        printf("Sentiment: Moderately Positive\n");
    else if (positiveCount == negativeCount && sentimentValue > 0)
        printf("Sentiment: Slightly Positive\n");
    else if (positiveCount == negativeCount && sentimentValue < 0)
        printf("Sentiment: Slightly Negative\n");
    else if (positiveCount < negativeCount && sentimentValue < 0)
        printf("Sentiment: Highly Negative\n");
    else if (positiveCount < negativeCount && sentimentValue > 0)
        printf("Sentiment: Moderately Negative\n");
    
    return 0;
}