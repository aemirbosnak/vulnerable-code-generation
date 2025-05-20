//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BALLS 75
#define NUM_PLAYERS 100

typedef struct {
    int player_id;
    int num_balls[NUM_BALLS];
} Player;

Player players[NUM_PLAYERS];
int ball_num[NUM_BALLS];
int ball_drawn[NUM_BALLS];

void initialize_balls() {
    for (int i = 1; i <= NUM_BALLS; i++) {
        srand(time(0));
        ball_num[i] = rand() % 75 + 1;
    }
}

void print_balls() {
    for (int i = 1; i <= NUM_BALLS; i++) {
        printf("%d ", ball_num[i]);
    }
    printf("\n");
}

void initialize_players() {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        players[i].player_id = i + 1;
        for (int j = 1; j <= NUM_BALLS; j++) {
            players[i].num_balls[j] = 0;
        }
    }
}

void print_players() {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d: ", i + 1);
        for (int j = 1; j <= NUM_BALLS; j++) {
            printf("%d ", players[i].num_balls[j]);
        }
        printf("\n");
    }
}

void draw_ball() {
    srand(time(0));
    int num = rand() % NUM_BALLS + 1;
    ball_drawn[num] = 1;
}

void check_bingo() {
    int player_id = -1;
    int balls_drawn = 0;
    for (int i = 0; i < NUM_PLAYERS; i++) {
        if (players[i].num_balls[ball_drawn[1]] == 1 && players[i].num_balls[ball_drawn[2]] == 1 && players[i].num_balls[ball_drawn[3]] == 1) {
            player_id = i + 1;
            balls_drawn = 3;
        }
    }
    if (player_id!= -1) {
        printf("Bingo! Player %d wins!\n", player_id);
    } else {
        printf("No winner this round.\n");
    }
}

int main() {
    initialize_balls();
    print_balls();
    initialize_players();
    print_players();
    for (int i = 0; i < NUM_BALLS; i++) {
        draw_ball();
        if (ball_drawn[i]) {
            printf("Ball %d drawn!\n", i + 1);
        }
    }
    check_bingo();
    return 0;
}