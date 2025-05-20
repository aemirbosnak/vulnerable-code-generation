//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: detailed
#include <stdio.h>
#include <string.h>

#define MAX_SENT_LEN 1024 // maximum sentence length
#define MAX_WORD_LEN 128 // maximum word length

// Function to count the number of words in a sentence
int count_words(char sentence[]) {
  int count = 0;
  char word[MAX_WORD_LEN];
  int i = 0, j = 0;

  while (sentence[i] != '\0') {
    if (sentence[i] == ' ' || sentence[i] == '\n' || sentence[i] == '\t') {
      word[j] = '\0';
      count++;
      j = 0;
    } else {
      word[j] = sentence[i];
      j++;
    }
    i++;
  }

  return count;
}

// Function to calculate the sentiment of a sentence
int calculate_sentiment(char sentence[]) {
  int sentiment = 0;
  char word[MAX_WORD_LEN];
  int i = 0, j = 0;

  while (sentence[i] != '\0') {
    if (sentence[i] == ' ' || sentence[i] == '\n' || sentence[i] == '\t') {
      word[j] = '\0';

      // Check if the word is positive, negative, or neutral
      if (strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "excellent") == 0) {
        sentiment += 1;
      } else if (strcmp(word, "bad") == 0 || strcmp(word, "terrible") == 0 || strcmp(word, "awful") == 0) {
        sentiment -= 1;
      }

      j = 0;
    } else {
      word[j] = sentence[i];
      j++;
    }
    i++;
  }

  return sentiment;
}

int main() {
  char sentence[MAX_SENT_LEN];
  int sentiment;

  printf("Please enter a sentence to analyze: ");
  fgets(sentence, MAX_SENT_LEN, stdin);

  // Remove trailing newline character from the sentence
  if (sentence[strlen(sentence) - 1] == '\n') {
    sentence[strlen(sentence) - 1] = '\0';
  }

  // Count the number of words in the sentence
  int num_words = count_words(sentence);

  // Calculate the sentiment of the sentence
  sentiment = calculate_sentiment(sentence);

  // Calculate the average sentiment per word
  float avg_sentiment = (float) sentiment / num_words;

  // Print the analysis results
  printf("Analysis results:\n");
  printf("- Total words: %d\n", num_words);
  printf("- Sentiment: %d\n", sentiment);
  printf("- Average sentiment per word: %.2f\n", avg_sentiment);

  return 0;
}