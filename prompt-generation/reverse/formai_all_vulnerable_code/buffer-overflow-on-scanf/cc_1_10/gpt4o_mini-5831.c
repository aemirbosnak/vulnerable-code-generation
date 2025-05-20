//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BITS 8

void displayBits(int num);
int playerTurn(int playerNum);
void showResults(int player1, int player2);

int main() {
    int player1 = 0, player2 = 0;
    int turn = 0;

    srand(time(0));  // Seed for random numbers

    printf("Welcome to Bitwise Battles!\n");
    printf("Two players will battle by setting bits in a byte (8 bits).\n");
    printf("The player with the highest remaining bits wins!\n\n");

    while (1) {
        printf("Current Scores:\n");
        printf("Player 1: ");
        displayBits(player1);
        printf("Player 2: ");
        displayBits(player2);

        // Player 1's turn
        player1 |= playerTurn(1);
        
        // Check if player 1 loses
        if (player1 == 0) {
            printf("Player 1 has no bits left! Player 2 wins!\n");
            break;
        }

        // Player 2's turn
        player2 |= playerTurn(2);

        // Check if player 2 loses
        if (player2 == 0) {
            printf("Player 2 has no bits left! Player 1 wins!\n");
            break;
        }
    }

    return 0;
}

void displayBits(int num) {
    for (int i = MAX_BITS - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int playerTurn(int playerNum) {
    int action;
    int bitPosition;

    printf("Player %d's turn:\n", playerNum);
    printf("Choose an action:\n");
    printf("1. Set a bit\n");
    printf("2. Clear a bit\n");
    printf("3. Toggle a bit\n");
    printf("4. Not (Invert the number)\n");
    printf("5. Shift left (<<)\n");
    printf("6. Shift right (>>)\n");
    printf("Enter action [1-6]: ");
    scanf("%d", &action);

    switch (action) {
        case 1:
            printf("Enter bit position to set (0-7): ");
            scanf("%d", &bitPosition);
            return (1 << bitPosition);  // Set the bit
        case 2:
            printf("Enter bit position to clear (0-7): ");
            scanf("%d", &bitPosition);
            return ~(1 << bitPosition);  // Clear the bit
        case 3:
            printf("Enter bit position to toggle (0-7): ");
            scanf("%d", &bitPosition);
            return (1 << bitPosition) ^ (1 << bitPosition);  // Toggle the bit
        case 4:
            printf("Applying NOT operation...\n");
            return ~0;  // Invert all bits (assuming a byte for simplicity)
        case 5:
            printf("Shifting left...\n");
            return (1 << MAX_BITS) - 1;  // Return all bits set as an example
        case 6:
            printf("Shifting right...\n");
            return 0;  // Return 0 as an example
        default:
            printf("Invalid action! Try again.\n");
            return playerTurn(playerNum);  // Retry
    }
}

void showResults(int player1, int player2) {
    printf("\nFinal Results:\n");
    printf("Player 1: ");
    displayBits(player1);
    printf("Player 2: ");
    displayBits(player2);
}