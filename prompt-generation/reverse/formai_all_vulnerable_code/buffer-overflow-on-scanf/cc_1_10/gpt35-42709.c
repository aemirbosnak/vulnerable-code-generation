//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: introspective
// Welcome to the Bingo Simulator!
// This is a simple program that simulates a game of bingo
// The user inputs the number of players and the program generates random bingo cards for each player.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void generate_card(int** card);
void print_card(int** card);
int check_bingo(int** card);

int main() {
    srand(time(NULL));
    int num_players;
    printf("Welcome to Bingo Simulator!\n");
    printf("How many players will be playing?\n");
    scanf("%d", &num_players);
    
    // Generate cards for each player
    int** cards = (int**) malloc(num_players * sizeof(int*));
    
    for (int i = 0; i < num_players; i++) {
        cards[i] = (int*) malloc(ROWS * COLS * sizeof(int));
        generate_card(cards[i]);
    }

    // Play the game!
    int round = 1;
    int winner = -1;

    while (winner == -1) {
        printf("Round %d\n", round);
        for (int i = 0; i < num_players; i++) {
            printf("Player %d's card:\n", i+1);
            print_card(cards[i]);
            if (check_bingo(cards[i])) {
                winner = i+1;
                break;
            }
        }
        round++;
    }

    printf("Bingo! Player %d wins!\n", winner);
    // Free memory
    for (int i = 0; i < num_players; i++) {
        free(cards[i]);
    }
    free(cards);
    return 0;
}

// Generates a random bingo card
void generate_card(int** card) {
    int nums[75];
    for (int i = 0; i < 75; i++) {
        nums[i] = i+1;
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int idx = rand() % (75-i*j);
            card[i][j] = nums[idx];
            nums[idx] = nums[74-i*j];
        }
    }
    // Replace center square with a free space
    card[2][2] = 0;
}

// Prints out the bingo card
void print_card(int** card) {
    printf("  B  I  N  G  O\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%3d", card[i][j]);
        }
        printf("\n");
    }
}

// Checks if the player has bingo
int check_bingo(int** card) {
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        int count = 0;
        for (int j = 0; j < COLS; j++) {
            if (card[i][j] == 0) {
                count++;
            }
        }
        if (count == COLS) {
            return 1;
        }
    }
    // Check columns
    for (int i = 0; i < COLS; i++) {
        int count = 0;
        for (int j = 0; j < ROWS; j++) {
            if (card[j][i] == 0) {
                count++;
            }
        }
        if (count == ROWS) {
            return 1;
        }
    }
    // Check diagonals
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < ROWS; i++) {
        if (card[i][i] == 0) {
            count1++;
        }
        if (card[i][COLS-i-1] == 0) {
            count2++;
        }
    }
    if (count1 == ROWS || count2 == ROWS) {
        return 1;
    }
    return 0;
}