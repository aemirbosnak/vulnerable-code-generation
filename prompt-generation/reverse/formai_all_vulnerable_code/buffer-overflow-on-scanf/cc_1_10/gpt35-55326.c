//FormAI DATASET v1.0 Category: Table Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to roll a dice
int rollDice() {
    return rand() % 6 + 1;
}

//Function to play the game
void playGame(int n) {
    //Initialize player positions and previous positions
    int playerPos[n];
    int prevPos[n];
    for (int i = 0; i < n; i++) {
        playerPos[i] = 0;
        prevPos[i] = 0;
    }

    int turn = 0; //Initialize turn to player 1
    int winner = -1; //-1 represents no winner yet
    srand(time(0)); //Seed the random number generator

    while (winner == -1) { //Loop until a winner is found
        printf("Player %d, it's your turn.\n", turn+1);

        //Roll the dice
        int roll = rollDice();
        printf("You rolled a %d!\n", roll);

        //Calculate new position
        int newPos = playerPos[turn] + roll;

        //Check if player has won
        if (newPos >= 100) {
            printf("Congratulations player %d, you have won the game!\n", turn+1);
            winner = turn;
            break;
        }

        //Check for chutes and ladders
        if (newPos == 4 || newPos == 11 || newPos == 24 || newPos == 34 || newPos == 46 || newPos == 57 || newPos == 69 || newPos == 78 || newPos == 87 || newPos == 94) {
            newPos += 10;
            printf("You've climbed a ladder! New position is %d.\n", newPos);
        } else if (newPos == 16 || newPos == 21 || newPos == 42 || newPos == 61 || newPos == 73 || newPos == 84 || newPos == 91) {
            newPos -= 10;
            printf("You've fallen down a chute. New position is %d.\n", newPos);
        }

        //If player has already been on that position, skip turn
        if (newPos == prevPos[turn]) {
            printf("You've already been there. Skipping turn.\n");
            turn = (turn + 1) % n;
            continue;
        }

        //Update player position
        prevPos[turn] = playerPos[turn];
        playerPos[turn] = newPos;
        printf("New position is %d.\n", newPos);

        //Switch to next player
        turn = (turn + 1) % n;
    }
}

int main() {
    int n;
    printf("Welcome to Chutes and Ladders! How many players? (2-4)\n");
    scanf("%d", &n);

    if (n < 2 || n > 4) {
        printf("Invalid input. Please enter a number between 2 and 4.\n");
        return 0;
    }

    playGame(n);

    return 0;
}