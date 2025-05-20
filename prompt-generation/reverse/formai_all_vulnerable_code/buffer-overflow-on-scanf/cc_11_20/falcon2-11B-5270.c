//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Player {
    char name[20];
    int chips;
};

struct Deck {
    int cards[52];
};

struct Hand {
    int value;
    int aces;
};

struct Game {
    struct Deck deck;
    struct Player players[4];
    int playerTurn;
    struct Hand dealerHand;
    struct Hand playerHand[4];
    bool gameInProgress;
};

void dealCards(struct Game* game, struct Player* player, struct Deck* deck) {
    int cardValue = 0;
    for (int i = 0; i < 2; i++) {
        cardValue = rand() % 13 + 1;
        if (cardValue == 1) {
            player->chips--;
            cardValue = 11;
        }
        game->deck.cards[i] = cardValue;
    }
}

int checkWin(struct Game* game, struct Player* player) {
    struct Hand hand = {0, 0};
    for (int i = 0; i < 2; i++) {
        hand.value += game->deck.cards[i];
        if (hand.value > 21 && hand.value!= 22) {
            hand.value = 1;
        }
        if (hand.value > 21 && hand.value == 22) {
            hand.value = 21;
        }
    }
    if (hand.value > 21) {
        return 0;
    } else if (hand.value > 21 && hand.value == 22) {
        return 1;
    } else if (hand.value > 21 && hand.value == 21) {
        return 2;
    } else if (hand.value == 21) {
        return 3;
    } else if (hand.value == 22) {
        return 4;
    } else if (hand.value == 20) {
        return 5;
    } else if (hand.value == 19) {
        return 6;
    } else if (hand.value == 18) {
        return 7;
    } else if (hand.value == 17) {
        return 8;
    } else if (hand.value == 16) {
        return 9;
    } else if (hand.value == 15) {
        return 10;
    } else if (hand.value == 14) {
        return 11;
    } else if (hand.value == 13) {
        return 12;
    } else if (hand.value == 12) {
        return 13;
    } else if (hand.value == 11) {
        return 14;
    } else if (hand.value == 10) {
        return 15;
    } else if (hand.value == 9) {
        return 16;
    } else if (hand.value == 8) {
        return 17;
    } else if (hand.value == 7) {
        return 18;
    } else if (hand.value == 6) {
        return 19;
    } else if (hand.value == 5) {
        return 20;
    } else if (hand.value == 4) {
        return 21;
    } else if (hand.value == 3) {
        return 22;
    } else if (hand.value == 2) {
        return 23;
    } else if (hand.value == 1) {
        return 24;
    }
}

void printCards(struct Player* player) {
    printf("%s's cards: ", player->name);
    for (int i = 0; i < 2; i++) {
        printf("%d ", player->chips);
    }
    printf("\n");
}

int main() {
    struct Game game;
    struct Player player1;
    struct Player player2;
    struct Player player3;
    struct Player player4;
    struct Deck deck;
    int option;
    bool gameOver = false;
    while (!gameOver) {
        printf("1. Deal cards\n2. Check win\n3. Print cards\n4. Exit\n");
        scanf("%d", &option);
        switch (option) {
            case 1:
                dealCards(&game, &player1, &deck);
                dealCards(&game, &player2, &deck);
                dealCards(&game, &player3, &deck);
                dealCards(&game, &player4, &deck);
                break;
            case 2:
                if (checkWin(&game, &player1) || checkWin(&game, &player2) || checkWin(&game, &player3) || checkWin(&game, &player4)) {
                    printf("Player %d wins!\n", player1.chips);
                    gameOver = true;
                }
                break;
            case 3:
                printCards(&player1);
                printCards(&player2);
                printCards(&player3);
                printCards(&player4);
                break;
            case 4:
                gameOver = true;
                break;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    }
    return 0;
}