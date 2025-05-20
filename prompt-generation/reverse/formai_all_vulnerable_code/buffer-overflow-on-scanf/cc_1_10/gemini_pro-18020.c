//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random string of a given length
char *generate_random_string(int length) {
  char *string = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    string[i] = (char)('a' + rand() % 26);
  }
  string[length] = '\0';
  return string;
}

// Function to calculate the typing speed
int calculate_typing_speed(char *input, int length, int time) {
  int count = 0;
  for (int i = 0; i < length; i++) {
    if (input[i] == *(input + i)) {
      count++;
    }
  }
  return (count * 60) / time;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the user's name
  char name[256];
  printf("Enter your name: ");
  scanf("%s", name);

  // Generate a random string of length 100
  int length = 100;
  char *string = generate_random_string(length);

  // Display the string to the user
  printf("\nType the following string as quickly and accurately as possible:\n");
  printf("%s\n", string);

  // Start the timer
  clock_t start = clock();

  // Get the user's input
  char input[256];
  printf("Type the string: ");
  scanf("%s", input);

  // Stop the timer
  clock_t end = clock();

  // Calculate the time taken
  int time = (end - start) / CLOCKS_PER_SEC;

  // Calculate the typing speed
  int speed = calculate_typing_speed(input, length, time);

  // Display the results
  printf("\nYour typing speed is %d words per minute.\n", speed);

  // Free the allocated memory
  free(string);

  return 0;
}