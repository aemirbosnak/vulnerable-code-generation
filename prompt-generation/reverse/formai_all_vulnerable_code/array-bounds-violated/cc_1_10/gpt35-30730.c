//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: portable
#include <stdio.h>
#include <string.h>
#define MAX_CHARS 1000

int score_sentence(char *sentence, char *keywords[], int weights[], int n_keywords){
    // Count the frequency of each keyword in the sentence
    int freq[n_keywords];
    for(int i=0; i<n_keywords; i++){
        freq[i] = 0;
        char *word = strtok(sentence, " ");
        while(word != NULL){
            if(strcmp(word, keywords[i]) == 0){
                freq[i]++;
            }
            word = strtok(NULL, " ");
        }
    }

    // Calculate the score of the sentence
    int score = 0;
    for(int i=0; i<n_keywords; i++){
        score += freq[i]*weights[i];
    }

    return score;
}

int main(){
    // Set up keywords and their weights for sentiment analysis
    char *keywords[] = {"good", "bad", "happy", "sad", "love", "hate"};
    int weights[] = {1, -1, 2, -2, 3, -3};
    int n_keywords = sizeof(keywords)/sizeof(keywords[0]);

    // Get input from user
    char input[MAX_CHARS];
    printf("Enter a sentence to analyze: ");
    fgets(input, MAX_CHARS, stdin);

    // Remove newline character at the end of input
    if(input[strlen(input)-1] == '\n'){
        input[strlen(input)-1] = '\0';
    }

    // Convert input to lowercase for case-insensitive matching
    for(int i=0; i<strlen(input); i++){
        input[i] = tolower(input[i]);
    }

    int score = score_sentence(input, keywords, weights, n_keywords);

    // Output result to user
    if(score > 0){
        printf("Positive sentiment with score of %d\n", score);
    }
    else if(score < 0){
        printf("Negative sentiment with score of %d\n", score);
    }
    else{
        printf("Neutral sentiment\n");
    }

    return 0;
}