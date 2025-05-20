//FormAI DATASET v1.0 Category: Funny ; Style: inquisitive
#include<stdio.h>

int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if(num % 2 == 0){
        printf("Wow! %d is an even number!\n", num);
    }else{
        printf("Hmmm... %d is an odd number.\n", num);
    }

    printf("Do you want to hear a funny joke?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    int choice;
    scanf("%d", &choice);

    if(choice == 1){
        printf("Why did the chicken cross the playground?\n");
        printf("To get to the other slide!\n");
    }else{
        printf("Alright, sad day for comedy.\n");
    }

    printf("How about another joke? (Y/N): ");
    char option;
    scanf(" %c", &option);

    if(option == 'Y' || option == 'y'){
        printf("What do you call an alligator in a vest?\n");
        printf("An inVESTigator!\n");
    }else{
        printf("Okay then, maybe next time!\n");
    }

    printf("Would you like to play a game? (1/0): ");
    int play_game;
    scanf("%d", &play_game);

    if(play_game == 1){
        printf("Great! Let's play Guess the Number!\n");
        printf("I am thinking of a number between 1-10. Can you guess it in 3 tries?\n");

        int number_to_guess = 7;
        int guess, number_of_guesses = 0;

        while(number_of_guesses < 3){
            printf("Guess #%d: ", number_of_guesses + 1);
            scanf("%d", &guess);

            if(guess == number_to_guess){
                printf("Wow!! You guessed it right in %d tries! You're awesome!\n", number_of_guesses + 1);
                break;
            }else{
                printf("Oops! That's not it. Try again!\n");
            }

            number_of_guesses++;
        }

        if(number_of_guesses == 3){
            printf("Sorry, you couldn't guess it in 3 tries. The number was %d.\n", number_to_guess);
        }
    }else{
        printf("Alright. I guess you're not in the mood for games.\n");
    }

    printf("Thanks for chatting with me! Goodbye!\n");

    return 0;
}