//FormAI DATASET v1.0 Category: Poker Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random card number
int random_card() {
    int card;
    srand(time(NULL));
    card = rand() % 13 + 1;
    return card;
}

// Function to print the card
void print_card(int card) {
    switch (card) {
        case 1:
            printf("Ace ");
            break;
        case 11:
            printf("Jack ");
            break;
        case 12:
            printf("Queen ");
            break;
        case 13:
            printf("King ");
            break;
        default:
            printf("%d ", card);
            break;
    }
}

int main() {
    // Declare variables
    int player1_card1, player1_card2, player2_card1, player2_card2;
    int player1_total = 0, player2_total = 0;
    char player1_choice, player2_choice;

    // Draw cards for player 1
    player1_card1 = random_card();
    player1_card2 = random_card();
    // Draw cards for player 2
    player2_card1 = random_card();
    player2_card2 = random_card();

    // Print the cards for each player
    printf("Player 1: ");
    print_card(player1_card1);
    print_card(player1_card2);
    printf("\n");

    printf("Player 2: ");
    print_card(player2_card1);
    print_card(player2_card2);
    printf("\n");

    // Calculate the total for each player
    player1_total = player1_card1 + player1_card2;
    player2_total = player2_card1 + player2_card2;

    // Ask each player if they want to draw another card
    printf("Player 1, do you want to draw another card? (y/n): ");
    scanf("%c", &player1_choice);

    printf("Player 2, do you want to draw another card? (y/n): ");
    scanf(" %c", &player2_choice);

    if (player1_choice == 'y') {
        int player1_card3 = random_card();
        player1_total += player1_card3;
        printf("Player 1 drew ");
        print_card(player1_card3);
        printf("\n");
    }

    if (player2_choice == 'y') {
        int player2_card3 = random_card();
        player2_total += player2_card3;
        printf("Player 2 drew ");
        print_card(player2_card3);
        printf("\n");
    }

    // Print the final total for each player
    printf("Player 1 total: %d\n", player1_total);
    printf("Player 2 total: %d\n", player2_total);

    // Determine the winner
    if (player1_total > player2_total) {
        printf("Player 1 wins!\n");
    } else if (player2_total > player1_total) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}