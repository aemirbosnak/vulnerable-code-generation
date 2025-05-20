//FormAI DATASET v1.0 Category: Table Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Returns the player that wins based on the sum of their cards
char check_winner(int player1_score, int player2_score){
    if(player1_score == player2_score){
        return 'D'; // Draw
    }else if(player1_score > 21 && player2_score > 21){
        return 'D'; // Both players bust
    }else if(player1_score > 21){
        return 'B'; // Player 2 wins due to player 1 bust
    }else if(player2_score > 21){
        return 'A'; // Player 1 wins due to player 2 bust
    }else if(player1_score > player2_score){
        return 'A'; // Player 1 wins
    }else{
        return 'B'; // Player 2 wins
    }
}

int main(){
    int player1_score = 0, player2_score = 0;
    int player1_cards[5] = {0}, player2_cards[5] = {0};

    printf("*** Welcome to the C Table Game! ***\n");

    // Player 1's turn
    printf("\nPlayer 1's turn:\n");
    for(int i=0; i<2; i++){
        int card = rand() % 10 + 1;
        player1_score += card;
        player1_cards[i] = card;
    }
    printf("Player 1's cards: ");
    for(int i=0; i<2; i++){
        printf("%d ", player1_cards[i]);
    }
    printf("\nPlayer 1's score: %d\n", player1_score);

    // Player 2's turn
    printf("\nPlayer 2's turn:\n");
    for(int i=0; i<2; i++){
        int card = rand() % 10 + 1;
        player2_score += card;
        player2_cards[i] = card;
    }
    printf("Player 2's cards: ");
    for(int i=0; i<2; i++){
        printf("%d ", player2_cards[i]);
    }
    printf("\nPlayer 2's score: %d\n", player2_score);

    // Ask players if they want to draw another card
    int player1_choice = 0, player2_choice = 0;
    do{
        printf("\nPlayer 1, do you want to draw another card? (1: Yes / 0: No): ");
        scanf("%d", &player1_choice);
        if(player1_choice == 1){
            int card = rand() % 10 + 1;
            player1_score += card;
            for(int i=0; i<5; i++){
                if(player1_cards[i] == 0){
                    player1_cards[i] = card; // Add card to player's hand
                    break;
                }
            }
            printf("Player 1's cards: ");
            for(int i=0; i<5; i++){
                if(player1_cards[i] != 0){
                    printf("%d ", player1_cards[i]); // Print player's cards
                }
            }
            printf("\nPlayer 1's score: %d\n", player1_score);
        }
    }while(player1_choice != 0);

    do{
        printf("\nPlayer 2, do you want to draw another card? (1: Yes / 0: No): ");
        scanf("%d", &player2_choice);
        if(player2_choice == 1){
            int card = rand() % 10 + 1;
            player2_score += card;
            for(int i=0; i<5; i++){
                if(player2_cards[i] == 0){
                    player2_cards[i] = card; // Add card to player's hand
                    break;
                }
            }
            printf("Player 2's cards: ");
            for(int i=0; i<5; i++){
                if(player2_cards[i] != 0){
                    printf("%d ", player2_cards[i]); // Print player's cards
                }
            }
            printf("\nPlayer 2's score: %d\n", player2_score);
        }
    }while(player2_choice != 0);

    // Determine the winner
    char winner = check_winner(player1_score, player2_score);
    if(winner == 'D'){
        printf("\nIt's a draw!");
    }else if(winner == 'A'){
        printf("\nPlayer 1 wins!");
    }else{
        printf("\nPlayer 2 wins!");
    }

    return 0;
}