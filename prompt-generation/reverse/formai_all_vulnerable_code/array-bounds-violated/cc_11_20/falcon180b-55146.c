//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_CARDS 50
#define MAX_NUMBERS 75

int main() {
    int num_players;
    int num_cards;
    int num_numbers;
    int i, j, k;
    int cards[MAX_CARDS];
    int numbers[MAX_NUMBERS];
    char names[MAX_PLAYERS][20];
    int player_cards[MAX_PLAYERS][MAX_CARDS];
    int player_numbers[MAX_PLAYERS][MAX_NUMBERS];
    int player_wins[MAX_PLAYERS];

    srand(time(NULL));

    // Get number of players
    printf("How many players? ");
    scanf("%d", &num_players);

    for (i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", names[i]);
    }

    // Get number of cards
    printf("How many cards? ");
    scanf("%d", &num_cards);

    // Get number of numbers
    printf("How many numbers? ");
    scanf("%d", &num_numbers);

    // Generate cards
    for (i = 0; i < num_cards; i++) {
        cards[i] = rand() % num_numbers;
    }

    // Shuffle cards
    for (i = 0; i < num_cards; i++) {
        j = rand() % num_cards;
        k = cards[i];
        cards[i] = cards[j];
        cards[j] = k;
    }

    // Distribute cards to players
    for (i = 0; i < num_players; i++) {
        for (j = 0; j < num_cards; j++) {
            player_cards[i][j] = cards[j];
        }
    }

    // Generate numbers
    for (i = 0; i < num_numbers; i++) {
        numbers[i] = rand() % num_numbers;
    }

    // Shuffle numbers
    for (i = 0; i < num_numbers; i++) {
        j = rand() % num_numbers;
        k = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = k;
    }

    // Play game
    int game_over = 0;
    while (!game_over) {
        printf("Current number: %d\n", numbers[0]);
        for (i = 0; i < num_players; i++) {
            int player_wins_this_round = 0;
            for (j = 0; j < num_cards; j++) {
                if (player_cards[i][j] == numbers[0]) {
                    player_cards[i][j] = -1;
                    player_wins_this_round++;
                }
            }
            player_wins[i] += player_wins_this_round;
            if (player_wins[i] == num_numbers) {
                game_over = 1;
                printf("%s wins!\n", names[i]);
            }
        }
        numbers[0] = numbers[num_numbers-1];
        num_numbers--;
    }

    // Print results
    for (i = 0; i < num_players; i++) {
        printf("%s: %d wins\n", names[i], player_wins[i]);
    }

    return 0;
}