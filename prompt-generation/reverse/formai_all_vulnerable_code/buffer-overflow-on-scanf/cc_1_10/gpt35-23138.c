//FormAI DATASET v1.0 Category: Poker Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int rank;
    int suit;
} Card;

void shuffle(Card *deck);
void deal(Card *deck, int num_players);
void display(Card *cards, int num_cards);

int main() {
    srand(time(NULL));

    Card deck[52];
    int num_players;

    printf("Welcome to the Surrealist Poker Game!\n");
    printf("How many players will be joining the game?\n");
    scanf("%d", &num_players);

    if (num_players < 1) {
        printf("Sorry, we need at least one player to start the game.\n");
        return 0;
    }

    printf("Let the game begin!\n");

    //Initialize the deck 
    for (int i = 0; i < 52; i++) {
        deck[i].rank = (i % 13) + 1;
        deck[i].suit = i / 13;
    }

    shuffle(deck);
    deal(deck, num_players);

    printf("Thanks for playing the Surrealist Poker Game! May your dreams be filled with wild cards.\n");

    return 0;
}

void shuffle(Card *deck) {
    //Fisher-Yates shuffle algorithm
    for (int i = 51; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal(Card *deck, int num_players) {
    int num_cards = 5;
    Card hands[num_players][num_cards];

    //Distribute cards to players
    for (int i = 0; i < num_cards; i++) {
        for (int j = 0; j < num_players; j++) {
            hands[j][i] = deck[(i * num_players) + j];
        }
    }

    //Display each player's hand
    for (int i = 0; i < num_players; i++) {
        printf("\nPlayer %d's hand:\n", i+1);
        display(hands[i], num_cards);
    }
}

void display(Card *cards, int num_cards) {
    char *rank_list[] = {"Ace", "King", "Queen", "Jack", "Ten", "Nine", "Eight", "Seven", "Six", "Five", "Four", "Three", "Two"};
    char *suit_list[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    for (int i = 0; i < num_cards; i++) {
        printf("\t%s of %s\n", rank_list[cards[i].rank-1], suit_list[cards[i].suit]);
    }
}