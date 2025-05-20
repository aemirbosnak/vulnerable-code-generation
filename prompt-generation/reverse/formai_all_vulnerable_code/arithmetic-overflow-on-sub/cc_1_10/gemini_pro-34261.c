//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the maximum length of the input string
#define MAX_INPUT_LENGTH 100

// Define the minimum typing speed in words per minute (WPM)
#define MIN_TYPING_SPEED 20

// Define the maximum typing speed in words per minute (WPM)
#define MAX_TYPING_SPEED 100

// Define the number of words in the test text
#define NUM_WORDS 100

// Define the test text
const char *test_text = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

// Function to get the current time in milliseconds
long long get_time_ms() {
  struct timespec time;
  clock_gettime(CLOCK_MONOTONIC, &time);
  return (long long)time.tv_sec * 1000 + (long long)time.tv_nsec / 1000000;
}

// Function to calculate the typing speed in words per minute (WPM)
int calculate_typing_speed(long long start_time, long long end_time, int num_words) {
  // Calculate the elapsed time in seconds
  double elapsed_time = (double)(end_time - start_time) / 1000;

  // Calculate the typing speed in words per minute (WPM)
  double typing_speed = (double)num_words / elapsed_time * 60;

  // Return the typing speed
  return (int)typing_speed;
}

// Function to run the typing speed test
void run_typing_speed_test() {
  // Get the starting time
  long long start_time = get_time_ms();

  // Prompt the user to enter the test text
  printf("Enter the following text as quickly and accurately as possible:\n\n%s\n", test_text);

  // Get the user's input
  char input[MAX_INPUT_LENGTH];
  fgets(input, MAX_INPUT_LENGTH, stdin);

  // Get the ending time
  long long end_time = get_time_ms();

  // Calculate the typing speed
  int typing_speed = calculate_typing_speed(start_time, end_time, NUM_WORDS);

  // Print the typing speed
  printf("\nYour typing speed is %d words per minute.\n", typing_speed);

  // Evaluate the typing speed
  if (typing_speed < MIN_TYPING_SPEED) {
    printf("Your typing speed is below the minimum required speed of %d words per minute. Please practice more to improve your typing speed.\n", MIN_TYPING_SPEED);
  } else if (typing_speed >= MIN_TYPING_SPEED && typing_speed < MAX_TYPING_SPEED) {
    printf("Your typing speed is within the acceptable range of %d to %d words per minute. Good job!\n", MIN_TYPING_SPEED, MAX_TYPING_SPEED);
  } else {
    printf("Your typing speed is above the maximum allowed speed of %d words per minute. Please slow down and focus on accuracy.\n", MAX_TYPING_SPEED);
  }
}

// Main function
int main() {
  // Run the typing speed test
  run_typing_speed_test();

  return 0;
}