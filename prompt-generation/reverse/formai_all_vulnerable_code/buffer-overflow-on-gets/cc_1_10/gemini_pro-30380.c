//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: modular
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of words to analyze.
#define MAX_WORDS 1000

// Define the maximum length of a word.
#define MAX_WORD_LENGTH 50

// Define the number of sentiment categories.
#define NUM_SENTIMENT_CATEGORIES 5

// Define the sentiment categories.
const char *SENTIMENT_CATEGORIES[] = {"Very negative", "Negative", "Neutral", "Positive", "Very positive"};

// Define the word counts for each sentiment category.
int word_counts[NUM_SENTIMENT_CATEGORIES];

// Define the total word count.
int total_word_count;

// Initialize the word counts.
void init_word_counts() {
  for (int i = 0; i < NUM_SENTIMENT_CATEGORIES; i++) {
    word_counts[i] = 0;
  }
}

// Get the sentiment category for a word.
int get_sentiment_category(const char *word) {
  // Convert the word to lowercase.
  char word_lower[MAX_WORD_LENGTH];
  for (int i = 0; i < strlen(word); i++) {
    word_lower[i] = tolower(word[i]);
  }

  // Check if the word is in the list of positive words.
  if (strcmp(word_lower, "good") == 0) {
    return 4;
  } else if (strcmp(word_lower, "great") == 0) {
    return 4;
  } else if (strcmp(word_lower, "excellent") == 0) {
    return 4;
  } else if (strcmp(word_lower, "amazing") == 0) {
    return 4;
  } else if (strcmp(word_lower, "wonderful") == 0) {
    return 4;

  // Check if the word is in the list of negative words.
  } else if (strcmp(word_lower, "bad") == 0) {
    return 0;
  } else if (strcmp(word_lower, "terrible") == 0) {
    return 0;
  } else if (strcmp(word_lower, "horrible") == 0) {
    return 0;
  } else if (strcmp(word_lower, "awful") == 0) {
    return 0;
  } else if (strcmp(word_lower, "disgusting") == 0) {
    return 0;
  }

  // The word is not in the list of positive or negative words, so it is neutral.
  return 2;
}

// Tokenize the text.
char **tokenize(const char *text) {
  // Allocate memory for the tokens.
  char **tokens = malloc(sizeof(char *) * MAX_WORDS);

  // Tokenize the text.
  int token_count = 0;
  char *token = strtok((char *)text, " ");
  while (token != NULL) {
    tokens[token_count] = token;
    token_count++;
    token = strtok(NULL, " ");
  }

  // Return the tokens.
  return tokens;
}

// Analyze the sentiment of the text.
int analyze_sentiment(const char *text) {
  // Tokenize the text.
  char **tokens = tokenize(text);

  // Get the sentiment category for each word.
  for (int i = 0; i < MAX_WORDS; i++) {
    if (tokens[i] != NULL) {
      int sentiment_category = get_sentiment_category(tokens[i]);
      word_counts[sentiment_category]++;
      total_word_count++;
    }
  }

  // Calculate the sentiment score.
  int sentiment_score = 0;
  for (int i = 0; i < NUM_SENTIMENT_CATEGORIES; i++) {
    sentiment_score += word_counts[i] * i;
  }

  // Return the sentiment score.
  return sentiment_score;
}

// Print the sentiment analysis results.
void print_results() {
  // Calculate the percentage of words in each sentiment category.
  float percentages[NUM_SENTIMENT_CATEGORIES];
  for (int i = 0; i < NUM_SENTIMENT_CATEGORIES; i++) {
    percentages[i] = (float)word_counts[i] / total_word_count * 100;
  }

  // Print the sentiment analysis results.
  printf("Sentiment analysis results:\n");
  for (int i = 0; i < NUM_SENTIMENT_CATEGORIES; i++) {
    printf("%s: %f%%\n", SENTIMENT_CATEGORIES[i], percentages[i]);
  }
}

// Main function.
int main() {
  // Initialize the word counts.
  init_word_counts();

  // Get the text from the user.
  char text[1000];
  printf("Enter the text to analyze: ");
  gets(text);

  // Analyze the sentiment of the text.
  int sentiment_score = analyze_sentiment(text);

  // Print the sentiment analysis results.
  print_results();

  return 0;
}