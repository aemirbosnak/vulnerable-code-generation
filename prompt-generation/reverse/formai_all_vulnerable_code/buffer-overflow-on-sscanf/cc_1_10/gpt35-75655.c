//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 200
#define MAX_WORDS 1000
#define POSITIVE_WORDS_FILE "positive_words.txt"
#define NEGATIVE_WORDS_FILE "negative_words.txt"

int is_positive_word(char *word, char positive_words[][MAX_LINE_LENGTH], int n_positive_words){
    for(int i=0; i<n_positive_words; i++){
        if(strcmp(word, positive_words[i])==0)
            return 1;
    }
    return 0;
}

int is_negative_word(char *word, char negative_words[][MAX_LINE_LENGTH], int n_negative_words){
    for(int i=0; i<n_negative_words; i++){
        if(strcmp(word, negative_words[i])==0)
            return 1;
    }
    return 0;
}

void sentiment_analysis(char *text){
    char *words[MAX_WORDS];
    int n_words = 0;
    char positive_words[MAX_WORDS][MAX_LINE_LENGTH];
    char negative_words[MAX_WORDS][MAX_LINE_LENGTH];
    int n_positive_words = 0, n_negative_words = 0;

    // tokenize the input text
    char *token = strtok(text, " ,.?!;-:\n");
    while(token != NULL){
        words[n_words] = token;
        n_words++;
        token = strtok(NULL, " ,.?!;-:\n");
    }

    // read positive and negative words file
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    fp = fopen(POSITIVE_WORDS_FILE, "r");
    if(fp == NULL){
        printf("Error: can't open file %s\n", POSITIVE_WORDS_FILE);
        exit(1);
    }
    while(fgets(line, MAX_LINE_LENGTH, fp)){
        sscanf(line ,"%s", positive_words[n_positive_words]);
        n_positive_words++;
    }
    fclose(fp);

    fp = fopen(NEGATIVE_WORDS_FILE, "r");
    if(fp == NULL){
        printf("Error: can't open file %s\n", NEGATIVE_WORDS_FILE);
        exit(1);
    }
    while(fgets(line, MAX_LINE_LENGTH, fp)){
        sscanf(line ,"%s", negative_words[n_negative_words]);
        n_negative_words++;
    }
    fclose(fp);

    // calculate sentiment score
    int sentiment_score = 0;
    for(int i=0; i<n_words; i++){
        if(is_positive_word(words[i], positive_words, n_positive_words)){
            sentiment_score++;
        }
        else if(is_negative_word(words[i], negative_words, n_negative_words)){
            sentiment_score--;
        }
    }

    // output sentiment score
    printf("Sentiment score: %d\n", sentiment_score);
    if(sentiment_score > 0){
        printf("Overall sentiment is positive\n");
    }
    else if(sentiment_score < 0){
        printf("Overall sentiment is negative\n");
    }
    else{
        printf("Overall sentiment is neutral\n");
    }
}

int main(){
    char text[MAX_LINE_LENGTH];
    printf("Enter some text to analyze sentiment: ");
    fgets(text, MAX_LINE_LENGTH, stdin);
    sentiment_analysis(text);
    return 0;
}