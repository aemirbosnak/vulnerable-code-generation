//Falcon-180B DATASET v1.0 Category: Table Game ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

enum{
    ROCK = 1,
    PAPER = 2,
    SCISSORS = 3,
    NUM_CHOICES = 4
};

// Function to generate random number between 1 and n
int randInt(int n){
    return rand()%n + 1;
}

// Function to print the game rules
void printRules(){
    printf("Welcome to the Rock Paper Scissors game!\n");
    printf("The rules are simple:\n");
    printf("Rock beats Scissors\n");
    printf("Scissors beats Paper\n");
    printf("Paper beats Rock\n");
    printf("If both players make the same choice, it's a tie.\n");
}

// Function to play the game
int playGame(){
    int player1Choice, player2Choice;
    int result;
    
    // Player 1 chooses
    printf("Player 1, choose your weapon:\n");
    printf("1. Rock\n2. Paper\n3. Scissors\n");
    scanf("%d", &player1Choice);
    
    // Player 2 chooses
    printf("Player 2, choose your weapon:\n");
    printf("1. Rock\n2. Paper\n3. Scissors\n");
    scanf("%d", &player2Choice);
    
    // Determine the winner
    if(player1Choice == player2Choice){
        result = 0; // Tie
    }
    else if(player1Choice == ROCK && player2Choice == SCISSORS ||
             player1Choice == SCISSORS && player2Choice == PAPER ||
             player1Choice == PAPER && player2Choice == ROCK){
        result = 1; // Player 1 wins
    }
    else{
        result = 2; // Player 2 wins
    }
    
    // Print the result
    if(result == 0){
        printf("It's a tie!\n");
    }
    else if(result == 1){
        printf("Player 1 wins!\n");
    }
    else{
        printf("Player 2 wins!\n");
    }
    
    return result;
}

// Function to play multiple rounds of the game
void playRounds(int numRounds){
    int player1Wins = 0;
    int player2Wins = 0;
    int numTies = 0;
    
    for(int i=0; i<numRounds; i++){
        int result = playGame();
        if(result == 1){
            player1Wins++;
        }
        else if(result == 2){
            player2Wins++;
        }
        else{
            numTies++;
        }
    }
    
    // Print the results
    printf("Player 1 won %d rounds.\n", player1Wins);
    printf("Player 2 won %d rounds.\n", player2Wins);
    printf("There were %d ties.\n", numTies);
}

int main(){
    srand(time(NULL));
    printRules();
    int numRounds;
    printf("How many rounds do you want to play? ");
    scanf("%d", &numRounds);
    playRounds(numRounds);
    return 0;
}