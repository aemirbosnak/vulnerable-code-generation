//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random string of length n
char *generate_random_string(int n) {
  char *str = malloc(n + 1);
  for (int i = 0; i < n; i++) {
    str[i] = 'a' + rand() % 26;
  }
  str[n] = '\0';
  return str;
}

// Function to test the typing speed of the user
int test_typing_speed() {
  // Generate a random string of length 100
  char *str = generate_random_string(100);

  // Start the timer
  clock_t start = clock();

  // Get the user's input
  char input[101];
  printf("Type the following string as fast as you can:\n%s\n", str);
  scanf("%s", input);

  // Stop the timer
  clock_t end = clock();

  // Calculate the typing speed in words per minute (WPM)
  double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
  double wpm = (100.0 / 5.0) * 60.0 / time_taken;

  // Free the allocated memory
  free(str);

  // Return the typing speed in WPM
  return wpm;
}

int main() {
  // Get the user's name
  char name[50];
  printf("Enter your name: ");
  scanf("%s", name);

  // Test the user's typing speed
  int wpm = test_typing_speed();

  // Print the user's name and typing speed
  printf("Hello %s, your typing speed is %d WPM!\n", name, wpm);

  return 0;
}