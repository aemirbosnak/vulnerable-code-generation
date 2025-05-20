//FormAI DATASET v1.0 Category: Poker Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_card(int card) {
    if (card < 11) {
        printf("%d", card);
    } else if (card == 11) {
        printf("J");
    } else if (card == 12) {
        printf("Q");
    } else if (card == 13) {
        printf("K");
    } else {
        printf("A");
    }
}

int draw_card(int used_cards[], int num_used, int deck[]) {
    int card;
    do {
        card = rand() % 13 + 1;
    } while (used_cards[num_used - 1] == card);
    used_cards[num_used] = card;
    deck[card - 1]--;

    return card;
}

int score_hand(int hand[], int num_cards) {
    int score = 0;
    int ace_count = 0;

    for (int i = 0; i < num_cards; i++) {
        if (hand[i] == 1) {
            ace_count++;
            score += 11;
        } else if (hand[i] > 10) {
            score += 10;
        } else {
            score += hand[i];
        }
    }
    while (score > 21 && ace_count > 0) {
        score -= 10;
        ace_count--;
    }

    return score;
}

void print_hand(int hand[], int num_cards) {
    for (int i = 0; i < num_cards; i++) {
        print_card(hand[i]);
        printf(" ");
    }
}

void play_game() {
    // initialize the deck
    int deck[13] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};

    // initialize used cards array
    int used_cards[52];
    int num_used = 0;

    // initialize player and dealer hands
    int player_hand[5];
    int num_player_cards = 0;
    int dealer_hand[5];
    int num_dealer_cards = 0;

    // draw two cards for player
    player_hand[0] = draw_card(used_cards, num_used++, deck);
    num_player_cards++;
    player_hand[1] = draw_card(used_cards, num_used++, deck);
    num_player_cards++;

    // draw one card for dealer
    dealer_hand[0] = draw_card(used_cards, num_used++, deck);
    num_dealer_cards++;

    int player_score = score_hand(player_hand, num_player_cards);
    int dealer_score = score_hand(dealer_hand, num_dealer_cards);

    // player's turn
    printf("Your hand: ");
    print_hand(player_hand, num_player_cards);
    printf("\n");

    while (player_score < 21) {
        printf("Do you want to hit or stand? ");
        char input[10];
        scanf("%s", input);

        if (strcmp(input, "hit") == 0) {
            player_hand[num_player_cards++] = draw_card(used_cards, num_used++, deck);
            player_score = score_hand(player_hand, num_player_cards);
            printf("Your hand: ");
            print_hand(player_hand, num_player_cards);
            printf("\n");
        } else if (strcmp(input, "stand") == 0) {
            break;
        }
    }

    // check if player busted
    if (player_score > 21) {
        printf("You busted! Dealer wins.\n");
        return;
    }

    // dealer's turn
    printf("Dealer's hand: ");
    print_hand(dealer_hand, num_dealer_cards);
    printf("\n");

    while (dealer_score < 17) {
        dealer_hand[num_dealer_cards++] = draw_card(used_cards, num_used++, deck);
        dealer_score = score_hand(dealer_hand, num_dealer_cards);
        printf("Dealer's hand: ");
        print_hand(dealer_hand, num_dealer_cards);
        printf("\n");
    }

    // check if dealer busted
    if (dealer_score > 21) {
        printf("Dealer busted! You win.\n");
        return;
    }

    // compare scores
    if (player_score > dealer_score) {
        printf("You win!\n");
    } else if (dealer_score > player_score) {
        printf("Dealer wins!\n");
    } else {
        printf("It's a tie!\n");
    }
}

int main() {
    printf("Welcome to the Poker Game!\n");

    while (1) {
        printf("Do you want to play a game? ");
        char input[10];
        scanf("%s", input);

        if (strcmp(input, "yes") == 0) {
            play_game();
        } else if (strcmp(input, "quit") == 0) {
            break;
        }
    }

    printf("Thanks for playing!\n");

    return 0;
}