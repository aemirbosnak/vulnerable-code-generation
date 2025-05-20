//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: artistic
#include <stdio.h>
#include <time.h>

// Define the maximum length of the input string.
#define MAX_INPUT_LENGTH 100

// Define the number of seconds to run the test.
#define TEST_DURATION 60

// Define the minimum number of words per minute to pass the test.
#define PASSING_WORDS_PER_MINUTE 40

// Create a timer object.
struct timer {
  time_t start;
  time_t end;
};

// Create a timer object and start the timer.
struct timer start_timer() {
  struct timer timer;
  timer.start = time(NULL);
  return timer;
}

// Stop the timer and return the elapsed time in seconds.
double stop_timer(struct timer timer) {
  timer.end = time(NULL);
  return difftime(timer.end, timer.start);
}

// Get a string from the user.
char *get_input_string() {
  char *input_string = malloc(MAX_INPUT_LENGTH * sizeof(char));
  printf("Enter a string: ");
  scanf("%s", input_string);
  return input_string;
}

// Count the number of words in a string.
int count_words(char *string) {
  int word_count = 0;
  int in_word = 0;

  for (int i = 0; string[i] != '\0'; i++) {
    if (string[i] == ' ' || string[i] == '\n' || string[i] == '\t') {
      in_word = 0;
    } else if (!in_word) {
      in_word = 1;
      word_count++;
    }
  }

  return word_count;
}

// Calculate the typing speed in words per minute.
double calculate_typing_speed(int word_count, double elapsed_time) {
  return (double)word_count / elapsed_time * 60;
}

// Print the results of the typing test.
void print_results(double typing_speed, int passing) {
  printf("Your typing speed is %.2f words per minute.\n", typing_speed);
  if (passing) {
    printf("Congratulations! You passed the typing test.\n");
  } else {
    printf("Sorry, but you did not pass the typing test.\n");
  }
}

// Main function.
int main() {
  // Get the input string from the user.
  char *input_string = get_input_string();

  // Start the timer.
  struct timer timer = start_timer();

  // Wait for the user to finish typing.
  while (getchar() != '\n');

  // Stop the timer.
  double elapsed_time = stop_timer(timer);

  // Count the number of words in the input string.
  int word_count = count_words(input_string);

  // Calculate the typing speed in words per minute.
  double typing_speed = calculate_typing_speed(word_count, elapsed_time);

  // Check if the user passed the typing test.
  int passing = typing_speed >= PASSING_WORDS_PER_MINUTE;

  // Print the results of the typing test.
  print_results(typing_speed, passing);

  // Free the memory allocated for the input string.
  free(input_string);

  return 0;
}