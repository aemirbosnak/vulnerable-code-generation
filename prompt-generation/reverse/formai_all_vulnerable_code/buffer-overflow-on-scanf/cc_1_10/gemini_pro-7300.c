//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment lexicon
char *positiveWords[] = {"good", "great", "excellent", "awesome", "superb", "wonderful"};
char *negativeWords[] = {"bad", "terrible", "awful", "horrible", "dreadful", "miserable"};

// Get the sentiment of a given string
int get_sentiment(char *string) {
  int sentiment = 0;

  // Split the string into words
  char *words[100];
  int num_words = 0;
  char *word = strtok(string, " ");
  while (word != NULL) {
    words[num_words] = word;
    num_words++;
    word = strtok(NULL, " ");
  }

  // Count the number of positive and negative words in the string
  for (int i = 0; i < num_words; i++) {
    for (int j = 0; j < 6; j++) {
      if (strcmp(words[i], positiveWords[j]) == 0) {
        sentiment++;
      } else if (strcmp(words[i], negativeWords[j]) == 0) {
        sentiment--;
      }
    }
  }

  // Return the sentiment
  return sentiment;
}

// Print the sentiment of a given string
void print_sentiment(char *string) {
  int sentiment = get_sentiment(string);

  if (sentiment > 0) {
    printf("The sentiment of the string is positive.\n");
  } else if (sentiment < 0) {
    printf("The sentiment of the string is negative.\n");
  } else {
    printf("The sentiment of the string is neutral.\n");
  }
}

// Get input from the user
char *get_input() {
  char *input = malloc(100);
  printf("Enter a string: ");
  scanf("%s", input);
  return input;
}

// Main function
int main() {
  // Get input from the user
  char *string = get_input();

  // Print the sentiment of the string
  print_sentiment(string);

  // Free the allocated memory
  free(string);

  return 0;
}