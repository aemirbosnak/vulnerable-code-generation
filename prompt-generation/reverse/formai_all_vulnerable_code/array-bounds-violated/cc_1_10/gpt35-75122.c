//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: protected
#include<stdio.h>
#include<string.h>

// Function to check if a character is a punctuation
int isPunct(char ch){
  if(ch == '.' || ch == ',' || ch == '?' || ch == '!' || ch == ';' || ch == ':' || ch == '-'){
    return 1;
  }
  return 0;
}

// Function to calculate the sentiment score for a sentence
int calcScore(char sentence[100]){
  char* token = strtok(sentence, " ");
  int score = 0;
  while(token != NULL){
    if(!isPunct(token[strlen(token)-1])){
      token[strlen(token)] = '.';
    }
    if(!strcmp(token, "good.") || !strcmp(token, "great.") || !strcmp(token, "nice.") || !strcmp(token, "awesome.") || !strcmp(token, "excellent.")){
      // Increment the score for positive words
      score += 2;
    }
    else if(!strcmp(token, "bad.") || !strcmp(token, "terrible.") || !strcmp(token, "awful.") || !strcmp(token, "poor.") || !strcmp(token, "disappointing.")){
      // Decrement the score for negative words
      score -= 2;
    }
    token = strtok(NULL, " ");
  }
  return score;
}

int main(){
  char review[1000];
  printf("Enter your review:\n");
  gets(review);
  int len = strlen(review);
  if(review[len-1] != '.'){
    review[len] = '.';
    review[len+1] = '\0';
  }
  char* sentence = strtok(review, ".");
  int totalScore = 0, numSentences = 0;
  while(sentence != NULL){
    int sentenceScore = calcScore(sentence);
    totalScore += sentenceScore;
    if(sentenceScore != 0){
      numSentences++;
    }
    sentence = strtok(NULL, ".");
  }
  if(numSentences != 0){
    // Calculate the average sentiment score for the review
    int avgScore = totalScore/numSentences;
    printf("The sentiment score for the review is %d\n", avgScore);
    if(avgScore < 0){
      printf("The review is negative\n");
    }
    else if(avgScore > 0){
      printf("The review is positive\n");
    }
    else{
      printf("The review is neutral\n");
    }
  }
  else{
    printf("No sentiment detected in the review\n");
  }
  return 0;
}