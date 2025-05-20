//FormAI DATASET v1.0 Category: Table Game ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to generate random number between 1 and 100
int randomNumberGenerator()
{
    srand(time(NULL)); //seeding the random number generator with current time
    int randomNumber = rand()%(100)+1; //generating random number between 1 and 100
    return randomNumber;
}

//Main function
int main()
{
    int userChoice; //to store user's choice (1 or 2)
    int userScore = 0; //to keep track of user's score
    int compScore = 0; //to keep track of computer's score
    int randomNumber; //to store randomly generated number
    printf("\n\t\tWelcome to the C Table Game\n\n");

    do{
        printf("\t\tEnter your choice:\n");
        printf("\t\t1. Play the game\n");
        printf("\t\t2. Quit\n");
        scanf("%d",&userChoice); //getting user choice

        switch(userChoice)
        {
            case 1: printf("\n\t\tYou have chosen to play the game.\n\n");
                    printf("\t\tGame starts now...\n\n");
                    printf("\t\tGuess a number between 1 and 100:\n");
                    scanf("%d",&userScore); //getting user's guess

                    randomNumber = randomNumberGenerator(); //generating random number between 1 and 100

                    while(userScore != randomNumber)
                    {
                        if(userScore < randomNumber)
                            printf("\t\tYour guess is too low. Try again:\n");
                        else
                            printf("\t\tYour guess is too high. Try again:\n");

                        scanf("%d",&userScore); //getting user's guess
                    }

                    printf("\n\t\tCongratulations! You guessed the right number.\n\n");
                    printf("\t\tYour score: %d\n",userScore);

                    //Computer's turn to guess
                    printf("\t\tComputer's turn to guess a number.\n\n");
                    printf("\t\tComputer is thinking...\n\n");

                    randomNumber = randomNumberGenerator(); //generating random number between 1 and 100
                    printf("\t\tComputer's guess: %d\n",randomNumber);

                    //Checking if computer's guess is same as user's score
                    if(randomNumber == userScore)
                    {
                        printf("\n\t\tOops! Computer guessed right.\n");
                        compScore++;
                        printf("\t\tComputer's score: %d\n",compScore);
                    }
                    else
                        printf("\n\t\tGood job! Computer guessed wrong.\n");

                    break;

            case 2: printf("\n\t\tThank you for playing!\n");
                    exit(0);

            default: printf("\n\t\tInvalid choice. Please choose again.\n");
        }
    }while(userChoice != 2); //exit loop when user chooses to quit

    return 0;
}