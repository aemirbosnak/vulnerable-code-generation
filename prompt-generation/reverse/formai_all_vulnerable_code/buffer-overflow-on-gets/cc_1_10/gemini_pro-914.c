//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment values
#define POSITIVE 1
#define NEGATIVE -1
#define NEUTRAL 0

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Create a dictionary of words and their sentiment values
char* dictionary[] = {
  "good", POSITIVE,
  "bad", NEGATIVE,
  "great", POSITIVE,
  "terrible", NEGATIVE,
  "excellent", POSITIVE,
  "horrible", NEGATIVE,
  "amazing", POSITIVE,
  "awful", NEGATIVE,
  "beautiful", POSITIVE,
  "ugly", NEGATIVE
};

// Get the sentiment value of a word
int get_sentiment(char* word) {
  // Loop through the dictionary to find the word
  for (int i = 0; i < sizeof(dictionary) / sizeof(char*); i++) {
    // If the word is found, return its sentiment value
    if (strcmp(word, dictionary[i]) == 0) {
      return dictionary[i + 1];
    }
  }

  // If the word is not found, return neutral
  return NEUTRAL;
}

// Get the sentiment of a sentence
int get_sentence_sentiment(char* sentence) {
  // Split the sentence into words
  char* words[MAX_WORD_LENGTH];
  int num_words = 0;
  char* word = strtok(sentence, " ");
  while (word != NULL) {
    words[num_words] = word;
    num_words++;
    word = strtok(NULL, " ");
  }

  // Calculate the sentiment of the sentence
  int sentiment = 0;
  for (int i = 0; i < num_words; i++) {
    sentiment += get_sentiment(words[i]);
  }

  // Return the sentiment of the sentence
  return sentiment;
}

// Print the sentiment of a sentence
void print_sentiment(int sentiment) {
  switch (sentiment) {
    case POSITIVE:
      printf("Positive\n");
      break;
    case NEGATIVE:
      printf("Negative\n");
      break;
    case NEUTRAL:
      printf("Neutral\n");
      break;
  }
}

// Main function
int main() {
  // Get the sentence from the user
  char sentence[100];
  printf("Enter a sentence: ");
  gets(sentence);

  // Get the sentiment of the sentence
  int sentiment = get_sentence_sentiment(sentence);

  // Print the sentiment of the sentence
  print_sentiment(sentiment);

  return 0;
}