//FormAI DATASET v1.0 Category: Table Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Wacky Table Game!\n");
    printf("You are playing against the quirky computer. Good luck!\n\n");

    // initialize variables
    int total = 0;
    int player_score = 0;
    int computer_score = 0;
    char hit_or_stand = 'h';
    
    // loop until someone wins or there's a tie
    while (total < 21) {
        printf("Your total score is: %d\n", player_score);
        printf("Your hand is: \n");

        // generate random numbers for player's hand
        srand(time(NULL));
        int card1 = rand() % 10 + 1;
        int card2 = rand() % 10 + 1;
        printf("%d %d\n", card1, card2);
        
        // add the two cards to the total and ask player to hit or stand
        total = card1 + card2;
        printf("Do you want to hit (h) or stand (s)? ");
        scanf(" %c", &hit_or_stand);
        
        // if player chooses to hit, generate another random card and add to total
        while (hit_or_stand == 'h') {
            int card = rand() % 10 + 1;
            printf("You drew: %d\n", card);
            total += card;
            printf("Your total is now: %d\n", total);

            if (total > 21) {
                printf("You busted! You lose this round.\n");
                computer_score += 1;
                break;
            } else if (total == 21) {
                printf("Twenty-one! You win this round!\n");
                player_score += 1;
                break;
            } else {
                printf("Do you want to hit (h) or stand (s)? ");
                scanf(" %c", &hit_or_stand);
            }
        }
        
        // if player chooses to stand, generate computer's hand and add to total
        if (hit_or_stand == 's') {
            int computer_card1 = rand() % 10 + 1;
            int computer_card2 = rand() % 10 + 1;
            printf("\nComputer's hand is: %d %d\n", computer_card1, computer_card2);
            int computer_total = computer_card1 + computer_card2;
            
            while (computer_total <= 16) {
                int computer_card = rand() % 10 + 1;
                computer_total += computer_card;
                printf("Computer drew: %d\n", computer_card);
                printf("Computer's total is now: %d\n", computer_total);
            }
            
            if (computer_total > 21) {
                printf("Computer busted! You win this round!\n");
                player_score += 1;
            } else if (computer_total > total) {
                printf("Computer wins this round!\n");
                computer_score += 1;
            } else if (total > computer_total) {
                printf("You win this round!\n");
                player_score += 1;
            } else {
                printf("It's a tie!\n");
            }
            
            printf("Press enter to play another round...\n");
            getchar();
            total = 0;
        }
    }
    
    // declare the winner
    if (player_score > computer_score) {
        printf("Congratulations! You beat the computer %d to %d!\n", player_score, computer_score);
    } else if (player_score < computer_score) {
        printf("Sorry, you lost to the computer %d to %d.\n", computer_score, player_score);
    } else {
        printf("It's a tie! Nobody wins.\n");
    }
    
    printf("Thanks for playing the Wacky Table Game!\n");
    
    return 0;
}