//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: irregular
// Hey there! Let's create a sentiment analysis tool using C programming language!
// First, we will import the necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Now let's define a function to get user input
char* getInput() {
  char* input = (char*)malloc(sizeof(char) * 100);
  printf("Enter your text: ");
  scanf("%[^\n]s", input);
  getchar();
  return input;
}

// Next, let's define our main function
int main() {
  // First we will get the input from the user
  char* input = getInput();
  
  // Now let's define our sentiment variables
  int positiveSentiment = 0;
  int negativeSentiment = 0;
  
  // Let's define some positive and negative sentiment words
  char* positiveWords[] = {"good", "great", "fantastic", "awesome", "excellent"};
  char* negativeWords[] = {"bad", "awful", "terrible", "horrible", "disgusting"};
  
  // Let's split the input into individual words
  char* word = strtok(input, " ");
  while (word != NULL) {
    // Let's check if the word is positive or negative
    for (int i = 0; i < 5; i++) {
      if (strcmp(word, positiveWords[i]) == 0) {
        positiveSentiment++;
      }
      if (strcmp(word, negativeWords[i]) == 0) {
        negativeSentiment++;
      }
    }
    // Move on to the next word
    word = strtok(NULL, " ");
  }
  
  // Finally, let's print out the sentiment analysis result
  printf("\nPositive Sentiment: %d\nNegative Sentiment: %d\n", positiveSentiment, negativeSentiment);
  
  // Free dynamically allocated memory
  free(input);
  
  // We're done!
  return 0;
}