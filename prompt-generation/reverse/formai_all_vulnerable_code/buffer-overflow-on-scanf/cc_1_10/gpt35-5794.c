//FormAI DATASET v1.0 Category: Random ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    //welcome message
    printf("Welcome to the amazing world of random numbers!\n");
    printf("Experience the thrill of randomness with us!\n");
    
    //generating seed for random number generation
    srand(time(NULL));
    
    //declaring variables
    int randomNumber, guess, attempts = 0;
    
    //generating random number between 1-100
    randomNumber = rand() % 100 + 1;
    
    //game instructions
    printf("\nGame Instructions:\n");
    printf("I am thinking of a number between 1 and 100.\n");
    printf("You have to guess the number in minimum attempts possible.\n");
    printf("Every time you guess, I will tell you if the number is higher or lower than your guess.\n");
    printf("Let's begin!\n\n");
    
    //gameplay
    do{
        //user input
        printf("Guess the number: ");
        scanf("%d", &guess);
        
        //incrementing attempts counter
        attempts++;
        
        //comparing guess with random number
        if(guess > randomNumber)
        {
            printf("The number is lower than your guess.\n\n");
        }
        else if(guess < randomNumber)
        {
            printf("The number is higher than your guess.\n\n");
        }
        else
        {
            //if guess matches random number, congratulating user
            printf("\nCongratulations, you have guessed the number in %d attempts!\n", attempts);
        }
    }while(guess != randomNumber);
    
    //exit message
    printf("\nThanks for playing!\n");
    printf("We hope you had a great time!\n");
    printf("Come back soon for another round of randomness!\n");
    
    return 0;
}