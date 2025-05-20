//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random sentence
char *generateSentence(int length) {
  char *sentence = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    sentence[i] = 'a' + rand() % 26;
  }
  sentence[length] = '\0';
  return sentence;
}

// Function to get the accuracy of the user's input
int getAccuracy(char *original, char *input) {
  int length = strlen(original);
  int correct = 0;
  for (int i = 0; i < length; i++) {
    if (original[i] == input[i]) {
      correct++;
    }
  }
  return (correct * 100) / length;
}

// Function to get the words per minute of the user's input
int getWordsPerMinute(int length, int time) {
  return (length / 5) * (60 / time);
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the user's name
  char name[20];
  printf("What's your name, typing superstar? ");
  scanf("%s", name);

  // Get the desired sentence length
  int length;
  printf("How long do you want your sentence to be? ");
  scanf("%d", &length);

  // Generate a random sentence
  char *sentence = generateSentence(length);

  // Get the user's input
  char input[length + 1];
  printf("Type the following sentence as fast as you can:\n%s\n", sentence);
  scanf("%s", input);

  // Calculate the accuracy and words per minute
  int accuracy = getAccuracy(sentence, input);
  int wpm = getWordsPerMinute(length, time(NULL) - clock());

  // Print the results
  printf("------------------------------------\n");
  printf("Name: %s\n", name);
  printf("Accuracy: %d%%\n", accuracy);
  printf("Words per minute: %d\n", wpm);
  printf("------------------------------------\n");

  return 0;
}