//FormAI DATASET v1.0 Category: Dice Roller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
    return rand() % 6 + 1;
}

void printDice(int value) {
    printf("+-----+\n");
    printf("|     |\n");
    printf("|  %d  |\n", value);
    printf("|     |\n");
    printf("+-----+\n");
}

int main() {
    // Seed the random number generator.
    srand(time(NULL));
    
    // Initialize the players.
    int numPlayers;
    printf("How many players? ");
    scanf("%d", &numPlayers);
    int players[numPlayers];
    for (int i = 0; i < numPlayers; i++) {
        players[i] = 0;
        printf("Player %d is ready!\n", i + 1);
    }
    
    // Play the game.
    int currentPlayer = 0;
    while (1) {
        printf("\nPlayer %d's turn! Press enter to roll the dice.\n", currentPlayer + 1);
        getchar();
        
        int roll = rollDice();
        printf("You rolled a %d!\n", roll);
        printDice(roll);
        
        players[currentPlayer] += roll;
        printf("Your total score is %d.\n", players[currentPlayer]);
        
        if (players[currentPlayer] >= 20) {
            printf("Player %d wins!\n", currentPlayer + 1);
            break;
        }
        
        currentPlayer = (currentPlayer + 1) % numPlayers;
    }
    
    return 0;
}