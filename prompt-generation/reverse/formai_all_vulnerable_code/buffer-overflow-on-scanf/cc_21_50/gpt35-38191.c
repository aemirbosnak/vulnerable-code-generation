//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: funny
#include <stdio.h>
#include <string.h>

int main() {
  
  char input[100]; // declaring an array to store user input
  int positivity = 0; // setting positivity score to 0
  int negativity = 0; // setting negativity score to 0
  
  printf("Welcome to the C Sentiment analysis tool!\n");
  printf("Please enter a sentence: ");
  scanf("%[^\n]s", input); // taking input with spaces included
  
  char *tokens = strtok(input, " "); // extracting each word using strtok function
  
  while(tokens != NULL) {
    
    // checking each word's positivity or negativity score
    if(strcmp(tokens, "happy") == 0 || strcmp(tokens, "joy") == 0 || strcmp(tokens, "fun") == 0) {
      positivity += 5;
    } else if(strcmp(tokens, "sad") == 0 || strcmp(tokens, "depressed") == 0 || strcmp(tokens, "bored") == 0) {
      negativity += 5;
    } else if(strcmp(tokens, "love") == 0 || strcmp(tokens, "like") == 0 || strcmp(tokens, "admire") == 0) {
      positivity += 3;
    } else if(strcmp(tokens, "hate") == 0 || strcmp(tokens, "dislike") == 0 || strcmp(tokens, "detest") == 0) {
      negativity += 3;
    } else if(strcmp(tokens, "awesome") == 0 || strcmp(tokens, "fantastic") == 0) {
      positivity += 2;
    } else if(strcmp(tokens, "terrible") == 0 || strcmp(tokens, "horrible") == 0) {
      negativity += 2;
    } else if(strcmp(tokens, "good") == 0 || strcmp(tokens, "great") == 0) {
      positivity += 1;
    } else if(strcmp(tokens, "bad") == 0 || strcmp(tokens, "awful") == 0) {
      negativity += 1;
    }
  
    tokens = strtok(NULL, " ");
  }
  
  // calculating overall sentiment score and displaying the result
  int totalScore = positivity - negativity;
  
  if(totalScore > 0) {
    printf("\n\nYour sentence has a positive sentiment score of %d. Keep spreading positivity!", totalScore);
  } else if(totalScore == 0) {
    printf("\n\nYour sentence has a neutral sentiment score of %d. Keep expressing yourself!", totalScore);
  } else {
    printf("\n\nYour sentence has a negative sentiment score of %d. Cheer up!", totalScore);
  }
  
  return 0;
}