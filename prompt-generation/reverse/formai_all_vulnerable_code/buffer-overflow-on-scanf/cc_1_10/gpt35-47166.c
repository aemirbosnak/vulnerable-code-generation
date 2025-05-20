//FormAI DATASET v1.0 Category: Poker Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HAND_SIZE 5

typedef enum {CLUBS, DIAMONDS, HEARTS, SPADES} Suit;
typedef enum {ACE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING} Rank;

typedef struct {
    Suit suit;
    Rank rank;
} Card;

typedef struct {
    Card hand[HAND_SIZE];
    int score;
} Player;

void playGame();
void printCard(Card card);
void printHand(Player player);
void shuffleDeck(Card deck[]);
void dealCards(Player players[], int numPlayers, Card deck[]);
void computeScore(Player *player);

int main() {
    playGame();
    return 0;
}

void playGame() {
    srand(time(NULL));
    int numPlayers;
    printf("Enter number of players: ");
    scanf("%d", &numPlayers);
    while (numPlayers <= 0) {
        printf("Invalid number of players, please enter a positive integer: ");
        scanf("%d", &numPlayers);
    }
    Card deck[52];
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            deck[i*4+j].rank = i+1;
            deck[i*4+j].suit = j;
        }
    }
    shuffleDeck(deck);
    Player players[numPlayers];
    for (int i = 0; i < numPlayers; i++) {
        players[i].score = 0;
    }
    dealCards(players, numPlayers, deck);
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d's hand:\n", i+1);
        printHand(players[i]);
        computeScore(&players[i]);
        printf("Player %d's score: %d\n", i+1, players[i].score);
    }
}

void printCard(Card card) {
    switch(card.rank) {
        case 1:
            printf("Ace");
            break;
        case 2:
            printf("Two");
            break;
        case 3:
            printf("Three");
            break;
        case 4:
            printf("Four");
            break;
        case 5:
            printf("Five");
            break;
        case 6:
            printf("Six");
            break;
        case 7:
            printf("Seven");
            break;
        case 8:
            printf("Eight");
            break;
        case 9:
            printf("Nine");
            break;
        case 10:
            printf("Ten");
            break;
        case 11:
            printf("Jack");
            break;
        case 12:
            printf("Queen");
            break;
        case 13:
            printf("King");
            break;
    }
    switch(card.suit) {
        case CLUBS:
            printf(" of Clubs\n");
            break;
        case DIAMONDS:
            printf(" of Diamonds\n");
            break;
        case HEARTS:
            printf(" of Hearts\n");
            break;
        case SPADES:
            printf(" of Spades\n");
            break;
    }
}

void printHand(Player player) {
    for (int i = 0; i < HAND_SIZE; i++) {
        printCard(player.hand[i]);
    }
}

void shuffleDeck(Card deck[]) {
    for (int i = 51; i >= 0; i--) {
        int j = rand() % (i+1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCards(Player players[], int numPlayers, Card deck[]) {
    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < HAND_SIZE; j++) {
            players[i].hand[j] = deck[i*HAND_SIZE+j];
        }
    }
}

void computeScore(Player *player) {
    int score = 0;
    int pairs = 0;
    int threeOfAKind = 0;
    int fourOfAKind = 0;
    int straight = 0;
    int flush = 0;
    int straightFlush = 0;
    int royalFlush = 0;
    int suitCount[4] = {0};
    int rankCount[13] = {0};
    for (int i = 0; i < HAND_SIZE; i++) {
        rankCount[player->hand[i].rank-1]++;
        suitCount[player->hand[i].suit]++;
    }
    for (int i = 0; i < 4; i++) {
        if (suitCount[i] == 5) {
            flush = 1;
            break;
        }
    }
    for (int i = 0; i < 13; i++) {
        if (rankCount[i] == 2) {
            pairs++;
        }
        if (rankCount[i] == 3) {
            threeOfAKind = 1;
        }
        if (rankCount[i] == 4) {
            fourOfAKind = 1;
        }
        if (i <= 8 && rankCount[i] == 1 && rankCount[i+1] == 1 && rankCount[i+2] == 1 && rankCount[i+3] == 1 && rankCount[i+4] == 1) {
            straight = 1;
            break;
        }
        if (i == 9 && rankCount[i] == 1 && rankCount[i+1] == 1 && rankCount[i+2] == 1 && rankCount[i+3] == 1 && rankCount[0] == 1) {
            straight = 1;
            break;
        }
    }
    if (flush && straight) {
        straightFlush = 1;
        if (player->hand[0].rank == ACE && player->hand[1].rank == TEN && player->hand[2].rank == JACK && player->hand[3].rank == QUEEN && player->hand[4].rank == KING) {
            royalFlush = 1;
        }
    }
    if (royalFlush) {
        score = 100;
    } else if (straightFlush) {
        score = 50;
    } else if (fourOfAKind) {
        score = 25;
    } else if (threeOfAKind && pairs == 1) {
        score = 10;
    } else if (flush) {
        score = 6;
    } else if (straight) {
        score = 5;
    } else if (threeOfAKind) {
        score = 3;
    } else if (pairs == 2) {
        score = 2;
    } else if (pairs == 1) {
        score = 1;
    }
    player->score = score;
}