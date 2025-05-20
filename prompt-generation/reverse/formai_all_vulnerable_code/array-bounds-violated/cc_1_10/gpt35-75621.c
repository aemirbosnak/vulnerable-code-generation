//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 100 // max length of the string to type
#define NUM_TRIES 3 // number of tries given to type the string
#define NUM_TESTS 5 // number of test strings to type

int checkString(char *typed, char *original);

int main() {
  srand(time(NULL));
  char testStrings[NUM_TESTS][MAX_LENGTH+1] = {
    "the quick brown fox jumps over the lazy dog",
    "the rain in spain falls mainly on the plain",
    "the cat in the hat",
    "peter piper picked a peck of pickled peppers",
    "to be or not to be that is the question"
  };

  int totalCorrect = 0;
  int totalAttempts = 0;

  printf("Welcome to the Typing Speed Test!\n");
  printf("Type the sentence as fast and as accurately as possible.\n");
  printf("You will have %d tries.\n", NUM_TRIES);

  for(int i=0; i<NUM_TESTS; i++) {
    int numAttempts = 0;
    int numCorrect = 0;
    char typed[MAX_LENGTH+1];

    printf("\n");

    // print the original string for the user to type
    printf("%s\n", testStrings[i]);

    // loop until user types string correctly or runs out of tries
    do {
      // prompt user for input
      printf("Type the sentence: ");
      fgets(typed, MAX_LENGTH+1, stdin);

      // remove newline character from input
      typed[strlen(typed)-1] = '\0';

      // check if string is correct
      if(checkString(typed, testStrings[i])) {
        printf("Correct!\n");
        numCorrect++;
        break;
      } else {
        printf("Incorrect. Try again.\n");
        numAttempts++;
      }
    } while(numAttempts < NUM_TRIES);

    // print results for this test
    printf("You typed the sentence %d times.\n", numAttempts+1);
    printf("You typed it correctly %d times.\n", numCorrect);

    totalCorrect += numCorrect;
    totalAttempts += numAttempts+1;
  }

  // print overall results
  printf("\n");
  printf("Overall Results:\n");
  printf("You typed %d sentences correctly out of %d attempts.\n", totalCorrect, totalAttempts);

  return 0;
}

/*
 * checkString - checks if two strings are equal
 * returns 1 if they are equal, 0 otherwise
 */
int checkString(char *typed, char *original) {
  if(strcmp(typed, original) == 0) {
    return 1;
  } else {
    return 0;
  }
}