//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function prototype
void gameInstructions();
void playGame();

//main function
int main(){
    //set seed for random function
    srand(time(0));

    int choice;
    printf("\nWelcome to the Random Number Game!\n\n");

    do{
        printf("\n\tMenu:");
        printf("\n\t1. Play Game");
        printf("\n\t2. Instructions");
        printf("\n\t3. Exit");

        printf("\n\tEnter your choice(1-3): ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                playGame();
                break;
            case 2:
                gameInstructions();
                break;
            case 3:
                printf("\nThanks for playing Random Number Game!\n\n");
                break;
            default:
                printf("\nInvalid choice! Please enter a valid choice(1-3).\n");
        }

    }while(choice != 3);

    return 0;
}

//function to display game instructions
void gameInstructions(){
    printf("\n\tInstructions:");
    printf("\n\t1. The computer will generate a random number between 1 and 100.");
    printf("\n\t2. You will have to guess this number within 5 attempts.");
    printf("\n\t3. After each guess, the computer will inform you if your guess is too high or too low.");
    printf("\n\t4. If you guess the number within 5 attempts, you win!");
    printf("\n\t5. If you are unable to guess the number within 5 attempts, you lose.");

    printf("\n\n\tPress enter to continue...");
    getchar();
    getchar();
}

//function to play the game
void playGame(){
    int randomNumber = rand()%100 + 1;
    int guess, attempts = 0;

    printf("\n\tGuess the number within 5 attempts! Good luck!\n");

    do{
        printf("\n\tEnter your guess: ");
        scanf("%d", &guess);

        attempts++;

        if(guess == randomNumber){
            printf("\n\tCongratulations! You won in %d attempts!\n", attempts);
            return;
        }
        else if(guess < randomNumber){
            printf("\n\tYour guess is too low. Try again.\n");
        }
        else{
            printf("\n\tYour guess is too high. Try again.\n");
        }
    }while(attempts < 5);

    printf("\n\tSorry! You lost. The number was %d.\n", randomNumber);
}