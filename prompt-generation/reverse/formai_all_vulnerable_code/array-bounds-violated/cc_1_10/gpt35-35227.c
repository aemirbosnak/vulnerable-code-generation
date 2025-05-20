//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: shape shifting
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Define a function for sentiment analysis
char* analyzeSentiment(char *input_text){
    char* sentiment;
    int positive_score = 0;
    int negative_score = 0;
    int index = 0;
    int len = strlen(input_text);

    // Loop through each word in the input_text
    while(index < len){
        char word[50];
        int word_index = 0;

        // Get the current word from the input_text
        while(input_text[index] != ' ' && index < len){
            word[word_index] = input_text[index];
            index++;
            word_index++;
        }
        word[word_index] = '\0';

        // Check if the current word is positive or negative
        if(strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "amazing") == 0){
            positive_score++;
        }
        else if(strcmp(word, "bad") == 0 || strcmp(word, "terrible") == 0 || strcmp(word, "awful") == 0){
            negative_score++;
        }

        index++;
    }

    // Calculate the sentiment of the input_text
    if(positive_score > negative_score){
        sentiment = "Positive";
    }
    else if(negative_score > positive_score){
        sentiment = "Negative";
    }
    else{
        sentiment = "Neutral";
    }

    // Return the sentiment
    return sentiment;
}

int main(){
    char input_text[500];

    // Get the input_text from the user
    printf("Enter the text to analyze: ");
    fgets(input_text, 500, stdin);

    // Remove the newline character at the end of the input_text
    input_text[strlen(input_text) - 1] = '\0';

    // Analyze the sentiment of the input_text
    char *sentiment = analyzeSentiment(input_text);

    // Print the sentiment
    printf("The sentiment of the text is %s.\n", sentiment);

    return 0;
}