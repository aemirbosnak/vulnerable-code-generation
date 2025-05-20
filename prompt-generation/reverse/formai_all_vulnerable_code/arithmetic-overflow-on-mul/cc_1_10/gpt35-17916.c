//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Define the maximum number of players and the maximum balance
#define MAX_PLAYERS 5
#define MAX_BALANCE 10000 //in cents

//Function to simulate a dice roll
int rollDice() {
    return rand() % 6 + 1;
}

int main() {
    //Initialize the random number generator
    srand(time(NULL));
    
    //Variable declarations
    int numPlayers, i, j, totalBalance = 0;
    int playerBalance[MAX_PLAYERS];
    char playerNames[MAX_PLAYERS][20];
    int currentPlayer;
    int isGameOver = 0;
    int totalTurns = 0;
    
    //Get the number of players
    printf("Welcome to Personal Finance Planner!\n");
    printf("How many players (1-5)? ");
    scanf("%d", &numPlayers);
    
    //Check if the number of players is valid
    if (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players!\n");
        return 0;
    }
    
    //Get the name and initial balance for each player
    for (i = 0; i < numPlayers; i++) {
        printf("Enter name for Player %d: ", i+1);
        scanf("%s", playerNames[i]);
        
        printf("Enter initial balance for %s (in dollars): ", playerNames[i]);
        scanf("%d", &playerBalance[i]);
        playerBalance[i] *= 100; //convert to cents
        
        //Check if the balance is valid
        if (playerBalance[i] < 0 || playerBalance[i] > MAX_BALANCE) {
            printf("Invalid initial balance!\n");
            return 0;
        }
        
        //Add the balance to the total balance
        totalBalance += playerBalance[i];
    }
    
    //Loop through turns until the game is over
    while (!isGameOver) {
        //Increment the turn counter
        totalTurns++;
        
        //Loop through each player's turn
        for (i = 0; i < numPlayers; i++) {
            currentPlayer = i;
            
            //Check if the player has enough balance to roll the dice
            if (playerBalance[currentPlayer] < 100) {
                printf("%s does not have enough balance to roll the dice.\n", playerNames[currentPlayer]);
                continue;
            }
            
            //Get the player's bet amount
            printf("%s, it's your turn. You have %d cents in your balance.\n", playerNames[currentPlayer], playerBalance[currentPlayer]);
            printf("Enter bet amount (in cents): ");
            int betAmount;
            scanf("%d", &betAmount);
            
            //Check if the bet amount is valid
            if (betAmount < 100 || betAmount > playerBalance[currentPlayer]) {
                printf("Invalid bet amount!\n");
                continue;
            }
            
            //Roll the dice and calculate the new balance
            int diceRoll = rollDice() + rollDice();
            printf("You rolled %d.\n", diceRoll);
            if (diceRoll == 7) {
                printf("Congratulations! You won %d cents.\n", betAmount);
                playerBalance[currentPlayer] += betAmount;
            } else {
                printf("Sorry, you lost %d cents.\n", betAmount);
                playerBalance[currentPlayer] -= betAmount;
            }
            
            //Check if the player is bankrupt
            if (playerBalance[currentPlayer] < 100) {
                printf("%s is bankrupt and cannot continue playing.\n", playerNames[currentPlayer]);
                numPlayers--;
                if (numPlayers == 1) {
                    isGameOver = 1;
                    break;
                }
            }
        }
    }
    
    //Print the game summary
    printf("\nGame over! Total turns played: %d\n", totalTurns);
    printf("Final balances:\n");
    for (i = 0; i < numPlayers; i++) {
        printf("%s: %d cents\n", playerNames[i], playerBalance[i]);
    }
    printf("Total balance: %d cents\n", totalBalance);
    
    return 0;
}