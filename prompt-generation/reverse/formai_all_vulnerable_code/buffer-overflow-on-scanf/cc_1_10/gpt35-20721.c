//FormAI DATASET v1.0 Category: Poker Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random card
int generateCard() {
    int card = (rand() % 13) + 1;
    return card;
}

// Function to determine the value of a card
int cardValue(int card) {
    if (card <= 10) {
        return card;
    }
    else if (card >= 11 && card <= 13) {
        return 10;
    }
    else if (card == 1) {
        return 11;
    }
}

int main() {
    // Initialize variables
    int player1Cards[10], player2Cards[10], player1Score = 0, player2Score = 0, player1CardsDrawn = 0, player2CardsDrawn = 0, card;
    char player1[20], player2[20];
    srand(time(NULL));
    
    // Get player names
    printf("Enter Player 1's name: ");
    scanf("%s", player1);
    printf("Enter Player 2's name: ");
    scanf("%s", player2);
    
    printf("\n");

    // Player 1's turn
    printf("%s's turn:\n", player1);
    card = generateCard();
    player1Cards[player1CardsDrawn] = card;
    player1Score += cardValue(card);
    player1CardsDrawn++;
    printf("Card Drawn: %d\n", card);
    printf("Score: %d\n", player1Score);

    // Player 2's turn
    printf("\n%s's turn:\n", player2);
    card = generateCard();
    player2Cards[player2CardsDrawn] = card;
    player2Score += cardValue(card);
    player2CardsDrawn++;
    printf("Card Drawn: %d\n", card);
    printf("Score: %d\n", player2Score);

    // Player 1's turn
    printf("\n%s's turn:\n", player1);
    card = generateCard();
    player1Cards[player1CardsDrawn] = card;
    player1Score += cardValue(card);
    player1CardsDrawn++;
    printf("Card Drawn: %d\n", card);
    printf("Score: %d\n", player1Score);

    // Player 2's turn
    printf("\n%s's turn:\n", player2);
    card = generateCard();
    player2Cards[player2CardsDrawn] = card;
    player2Score += cardValue(card);
    player2CardsDrawn++;
    printf("Card Drawn: %d\n", card);
    printf("Score: %d\n", player2Score);

    // Check for blackjack
    if (player1Score == 21) {
        printf("\n%s wins with Blackjack!", player1);
    }
    else if (player2Score == 21) {
        printf("\n%s wins with Blackjack!", player2);
    }
    else {
        // Player 1's turn
        printf("\n%s's turn:\n", player1);
        while (player1Score <= 21) {
            char choice;
            printf("Do you want to hit or stand (h/s)? ");
            scanf(" %c", &choice);
            if (choice == 'h') {
                card = generateCard();
                player1Cards[player1CardsDrawn] = card;
                player1Score += cardValue(card);
                player1CardsDrawn++;
                printf("Card Drawn: %d\n", card);
                printf("Score: %d\n", player1Score);
            }
            else {
                break;
            }
        }

        // Player 2's turn
        printf("\n%s's turn:\n", player2);
        while (player2Score <= 21) {
            char choice;
            printf("Do you want to hit or stand (h/s)? ");
            scanf(" %c", &choice);
            if (choice == 'h') {
                card = generateCard();
                player2Cards[player2CardsDrawn] = card;
                player2Score += cardValue(card);
                player2CardsDrawn++;
                printf("Card Drawn: %d\n", card);
                printf("Score: %d\n", player2Score);
            }
            else {
                break;
            }
        }

        // Determine winner
        if (player1Score > 21 && player2Score > 21) {
            printf("\nIt's a tie!");
        }
        else if (player1Score > 21) {
            printf("\n%s wins with a score of %d!", player2, player2Score);
        }
        else if (player2Score > 21) {
            printf("\n%s wins with a score of %d!", player1, player1Score);
        }
        else if (player1Score > player2Score) {
            printf("\n%s wins with a score of %d!", player1, player1Score);
        }
        else if (player2Score > player1Score) {
            printf("\n%s wins with a score of %d!", player2, player2Score);
        }
        else {
            printf("\nIt's a tie!");
        }
    }

    return 0;
}