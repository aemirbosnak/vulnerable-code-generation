//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Cryptic
#include<stdio.h>      // Library for input and output operations
#include<string.h>     // Library for string operations

void main()
{
  char sentence[100];   // Define a character array to store the input sentence
  int positive = 0, negative = 0, neutral = 0;  // Initialize counters for positive, negative and neutral sentences
   
  printf("Enter the sentence to analyze sentiment: ");
  scanf("%[^\n]",sentence);      // Read the input sentence until a newline character is encountered
  
  int len = strlen(sentence);    // Store the length of the sentence in a variable
  
  for(int i=0; i<len; i++)      // Loop through each character in the sentence
  {
      if(sentence[i] == 'g')    // Check if the character is g
      {
          if(sentence[i+1] == 'o' && sentence[i+2] == 'o' && sentence[i+3] == 'd')    // Check if the three characters after g are o, o, d
          {
              positive++;      // Increment counter for positive sentences
          }
      }
      else if(sentence[i] == 'b')    // Check if the character is b
      {
          if(sentence[i+1] == 'a' && sentence[i+2] == 'd')    // Check if the two characters after b are a, d
          {
              negative++;      // Increment counter for negative sentences
          }
      }
      else if(sentence[i] == ' ')    // Check if the character is a space
      {
          neutral++;       // Increment counter for neutral sentences
      }
  }
   
  printf("\nSentiment Analysis Result:\n");
  printf("Positive Sentences Count: %d\n", positive);    // Print the number of positive sentences
  printf("Negative Sentences Count: %d\n", negative);    // Print the number of negative sentences
  printf("Neutral Sentences Count: %d\n", neutral);      // Print the number of neutral sentences
   
  if(positive > negative)         // Check if there are more positive sentences than negative sentences
  {
      printf("\nOverall Sentiment : Positive");     // Print overall sentiment as positive
  }
  else if(positive < negative)    // Check if there are more negative sentences than positive sentences
  {
      printf("\nOverall Sentiment : Negative");     // Print overall sentiment as negative
  }
  else                            // If the number of positive and negative sentences are same
  {
      printf("\nOverall Sentiment : Neutral");      // Print overall sentiment as neutral
  }
}