//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to generate random number between 1 to 100
int generateRandomNumber(){
    srand(time(0));
    return rand() % 100 + 1;
}

int main(){
  int userGuess, randomNumber, attempts = 10;
  char playAgain;
  
  do{
    printf("\nWelcome to the Number Guessing Game!\n");
    randomNumber = generateRandomNumber();
    printf("\nA random number between 1 to 100 has been generated.\nYou need to guess the number in only 10 attempts.\n");

    //Main loop to get user input and check if it matches the random number
    while(attempts > 0){
        printf("\nAttempts left: %d\n", attempts);
        printf("Enter your guess between 1 to 100: ");
        scanf("%d", &userGuess);
        
        if(userGuess == randomNumber){
            printf("\nCongratulations! You have guessed the number correctly.\n");
            break;
        }
        else if(userGuess < randomNumber){
            printf("\nWrong Guess! The number you guessed is less than the random number.\n");
            attempts--;
        }
        else{
            printf("\nWrong Guess! The number you guessed is greater than the random number.\n");
            attempts--;
        }
    }

    if(attempts == 0){
        printf("\nSorry, you have lost the game. The correct number was %d\n", randomNumber);
    }

    //Asking user if they want to play again
    printf("\nDo you want to play again? (y/n) ");
    scanf(" %c", &playAgain);
    attempts = 10; //Resetting attempts for next round
  }while(playAgain == 'Y' || playAgain == 'y');
  return 0;
}