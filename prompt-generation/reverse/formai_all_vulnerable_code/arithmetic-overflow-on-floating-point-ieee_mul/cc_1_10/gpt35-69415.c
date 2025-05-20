//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  char ch;
  int i, score, randnum, num_chars, num_mistakes;
  double typing_speed;
  time_t start_time, end_time;
  //Welcome message
  printf("Welcome to the Typing Speed Test!\n");
  printf("You will be shown a series of random characters to type.\n");
  printf("Try to type as many as you can within a minute!\n\n");

  printf("Press any key when you are ready to start.\n");
  getchar(); // Waits for user to press any key

  //Time starts
  time(&start_time);

  //Loop to generate random characters and score the user
  score = 0;
  num_chars = 0;
  num_mistakes = 0;
  while (difftime(time(NULL), start_time) < 60){ //Runs for 60 seconds
    srand((unsigned int) time(NULL)); //Sets a random seed
    randnum = rand() % 26 + 65; //Generates a random capital letter
    ch = (char) randnum;
    printf("%c", ch);
    fflush(stdout); //Forces output to be displayed
    ch = getchar();

    if (ch == '\n' || ch == '\r'){ //Does not count enter as a typing character
      continue;
    }
    else if (ch == 27){ //Escape key to quit
      break;
    }
    else if (ch != randnum){ //Counts mistakes and lets user type again
      printf("\nWrong! Try again.\n");
      num_mistakes++;
      continue;
    }
    else{ //Correct typing
      score++;
      num_chars++;
    }
  } 

  //Time ends
  time(&end_time);

  //Calculates user's typing speed and displays results
  typing_speed = ((double) score / difftime(end_time, start_time)) * 60;
  printf("\n\nGreat job!\n");
  printf("Your typing speed was %.2f characters per minute!\n", typing_speed);
  printf("You typed %d characters with %d mistakes.\n", num_chars, num_mistakes);

  return 0;
}