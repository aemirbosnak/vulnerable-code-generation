//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
    int player1Score = 0, player2Score = 0;
    
    printf("Welcome to the C Table Game!\n");
    
    while (player1Score < 10 && player2Score < 10) {
        printf("Player 1's turn: ");
        int choice = scanf("%d", &player1Score);
        
        if (choice == 1) {
            player1Score += 1;
            printf("Player 1's score: %d\n", player1Score);
        } else if (choice == 2) {
            player1Score += 2;
            printf("Player 1's score: %d\n", player1Score);
        } else if (choice == 3) {
            player1Score += 3;
            printf("Player 1's score: %d\n", player1Score);
        } else if (choice == 4) {
            player1Score += 4;
            printf("Player 1's score: %d\n", player1Score);
        } else if (choice == 5) {
            player1Score += 5;
            printf("Player 1's score: %d\n", player1Score);
        } else if (choice == 6) {
            player1Score += 6;
            printf("Player 1's score: %d\n", player1Score);
        } else if (choice == 7) {
            player1Score += 7;
            printf("Player 1's score: %d\n", player1Score);
        } else if (choice == 8) {
            player1Score += 8;
            printf("Player 1's score: %d\n", player1Score);
        } else if (choice == 9) {
            player1Score += 9;
            printf("Player 1's score: %d\n", player1Score);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
        
        printf("Player 2's turn: ");
        int choice2 = scanf("%d", &player2Score);
        
        if (choice2 == 1) {
            player2Score += 1;
            printf("Player 2's score: %d\n", player2Score);
        } else if (choice2 == 2) {
            player2Score += 2;
            printf("Player 2's score: %d\n", player2Score);
        } else if (choice2 == 3) {
            player2Score += 3;
            printf("Player 2's score: %d\n", player2Score);
        } else if (choice2 == 4) {
            player2Score += 4;
            printf("Player 2's score: %d\n", player2Score);
        } else if (choice2 == 5) {
            player2Score += 5;
            printf("Player 2's score: %d\n", player2Score);
        } else if (choice2 == 6) {
            player2Score += 6;
            printf("Player 2's score: %d\n", player2Score);
        } else if (choice2 == 7) {
            player2Score += 7;
            printf("Player 2's score: %d\n", player2Score);
        } else if (choice2 == 8) {
            player2Score += 8;
            printf("Player 2's score: %d\n", player2Score);
        } else if (choice2 == 9) {
            player2Score += 9;
            printf("Player 2's score: %d\n", player2Score);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    
    if (player1Score > player2Score) {
        printf("Player 1 wins!\n");
    } else if (player1Score < player2Score) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }
    
    return 0;
}