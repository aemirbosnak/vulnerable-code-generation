//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 100
#define MAX_PLAYERS 10
#define MAX_BALLS 75

typedef struct {
    int id;
    char name[20];
} Player;

typedef struct {
    int num;
    char name[20];
} Ball;

void init_players(Player players[], int num_players) {
    for (int i = 0; i < num_players; i++) {
        players[i].id = i;
        printf("Enter name for player %d: ", i);
        scanf("%s", players[i].name);
    }
}

void init_balls(Ball balls[], int num_balls) {
    for (int i = 0; i < num_balls; i++) {
        balls[i].num = i + 1;
        sprintf(balls[i].name, "Ball %d", balls[i].num);
    }
}

void shuffle_balls(Ball balls[], int num_balls) {
    for (int i = 0; i < num_balls; i++) {
        int j = rand() % num_balls;
        Ball temp = balls[i];
        balls[i] = balls[j];
        balls[j] = temp;
    }
}

void draw_ball(Ball ball) {
    printf("%s\n", ball.name);
}

int main() {
    srand(time(NULL));

    Player players[MAX_PLAYERS];
    int num_players;

    printf("Enter number of players: ");
    scanf("%d", &num_players);

    init_players(players, num_players);

    Ball balls[MAX_BALLS];
    int num_balls;

    printf("Enter number of balls: ");
    scanf("%d", &num_balls);

    init_balls(balls, num_balls);

    shuffle_balls(balls, num_balls);

    for (int i = 0; i < num_balls; i++) {
        draw_ball(balls[i]);
    }

    return 0;
}