//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a sentence
#define MAX_SENTENCE_LENGTH 1024

// Define the number of sentiment categories
#define NUM_SENTIMENT_CATEGORIES 3

// Define the sentiment categories
char *sentiment_categories[] = {"positive", "neutral", "negative"};

// Define the word lists for each sentiment category
char *positive_words[] = {"good", "great", "excellent", "wonderful", "amazing"};
char *neutral_words[] = {"okay", "alright", "fine", "fair", "average"};
char *negative_words[] = {"bad", "terrible", "awful", "horrible", "dreadful"};

// Function to tokenize a sentence into words
char **tokenize_sentence(char *sentence) {
  // Allocate memory for the array of words
  char **words = malloc(sizeof(char *) * MAX_SENTENCE_LENGTH);

  // Tokenize the sentence into words
  char *word = strtok(sentence, " ");
  int i = 0;
  while (word != NULL) {
    words[i] = word;
    i++;
    word = strtok(NULL, " ");
  }

  // Return the array of words
  return words;
}

// Function to count the number of occurrences of a word in a sentence
int count_word_occurrences(char *word, char **words) {
  // Initialize the count to 0
  int count = 0;

  // Iterate over the words in the sentence
  for (int i = 0; i < MAX_SENTENCE_LENGTH; i++) {
    // If the word is found in the sentence, increment the count
    if (strcmp(word, words[i]) == 0) {
      count++;
    }
  }

  // Return the count
  return count;
}

// Function to determine the sentiment of a sentence
char *determine_sentiment(char *sentence) {
  // Tokenize the sentence into words
  char **words = tokenize_sentence(sentence);

  // Count the number of occurrences of each word in the sentence
  int positive_word_count = 0;
  int neutral_word_count = 0;
  int negative_word_count = 0;
  for (int i = 0; i < MAX_SENTENCE_LENGTH; i++) {
    positive_word_count += count_word_occurrences(positive_words[i], words);
    neutral_word_count += count_word_occurrences(neutral_words[i], words);
    negative_word_count += count_word_occurrences(negative_words[i], words);
  }

  // Determine the sentiment of the sentence
  char *sentiment;
  if (positive_word_count > neutral_word_count && positive_word_count > negative_word_count) {
    sentiment = sentiment_categories[0];
  } else if (neutral_word_count > positive_word_count && neutral_word_count > negative_word_count) {
    sentiment = sentiment_categories[1];
  } else {
    sentiment = sentiment_categories[2];
  }

  // Return the sentiment
  return sentiment;
}

// Main function
int main() {
  // Get the sentence from the user
  char sentence[MAX_SENTENCE_LENGTH];
  printf("Enter a sentence: ");
  scanf("%s", sentence);

  // Determine the sentiment of the sentence
  char *sentiment = determine_sentiment(sentence);

  // Print the sentiment of the sentence
  printf("The sentiment of the sentence is: %s\n", sentiment);

  return 0;
}