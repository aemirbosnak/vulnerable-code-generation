//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>

#define MAX_CARDS 20
#define MAX_PLAYERS 4

typedef struct {
    char name[32];
    int score;
} player_t;

typedef struct {
    int value;
    int matched;
} card_t;

void shuffle_cards(card_t *cards, int num_cards)
{
    int i, j, k;
    for (i = 0; i < num_cards; i++) {
        j = rand() % num_cards;
        k = cards[i].value;
        cards[i].value = cards[j].value;
        cards[j].value = k;
    }
}

int main(void)
{
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    card_t cards[MAX_CARDS];
    player_t players[MAX_PLAYERS];
    int num_cards, num_players;
    char input[128];
    int turn;
    int card1, card2;
    int score;
    int winner;

    srand(time(NULL));

    printf("Welcome to the Memory Game!\n");
    printf("How many cards do you want to play with (2-20)? ");
    scanf("%d", &num_cards);
    while (num_cards < 2 || num_cards > 20) {
        printf("Invalid number of cards. Please enter a number between 2 and 20: ");
        scanf("%d", &num_cards);
    }

    printf("How many players are playing (1-4)? ");
    scanf("%d", &num_players);
    while (num_players < 1 || num_players > 4) {
        printf("Invalid number of players. Please enter a number between 1 and 4: ");
        scanf("%d", &num_players);
    }

    for (i = 0; i < num_players; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    for (i = 0; i < num_cards; i++) {
        cards[i].value = i + 1;
        cards[i].matched = 0;
    }

    shuffle_cards(cards, num_cards);

    turn = 0;

    while (1) {
        printf("\nIt is %s's turn.\n", players[turn].name);
        printf("Enter the number of the first card you want to flip: ");
        scanf("%d", &card1);
        while (card1 < 1 || card1 > num_cards || cards[card1 - 1].matched) {
            printf("Invalid card number. Please enter a number between 1 and %d: ", num_cards);
            scanf("%d", &card1);
        }

        printf("Enter the number of the second card you want to flip: ");
        scanf("%d", &card2);
        while (card2 < 1 || card2 > num_cards || cards[card2 - 1].matched || card1 == card2) {
            printf("Invalid card number. Please enter a number between 1 and %d: ", num_cards);
            scanf("%d", &card2);
        }

        cards[card1 - 1].matched = 1;
        cards[card2 - 1].matched = 1;

        if (cards[card1 - 1].value == cards[card2 - 1].value) {
            printf("You matched a pair of cards!\n");
            players[turn].score += 2;
        } else {
            printf("You did not match a pair of cards.\n");
            turn = (turn + 1) % num_players;
        }

        for (i = 0; i < num_cards; i++) {
            if (cards[i].matched) {
                printf("  ");
            } else {
                printf("%2d  ", i + 1);
            }
            if ((i + 1) % 5 == 0) {
                printf("\n");
            }
        }

        score = 0;
        for (i = 0; i < num_players; i++) {
            score += players[i].score;
        }
        if (score == num_cards * 2) {
            winner = (turn + 1) % num_players;
            printf("\n%s wins the game!\n", players[winner].name);
            break;
        }

        turn = (turn + 1) % num_players;
    }

    return 0;
}