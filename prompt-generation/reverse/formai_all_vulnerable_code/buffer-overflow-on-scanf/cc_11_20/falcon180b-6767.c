//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 100
#define MAX_PLAYERS 10

typedef struct {
    int id;
    char name[20];
    int score;
    int cards[MAX_CARDS]; // 0-75
} Player;

int main() {
    int num_players;
    printf("How many players? ");
    scanf("%d", &num_players);

    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    srand(time(NULL));
    Player players[num_players];

    // Initialize players
    for (int i = 0; i < num_players; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].id = i + 1;
        players[i].score = 0;
    }

    // Shuffle cards
    int cards[MAX_CARDS];
    for (int i = 1; i <= 75; i++) {
        cards[i - 1] = i;
    }
    for (int i = 0; i < MAX_CARDS; i++) {
        int j = rand() % MAX_CARDS;
        int temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }

    // Deal cards
    for (int i = 0; i < num_players; i++) {
        for (int j = 0; j < 5; j++) {
            players[i].cards[j] = cards[5 * i + j];
        }
    }

    // Play game
    int current_player = 1;
    int current_card = 1;
    while (current_player <= num_players) {
        printf("Player %d's turn. Press enter to draw a card or type 'bingo' to end your turn.\n", current_player);
        char input[20];
        scanf("%s", input);

        if (strcmp(input, "bingo") == 0) {
            current_player++;
            continue;
        }

        int card = cards[current_card - 1];
        players[current_player - 1].cards[current_card - 1] = card;
        current_card++;

        if (current_card > 5) {
            current_card = 1;
        }

        current_player++;
    }

    // Determine winners
    int max_score = 0;
    for (int i = 0; i < num_players; i++) {
        int score = 0;
        for (int j = 0; j < 5; j++) {
            if (players[i].cards[j] % 15 == 0) {
                score += 15;
            } else if (players[i].cards[j] % 10 == 0) {
                score += 10;
            } else if (players[i].cards[j] % 5 == 0) {
                score += 5;
            }
        }
        if (score > max_score) {
            max_score = score;
        }
    }

    printf("Game over. Winners:\n");
    for (int i = 0; i < num_players; i++) {
        if (players[i].score == max_score) {
            printf("Player %d\n", players[i].id);
        }
    }

    return 0;
}