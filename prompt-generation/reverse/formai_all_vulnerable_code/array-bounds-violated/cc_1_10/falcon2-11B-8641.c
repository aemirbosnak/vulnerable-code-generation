//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Player {
    int score;
    char name[50];
} Player;

void play_game(Player p1, Player p2);

int main() {
    srand(time(NULL));

    Player p1 = {0, "Player 1"};
    Player p2 = {0, "Player 2"};

    play_game(p1, p2);

    return 0;
}

void play_game(Player p1, Player p2) {
    int roll;
    int player;
    int score[2] = {0, 0};

    printf("Let's start the game!\n");
    printf("Player %s, roll the dice...\n", p1.name);
    for (int i = 0; i < 2; i++) {
        roll = rand() % 6 + 1;
        printf("You rolled a %d\n", roll);
        score[player] += roll;
        printf("Your score is %d\n", score[player]);
        player = (player + 1) % 2;
    }

    printf("\nPlayer %s, roll the dice...\n", p2.name);
    for (int i = 0; i < 2; i++) {
        roll = rand() % 6 + 1;
        printf("You rolled a %d\n", roll);
        score[player] += roll;
        printf("Your score is %d\n", score[player]);
        player = (player + 1) % 2;
    }

    printf("\nThe scores are:\nPlayer 1: %d\nPlayer 2: %d\n", score[0], score[1]);

    if (score[0] > score[1]) {
        printf("Player 1 wins!\n");
    } else if (score[0] < score[1]) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }
}