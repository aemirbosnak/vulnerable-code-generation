//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_CARDS 75
#define MAX_BALLS 75

typedef struct {
    int id;
    char name[20];
} Player;

typedef struct {
    int value;
    char color[10];
} Card;

typedef struct {
    int value;
    char color[10];
} Ball;

void generate_card(Card *card) {
    int value = rand() % 15 + 1;
    strcpy(card->color, "red");
    if (value > 10) {
        strcpy(card->color, "black");
        value += 10;
    }
    card->value = value;
}

void generate_ball(Ball *ball) {
    int value = rand() % 15 + 1;
    strcpy(ball->color, "red");
    if (value > 10) {
        strcpy(ball->color, "black");
        value += 10;
    }
    ball->value = value;
}

int main() {
    srand(time(NULL));

    Player players[MAX_PLAYERS];
    Card cards[MAX_CARDS];
    Ball balls[MAX_BALLS];

    int num_players = 0;
    printf("Enter the number of players (up to %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].id = i + 1;
    }

    int num_cards = 0;
    printf("Enter the number of cards (up to %d): ", MAX_CARDS);
    scanf("%d", &num_cards);

    for (int i = 0; i < num_cards; i++) {
        generate_card(&cards[i]);
    }

    int num_balls = 0;
    printf("Enter the number of balls (up to %d): ", MAX_BALLS);
    scanf("%d", &num_balls);

    for (int i = 0; i < num_balls; i++) {
        generate_ball(&balls[i]);
    }

    int current_card = 0;
    int current_ball = 0;

    while (1) {
        printf("Current card: %d (%s)\n", cards[current_card].value, cards[current_card].color);
        printf("Current ball: %d (%s)\n", balls[current_ball].value, balls[current_ball].color);

        char choice;
        printf("Press b to draw a ball or c to draw a card: ");
        scanf(" %c", &choice);

        if (choice == 'b') {
            if (current_ball >= num_balls) {
                printf("No more balls left.\n");
            } else {
                printf("Drawn ball: %d (%s)\n", balls[current_ball].value, balls[current_ball].color);
                current_ball++;
            }
        } else if (choice == 'c') {
            if (current_card >= num_cards) {
                printf("No more cards left.\n");
            } else {
                printf("Drawn card: %d (%s)\n", cards[current_card].value, cards[current_card].color);
                current_card++;
            }
        }
    }

    return 0;
}