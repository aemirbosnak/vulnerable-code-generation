//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char words[5][10] = {"surreal", "dream", "unicorn", "octopus", "piano"}; // words to type
  int count = 0; // count of correctly typed words
  time_t start, end; // for timing the test
  srand(time(NULL));

  printf("Welcome to the Surrealist Typing Speed Test!\n\n");
  printf("Type the following words: \n");

  for (int i = 0; i < 5; i++) {
    printf("%s\t", words[i]);
  }

  printf("\n\nType them as fast as you can!\n\n");
  printf("Press ENTER to start");
  getchar(); // wait for user to press enter

  start = time(NULL); // start timing the test

  for (int i = 0; i < 5; i++) {
    printf("%s: ", words[i]); // display current word
    char input[10]; // buffer for user input
    scanf("%s", input); // read user input
    if (strcmp(words[i], input) == 0) { // check if input matches
      count++; // increment count
      printf("Correct!\n");
    }
    else {
      printf("Incorrect!\n"); // notify user of incorrect typing
    }
  }

  end = time(NULL); // end timing the test

  printf("\nYou typed %d words correctly in %ld seconds!\n", count, end - start);

  if (count <= 2) {
    printf("Your surrealist typing skills need improvement!\n");
  }
  else if (count >= 3 && count <= 4) {
    printf("Not bad, but you can definitely be more surreal!\n");
  }
  else if (count == 5) {
    printf("Wow! You have some seriously surreal typing skills!\n");
  }

  return 0; // end program
}