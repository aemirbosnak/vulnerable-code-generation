//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define BINGO_NUMBERS 75
#define CARD_ROWS 5
#define CARD_COLS 5
#define MAX_PLAYERS 5

typedef struct {
    int numbers[CARD_ROWS][CARD_COLS];
    bool marked[CARD_ROWS][CARD_COLS];
} BingoCard;

void generate_bingo_card(BingoCard *card);
void print_bingo_card(const BingoCard *card);
void draw_number(int *drawn_numbers, int *num_drawn);
bool check_bingo(const BingoCard *card);
void reset_card(BingoCard *card);
void play_bingo(int num_players);

int main() {
    srand(time(NULL));
    int num_players;

    printf("Enter the number of players (1-5): ");
    scanf("%d", &num_players);
    
    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players. Please restart the program.\n");
        return 1;
    }

    play_bingo(num_players);
    return 0;
}

void generate_bingo_card(BingoCard *card) {
    // Generate Bingo Card
    for (int j = 0; j < CARD_COLS; j++) {
        int col_numbers[BINGO_NUMBERS];
        for (int i = 1; i <= BINGO_NUMBERS; i++) {
            col_numbers[i - 1] = i;
        }
        for (int i = 0; i < CARD_ROWS; i++) {
            while (true) {
                int index = rand() % BINGO_NUMBERS;
                int number = col_numbers[index];
                bool already_exists = false;
                // Check if the number is already assigned in the card
                for (int k = 0; k < i; k++) {
                    if (card->numbers[k][j] == number) {
                        already_exists = true;
                        break;
                    }
                }
                if (!already_exists) {
                    card->numbers[i][j] = number;
                    break;
                }
            }
        }
    }
    card->marked[2][2] = true; // Free space in the middle
}

void print_bingo_card(const BingoCard *card) {
    printf("\nBINGO Card:\n");
    printf(" B   I   N   G   O\n");
    for (int i = 0; i < CARD_ROWS; i++) {
        for (int j = 0; j < CARD_COLS; j++) {
            if (card->marked[i][j]) {
                printf("[*] ");
            } else {
                printf("[%2d] ", card->numbers[i][j]);
            }
        }
        printf("\n");
    }
}

void draw_number(int *drawn_numbers, int *num_drawn) {
    while (true) {
        int number = rand() % BINGO_NUMBERS + 1;
        bool already_drawn = false;
        for (int i = 0; i < *num_drawn; i++) {
            if (drawn_numbers[i] == number) {
                already_drawn = true;
                break;
            }
        }
        if (!already_drawn) {
            drawn_numbers[*num_drawn] = number;
            (*num_drawn)++;
            printf("Number drawn: %d\n", number);
            break;
        }
    }
}

bool check_bingo(const BingoCard *card) {
    // Check rows and columns for Bingo
    for (int i = 0; i < CARD_ROWS; i++) {
        bool row_bingo = true;
        bool col_bingo = true;
        
        for (int j = 0; j < CARD_COLS; j++) {
            if (!card->marked[i][j]) {
                row_bingo = false;
            }
            if (!card->marked[j][i]) {
                col_bingo = false;
            }
        }
        if (row_bingo || col_bingo) {
            return true;
        }
    }

    // Check diagonals for Bingo
    bool diag1_bingo = true;
    bool diag2_bingo = true;
    
    for (int i = 0; i < CARD_ROWS; i++) {
        if (!card->marked[i][i]) {
            diag1_bingo = false;
        }
        if (!card->marked[i][CARD_COLS - 1 - i]) {
            diag2_bingo = false;
        }
    }

    return diag1_bingo || diag2_bingo;
}

void reset_card(BingoCard *card) {
    for (int i = 0; i < CARD_ROWS; i++) {
        for (int j = 0; j < CARD_COLS; j++) {
            card->marked[i][j] = false; 
        }
    }
}

void play_bingo(int num_players) {
    BingoCard cards[MAX_PLAYERS];
    int drawn_numbers[BINGO_NUMBERS] = {0};
    int num_drawn = 0;
    bool game_over = false;

    // Generate cards for players
    for (int i = 0; i < num_players; i++) {
        generate_bingo_card(&cards[i]);
        print_bingo_card(&cards[i]);
    }
    
    // Game Loop
    while (!game_over) {
        draw_number(drawn_numbers, &num_drawn);
        
        // Mark drawn number on players' cards
        for (int i = 0; i < num_players; i++) {
            for (int j = 0; j < CARD_ROWS; j++) {
                for (int k = 0; k < CARD_COLS; k++) {
                    if (cards[i].numbers[j][k] == drawn_numbers[num_drawn - 1]) {
                        cards[i].marked[j][k] = true;
                    }
                }
            }
            print_bingo_card(&cards[i]);
            if (check_bingo(&cards[i])) {
                printf("Player %d has BINGO!\n", i + 1);
                game_over = true;
                break;
            }
        }
    }
}