//FormAI DATASET v1.0 Category: Poker Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 6
#define MAX_CARDS 52

const char *ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

typedef struct {
    int rank;
    int suit;
} Card;

typedef struct {
    Card cards[2];
    int chips;
} Player;

typedef struct {
    Card cards[5];
} Hand;

int deck[MAX_CARDS];
Player players[MAX_PLAYERS];
Hand table;

// Function prototypes
void shuffle_deck();
void deal_cards();
void print_card(Card);
void print_hand(Hand);
void take_turn(int);
int evaluate_hand(Hand);
void payout(int);

int main(void) {
    int num_players = 0;
    int winner = -1;

    printf("Welcome to C Poker!\n\n");
    printf("How many players (up to %d)? ", MAX_PLAYERS);
    scanf("%d", &num_players);

    if (num_players < 2 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    srand(time(NULL));

    // Initialize players with empty hand and starting chips
    for (int i = 0; i < num_players; i++) {
        players[i].chips = 1000;
    }

    while (1) {
        // Shuffle deck and deal cards
        shuffle_deck();
        deal_cards();

        // Players take turns betting and discarding
        for (int i = 0; i < num_players; i++) {
            take_turn(i);
        }

        // Showdown - evaluate hands and determine winner
        printf("\nShowdown!\nTable:");
        print_hand(table);

        int best_hand = -1;
        int max_value = 0;

        for (int i = 0; i < num_players; i++) {
            Hand hand;
            hand.cards[0] = players[i].cards[0];
            hand.cards[1] = players[i].cards[1];
            hand.cards[2] = table.cards[0];
            hand.cards[3] = table.cards[1];
            hand.cards[4] = table.cards[2];

            int value = evaluate_hand(hand);
            printf("\nPlayer %d:", i + 1);
            print_hand(hand);

            if (value > max_value) {
                max_value = value;
                best_hand = i;
            }
        }

        printf("\nPlayer %d wins the pot!\n\n", best_hand + 1);
        payout(best_hand);

        // Check if any players have run out of chips
        int remaining_players = 0;

        for (int i = 0; i < num_players; i++) {
            if (players[i].chips > 0) {
                remaining_players++;
                winner = i;
            }
        }

        if (remaining_players < 2) {
            break;
        }
    }

    printf("\nThe game is over. ");
    
    if (winner >= 0) {
        printf("Player %d has won!", winner + 1);
    } else {
        printf("There is no winner.");
    }

    return 0;
}

void shuffle_deck() {
    for (int i = 0; i < MAX_CARDS; i++) {
        deck[i] = i;
    }

    for (int i = 0; i < MAX_CARDS - 1; i++) {
        int j = i + rand() / (RAND_MAX / (MAX_CARDS - i) + 1);
        int temp = deck[j];
        deck[j] = deck[i];
        deck[i] = temp;
    }
}

void deal_cards() {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < MAX_PLAYERS; j++) {
            players[j].cards[i].rank = deck[2*j+i] % 13;
            players[j].cards[i].suit = deck[2*j+i] / 13;
        }
    }

    for (int i = 0; i < 5; i++) {
        table.cards[i].rank = deck[MAX_PLAYERS*2+i] % 13;
        table.cards[i].suit = deck[MAX_PLAYERS*2+i] / 13;
    }
}

void print_card(Card card) {
    printf("%s of %s", ranks[card.rank], suits[card.suit]);
}

void print_hand(Hand hand) {
    for (int i = 0; i < 5; i++) {
        printf(" ");
        print_card(hand.cards[i]);
    }
}

void take_turn(int player) {
    int choice = 0;
    int bet = 0;

    printf("\nPlayer %d's turn - current bet: %d\n", player + 1, players[player].chips);

    printf("1) Bet\n2) Discard\nChoice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("How much to bet? ");
        scanf("%d", &bet);

        if (bet > players[player].chips) {
            printf("You do not have enough chips to make that bet.\n");
            bet = 0;
        } else {
            players[player].chips -= bet;
            printf("Player %d bets %d.\n", player + 1, bet);
        }
    } else if (choice == 2) {
        printf("Which card(s) to discard (enter 1 to 5, separated by spaces)? ");
        int c1, c2, c3, c4, c5;
        scanf("%d %d %d %d %d", &c1, &c2, &c3, &c4, &c5);

        // Replace discarded cards with new ones from the deck
        int discard[] = {c1, c2, c3, c4, c5};
        for (int i = 0; i < 5; i++) {
            if (discard[i] > 0 && discard[i] < 6) {
                players[player].cards[discard[i] - 1].rank = deck[MAX_PLAYERS*2+i+1] % 13;
                players[player].cards[discard[i] - 1].suit = deck[MAX_PLAYERS*2+i+1] / 13;
                printf("Player %d discards:", player + 1);
                print_card(players[player].cards[discard[i] - 1]);
                printf("\n");
            }
        }
    }
}

int evaluate_hand(Hand hand) {
    int rank_count[13] = {0};
    int suit_count[4] = {0};
    int pairs = 0;
    int three_of_a_kind = 0;
    int straight = 0;
    int flush = 0;

    // Count ranks and suits
    for (int i = 0; i < 5; i++) {
        rank_count[hand.cards[i].rank]++;
        suit_count[hand.cards[i].suit]++;
    }

    // Check for pairs, three of a kind, and four of a kind
    for (int i = 0; i < 13; i++) {
        if (rank_count[i] == 2) {
            pairs++;
        } else if (rank_count[i] == 3) {
            three_of_a_kind = 1;
        } else if (rank_count[i] == 4) {
            return 7; // Four of a kind
        }
    }

    // Check for full house
    if (pairs == 1 && three_of_a_kind == 1) {
        return 6;
    }

    // Check for flush
    for (int i = 0; i < 4; i++) {
        if (suit_count[i] == 5) {
            flush = 1;
        }
    }

    // Check for straight
    for (int i = 0; i < 9; i++) {
        if (rank_count[i] == 1 && rank_count[i + 1] == 1 &&
            rank_count[i + 2] == 1 && rank_count[i + 3] == 1 &&
            rank_count[i + 4] == 1) {
            straight = 1;
        }
    }

    // Check for straight flush
    if (flush == 1 && straight == 1) {
        return 8;
    }

    if (flush == 1) {
        return 5;
    }

    if (straight == 1) {
        return 4;
    }

    if (three_of_a_kind == 1) {
        return 3;
    }

    if (pairs == 2) {
        return 2;
    }

    if (pairs == 1) {
        return 1;
    }

    return 0;
}

void payout(int winner) {
    int pot = 0;

    for (int i = 0; i < MAX_PLAYERS; i++) {
        pot += players[i].chips;
        players[i].chips = 0;
    }

    players[winner].chips = pot;
}