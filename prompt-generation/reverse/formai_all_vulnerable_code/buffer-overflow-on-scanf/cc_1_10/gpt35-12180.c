//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to get a random letter from A to Z
char getRandomLetter() {
  return 'A' + rand() % 26;
}

int main() {
  srand(time(NULL));  // seed the random number generator

  // welcome message and instructions
  printf("Welcome to the Typing Speed Test!\n");
  printf("Type the letter given and press Enter. You have 5 seconds for each letter.\n\n");

  int score = 0;  // initialize score to 0
  time_t start, end;  // variables to record start and end times

  while (1) {  // loop forever until user quits
    char letter = getRandomLetter();  // get a new letter

    printf("Type the letter %c: ", letter);

    time(&start);  // record start time

    char input;
    scanf(" %c", &input);  // read user input

    time(&end);  // record end time

    int diff = difftime(end, start);  // calculate time difference in seconds

    if (input == letter && diff <= 5) {  // correct answer and within time limit
      printf("Correct! You took %d seconds.\n", diff);
      score++;
    } else if (input != letter) {  // incorrect answer
      printf("Incorrect. The letter was %c.\n", letter);
    } else {  // correct answer but took too long
      printf("Too slow! The letter was %c.\n", letter);
    }

    // display score and ask if user wants to play again
    printf("Current Score: %d\n", score);
    printf("Play again? (y/n): ");

    char again;
    scanf(" %c", &again);

    if (again == 'n') {  // user wants to quit
      printf("Thanks for playing! Final score: %d\n", score);
      break;
    }

    // give user a break for 1 second before the next letter
    printf("Get ready for the next letter...\n");
    sleep(1);
  }

  return 0;
}