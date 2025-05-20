//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a card
typedef struct {
    char suit;
    char rank;
} Card;

// Structure to represent a hand
typedef struct {
    Card cards[5];
    int score;
} Hand;

// Function to deal a hand
void deal_hand(Hand *hand) {
    int i;
    for (i = 0; i < 5; i++) {
        hand->cards[i] = (Card){rand() % 13 + 'A', rand() % 4 + 'S'};
    }
    hand->score = calculate_hand_score(hand);
}

// Function to calculate the score of a hand
int calculate_hand_score(Hand hand) {
    int straight_flush = false;
    int four_of_a_kind = false;
    int full_house = false;
    int flush = false;
    int straight = false;
    int three_of_a_kind = false;
    int two_pair = false;
    int one_pair = false;
    int high_card = false;

    // Check for straight flush
    for (int i = 0; i < 4 && hand.cards[i].rank == hand.cards[i+1].rank; i++) {
        if (hand.cards[i].suit == hand.cards[i+1].suit) {
            straight_flush = true;
            break;
        }
    }

    // Check for four of a kind
    for (int i = 0; i < 4 && hand.cards[i].rank == hand.cards[i+1].rank; i++) {
        if (hand.cards[i].rank == 'A' && hand.cards[i+1].rank == 'K') {
            four_of_a_kind = true;
            break;
        }
    }

    // Check for full house
    for (int i = 0; i < 4 && hand.cards[i].rank == hand.cards[i+1].rank; i++) {
        if (hand.cards[i].rank == 'A' && hand.cards[i+1].rank == 'K') {
            full_house = true;
            break;
        }
    }

    // Check for flush
    for (int i = 0; i < 4 && hand.cards[i].suit == hand.cards[i+1].suit; i++) {
        flush = true;
        break;
    }

    // Check for straight
    for (int i = 0; i < 5 && hand.cards[i].rank == hand.cards[i+1].rank; i++) {
        straight = true;
        break;
    }

    // Check for three of a kind
    for (int i = 0; i < 4 && hand.cards[i].rank == hand.cards[i+1].rank; i++) {
        if (hand.cards[i].rank == 'A' && hand.cards[i+1].rank == 'K') {
            three_of_a_kind = true;
            break;
        }
    }

    // Check for two pair
    for (int i = 0; i < 4 && hand.cards[i].rank == hand.cards[i+1].rank; i++) {
        if (hand.cards[i].rank == 'A' && hand.cards[i+1].rank == 'K') {
            two_pair = true;
            break;
        }
    }

    // Check for one pair
    for (int i = 0; i < 4 && hand.cards[i].rank == hand.cards[i+1].rank; i++) {
        if (hand.cards[i].rank == 'A' && hand.cards[i+1].rank == 'K') {
            one_pair = true;
            break;
        }
    }

    // Check for high card
    if (straight_flush == false && four_of_a_kind == false && full_house == false && flush == false && straight == false && three_of_a_kind == false && two_pair == false && one_pair == false) {
        high_card = true;
    }

    return (straight_flush? 9 : (four_of_a_kind? 8 : (full_house? 7 : (flush? 6 : (straight? 5 : (three_of_a_kind? 4 : (two_pair? 3 : (one_pair? 2 : 1)))))))) * hand.score;
}

int main() {
    int n;
    printf("Enter number of players: ");
    scanf("%d", &n);

    Hand *hands = malloc(n * sizeof(Hand));
    for (int i = 0; i < n; i++) {
        hands[i].score = 0;
        deal_hand(&hands[i]);
    }

    int max_score = 0;
    int max_score_hand_index = 0;
    for (int i = 0; i < n; i++) {
        if (hands[i].score > max_score) {
            max_score = hands[i].score;
            max_score_hand_index = i;
        }
    }

    printf("Player %d wins with a score of %d\n", max_score_hand_index+1, max_score);

    for (int i = 0; i < n; i++) {
        free(hands[i].cards);
    }
    free(hands);

    return 0;
}