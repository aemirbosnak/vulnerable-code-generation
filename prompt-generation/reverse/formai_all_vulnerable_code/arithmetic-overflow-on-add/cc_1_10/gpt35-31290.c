//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    //Initialize variables
    int number_of_guesses = 0;
    int guess = 0;
    int secret_number;
    int max_guesses;
    int play_again = 1;
    char play_again_input;
    
    //Set random seed
    srand(time(0));
    
    //Begin game loop
    while(play_again) {
        number_of_guesses = 0;
        printf("Welcome to the guessing game!\n");
        printf("Please enter the maximum number you would like to guess:\n");
        scanf("%d", &secret_number);
        printf("Please enter the maximum number of guesses you get:\n");
        scanf("%d", &max_guesses);
        printf("You have %d guesses to guess the secret number between 1 and %d\n", max_guesses, secret_number);
        secret_number = rand() % secret_number + 1;
        
        //Guess loop
        while(number_of_guesses < max_guesses) {
            printf("Guess the secret number:");
            scanf("%d", &guess);
            
            //Check if guess is correct
            if(guess == secret_number) {
                printf("Congratulations! You guessed the secret number in %d tries!\n", number_of_guesses+1);
                break;
            }
            
            //Provide hints if guess is too high or low
            if(guess < secret_number) {
                printf("Too low!\n");
            }
            else {
                printf("Too high!\n");
            }
            
            number_of_guesses++;    
        }
        
        //If the maximum number of guesses were reached without guessing correctly
        if(number_of_guesses == max_guesses) {
            printf("Sorry, you have run out of guesses. The secret number was %d.\n", secret_number);
        }
        
        //Ask the player if they want to play again
        printf("Would you like to play again? [Y/N]\n");
        scanf(" %c", &play_again_input);
        
        //Set play_again variable based on their input
        if(play_again_input == 'Y' || play_again_input == 'y') {
            play_again = 1;
        }
        else {
            play_again = 0;
        }
    }
    
    return 0;
}