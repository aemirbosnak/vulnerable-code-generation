//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 1000
#define MAX_PLAYERS 10
#define MAX_NUMBERS 75

typedef struct {
    int numbers[MAX_NUMBERS];
    int num_called;
    int player_id;
} BingoCard;

void generate_card(BingoCard *card) {
    for (int i = 0; i < MAX_NUMBERS; i++) {
        card->numbers[i] = rand() % 15 + 1;
    }
}

int is_valid_number(int number) {
    return number >= 1 && number <= 15;
}

int main() {
    srand(time(NULL));

    int num_players;
    printf("Enter number of players: ");
    scanf("%d", &num_players);

    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    BingoCard cards[num_players];
    for (int i = 0; i < num_players; i++) {
        generate_card(&cards[i]);
    }

    int num_called = 0;
    int players_left = num_players;

    while (players_left > 0) {
        int number = rand() % 15 + 1;
        printf("Called number: %d\n", number);

        for (int i = 0; i < num_players; i++) {
            if (is_valid_number(number) && cards[i].numbers[num_called] == number) {
                cards[i].numbers[num_called] = 0;
                num_called++;
            }
        }

        if (num_called == MAX_NUMBERS) {
            printf("Player %d wins!\n", 0);
            break;
        } else if (players_left == 1) {
            printf("Player %d wins!\n", 0);
            break;
        }
    }

    return 0;
}