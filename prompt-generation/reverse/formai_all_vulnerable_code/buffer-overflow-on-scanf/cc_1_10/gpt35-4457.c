//FormAI DATASET v1.0 Category: Poker Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct card {
    char face; // Face value of the card (A, J, Q, K, or 2-10)
    char suit; // Suit of the card (C, D, H, or S)
};

void shuffle(struct card deck[]) {
    int i, j;
    struct card temp;
    srand(time(NULL));
    for (i = 0; i < 52; i++) {
        j = rand() % 52;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal(struct card deck[], struct card hand[], int *cardIndex) {
    hand[*cardIndex] = deck[*cardIndex];
    (*cardIndex)++;
}

int evaluate(struct card hand[]) {
    int i, value = 0, aces = 0;
    for (i = 0; i < 5; i++) {
        if (hand[i].face == 'A') {
            aces++;
        }
        else if (hand[i].face == 'J' || hand[i].face == 'Q' || hand[i].face == 'K') {
            value += 10;
        }
        else {
            value += hand[i].face - '0';
        }
    }
    while (aces > 0) {
        if (value + 11 <= 21) {
            value += 11;
        }
        else {
            value += 1;
        }
        aces--;
    }
    return value;
}

int main() {
    struct card deck[52] = {
        {'A', 'C'}, {'2', 'C'}, {'3', 'C'}, {'4', 'C'}, {'5', 'C'}, {'6', 'C'}, {'7', 'C'}, {'8', 'C'}, {'9', 'C'}, {'1', 'C'}, {'J', 'C'}, {'Q', 'C'}, {'K', 'C'},
        {'A', 'D'}, {'2', 'D'}, {'3', 'D'}, {'4', 'D'}, {'5', 'D'}, {'6', 'D'}, {'7', 'D'}, {'8', 'D'}, {'9', 'D'}, {'1', 'D'}, {'J', 'D'}, {'Q', 'D'}, {'K', 'D'},
        {'A', 'H'}, {'2', 'H'}, {'3', 'H'}, {'4', 'H'}, {'5', 'H'}, {'6', 'H'}, {'7', 'H'}, {'8', 'H'}, {'9', 'H'}, {'1', 'H'}, {'J', 'H'}, {'Q', 'H'}, {'K', 'H'},
        {'A', 'S'}, {'2', 'S'}, {'3', 'S'}, {'4', 'S'}, {'5', 'S'}, {'6', 'S'}, {'7', 'S'}, {'8', 'S'}, {'9', 'S'}, {'1', 'S'}, {'J', 'S'}, {'Q', 'S'}, {'K', 'S'}
    };
    struct card playerHand[5], dealerHand[5];
    int cardIndex = 0, playerValue, dealerValue, betAmount, playerBalance = 100;
    char choice;
    printf("Welcome to the C Poker Game!\n");
    while (playerBalance > 0) {
        printf("\nYour current balance is $%d\n", playerBalance);
        do {
            printf("Enter your bet amount (minimum $5): ");
            scanf("%d", &betAmount);
        } while (betAmount < 5 || betAmount > playerBalance);
        playerBalance -= betAmount;
        shuffle(deck);
        deal(deck, playerHand, &cardIndex);
        deal(deck, dealerHand, &cardIndex);
        deal(deck, playerHand, &cardIndex);
        deal(deck, dealerHand, &cardIndex);
        playerValue = evaluate(playerHand);
        dealerValue = evaluate(dealerHand);
        printf("\nDealer's hand: %c%c %c?\n", dealerHand[0].face, dealerHand[0].suit, (dealerHand[1].face == 'A' || dealerHand[1].face == '1') ? '1' : '?');
        printf("Your hand: %c%c %c%c\n", playerHand[0].face, playerHand[0].suit, playerHand[1].face, playerHand[1].suit);
        if (playerValue == 21) {
            printf("Blackjack! You win $%d\n", betAmount * 2);
            playerBalance += betAmount * 2;
            continue;
        }
        while (1) {
            printf("Do you want to hit or stand? ");
            scanf(" %c", &choice);
            if (choice == 'h') {
                deal(deck, playerHand, &cardIndex);
                playerValue = evaluate(playerHand);
                printf("Your hand: ");
                for (int i = 0; i < 5; i++) {
                    if (playerHand[i].face != '\0') {
                        printf("%c%c ", playerHand[i].face, playerHand[i].suit);
                    }
                }
                printf("\n");
                if (playerValue > 21) {
                    printf("You bust! You lose $%d\n", betAmount);
                    break;
                }
            }
            else {
                printf("Dealer's hand: %c%c %c%c\n", dealerHand[0].face, dealerHand[0].suit, dealerHand[1].face, dealerHand[1].suit);
                while (dealerValue <= 16) {
                    deal(deck, dealerHand, &cardIndex);
                    dealerValue = evaluate(dealerHand);
                }
                if (dealerValue > 21 || playerValue > dealerValue) {
                    printf("You win $%d\n", betAmount * 2);
                    playerBalance += betAmount * 2;
                }
                else if (playerValue == dealerValue) {
                    printf("Push. You get your bet amount back.\n");
                    playerBalance += betAmount;
                }
                else {
                    printf("You lose $%d\n", betAmount);
                }
                break;
            }
        }
    }
    printf("Game over! You ran out of money.\n");
    return 0;
}