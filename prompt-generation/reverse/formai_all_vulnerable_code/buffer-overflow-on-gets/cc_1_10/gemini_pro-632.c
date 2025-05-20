//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// An array of positive words
char *positiveWords[] = {"good", "great", "awesome", "superb", "excellent", "wonderful", "marvelous", "terrific", "fantastic", "splendid"};

// An array of negative words
char *negativeWords[] = {"bad", "terrible", "awful", "horrible", "dreadful", "disgusting", "nauseating", "repulsive", "abominable", "detestable"};

// Function to count the number of occurrences of a word in a string
int countOccurrences(char *string, char *word) {
  int count = 0;
  char *ptr = strstr(string, word);
  while (ptr != NULL) {
    count++;
    ptr = strstr(ptr + 1, word);
  }
  return count;
}

// Function to analyze the sentiment of a string
int analyzeSentiment(char *string) {
  // Convert the string to lowercase
  char *lowercaseString = strdup(string);
  for (int i = 0; lowercaseString[i] != '\0'; i++) {
    lowercaseString[i] = tolower(lowercaseString[i]);
  }

  // Count the number of occurrences of positive and negative words
  int positiveCount = 0;
  int negativeCount = 0;
  for (int i = 0; i < 10; i++) {
    positiveCount += countOccurrences(lowercaseString, positiveWords[i]);
    negativeCount += countOccurrences(lowercaseString, negativeWords[i]);
  }

  // Free the memory allocated for the lowercase string
  free(lowercaseString);

  // Return the sentiment score
  if (positiveCount > negativeCount) {
    return 1;
  } else if (negativeCount > positiveCount) {
    return -1;
  } else {
    return 0;
  }
}

int main() {
  // Get the input string from the user
  char string[100];
  printf("Enter a string: ");
  gets(string);

  // Analyze the sentiment of the string
  int sentiment = analyzeSentiment(string);

  // Print the sentiment score
  if (sentiment == 1) {
    printf("The sentiment of the string is positive.\n");
  } else if (sentiment == -1) {
    printf("The sentiment of the string is negative.\n");
  } else {
    printf("The sentiment of the string is neutral.\n");
  }

  return 0;
}