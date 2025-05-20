//FormAI DATASET v1.0 Category: Poker Game ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to get a random number between min and max inclusive
int get_random(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to get the rank of a card
int get_rank(int card) {
    return card % 13 + 2;
}

// Function to get the suit of a card
char get_suit(int card) {
    switch(card / 13) {
        case 0:
            return 'C';
        case 1:
            return 'D';
        case 2:
            return 'H';
        case 3:
            return 'S';
    }
}

// Function to print the cards in a hand
void print_hand(int hand[], int count) {
    printf("Your hand:");
    for(int i=0; i<count; i++) {
        printf(" %d%c", get_rank(hand[i]), get_suit(hand[i]));
    }
    printf("\n");
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Welcome message
    printf("Welcome to the C Poker Game!\n");
    
    // Generate 5 random cards for the player's hand
    int player_hand[5];
    for(int i=0; i<5; i++) {
        player_hand[i] = get_random(0, 51);
    }
    
    // Print the player's hand
    print_hand(player_hand, 5);
    
    // Prompt the player to discard cards
    printf("How many cards would you like to discard? (0-5): ");
    int discard_count;
    scanf("%d", &discard_count);
    
    if(discard_count > 0) {
        // Discard the selected cards and draw new ones
        for(int i=0; i<discard_count; i++) {
            printf("Which card would you like to discard? (1-5): ");
            int discard_index;
            scanf("%d", &discard_index);
            
            player_hand[discard_index-1] = get_random(0, 51);
        }
        
        // Print the new hand
        print_hand(player_hand, 5);
    }
    
    // Determine the rank of the player's hand
    int rank = -1;
    // Check for Royal Flush
    if(get_rank(player_hand[0])==10 && get_rank(player_hand[1])==11 && 
       get_rank(player_hand[2])==12 && get_rank(player_hand[3])==13 && 
       get_rank(player_hand[4])==14 && get_suit(player_hand[0])==get_suit(player_hand[1]) &&
       get_suit(player_hand[1])==get_suit(player_hand[2]) && get_suit(player_hand[2])==get_suit(player_hand[3]) && 
       get_suit(player_hand[3])==get_suit(player_hand[4])) {
           rank = 10;
    } 
    // Check for Straight Flush
    else if((get_rank(player_hand[0])+1)==get_rank(player_hand[1]) && 
            (get_rank(player_hand[1])+1)==get_rank(player_hand[2]) && 
            (get_rank(player_hand[2])+1)==get_rank(player_hand[3]) && 
            (get_rank(player_hand[3])+1)==get_rank(player_hand[4]) && 
            get_suit(player_hand[0])==get_suit(player_hand[1]) &&
            get_suit(player_hand[1])==get_suit(player_hand[2]) && 
            get_suit(player_hand[2])==get_suit(player_hand[3]) && 
            get_suit(player_hand[3])==get_suit(player_hand[4])) {
                rank = 9;
    }
    // Check for Four of a Kind
    else if((get_rank(player_hand[0])==get_rank(player_hand[1]) && get_rank(player_hand[1])==get_rank(player_hand[2]) && get_rank(player_hand[2])==get_rank(player_hand[3])) ||
           (get_rank(player_hand[1])==get_rank(player_hand[2]) && get_rank(player_hand[2])==get_rank(player_hand[3]) && get_rank(player_hand[3])==get_rank(player_hand[4]))) {
               rank = 8;
    }
    // Check for Full House
    else if((get_rank(player_hand[0])==get_rank(player_hand[1]) && get_rank(player_hand[1])==get_rank(player_hand[2]) && get_rank(player_hand[3])==get_rank(player_hand[4])) ||
           (get_rank(player_hand[0])==get_rank(player_hand[1]) && get_rank(player_hand[2])==get_rank(player_hand[3]) && get_rank(player_hand[3])==get_rank(player_hand[4]))) {
               rank = 7;
    }
    // Check for Flush
    else if(get_suit(player_hand[0])==get_suit(player_hand[1]) && 
            get_suit(player_hand[1])==get_suit(player_hand[2]) && 
            get_suit(player_hand[2])==get_suit(player_hand[3]) && 
            get_suit(player_hand[3])==get_suit(player_hand[4])) {
                rank = 6;
    }
    // Check for Straight
    else if((get_rank(player_hand[0])+1)==get_rank(player_hand[1]) && 
            (get_rank(player_hand[1])+1)==get_rank(player_hand[2]) && 
            (get_rank(player_hand[2])+1)==get_rank(player_hand[3]) && 
            (get_rank(player_hand[3])+1)==get_rank(player_hand[4])) {
                rank = 5;
    }
    // Check for Three of a Kind
    else if((get_rank(player_hand[0])==get_rank(player_hand[1]) && get_rank(player_hand[1])==get_rank(player_hand[2])) ||
           (get_rank(player_hand[1])==get_rank(player_hand[2]) && get_rank(player_hand[2])==get_rank(player_hand[3])) ||
           (get_rank(player_hand[2])==get_rank(player_hand[3]) && get_rank(player_hand[3])==get_rank(player_hand[4]))) {
               rank = 4;
    }
    // Check for Two Pair
    else if((get_rank(player_hand[0])==get_rank(player_hand[1]) && get_rank(player_hand[2])==get_rank(player_hand[3])) ||
           (get_rank(player_hand[0])==get_rank(player_hand[1]) && get_rank(player_hand[3])==get_rank(player_hand[4])) ||
           (get_rank(player_hand[1])==get_rank(player_hand[2]) && get_rank(player_hand[3])==get_rank(player_hand[4]))) {
               rank = 3;
    }
    // Check for One Pair
    else if(get_rank(player_hand[0])==get_rank(player_hand[1]) ||
           get_rank(player_hand[1])==get_rank(player_hand[2]) ||
           get_rank(player_hand[2])==get_rank(player_hand[3]) ||
           get_rank(player_hand[3])==get_rank(player_hand[4])) {
               rank = 2;
    }
    // High Card
    else {
        rank = 1;
    }
    
    // Print the rank of the player's hand
    printf("Your hand's rank is: %d\n", rank);
    
    return 0;
}