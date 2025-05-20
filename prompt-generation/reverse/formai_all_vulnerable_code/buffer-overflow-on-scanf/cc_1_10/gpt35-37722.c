//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to clear terminal screen
void clearScreen() {
  system("clear");
}

//Function to generate random integer between two numbers
int generateRandomNumber(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

//Function to perform the brain-bending game
void playMindBendingGame() {
  //Generating the two random numbers
  int num1 = generateRandomNumber(1, 10);
  int num2 = generateRandomNumber(1, 10);

  //Calculating the expected answer
  int expected = (num1 + num2) * 3;

  //Asking the user for their answer
  int answer;
  printf("What is ( %d + %d ) * 3 : ", num1, num2);
  scanf("%d", &answer);

  //Checking if the user's answer is correct
  if(answer == expected) {
    printf("Congratulations! You have won the game!\n");
  }
  else {
    printf("Sorry! That is not the correct answer. Better luck next time!\n");
  }
}

//Main function
int main() {
  //Setting the seed for random number generation
  srand(time(0));

  //Displaying welcome message
  printf("Welcome to the Mind-Bending Game!\n");

  //Setting the initial score
  int score = 0;

  //Loop to play the game multiple times
  while(1) {
    //Clearing the screen
    clearScreen();

    //Printing the current score
    printf("Current Score: %d\n", score);

    //Playing the game and updating the score accordingly
    playMindBendingGame();
    score++;

    //Asking the user if they want to play again
    char choice;
    printf("Do you want to play again? (Y/N) : ");
    scanf(" %c", &choice);

    //Breaking the loop if the user chooses not to play again
    if(choice == 'N' || choice == 'n') {
      printf("Thanks for playing the Mind-Bending Game. Your final score is: %d\n", score);
      break;
    }
  }

  return 0;
}