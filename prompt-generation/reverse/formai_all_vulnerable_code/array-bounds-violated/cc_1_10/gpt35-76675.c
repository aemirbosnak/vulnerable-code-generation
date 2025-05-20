//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to count the number of positive and negative words in a sentence
void count_positive_negative(char *sentence, int *positive_count, int *negative_count) {
    char *positive_words[] = {"good", "great", "excellent", "happy", "positive"};
    char *negative_words[] = {"bad", "terrible", "poor", "unhappy", "negative"};
    char *token = strtok(sentence, " ");

    while(token != NULL) {
        for(int i=0; i<5; i++) {
            if(strcmp(token, positive_words[i]) == 0) {
                (*positive_count)++;
            } else if(strcmp(token, negative_words[i]) == 0) {
                (*negative_count)++;
            }
        }
        token = strtok(NULL, " ");
    }
}

//Function to perform sentiment analysis
void perform_sentiment_analysis(char *sentence) {
    int positive_count = 0;
    int negative_count = 0;

    count_positive_negative(sentence, &positive_count, &negative_count);

    printf("\nPositive Words Count: %d", positive_count);
    printf("\nNegative Words Count: %d", negative_count);

    if(positive_count > negative_count) {
        printf("\nThe sentence has a positive sentiment");
    } else if(negative_count > positive_count) {
        printf("\nThe sentence has a negative sentiment");
    } else {
        printf("\nThe sentence has a neutral sentiment");
    }
}

//Main function to demonstrate the usage of the sentiment analysis tool
int main() {
    char sentence[100];

    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);

    //Removing the newline character from the input
    if(sentence[strlen(sentence)-1] == '\n') {
        sentence[strlen(sentence)-1] = '\0';
    }

    perform_sentiment_analysis(sentence);

    return 0;
}