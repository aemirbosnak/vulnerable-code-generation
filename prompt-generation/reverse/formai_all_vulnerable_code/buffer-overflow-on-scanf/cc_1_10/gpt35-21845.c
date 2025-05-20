//FormAI DATASET v1.0 Category: Table Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int input;
    int number;
    int lives = 5;
    int quit = 0;
    int playAgain = 1;

    // set the seed for the random number generator
    srand(time(0));

    // print a welcome message
    printf("Welcome to the Guess the Number game!\n");

    while(playAgain == 1){
        // generate a random number between 1 and 100
        number = (rand() % 100) + 1;
        lives = 5;
        quit = 0;

        printf("I'm thinking of a number between 1 and 100. You have %d lives.\n", lives);

        // loop until the player guesses the number or runs out of lives
        while(lives > 0 && quit == 0){
            printf("Guess the number: ");
            scanf("%d", &input);

            if(input < 1 || input > 100){
                printf("Invalid input. Please enter a number between 1 and 100.\n");
            }
            else if(input == number){
                printf("Congratulations! You guessed the number in %d tries!\n", 6-lives);
                quit = 1;
            }
            else if(input < number){
                lives--;
                printf("Too low. You have %d lives left.\n", lives);
            }
            else{
                lives--;
                printf("Too high. You have %d lives left.\n", lives);
            }
        }

        if(quit == 0){
            printf("Sorry, you ran out of lives. The number was %d.\n", number);
        }

        // ask if the player wants to play again
        printf("Do you want to play again? (1 for yes, 0 for no): ");
        scanf("%d", &playAgain);
    }

    printf("Thanks for playing!\n");

    return 0;
}