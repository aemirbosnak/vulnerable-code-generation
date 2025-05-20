//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_CARDS 8

typedef struct Card {
    char suit;
    char number;
} Card;

typedef struct MemoryGame {
    Card cards[MAX_CARDS];
    int cardIndex;
    int turn;
} MemoryGame;

void print_cards(MemoryGame* game) {
    printf("Turn: %d\n", game->turn);
    for (int i = 0; i < MAX_CARDS; i++) {
        if (game->cards[i].suit == 'H' || game->cards[i].suit == 'S') {
            printf("    %-2c%2d\n", game->cards[i].suit, game->cards[i].number);
        }
    }
}

void play_game(MemoryGame* game) {
    for (int turn = 0; turn < MAX_CARDS; turn++) {
        print_cards(game);
        printf("Turn: %d\n", turn);

        if (game->cardIndex >= MAX_CARDS) {
            printf("Game over!\n");
            break;
        }

        if (game->cards[game->cardIndex].suit == 'H' || game->cards[game->cardIndex].suit == 'S') {
            printf("Turn: %d\n", turn);
            printf("Guess the card: ");
            scanf("%c%c", &(game->cards[game->cardIndex].suit), &(game->cards[game->cardIndex].number));
        }

        game->cardIndex++;
    }
}

int main() {
    MemoryGame game = { { 'H', '1' }, 0, 0 };

    play_game(&game);

    return 0;
}