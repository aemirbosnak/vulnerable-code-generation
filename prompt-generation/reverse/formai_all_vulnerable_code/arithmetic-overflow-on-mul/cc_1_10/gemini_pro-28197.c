//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUF_SIZE 1024

// Function to print the instructions
void print_instructions() {
  printf("Typing Speed Test\n");
  printf("------------------\n");
  printf("Instructions:\n");
  printf("1. Type the following text as fast as you can.\n");
  printf("2. The test will end when you press the Enter key.\n");
  printf("3. Your typing speed will be displayed in words per minute (WPM).\n");
  printf("\n");
}

// Function to get the current time in milliseconds
long long get_time_ms() {
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);
  return (long long)ts.tv_sec * 1000 + (long long)ts.tv_nsec / 1000000;
}

// Function to calculate the typing speed in WPM
double calculate_wpm(int num_words, long long start_time, long long end_time) {
  double elapsed_time = (double)(end_time - start_time) / 1000;
  return (double)num_words / elapsed_time * 60;
}

// Function to run the typing speed test
void run_test() {
  // Print the instructions
  print_instructions();

  // Get the current time
  long long start_time = get_time_ms();

  // Get the input text
  char input_text[BUF_SIZE];
  printf("Enter the text:\n");
  fgets(input_text, BUF_SIZE, stdin);

  // Get the current time
  long long end_time = get_time_ms();

  // Calculate the number of words typed
  int num_words = 0;
  char *word = strtok(input_text, " ");
  while (word != NULL) {
    num_words++;
    word = strtok(NULL, " ");
  }

  // Calculate the typing speed
  double wpm = calculate_wpm(num_words, start_time, end_time);

  // Print the results
  printf("Your typing speed is: %.2f WPM\n", wpm);
}

int main() {
  // Run the typing speed test
  run_test();

  return 0;
}