//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: active
#include <stdio.h>
#include <string.h>

// Function to determine the sentiment of a sentence
int getSentiment(char sentence[]) {
    char positiveWords[10][20] = {"good", "happy", "love", "excited", "pleased", "great", "joyful", "success", "excellent", "fantastic"};
    char negativeWords[10][20] = {"bad", "disappointed", "sad", "hate", "disgusted", "horrible", "failure", "awful", "terrible", "regret"};
    char word[20];
    int sentimentScore = 0;
    int numberOfWords = 0;
    int i, j;
  
    for(i=0; i<strlen(sentence); i++) {
        j = 0;
        while(sentence[i] != ' ' && sentence[i] != '\0') {
            word[j++] = sentence[i++];
        }
        word[j] = '\0';
    
        // Check if word is positive or negative
        for(j=0; j<10; j++) {
            if(strcmp(word, positiveWords[j]) == 0) {
                sentimentScore++;
                numberOfWords++;
                break;
            } else if(strcmp(word, negativeWords[j]) == 0) {
                sentimentScore--;
                numberOfWords++;
                break;
            }
        }
    }
    
    if(numberOfWords == 0) {
        return 0;
    }
    
    // Calculate average sentiment by dividing sentiment score by number of words
    return (sentimentScore/numberOfWords);
}

int main() {
    char sentence[100];
    int sentiment;
    
    printf("Enter a sentence: ");
    scanf("%[^\n]", sentence);
    
    sentiment = getSentiment(sentence);
    
    if(sentiment > 0) {
        printf("Positive sentence!\n");
    } else if(sentiment < 0) {
        printf("Negative sentence :(\n");
    } else {
        printf("Neutral sentence.\n");
    }
    
    return 0;
}