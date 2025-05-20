//FormAI DATASET v1.0 Category: Table Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function that generates a random number between the specified range
int randomNumber(int min, int max) {
    srand(time(NULL)); // seed the random number generator
    return (rand() % (max - min + 1)) + min; // return the random number
}

int main() {
    int numPlayers, rows, cols, i, j, k, numRounds = 1, playerTurn = 0;
    printf("Welcome to the C Table Game!\n\n");
    printf("Enter the number of players (2-4): ");
    scanf("%d", &numPlayers);
    while(numPlayers < 2 || numPlayers > 4) { // keep prompting until the correct number of players is entered
        printf("Invalid number of players. Enter a number between 2 and 4: ");
        scanf("%d", &numPlayers);
    }
    printf("\n");

    rows = numPlayers + 2; // set the number of rows based on the number of players
    cols = numPlayers + 3; // set the number of columns based on the number of players

    int table[rows][cols]; // create the table array

    // Initialize the table array with zeros
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            table[i][j] = 0;
        }
    }

    // Set the player numbers in the first row of the table
    for(i = 1; i <= numPlayers; i++) {
        table[0][i] = i;
    }

    // Set the player scores in the last row of the table
    for(i = 1; i <= numPlayers; i++) {
        table[rows-1][i] = 0;
    }

    // Set the round numbers in the first column of the table
    for(i = 1; i <= numPlayers+1; i++) {
        table[i][0] = i;
    }

    // Set the multiplier values in the last column of the table
    for(i = 1; i <= numPlayers+1; i++) {
        table[i][cols-1] = 1;
    }

    // Print the initial table
    printf("Initial Table:\n\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%d\t", table[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Play the game
    while(numRounds <= numPlayers * 5) { // play the game for 5 rounds per player
        for(i = 1; i <= numPlayers; i++) { // loop through each player's turn
            int dice = randomNumber(1, 6); // roll the dice
            printf("Player %d rolled a %d\n", i, dice);

            // Update the player's score with the roll of the dice and the multiplier value
            table[rows-1][i] += dice * table[playerTurn+1][cols-1];

            // Update the multiplier value for the next round
            if(table[playerTurn+1][cols-1] < 5) {
                table[playerTurn+2][cols-1] += 1;
            }

            // Print the updated table
            printf("\nUpdated Table:\n\n");
            for(j = 0; j < rows; j++) {
                for(k = 0; k < cols; k++) {
                    printf("%d\t", table[j][k]);
                }
                printf("\n");
            }
            printf("\n");

            // Check if the player has won the game
            if(table[rows-1][i] >= 50) {
                printf("Player %d wins the game!\n", i);
                return 0;
            }

            playerTurn++; // move on to the next player's turn
            if(playerTurn == numPlayers) { // reset playerTurn if all players have had their turn
                playerTurn = 0;
            }
        }
        numRounds++; // move on to the next round
    }

    printf("Game over. No player has won.\n");
    return 0;
}