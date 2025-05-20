//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 16
#define NUM_ROWS 4
#define NUM_COLS 4
#define NUM_MATCHES 8

int cards[NUM_CARDS];
int matches[NUM_MATCHES];
char card_images[NUM_CARDS][3];
int num_matches_found;
int num_turns;
int game_over;

void init_cards() {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        cards[i] = i + 1;
    }
}

void shuffle_cards() {
    int i, j, temp;
    srand(time(0));
    for (i = 0; i < NUM_CARDS; i++) {
        j = rand() % NUM_CARDS;
        temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

void print_cards() {
    int i, j;
    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            printf(" %d ", cards[(i * NUM_COLS) + j]);
        }
        printf("\n");
    }
}

void init_game() {
    int i;
    for (i = 0; i < NUM_MATCHES; i++) {
        matches[i] = -1;
    }
    num_matches_found = 0;
    num_turns = 0;
    game_over = 0;
}

void play_turn(int card1, int card2) {
    int i;
    if (card1 == card2) {
        printf("Match found!\n");
        num_matches_found++;
        matches[num_matches_found - 1] = card1;
    } else {
        printf("No match.\n");
        num_turns++;
    }
    if (num_matches_found == NUM_MATCHES) {
        game_over = 1;
    }
}

int main() {
    int i;
    init_cards();
    shuffle_cards();
    init_game();
    print_cards();
    while (!game_over) {
        int card1, card2;
        printf("Enter the numbers of two cards to flip: ");
        scanf("%d %d", &card1, &card2);
        card1--;
        card2--;
        play_turn(card1, card2);
        print_cards();
    }
    printf("Game over. You found %d matches in %d turns.\n", num_matches_found, num_turns);
    return 0;
}