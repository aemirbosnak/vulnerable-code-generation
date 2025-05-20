//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_LENGTH 100
#define MAX_TIME 10

int main() {
  char user_input[MAX_LENGTH], random_string[MAX_LENGTH];
  int i, j, correct_characters = 0, incorrect_characters = 0, typing_speed;
  time_t start_time, end_time;

  printf("Welcome to the Typing Speed Test!\n\n");
  printf("Type the following sentence as fast as you can:\n\n");

  srand((unsigned) time(NULL));

  // Generate random sentence
  for (i = 0; i < MAX_LENGTH - 1; i++) {
    random_string[i] = (char) (rand() % 93 + 33); // ASCII code for printable characters
    printf("%c", random_string[i]);
  }

  printf("\n\nPress ENTER when ready.");
  getchar();

  // Start timer
  time(&start_time);

  // Get user input
  fgets(user_input, MAX_LENGTH, stdin);

  // End timer
  time(&end_time);

  // Calculate typing speed
  typing_speed = (int) difftime(end_time, start_time);
  
  // Check each character for correctness
  for (i = 0; i < MAX_LENGTH - 1; i++) {
    if (user_input[i] != random_string[i]) {
      incorrect_characters++;
    } else {
      correct_characters++;
    }
  }

  printf("\n\nYou typed %d correct characters and %d incorrect characters in %d seconds.", correct_characters, incorrect_characters, typing_speed);

  // Adjust typing speed for errors
  typing_speed *= (float) (correct_characters) / (correct_characters + incorrect_characters);

  printf("\n\nYour adjusted typing speed is %d characters per minute.", (int) ((float) (MAX_LENGTH - 1) / typing_speed * 60));

  return 0;
}