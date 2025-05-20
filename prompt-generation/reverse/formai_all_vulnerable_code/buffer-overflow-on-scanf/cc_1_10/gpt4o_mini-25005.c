//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BINGO_SIZE 5
#define NUM_BALLS 75
#define MAX_PLAYERS 10

typedef struct {
    int card[BINGO_SIZE][BINGO_SIZE];
    int marked[BINGO_SIZE][BINGO_SIZE];
} BingoCard;

int balls[NUM_BALLS];
int ball_count = 0;

void generate_bingo_card(BingoCard *card) {
    int num_set = 0;
    int col_min, col_max;

    // Fill in the BINGO card with random numbers
    for (int j = 0; j < BINGO_SIZE; j++) {
        if (j == 0) { col_min = 1; col_max = 15; }
        else if (j == 1) { col_min = 16; col_max = 30; }
        else if (j == 2) { col_min = 31; col_max = 45; }
        else if (j == 3) { col_min = 46; col_max = 60; }
        else { col_min = 61; col_max = 75; }

        num_set = 0;
        while (num_set < BINGO_SIZE) {
            int rand_num = (rand() % (col_max - col_min + 1)) + col_min;
            int exists = 0;

            for (int k = 0; k < num_set; k++) {
                if (card->card[k][j] == rand_num) {
                    exists = 1;
                    break;
                }
            }

            if (!exists) {
                card->card[num_set][j] = rand_num;
                num_set++;
            }
        }
    }

    card->marked[2][2] = 1; // Free space
}

void print_bingo_card(BingoCard *card) {
    printf("B   I   N   G   O\n");
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (card->marked[i][j])
                printf("*  ");
            else
                printf("%2d ", card->card[i][j]);
        }
        printf("\n");
    }
}

void mark_ball(BingoCard *card, int ball) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (card->card[i][j] == ball) {
                card->marked[i][j] = 1;
            }
        }
    }
}

int check_bingo(BingoCard *card) {
    // Check rows and columns
    for (int i = 0; i < BINGO_SIZE; i++) {
        int row_bingo = 1, col_bingo = 1;
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (!card->marked[i][j]) row_bingo = 0;
            if (!card->marked[j][i]) col_bingo = 0;
        }
        if (row_bingo || col_bingo) return 1;
    }

    // Check diagonals
    if (card->marked[0][0] && card->marked[1][1] && card->marked[2][2] &&
        card->marked[3][3] && card->marked[4][4]) 
        return 1;

    if (card->marked[0][4] && card->marked[1][3] && card->marked[2][2] &&
        card->marked[3][1] && card->marked[4][0]) 
        return 1;

    return 0;
}

void initialize_balls() {
    for (int i = 0; i < NUM_BALLS; i++) {
        balls[i] = i + 1;
    }
    // Shuffle the balls
    for (int i = NUM_BALLS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = balls[i];
        balls[i] = balls[j];
        balls[j] = temp;
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    int num_players;
    printf("Enter the number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &num_players);
    
    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting.\n");
        return 1;
    }

    BingoCard players[MAX_PLAYERS];
    for (int i = 0; i < num_players; i++) {
        generate_bingo_card(&players[i]);
        printf("Player %d's Bingo Card:\n", i + 1);
        print_bingo_card(&players[i]);
        printf("\n");
    }

    initialize_balls();
    printf("Bingo game starts!\n");

    while (ball_count < NUM_BALLS) {
        int current_ball = balls[ball_count++];
        printf("Ball drawn: %d\n", current_ball);
        
        for (int i = 0; i < num_players; i++) {
            mark_ball(&players[i], current_ball);
            if (check_bingo(&players[i])) {
                printf("Player %d has BINGO!\n", i + 1);
                return 0; // End game on bingo
            }
        }
        printf("\n");
    }

    printf("No winner this time.\n");
    return 0;
}