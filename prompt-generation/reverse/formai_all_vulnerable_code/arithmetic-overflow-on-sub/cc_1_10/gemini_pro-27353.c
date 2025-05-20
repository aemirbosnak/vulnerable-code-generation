//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: all-encompassing
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TEST_LENGTH 100

int main() {
  // Initialize random seed
  srand(time(NULL));

  // Generate random test string
  char test_string[TEST_LENGTH + 1];
  for (int i = 0; i < TEST_LENGTH; i++) {
    test_string[i] = (char)('a' + rand() % 26);
  }
  test_string[TEST_LENGTH] = '\0';

  // Print test string
  printf("Type the following string as fast as you can:\n%s\n\n", test_string);

  // Start timer
  clock_t start = clock();

  // Get user input
  char user_input[TEST_LENGTH + 1];
  fgets(user_input, TEST_LENGTH + 1, stdin);

  // Stop timer
  clock_t end = clock();

  // Calculate typing speed
  double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
  double typing_speed = TEST_LENGTH / time_taken;

  // Print results
  printf("\nYou typed %d characters in %.2f seconds.\n", TEST_LENGTH, time_taken);
  printf("Your typing speed is %.2f characters per second.\n", typing_speed);

  // Compare user input to test string
  int errors = 0;
  for (int i = 0; i < TEST_LENGTH; i++) {
    if (tolower(user_input[i]) != tolower(test_string[i])) {
      errors++;
    }
  }

  // Print error count
  printf("\nYou made %d errors.\n", errors);

  return 0;
}