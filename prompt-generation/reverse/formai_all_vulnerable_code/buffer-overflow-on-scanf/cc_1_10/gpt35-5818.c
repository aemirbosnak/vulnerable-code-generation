//FormAI DATASET v1.0 Category: Poker Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5
#define NUM_SUITS 4
#define NUM_RANKS 13

const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
const char *ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

typedef struct card {
    int value;
    int suit;
} Card;

void shuffle_deck(Card deck[]);
void print_hand(Card hand[]);
void print_card(Card card);
int calculate_hand(Card hand[]);
void sort_hand(Card hand[]);
int get_rank_counts(Card hand[]);
int is_straight(Card hand[]);
int is_flush(Card hand[]);
int is_straight_flush(Card hand[]);
int is_royal_flush(Card hand[]);

int main() {
    srand(time(NULL));

    Card deck[DECK_SIZE];
    Card hand[HAND_SIZE];
    int menu_choice, hand_value;

    do {
        printf("Poker Menu\n");
        printf("1. Play a hand\n");
        printf("2. Exit\n");
        printf("Choice: ");
        scanf("%d", &menu_choice);

        switch(menu_choice) {
            case 1:
                shuffle_deck(deck);

                for(int i = 0;i < HAND_SIZE;i++) {
                    hand[i] = deck[i];
                }

                hand_value = calculate_hand(hand);
                printf("\nYour hand: ");
                print_hand(hand);
                printf("Value: %d\n", hand_value);

                if(hand_value == 10) {
                    printf("Royal Flush!\n");
                } else if(hand_value == 9) {
                    printf("Straight Flush!\n");
                } else if(hand_value == 8) {
                    printf("Four of a Kind!\n");
                } else if(hand_value == 7) {
                    printf("Full House!\n");
                } else if(hand_value == 6) {
                    printf("Flush!\n");
                } else if(hand_value == 5) {
                    printf("Straight!\n");
                } else if(hand_value == 4) {
                    printf("Three of a Kind!\n");
                } else if(hand_value == 3) {
                    printf("Two Pair!\n");
                } else if(hand_value == 2) {
                    printf("Pair!\n");
                } else {
                    printf("High Card.\n");
                }

                break;
            case 2:
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while(menu_choice != 2);

    return 0;
}

void shuffle_deck(Card deck[]) {
    for(int i = DECK_SIZE - 1;i >= 0;i--) {
        int j = rand() % (i + 1);
        Card temp = deck[j];
        deck[j] = deck[i];
        deck[i] = temp;
    }
}

void print_hand(Card hand[]) {
    for(int i = 0;i < HAND_SIZE;i++) {
        print_card(hand[i]);
        printf(" ");
    }

    printf("\n");
}

void print_card(Card card) {
    printf("%s of %s", ranks[card.value], suits[card.suit]);
}

int calculate_hand(Card hand[]) {
    sort_hand(hand);

    if(is_royal_flush(hand)) {
        return 10;
    } else if(is_straight_flush(hand)) {
        return 9;
    } else if(get_rank_counts(hand) == 4) {
        return 8;
    } else if(get_rank_counts(hand) == 3 && is_pair(hand)) {
        return 7;
    } else if(is_flush(hand)) {
        return 6;
    } else if(is_straight(hand)) {
        return 5;
    } else if(get_rank_counts(hand) == 3) {
        return 4;
    } else if(get_rank_counts(hand) == 2 && is_pair(hand)) {
        return 3;
    } else if(get_rank_counts(hand) == 2) {
        return 2;
    } else {
        return 1;
    }
}

void sort_hand(Card hand[]) {
    for(int i = 0;i < HAND_SIZE;i++) {
        for(int j = i + 1;j < HAND_SIZE;j++) {
            if(hand[j].value < hand[i].value) {
                Card temp = hand[i];
                hand[i] = hand[j];
                hand[j] = temp;
            }
        }
    }
}

int get_rank_counts(Card hand[]) {
    int counts[NUM_RANKS] = {0};

    for(int i = 0;i < HAND_SIZE;i++) {
        counts[hand[i].value]++;
    }

    int max_count = 0;

    for(int i = 0;i < NUM_RANKS;i++) {
        if(counts[i] > max_count) {
            max_count = counts[i];
        }
    }

    return max_count;
}

int is_pair(Card hand[]) {
    int counts[NUM_RANKS] = {0};

    for(int i = 0;i < HAND_SIZE;i++) {
        counts[hand[i].value]++;
    }

    int pairs = 0;

    for(int i = 0;i < NUM_RANKS;i++) {
        if(counts[i] == 2) {
            pairs++;
        }
    }

    return pairs == 1;
}

int is_straight(Card hand[]) {
    int sequence_length = 0;

    for(int i = 0;i < HAND_SIZE - 1;i++) {
        if(hand[i].value + 1 == hand[i + 1].value) {
            sequence_length++;
        } else {
            sequence_length = 0;
        }

        if(sequence_length == 4) {
            return 1;
        }
    }

    return 0;
}

int is_flush(Card hand[]) {
    int suit_counts[NUM_SUITS] = {0};

    for(int i = 0;i < HAND_SIZE;i++) {
        suit_counts[hand[i].suit]++;
    }

    for(int i = 0;i < NUM_SUITS;i++) {
        if(suit_counts[i] == HAND_SIZE) {
            return 1;
        }
    }

    return 0;
}

int is_straight_flush(Card hand[]) {
    return is_flush(hand) && is_straight(hand);
}

int is_royal_flush(Card hand[]) {
    return is_straight_flush(hand) && hand[0].value == 0 && hand[1].value == 9;
}