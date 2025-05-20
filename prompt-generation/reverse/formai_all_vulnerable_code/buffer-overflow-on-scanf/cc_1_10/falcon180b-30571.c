//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_CARDS 100
#define MAX_BALLS 75

typedef struct {
    char name[20];
    int score;
} Player;

typedef struct {
    int num;
    char called;
} Ball;

void init_card(int card[5][5]) {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            card[i][j] = -1;
        }
    }
}

void print_card(int card[5][5]) {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%3d ", card[i][j]);
        }
        printf("\n");
    }
}

void generate_ball(Ball ball[MAX_BALLS]) {
    int i;
    for (i = 0; i < MAX_BALLS; i++) {
        ball[i].num = rand() % 75 + 1;
        ball[i].called = 0;
    }
}

int compare_cards(int card1[5][5], int card2[5][5]) {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (card1[i][j]!= card2[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

void play_bingo(int card[MAX_PLAYERS][5][5], Ball ball[MAX_BALLS], Player player[MAX_PLAYERS]) {
    int i, j, k;
    for (k = 0; k < MAX_BALLS; k++) {
        printf("Ball %d: %d\n", k + 1, ball[k].num);
        for (i = 0; i < MAX_PLAYERS; i++) {
            if (player[i].score == 0) {
                continue;
            }
            for (j = 0; j < 5; j++) {
                if (card[i][j][k % 5] == ball[k].num) {
                    card[i][j][k % 5] = -1;
                    player[i].score--;
                }
            }
            if (player[i].score == 0) {
                printf("Player %s wins!\n", player[i].name);
                exit(0);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int i, j, k;
    Player player[MAX_PLAYERS];
    int num_players;
    printf("How many players? ");
    scanf("%d", &num_players);
    for (i = 0; i < num_players; i++) {
        printf("Enter name of player %d: ", i + 1);
        scanf("%s", player[i].name);
        player[i].score = 15;
    }
    int card[MAX_PLAYERS][5][5];
    for (i = 0; i < MAX_PLAYERS; i++) {
        for (j = 0; j < 5; j++) {
            init_card(card[i][j]);
        }
    }
    Ball ball[MAX_BALLS];
    generate_ball(ball);
    play_bingo(card, ball, player);
    return 0;
}