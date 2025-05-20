//FormAI DATASET v1.0 Category: Table Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("Welcome to Rock Paper Scissors!\n");
    printf("You will be playing against the computer.\n");

    int playerScore = 0;
    int computerScore = 0;
    char playerChoice;
    char computerChoice;
    srand(time(NULL));

    while(1){ //infinite loop
        printf("Enter your choice (R for Rock, P for Paper, S for Scissors): ");
        scanf(" %c", &playerChoice); //space before %c prevents buffer issues

        if(playerChoice == 'R' || playerChoice == 'r')
            printf("You chose: Rock!\n");
        else if(playerChoice == 'P' || playerChoice == 'p')
            printf("You chose: Paper!\n");
        else if(playerChoice == 'S' || playerChoice == 's')
            printf("You chose: Scissors!\n");
        else{
            printf("Invalid choice! Try again.\n");
            continue; //skips the rest of the code in the loop and starts again
        }

        int randomNum = rand() % 3; //generates a random number between 0-2 inclusive
        if(randomNum == 0){
            computerChoice = 'R';
            printf("Computer chose: Rock!\n");
        }
        else if(randomNum == 1){
            computerChoice = 'P';
            printf("Computer chose: Paper!\n");
        }
        else{
            computerChoice = 'S';
            printf("Computer chose: Scissors!\n");
        }

        //determine winner and update scores
        if(playerChoice == computerChoice)
            printf("It's a tie!\n");
        else if(playerChoice == 'R' || playerChoice == 'r'){
            if(computerChoice == 'P')
                printf("Computer wins!\n"), computerScore++;
            else
                printf("You win!\n"), playerScore++;
        }
        else if(playerChoice == 'P' || playerChoice == 'p'){
            if(computerChoice == 'S')
                printf("Computer wins!\n"), computerScore++;
            else
                printf("You win!\n"), playerScore++;
        }
        else{ //playerChoice is 'S' or 's'
            if(computerChoice == 'R')
                printf("Computer wins!\n"), computerScore++;
            else
                printf("You win!\n"), playerScore++;
        }

        printf("Score: You %d - %d Computer\n\n", playerScore, computerScore);

        if(playerScore == 5){
            printf("Congratulations! You are the winner.\n");
            break; //exit loop
        }
        else if(computerScore == 5){
            printf("Sorry! The computer beat you.\n");
            break; //exit loop
        }
    }

    return 0;
}