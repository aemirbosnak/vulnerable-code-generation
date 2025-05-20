//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: portable
#include <stdio.h>
#include <string.h>

// Function to analyze sentiment of given string
int analyzeSentiment(char *str){

    // Array of positive words
    char* positive_words[] = {"good", "great", "excellent", "awesome", "fantastic", "amazing", "happy", "love"};

    // Array of negative words
    char* negative_words[] = {"bad", "terrible", "horrible", "awful", "disappointing", "painful", "hate", "anger"};

    int positive_count = 0;
    int negative_count = 0;

    char* token = strtok(str, " ");

    while (token != NULL) {
        for (int i = 0; i < 8; i++) {

            if (strcmp(token, positive_words[i]) == 0) {
                positive_count++;
            }
            if (strcmp(token, negative_words[i]) == 0) {
                negative_count++;
            }
        }
        token = strtok(NULL, " ");
    }

    if(positive_count > negative_count){
        return 1; // Positive sentiment
    } else if(positive_count < negative_count){
        return -1; // Negative sentiment
    } else {
        return 0; // Neutral sentiment
    }

}

int main(){
    
    char str[100];
    printf("Enter a string to analyze its sentiment: ");
    gets(str);

    int sentiment_value = analyzeSentiment(str);

    if(sentiment_value == 1){
        printf("The sentiment of given string is Positive.\n");
    } else if(sentiment_value == -1){
        printf("The sentiment of given string is Negative.\n");
    } else {
        printf("The sentiment of given string is Neutral.\n");
    }

    return 0;
}