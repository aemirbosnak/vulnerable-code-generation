//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Memory Game rules:
// 1. The game randomly selects two cards from a deck of cards.
// 2. The player has to guess the card that matches the first card.
// 3. If the player guesses correctly, they get to choose another card from the deck.
// 4. If the player guesses incorrectly, the game ends.

typedef struct {
    int number;
    int color;
} Card;

Card deck[52];
int num_cards = 52;
int current_card = 0;
int player_guess = -1;
int game_over = 0;

void init_deck() {
    srand(time(NULL));
    for (int i = 0; i < num_cards; i++) {
        deck[i].number = rand() % 4 + 1;
        deck[i].color = rand() % 2 + 1;
    }
}

void print_deck() {
    printf("Deck of cards:\n");
    for (int i = 0; i < num_cards; i++) {
        printf("Card %d: %d %d\n", i + 1, deck[i].number, deck[i].color);
    }
}

void print_cards() {
    printf("Current cards:\n");
    printf("Card 1: %d %d\n", deck[current_card].number, deck[current_card].color);
    printf("Card 2: %d %d\n", deck[current_card + 1].number, deck[current_card + 1].color);
}

int get_player_guess() {
    printf("Guess the color of the second card: ");
    scanf("%d", &player_guess);
    return player_guess;
}

int main() {
    init_deck();
    print_deck();
    print_cards();

    int correct_guesses = 0;
    int wrong_guesses = 0;

    while (game_over == 0) {
        player_guess = get_player_guess();

        if (player_guess == deck[current_card + 1].color) {
            printf("Correct!\n");
            correct_guesses++;
            current_card++;
            print_cards();
        } else {
            printf("Wrong!\n");
            wrong_guesses++;
            game_over = 1;
        }
    }

    printf("You made %d correct guesses and %d wrong guesses.\n", correct_guesses, wrong_guesses);

    return 0;
}