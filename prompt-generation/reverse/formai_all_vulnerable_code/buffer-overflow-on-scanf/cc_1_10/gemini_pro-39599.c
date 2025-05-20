//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// Function to generate a random string of length n
char *generate_random_string(int n) {
  char *str = malloc(n + 1);
  int i;
  for (i = 0; i < n; i++) {
    str[i] = rand() % 26 + 'a';
  }
  str[n] = '\0';
  return str;
}

// Function to compare two strings
int compare_strings(const char *str1, const char *str2) {
  int i;
  for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
    if (str1[i] != str2[i]) {
      return 0;
    }
  }
  return 1;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the user's name
  char name[256];
  printf("What is your name? ");
  scanf("%s", name);

  // Get the user's desired test length
  int length;
  printf("How long do you want the test to be (in seconds)? ");
  scanf("%d", &length);

  // Generate a random string
  char *str = generate_random_string(length);

  // Start the timer
  clock_t start = clock();

  // Get the user's input
  char input[256];
  printf("Type the following string as accurately and quickly as possible:\n%s\n", str);
  scanf("%s", input);

  // Stop the timer
  clock_t end = clock();

  // Calculate the user's typing speed
  double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
  int speed = (int)(strlen(str) / time_taken);

  // Compare the user's input to the original string
  int correct = compare_strings(input, str);

  // Print the results
  printf("Your typing speed is %d characters per second.\n", speed);
  if (correct) {
    printf("Congratulations, you typed the string correctly!\n");
  } else {
    printf("Oops, you made some mistakes.\n");
  }

  // Free the allocated memory
  free(str);

  return 0;
}