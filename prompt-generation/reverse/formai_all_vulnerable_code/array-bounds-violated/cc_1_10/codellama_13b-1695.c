//Code Llama-13B DATASET v1.0 Category: Bingo Simulator ; Style: invasive
/* Bingo Simulator */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NUMBERS 50
#define MAX_BOARD_SIZE 25

typedef struct {
    int numbers[MAX_BOARD_SIZE];
    int numbers_count;
    int drawn_numbers[MAX_NUMBERS];
    int drawn_numbers_count;
    int won;
} Player;

void print_board(int numbers[], int numbers_count) {
    int i;
    printf("Board:\n");
    for (i = 0; i < numbers_count; i++) {
        printf("%d ", numbers[i]);
        if ((i + 1) % 5 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

void print_drawn_numbers(int numbers[], int numbers_count) {
    int i;
    printf("Drawn numbers:\n");
    for (i = 0; i < numbers_count; i++) {
        printf("%d ", numbers[i]);
        if ((i + 1) % 5 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

void generate_numbers(int numbers[], int numbers_count) {
    int i;
    for (i = 0; i < numbers_count; i++) {
        numbers[i] = i + 1;
    }
}

void shuffle_numbers(int numbers[], int numbers_count) {
    int i, j, temp;
    for (i = 0; i < numbers_count; i++) {
        j = rand() % numbers_count;
        temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }
}

void draw_numbers(int numbers[], int numbers_count, int drawn_numbers[], int drawn_numbers_count) {
    int i, j;
    for (i = 0; i < drawn_numbers_count; i++) {
        drawn_numbers[i] = numbers[i];
    }
}

void check_bingo(Player *players, int players_count, int drawn_numbers[], int drawn_numbers_count) {
    int i, j, k;
    for (i = 0; i < players_count; i++) {
        for (j = 0; j < drawn_numbers_count; j++) {
            for (k = 0; k < players[i].numbers_count; k++) {
                if (players[i].numbers[k] == drawn_numbers[j]) {
                    players[i].won = 1;
                    break;
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int i, j;
    Player players[MAX_PLAYERS];
    int numbers[MAX_NUMBERS];
    int drawn_numbers[MAX_NUMBERS];
    int numbers_count = 50;
    int drawn_numbers_count = 75;

    generate_numbers(numbers, numbers_count);
    shuffle_numbers(numbers, numbers_count);

    for (i = 0; i < MAX_PLAYERS; i++) {
        players[i].numbers_count = 25;
        draw_numbers(numbers, players[i].numbers_count, players[i].numbers, numbers_count);
        players[i].drawn_numbers_count = 0;
        players[i].won = 0;
    }

    printf("Initial board:\n");
    print_board(numbers, numbers_count);

    for (i = 0; i < drawn_numbers_count; i++) {
        drawn_numbers[i] = numbers[i];
    }

    printf("Drawn numbers:\n");
    print_drawn_numbers(drawn_numbers, drawn_numbers_count);

    check_bingo(players, MAX_PLAYERS, drawn_numbers, drawn_numbers_count);

    for (i = 0; i < MAX_PLAYERS; i++) {
        if (players[i].won) {
            printf("Player %d has won!\n", i + 1);
        }
    }

    return 0;
}