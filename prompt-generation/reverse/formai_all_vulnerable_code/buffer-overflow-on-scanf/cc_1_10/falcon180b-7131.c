//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 100
#define MAX_PLAYERS 10
#define MAX_BALLS 100

typedef struct {
    int num;
    int marked;
} Card;

typedef struct {
    int id;
    int cards[MAX_CARDS];
    int balls[MAX_BALLS];
} Player;

Card cards[MAX_CARDS];
Player players[MAX_PLAYERS];

void init_cards() {
    int i;
    for (i = 0; i < MAX_CARDS; i++) {
        cards[i].num = i + 1;
        cards[i].marked = 0;
    }
}

void init_player(int id) {
    int i;
    for (i = 0; i < MAX_CARDS; i++) {
        players[id].cards[i] = 0;
    }
    for (i = 0; i < MAX_BALLS; i++) {
        players[id].balls[i] = 0;
    }
}

void draw_ball() {
    int num = rand() % MAX_CARDS + 1;
    printf("Ball %d drawn\n", num);
}

void mark_card(int num) {
    int i;
    for (i = 0; i < MAX_PLAYERS; i++) {
        if (players[i].cards[num - 1]) {
            players[i].cards[num - 1] = 1;
        }
    }
}

int check_winner() {
    int i;
    for (i = 0; i < MAX_PLAYERS; i++) {
        int count = 0;
        int j;
        for (j = 0; j < MAX_CARDS; j++) {
            if (players[i].cards[j]) {
                count++;
            }
        }
        if (count == 5) {
            return i + 1;
        }
    }
    return 0;
}

int main() {
    int num_players, winner;
    srand(time(NULL));

    printf("Welcome to Bingo Simulator!\n");
    printf("How many players? ");
    scanf("%d", &num_players);

    init_cards();

    for (int i = 0; i < num_players; i++) {
        init_player(i + 1);
    }

    int balls_drawn = 0;
    while (balls_drawn < MAX_BALLS) {
        draw_ball();
        mark_card(cards[balls_drawn].num);
        balls_drawn++;
    }

    winner = check_winner();

    if (winner) {
        printf("Player %d wins!\n", winner);
    } else {
        printf("No winner.\n");
    }

    return 0;
}