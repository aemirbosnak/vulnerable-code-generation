//FormAI DATASET v1.0 Category: Poker Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define global variables
char suits[4][9] = {"Hearts", "Diamonds", "Spades", "Clubs"};
char faces[13][6] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
int values[13] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

// Function to shuffle the deck
void shuffleDeck(int deck[][13]) {
    int row, column, temp;
    for (row = 0; row < 4; row++) {
        for (column = 0; column < 13; column++) {
            int randRow = rand() % 4;
            int randColumn = rand() % 13;
            temp = deck[row][column];
            deck[row][column] = deck[randRow][randColumn];
            deck[randRow][randColumn] = temp;
        }
    }
}

// Function to print the deck
void printDeck(int deck[][13]) {
    int row, column;
    for (row = 0; row < 4; row++) {
        for (column = 0; column < 13; column++) {
            printf("%5s of %-8s%c", faces[column], suits[row], (column+1)%4?' ':'\n');
        }
    }
    printf("\n");
}

// Function to deal the initial cards to the player and dealer
void dealCards(int deck[][13], int *playerHand[], int *dealerHand[]) {
    int playerCount = 0, dealerCount = 0;
    while (playerCount < 2) {
        for (int row = 0; row < 4; row++) {
            for (int column = 0; column < 13; column++) {
                if (deck[row][column] != 0) {
                    if (playerCount == 0) {
                        playerHand[playerCount++] = &values[column];
                    } else if (playerCount == 1) {
                        playerHand[playerCount++] = &values[column];
                        return;
                    }
                }
            }
        }
    }

    while (dealerCount < 2) {
        for (int row = 0; row < 4; row++) {
            for (int column = 0; column < 13; column++) {
                if (deck[row][column] != 0) {
                    if (dealerCount == 0) {
                        dealerHand[dealerCount++] = &values[column];
                    } else if (dealerCount == 1) {
                        dealerHand[dealerCount++] = &values[column];
                        return;
                    }
                }
            }
        }
    }
}

// Function to check if a player has a blackjack
int checkBlackjack(int *hand[]) {
    int total = 0;
    if (*hand[0] == 11 && *hand[1] == 10) {
        return 1;
    } else if (*hand[0] == 10 && *hand[1] == 11) {
        return 1;
    } else {
        return 0;
    }
}

// Function to calculate the total value of a hand
int calculateTotal(int *hand[]) {
    int total = 0, aces = 0;
    for (int i = 0; i < 2; i++) {
        if (*hand[i] == 11) {
            aces++;
        }
        total += *hand[i];
    }
    if (aces > 0 && total > 21) {
        for (int i = 0; i < aces; i++) {
            total -= 10;
            if (total <= 21) {
                break;
            }
        }
    }
    return total;
}

// Function for player's turn
void playerTurn(int deck[][13], int *playerHand[]) {
    char choice;
    int total = calculateTotal(playerHand);
    printf("Your current hand: %d\n", total);
    while (total <= 21) {
        printf("Would you like to hit (h) or stand (s)? ");
        scanf(" %c", &choice);
        if (choice == 'h') {
            for (int row = 0; row < 4; row++) {
                for (int column = 0; column < 13; column++) {
                    if (deck[row][column] != 0 && *playerHand[0] != 0) {
                        playerHand[2] = &values[column];
                        deck[row][column] = 0;
                        total = calculateTotal(playerHand);
                        printf("Your current hand: %d\n", total);
                        break;
                    } else if (deck[row][column] == 0) {
                        continue;
                    }
                }
                if (playerHand[2] != 0) {
                    break;
                }
            }
        } else if (choice == 's') {
            printf("You have chosen to stand.\n");
            return;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }
    printf("Bust! Your total is now %d.\n", total);
    return;
}

// Function for dealer's turn
void dealerTurn(int deck[][13], int *dealerHand[]) {
    int total = calculateTotal(dealerHand);
    printf("Dealer's current hand: %d\n", total);
    while (total < 17) {
        for (int row = 0; row < 4; row++) {
            for (int column = 0; column < 13; column++) {
                if (deck[row][column] != 0 && *dealerHand[0] != 0) {
                    dealerHand[2] = &values[column];
                    deck[row][column] = 0;
                    total = calculateTotal(dealerHand);
                    printf("Dealer's current hand: %d\n", total);
                    break;
                } else if (deck[row][column] == 0) {
                    continue;
                }
            }
            if (dealerHand[2] != 0) {
                break;
            }
        }
    }
    if (total > 21) {
        printf("Dealer busts! Their total is now %d.\n", total);
    } else {
        printf("Dealer stands with a total of %d.\n", total);
    }
    return;
}

// Function to declare the winner
void declareResult(int *playerHand[], int *dealerHand[]) {
    int playerTotal = calculateTotal(playerHand);
    int dealerTotal = calculateTotal(dealerHand);
    if (dealerTotal > 21) {
        printf("You have won!\n");
    } else if (playerTotal > dealerTotal && playerTotal <= 21) {
        printf("You have won!\n");
    } else if (playerTotal == dealerTotal) {
        printf("It's a tie.\n");
    } else {
        printf("Dealer wins. Better luck next time!\n");
    }
}

// Function to play the game
void playGame() {
    srand(time(NULL));
    int deck[4][13], *playerHand[3] = {0}, *dealerHand[3] = {0};
    for (int row = 0; row < 4; row++) {
        for (int column = 0; column < 13; column++) {
            deck[row][column] = values[column];
        }
    }
    shuffleDeck(deck);
    dealCards(deck, playerHand, dealerHand);
    printf("Dealer's upcard: %s of %s\n", faces[0], suits[0]);
    int blackjack = checkBlackjack(playerHand);
    printf("Your hand: ");
    for (int i = 0; i < 2; i++) {
        printf("%s of %s ", faces[i], suits[0]);
    }
    printf("\n");
    if (blackjack == 1) {
        printf("Blackjack! You win!\n");
        return;
    } else {
        playerTurn(deck, playerHand);
        dealerTurn(deck, dealerHand);
        declareResult(playerHand, dealerHand);
    }
}

// Main function to run the game
int main() {
    char choice;
    do {
        printf("Welcome to the C Poker Game!\n");
        printf("Press any key to start a new game or 'q' to quit.\n");
        scanf(" %c", &choice);
        if (choice != 'q') {
            playGame();
        } else {
            printf("Thanks for playing!\n");
            return 0;
        }
    } while (choice != 'q');
    return 0;
}