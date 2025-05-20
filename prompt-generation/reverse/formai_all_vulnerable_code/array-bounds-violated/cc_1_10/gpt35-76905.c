//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>
#include<ctype.h>

//function to calculate the sentiment score
int calculateSentimentScore(char str[]) {

    //arrays to store positive and negative words
    char positiveWords[5][10] = {"good", "happy", "great", "awesome", "excellent"};
    char negativeWords[5][10] = {"bad", "sad", "horrible", "awful", "terrible"};

    int positiveScore = 0;
    int negativeScore = 0;
    int len = strlen(str);
    int wordLen = 0;

    //loop through the input string character by character
    for(int i=0; i<len; i++) {

        //if a space is encountered, it indicates end of a word
        if(str[i] == ' ') {

            //reset the word length
            wordLen = 0;

        } else {

            //if the character is not a space, increment word length
            wordLen++;

            //if the word length exceeds 10 characters, ignore the word
            if(wordLen > 10) {
                continue;
            }

            //convert the character to lowercase for comparison
            str[i] = tolower(str[i]);

            //loop through the positive words array to check if the input string contains any positive word
            for(int j=0; j<5; j++) {
                if(strncmp(str+i-positiveScore, positiveWords[j], positiveScore) == 0) {
                    positiveScore++;
                    break;
                }
            }

            //loop through the negative words array to check if the input string contains any negative word
            for(int j=0; j<5; j++) {
                if(strncmp(str+i-negativeScore, negativeWords[j], negativeScore) == 0) {
                    negativeScore++;
                    break;
                }
            }
        }
    }

    //calculate the final sentiment score
    int sentimentScore = positiveScore - negativeScore;

    return sentimentScore;
}

//main function
int main() {

    char inputString[100];
    int sentimentScore;

    //get the input string from user
    printf("Enter the input string: ");
    fgets(inputString, 100, stdin);

    //remove newline character from the input string
    inputString[strlen(inputString)-1] = '\0';

    //calculate the sentiment score
    sentimentScore = calculateSentimentScore(inputString);

    //print the sentiment score
    printf("\nSentiment Score: %d\n", sentimentScore);

    return 0;
}