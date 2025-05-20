//FormAI DATASET v1.0 Category: Table Game ; Style: interoperable
/*This is a program for a game called "Matchsticks".
In this game, there are 21 matchsticks. Two players take turns removing 1, 2, or 3 matchsticks.
The player who removes the last matchstick loses.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//global variable to keep track of remaining matchsticks
int matchsticks = 21;

//function to get the player's move
int getMove() {
    int move;
    printf("Enter your move (1-3): ");
    scanf("%d", &move);

    //validate move
    while (move < 1 || move > 3 || move > matchsticks) {
        printf("Invalid move. Choose again.\n");
        printf("Enter your move (1-3): ");
        scanf("%d", &move);
    }

    return move;
}

//function to get the computer's move randomly
int computerMove() {
    int move = rand() % 3 + 1;

    //make sure the computer does not take more matchsticks than there are remaining
    if (move > matchsticks) {
        move = matchsticks;
    }

    printf("Computer chooses %d.\n", move);

    return move;
}

int main() {
    srand(time(NULL));

    printf("Welcome to Matchsticks!\n");
    printf("There are %d matchsticks remaining.\n", matchsticks);

    //take turns until there are no matchsticks left
    while (matchsticks > 0) {
        //get player's move
        int playerMove = getMove();
        matchsticks -= playerMove;
        printf("Player takes %d matchsticks. %d remaining.\n", playerMove, matchsticks);

        //check if player has won
        if (matchsticks == 0) {
            printf("Player wins!\n");
            break;
        }

        //get computer's move
        int computer = computerMove();
        matchsticks -= computer;
        printf("Computer takes %d matchsticks. %d remaining.\n", computer, matchsticks);

        //check if computer has won
        if (matchsticks == 0) {
            printf("Computer wins!\n");
            break;
        }
    }

    return 0;
}