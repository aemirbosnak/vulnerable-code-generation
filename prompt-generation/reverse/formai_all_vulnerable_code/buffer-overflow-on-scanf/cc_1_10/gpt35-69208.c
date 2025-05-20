//FormAI DATASET v1.0 Category: Poker Game ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int deck[52];
    char suits[4][10] = {"Hearts", "Clubs", "Diamonds", "Spades"};
    char ranks[13][10] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    int i, j, k, drawn, p1_score, p2_score, winner;
    int p1_card1, p1_card2, p1_card3, p2_card1, p2_card2, p2_card3;
    char p1_name[20], p2_name[20];
    
    // Get Player Names
    printf("Welcome to the C Poker Game!\n");
    printf("Enter Player 1 Name: ");
    scanf("%s", p1_name);
    printf("Enter Player 2 Name: ");
    scanf("%s", p2_name);
    printf("\n");
    
    // Shuffle Deck
    srand(time(NULL));
    for(i=0; i<52; i++) {
        deck[i] = i;
    }
    for(i=0; i<52; i++) {
        j = rand() % 52;
        k = deck[i];
        deck[i] = deck[j];
        deck[j] = k;
    }
    
    // Draw Cards
    drawn = 0;
    p1_card1 = deck[drawn++];
    p1_card2 = deck[drawn++];
    p2_card1 = deck[drawn++];
    p2_card2 = deck[drawn++];
    
    // Print Initial Cards
    printf("%s's Cards: %s of %s, %s of %s\n", p1_name, ranks[p1_card1%13], suits[p1_card1/13], ranks[p1_card2%13], suits[p1_card2/13]);
    printf("%s's Cards: %s of %s, %s of %s\n", p2_name, ranks[p2_card1%13], suits[p2_card1/13], ranks[p2_card2%13], suits[p2_card2/13]);
    printf("\n");
    
    // Prompt Players to Draw Third Card
    printf("%s: Draw a Third Card? (1 for Yes, 0 for No) ", p1_name);
    scanf("%d", &p1_card3);
    printf("%s: Draw a Third Card? (1 for Yes, 0 for No) ", p2_name);
    scanf("%d", &p2_card3);
    printf("\n");
    
    // Determine Player Scores
    p1_score = (p1_card1%13 + p1_card2%13 + p1_card3%13)%10;
    p2_score = (p2_card1%13 + p2_card2%13 + p2_card3%13)%10;
    
    // Print Player Scores
    printf("%s's Score: %d\n", p1_name, p1_score);
    printf("%s's Score: %d\n", p2_name, p2_score);
    printf("\n");
    
    // Determine Winner
    if(p1_score > p2_score) {
        winner = 1;
    } else if(p2_score > p1_score) {
        winner = 2;
    } else {
        winner = 0;
    }
    
    // Print Winner
    if(winner == 1) {
        printf("%s Wins!\n", p1_name);
    } else if(winner == 2) {
        printf("%s Wins!\n", p2_name);
    } else {
        printf("It's a Tie!\n");
    }
    
    return 0;
}