//Gemma-7B DATASET v1.0 Category: Data mining ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void analyze_love_letters(char **letters, int num_letters) {
  for (int i = 0; i < num_letters; i++) {
    char *letter = letters[i];

    // Calculate the sentiment score for each letter
    int sentiment_score = calculate_sentiment_score(letter);

    // Print the sentiment score
    printf("Letter %d: Sentiment score = %d\n", i + 1, sentiment_score);
  }
}

int calculate_sentiment_score(char *letter) {
  int score = 0;

  // Count the number of positive words in the letter
  int num_positive_words = count_positive_words(letter);

  // Count the number of negative words in the letter
  int num_negative_words = count_negative_words(letter);

  // Calculate the sentiment score
  score = num_positive_words - num_negative_words;

  return score;
}

int count_positive_words(char *letter) {
  char *positive_words[] = {"love", "happy", "joy", "sweet", "beautiful"};

  int num_positive_words = 0;

  for (int i = 0; i < 5; i++) {
    if (strstr(letter, positive_words[i]) != NULL) {
      num_positive_words++;
    }
  }

  return num_positive_words;
}

int count_negative_words(char *letter) {
  char *negative_words[] = {"hate", "sad", "anger", "fear", "pain"};

  int num_negative_words = 0;

  for (int i = 0; i < 5; i++) {
    if (strstr(letter, negative_words[i]) != NULL) {
      num_negative_words++;
    }
  }

  return num_negative_words;
}

int main() {
  // Create an array of love letters
  char **letters = (char **)malloc(MAX * sizeof(char *));

  // Get the number of letters
  int num_letters = 0;

  // Read the letters
  printf("Enter the number of letters: ");
  scanf("%d", &num_letters);

  // Allocate memory for the letters
  letters = (char **)malloc(num_letters * sizeof(char *));

  // Get the letters
  for (int i = 0; i < num_letters; i++) {
    printf("Enter letter %d: ", i + 1);
    letters[i] = (char *)malloc(MAX * sizeof(char));
    scanf("%[^\n]", letters[i]);
  }

  // Analyze the letters
  analyze_love_letters(letters, num_letters);

  // Free the memory
  for (int i = 0; i < num_letters; i++) {
    free(letters[i]);
  }
  free(letters);

  return 0;
}