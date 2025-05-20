//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 5
#define MAX_COLS 5
#define MAX_NUMBERS 75

void generate_card(int card[MAX_ROWS][MAX_COLS]) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            card[i][j] = rand() % MAX_NUMBERS + 1;
        }
    }
}

void print_card(int card[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int player_cards[MAX_ROWS][MAX_COLS];
    int called_numbers[MAX_NUMBERS];
    int num_players = 0;
    int i, j;

    // Initialize game
    printf("Welcome to Mind-Bending C Bingo!\n");
    printf("How many players will be playing? ");
    scanf("%d", &num_players);

    // Generate player cards
    for (i = 0; i < num_players; i++) {
        generate_card(player_cards[i]);
        print_card(player_cards[i]);
        printf("\nPlayer %d's card:\n", i + 1);
    }

    // Start game loop
    int game_over = 0;
    while (!game_over) {
        int num_called = 0;
        for (i = 0; i < MAX_NUMBERS; i++) {
            called_numbers[i] = 0;
        }

        // Call numbers
        while (num_called < MAX_NUMBERS) {
            int num = rand() % MAX_NUMBERS + 1;
            if (called_numbers[num] == 0) {
                called_numbers[num] = 1;
                num_called++;
            }
        }

        // Check for winners
        for (i = 0; i < num_players; i++) {
            int wins = 0;
            for (j = 0; j < MAX_NUMBERS; j++) {
                if (called_numbers[j] == 1 && player_cards[i][j] == 1) {
                    wins++;
                }
            }
            if (wins == MAX_NUMBERS) {
                printf("Player %d wins!\n", i + 1);
                game_over = 1;
                break;
            }
        }
    }

    return 0;
}