//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a sentence
#define MAX_SENTENCE_LENGTH 1024

// Define the number of sentiment categories
#define NUM_SENTIMENT_CATEGORIES 5

// Define the sentiment categories
char *sentiment_categories[] = {
  "Very negative",
  "Negative",
  "Neutral",
  "Positive",
  "Very positive"
};

// Define the sentiment scores for each word
int sentiment_scores[] = {
  -3, -2, -1, 0, 1, 2, 3
};

// Define the number of words in the sentiment dictionary
#define NUM_WORDS_IN_SENTIMENT_DICTIONARY 100

// Define the sentiment dictionary
char *sentiment_dictionary[] = {
  "bad", "terrible", "horrible", "awful", "worst",
  "good", "great", "excellent", "wonderful", "best"
};

// Function to get the sentiment score of a sentence
int get_sentiment_score(char *sentence) {
  // Initialize the sentiment score to 0
  int sentiment_score = 0;

  // Tokenize the sentence into words
  char *words[MAX_SENTENCE_LENGTH];
  int num_words = tokenize(sentence, words);

  // Loop through the words in the sentence
  for (int i = 0; i < num_words; i++) {
    // Get the sentiment score for the word
    int word_sentiment_score = get_sentiment_score_for_word(words[i]);

    // Add the word sentiment score to the total sentiment score
    sentiment_score += word_sentiment_score;
  }

  // Return the total sentiment score
  return sentiment_score;
}

// Function to get the sentiment score for a word
int get_sentiment_score_for_word(char *word) {
  // Initialize the sentiment score to 0
  int sentiment_score = 0;

  // Loop through the words in the sentiment dictionary
  for (int i = 0; i < NUM_WORDS_IN_SENTIMENT_DICTIONARY; i++) {
    // If the word is in the sentiment dictionary, get its sentiment score
    if (strcmp(word, sentiment_dictionary[i]) == 0) {
      sentiment_score = sentiment_scores[i];
      break;
    }
  }

  // Return the sentiment score
  return sentiment_score;
}

// Function to tokenize a sentence into words
int tokenize(char *sentence, char *words[]) {
  // Initialize the number of words to 0
  int num_words = 0;

  // Split the sentence into words by spaces
  char *word = strtok(sentence, " ");

  // While there are more words in the sentence
  while (word != NULL) {
    // Add the word to the array of words
    words[num_words++] = word;

    // Get the next word in the sentence
    word = strtok(NULL, " ");
  }

  // Return the number of words in the sentence
  return num_words;
}

// Main function
int main() {
  // Get the sentence from the user
  char sentence[MAX_SENTENCE_LENGTH];
  printf("Enter a sentence: ");
  scanf("%s", sentence);

  // Get the sentiment score of the sentence
  int sentiment_score = get_sentiment_score(sentence);

  // Print the sentiment score
  if (sentiment_score < 0) {
    printf("The sentence has a negative sentiment.\n");
  } else if (sentiment_score > 0) {
    printf("The sentence has a positive sentiment.\n");
  } else {
    printf("The sentence has a neutral sentiment.\n");
  }

  return 0;
}