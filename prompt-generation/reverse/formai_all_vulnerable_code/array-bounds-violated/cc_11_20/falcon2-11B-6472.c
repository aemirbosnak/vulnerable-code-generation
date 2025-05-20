//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize the deck of cards
    int deck[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int n = sizeof(deck) / sizeof(deck[0]);
    
    // Shuffle the deck
    srand(time(NULL));
    for (int i = 0; i < n - 1; i++) {
        int j = rand() % (i + 1);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
    
    // Print the initial deck of cards
    printf("Initial deck of cards:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", deck[i]);
    }
    printf("\n");
    
    // Game loop
    int turn = 0;
    int player1_score = 0;
    int player2_score = 0;
    while (turn < n) {
        // Player 1's turn
        int p1_guess = 0;
        while (p1_guess!= 1 && p1_guess!= 2) {
            printf("Player 1, make a guess: ");
            scanf("%d", &p1_guess);
        }
        
        if (p1_guess == 1) {
            turn++;
        } else {
            // Check if the guess is correct
            if (deck[p1_guess - 1] == deck[turn]) {
                printf("Correct!\n");
                player1_score++;
            } else {
                printf("Incorrect!\n");
            }
        }
        
        // Player 2's turn
        int p2_guess = 0;
        while (p2_guess!= 1 && p2_guess!= 2) {
            printf("Player 2, make a guess: ");
            scanf("%d", &p2_guess);
        }
        
        if (p2_guess == 1) {
            turn++;
        } else {
            // Check if the guess is correct
            if (deck[p2_guess - 1] == deck[turn]) {
                printf("Correct!\n");
                player2_score++;
            } else {
                printf("Incorrect!\n");
            }
        }
    }
    
    // End of game
    printf("Game over!\n");
    printf("Player 1 score: %d\n", player1_score);
    printf("Player 2 score: %d\n", player2_score);
    
    return 0;
}