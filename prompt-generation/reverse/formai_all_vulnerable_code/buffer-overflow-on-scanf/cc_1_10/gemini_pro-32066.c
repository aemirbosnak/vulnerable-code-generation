//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: light-weight
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Generate a random string of length n
char *generateString(int n) {
  char *str = malloc(n + 1);
  for (int i = 0; i < n; i++) {
    str[i] = 'a' + rand() % 26;
  }
  str[n] = '\0';
  return str;
}

// Get the accuracy of the user's input
float getAccuracy(char *str1, char *str2) {
  int len = strlen(str1);
  int correct = 0;
  for (int i = 0; i < len; i++) {
    if (str1[i] == str2[i]) {
      correct++;
    }
  }
  return (float)correct / len * 100;
}

// Main function
int main() {
  // Initialize random seed
  srand(time(NULL));

  // Get the length of the string from the user
  int n;
  printf("Enter the length of the string: ");
  scanf("%d", &n);

  // Generate a random string
  char *str = generateString(n);

  // Display the string to the user
  printf("Type the following string as fast as you can:\n");
  printf("%s\n", str);

  // Get the start time
  clock_t start = clock();

  // Read the user's input
  char *userInput = malloc(n + 1);
  scanf("%s", userInput);

  // Get the end time
  clock_t end = clock();

  // Calculate the time taken
  double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

  // Calculate the speed in words per minute (wpm)
  double wpm = (double)n / 5 / timeTaken * 60;

  // Calculate the accuracy
  float accuracy = getAccuracy(str, userInput);

  // Display the results
  printf("Time taken: %.2fs\n", timeTaken);
  printf("Speed: %.2f wpm\n", wpm);
  printf("Accuracy: %.2f%%\n", accuracy);

  // Free the allocated memory
  free(str);
  free(userInput);

  return 0;
}