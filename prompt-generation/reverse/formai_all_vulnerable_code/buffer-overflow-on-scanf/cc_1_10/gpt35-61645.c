//FormAI DATASET v1.0 Category: Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    //Initialize variables
    int score = 0;
    int roundScore = 0;
    int dice1, dice2;
    char choice;
    srand(time(NULL));
    
    //Welcome message
    printf("Welcome to the Dice Rolling Game!\n");
    printf("You will be rolling two dice and adding their values to your score.\n");
    printf("If you roll a double, you get to roll again!\n");
    printf("The first player to reach a score of 100 wins!\n");
    
    //Main game loop
    while (score < 100) {
        
        roundScore = 0;
        printf("\nYour current score is: %d\n", score);
        printf("Press any key to roll the dice!\n");
        getchar(); //waits for user to press any key
        
        //Roll the dice
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        printf("You rolled a %d and a %d!\n", dice1, dice2);
        
        //Add the roll to the round score
        roundScore = dice1 + dice2;
        
        //If the roll is a double, roll again
        if (dice1 == dice2) {
            printf("You rolled a double! Roll again!\n");
            dice1 = rand() % 6 + 1;
            dice2 = rand() % 6 + 1;
            printf("You rolled a %d and a %d!\n", dice1, dice2);
            roundScore += dice1 + dice2;
        }
        
        //Update the score
        score += roundScore;
        
        //Print the round score
        printf("Your round score is: %d\n", roundScore);
        
        //Check if the player has won
        if (score >= 100) {
            printf("You win with a score of %d!\n", score);
            break;
        }
        
        //Otherwise, ask the player if they want to roll again
        printf("Do you want to roll again? (y/n)\n");
        scanf(" %c", &choice); //scan the first character entered by the user
        
        //If the player wants to stop rolling, end the game
        if (choice == 'n') {
            printf("Thanks for playing! Your final score is %d.\n", score);
            break;
        }
    }
    
    return 0;
}