//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Welcome to the Typing Speed Test program!\n");
  printf("You will be given a set of random words to type as quickly and accurately as possible.\n");
  printf("Press enter to start the test.\n");
  getchar(); // wait for user to press enter
  printf("\n");

  char *words[] = {"apple", "banana", "cherry", "orange", "grape", "pineapple", "blueberry", "watermelon", "strawberry", "kiwi", "mango", "peach", "raspberry", "blackberry", "pomegranate", "apricot", "avocado", "coconut", "fig", "lemon"};
  int num_words = 20; // number of words in the array
  int num_tests = 5; // number of tests to run
  int word_length;
  char answer[20]; // answer buffer
  int i, j;
  int mistakes = 0;
  int total_words = 0;

  srand(time(NULL)); // seed random number generator

  for (i = 0; i < num_tests; i++) {
    printf("Test #%d:\n", i+1);
    printf("Type the following words:\n");

    for (j = 0; j < 5; j++) {
      // choose a random word from the array
      char *current_word = words[rand() % num_words]; 
      word_length = strlen(current_word);

      printf("%s ", current_word); // print the word to type

      scanf("%s", answer); // read user input

      // check if answer is correct
      if (strcmp(answer, current_word) != 0) {
        mistakes++;
      }

      total_words++;
    }

    printf("\n");
    printf("Test complete!\n");
    printf("You made %d mistake(s).\n", mistakes);
    printf("Your typing speed for this test is: %.2f words per minute.\n", ((float) (total_words - mistakes) / 5) * 12); // calculate words per minute
    printf("\n");

    mistakes = 0;
    total_words = 0;
  }

  printf("Thank you for using the Typing Speed Test program!\n");

  return 0;
}