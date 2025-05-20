//FormAI DATASET v1.0 Category: Poker Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 6   // maximum allowed players in this game
#define HAND_SIZE 5     // number of cards in each player's hand
#define NUM_SUITS 4     // number of different suits in a deck
#define NUM_RANKS 13    // number of different ranks in a deck

#define SPADES 0
#define HEARTS 1
#define DIAMONDS 2
#define CLUBS 3

#define ACE 0
#define JACK 10
#define QUEEN 11
#define KING 12

// structure representing the cards of each player
typedef struct {
    int hand[HAND_SIZE];
    int score;
} Player;


// function to check if a card is already in a hand
int contains_card(Player p, int card) {
    for (int i = 0; i < HAND_SIZE; i++) {
        if (p.hand[i] == card) {
            return 1;
        }
    }
    return 0;
}

// function to initialize the deck
int *init_deck() {
    static int deck[NUM_SUITS * NUM_RANKS];
    for (int i = 0; i < NUM_SUITS; i++) {
        for (int j = 0; j < NUM_RANKS; j++) {
            deck[NUM_RANKS*i + j] = j;
        }
    }
    return deck;
}

// function to shuffle the deck
void shuffle_deck(int *deck) {
    srand(time(0)); // seed the random number generator
    for (int i = 0; i < NUM_SUITS * NUM_RANKS; i++) {
        int j = rand() % (NUM_SUITS * NUM_RANKS);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// function to deal cards to players
void deal_cards(int *deck, Player *players, int num_players) {
    for (int i = 0; i < num_players; i++) {
        for (int j = 0; j < HAND_SIZE; j++) {
            int card = rand() % (NUM_SUITS * NUM_RANKS);
            while (contains_card(players[i], card)) {
                card = rand() % (NUM_SUITS * NUM_RANKS);
            }
            players[i].hand[j] = deck[card];
        }
    }
}

// function to remove a card from a player's hand
void remove_card(Player *p, int card) {
    for (int i = 0; i < HAND_SIZE; i++) {
        if (p->hand[i] == card) {
            p->hand[i] = -1;
            break;
        }
    }
}

// function to determine the value of a player's hand
int hand_value(Player p) {
    int value = 0;
    int num_aces = 0;
    for (int i = 0; i < HAND_SIZE; i++) {
        int rank = p.hand[i] % NUM_RANKS;
        if (rank == ACE) {
            num_aces++;
        } else if (rank >= JACK && rank <= KING) {
            value += 10;
        } else {
            value += rank + 1;
        }
    }
    while (num_aces > 0 && value + 11 <= 21) {
        value += 11;
        num_aces--;
    }
    value += num_aces;
    return value;
}

// function to print a player's hand
void print_hand(Player p) {
    for (int i = 0; i < HAND_SIZE; i++) {
        if (p.hand[i] == -1) {
            printf(" - ");
        } else {
            int suit = p.hand[i] / NUM_RANKS;
            int rank = p.hand[i] % NUM_RANKS;
            printf(" %c%c", rank == ACE ? 'A' : rank == JACK ? 'J' : rank == QUEEN ? 'Q' : rank == KING ? 'K' : '1' + rank, suit == SPADES ? 'S' : suit == HEARTS ? 'H' : suit == DIAMONDS ? 'D' : 'C');
        }
    }
}

// function to play a round of the game
void play_round(Player *players, int num_players) {
    // allow each player to take their turn
    for (int i = 0; i < num_players; i++) {
        printf("\n\nPlayer %d's turn:\n", i+1);
        print_hand(players[i]);
        int choice = 0;
        while (1) {
            printf("\n\nDo you want to hit (1) or stay (2)? ");
            scanf("%d", &choice);
            if (choice == 1) {
                int card = rand() % (NUM_SUITS * NUM_RANKS);
                while (contains_card(players[i], card)) {
                    card = rand() % (NUM_SUITS * NUM_RANKS);
                }
                players[i].hand[HAND_SIZE-1] = card;
                printf("\n\nPlayer %d drew:", i+1);
                print_hand(players[i]);
                if (hand_value(players[i]) > 21) {
                    printf("\n\nPlayer %d busts!", i+1);
                    break;
                }
            } else {
                printf("\n\nPlayer %d stays.", i+1);
                break;
            }
        }
    }

    // determine the winner(s) of the round
    int winner_scores[MAX_PLAYERS];
    int num_winners = 0;
    int best_score = 0;
    for (int i = 0; i < num_players; i++) {
        players[i].score = hand_value(players[i]);
        if (players[i].score <= 21) {
            if (players[i].score > best_score) {
                best_score = players[i].score;
                num_winners = 1;
                winner_scores[0] = i;
            } else if (players[i].score == best_score) {
                winner_scores[num_winners] = i;
                num_winners++;
            }
        }
    }
    printf("\n\nThe round is over.\n");
    if (num_winners == 0) {
        printf("No winners this round.\n");
    } else {
        printf("Winner(s):");
        for (int i = 0; i < num_winners; i++) {
            printf(" Player %d", winner_scores[i] + 1);
        }
        printf("\n");
    }

    // remove all cards from each player's hand
    for (int i = 0; i < num_players; i++) {
        for (int j = 0; j < HAND_SIZE; j++) {
            int card = players[i].hand[j];
            if (card != -1) {
                remove_card(&players[i], card);
            }
        }
    }
}

int main() {
    int num_players;
    do {
        printf("How many players? (1-%d) ", MAX_PLAYERS);
        scanf("%d", &num_players);
    } while (num_players < 1 || num_players > MAX_PLAYERS);

    // initialize the deck and shuffle it
    int *deck = init_deck();
    shuffle_deck(deck);

    while (1) {
        Player players[MAX_PLAYERS];
        deal_cards(deck, players, num_players);
        play_round(players, num_players);

        int play_again = 0;
        printf("\n\nDo you want to play again? (1 for yes, 0 for no) ");
        scanf("%d", &play_again);
        if (play_again == 0) {
            break;
        }
    }

    return 0;
}