//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int count = 0, errors = 0, time_taken;
  char user_input, random_char;

  // Random character generation
  srand(time(NULL));
  random_char = rand() % 26 + 97;

  printf("Type the given character as fast as you can:\n%c\n", random_char);

  clock_t start_time = clock(); // Start time

  // Read user input character
  scanf("%c", &user_input);

  while (user_input != '\n') {
    count++;

    if (user_input == random_char) {
      printf("Correct!\n");
    } else {
      printf("Wrong! Try again.\n");
      errors++;
    }

    // Generate next random character
    random_char = rand() % 26 + 97;

    printf("Type the next character:\n%c\n", random_char);

    // Read next user input character
    scanf("%c", &user_input);
  }

  clock_t end_time = clock(); // End time

  time_taken = (float)(end_time - start_time) / CLOCKS_PER_SEC;

  // Calculate typing speed
  float speed = count / (float)time_taken * 60;
  printf("Typing Speed: %.2f WPM\n", speed);

  // Calculate error rate
  float error_rate = (errors / (float)count) * 100;
  printf("Error Rate: %.2f%%\n", error_rate);

  return 0;
}