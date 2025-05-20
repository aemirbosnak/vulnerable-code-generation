//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define BINGO_SIZE 5
#define MAX_PLAYERS 4
#define MAX_NUMBERS 75

typedef struct {
    int card[BINGO_SIZE][BINGO_SIZE];
    bool marked[BINGO_SIZE][BINGO_SIZE];
    char name[20];
} Player;

void initialize_card(int card[BINGO_SIZE][BINGO_SIZE]);
void print_card(int card[BINGO_SIZE][BINGO_SIZE], bool marked[BINGO_SIZE][BINGO_SIZE]);
bool check_bingo(bool marked[BINGO_SIZE][BINGO_SIZE]);
void call_number(int *called_numbers, int *called_count);
void reset_game();
void play_bingo(Player players[], int num_players);

int main() {
    srand(time(NULL));
    Player players[MAX_PLAYERS];
    int num_players;
    
    printf("Welcome to the Bingo Game!\n");
    printf("Enter number of players (1 to 4): ");
    scanf("%d", &num_players);

    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting...\n");
        return 1;
    }

    for (int i = 0; i < num_players; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
        initialize_card(players[i].card);
        for (int j = 0; j < BINGO_SIZE; j++) {
            for (int k = 0; k < BINGO_SIZE; k++) {
                players[i].marked[j][k] = false;
            }
        }
    }

    play_bingo(players, num_players);
    return 0;
}

void initialize_card(int card[BINGO_SIZE][BINGO_SIZE]) {
    int columns[5][15] = {{1, 15}, {16, 30}, {31, 45}, {46, 60}, {61, 75}};
    for (int col = 0; col < BINGO_SIZE; col++) {
        int numbers[5];
        for (int i = 0; i < 5; i++) {
            numbers[i] = 0;
        }
        for (int i = 0; i < BINGO_SIZE; i++) {
            int random_number;
            bool unique;
            do {
                unique = true;
                random_number = rand() % (columns[col][1] - columns[col][0] + 1) + columns[col][0];
                for (int j = 0; j < i; j++) {
                    if (numbers[j] == random_number) {
                        unique = false;
                        break;
                    }
                }
            } while (!unique);
            numbers[i] = random_number;
        }
        
        for (int i = 0; i < BINGO_SIZE; i++) {
            card[i][col] = numbers[i];
        }
    }
    
    card[2][2] = 0; // Free space
}

void print_card(int card[BINGO_SIZE][BINGO_SIZE], bool marked[BINGO_SIZE][BINGO_SIZE]) {
    printf(" B   I   N   G   O\n");
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (marked[i][j])
                printf(" X  ");
            else
                printf("%2d  ", card[i][j]);
        }
        printf("\n");
    }
}

bool check_bingo(bool marked[BINGO_SIZE][BINGO_SIZE]) {
    // Check rows and columns
    for (int i = 0; i < BINGO_SIZE; i++) {
        if ((marked[i][0] && marked[i][1] && marked[i][2] && marked[i][3] && marked[i][4]) || 
            (marked[0][i] && marked[1][i] && marked[2][i] && marked[3][i] && marked[4][i])) {
            return true;
        }
    }
    // Check diagonals
    if ((marked[0][0] && marked[1][1] && marked[2][2] && marked[3][3] && marked[4][4]) || 
        (marked[0][4] && marked[1][3] && marked[2][2] && marked[3][1] && marked[4][0])) {
        return true;
    }
    
    return false;
}

void call_number(int *called_numbers, int *called_count) {
    int number;
    do {
        number = rand() % MAX_NUMBERS + 1;
        bool unique = true;
        for (int i = 0; i < *called_count; i++) {
            if (called_numbers[i] == number) {
                unique = false;
                break;
            }
        }
        if (unique) {
            called_numbers[*called_count] = number;
            (*called_count)++;
            break;
        }
    } while (true);
    printf("Called number: %d\n", number);
}

void play_bingo(Player players[], int num_players) {
    int called_numbers[MAX_NUMBERS];
    int called_count = 0;
    while (true) {
        call_number(called_numbers, &called_count);
        
        for (int i = 0; i < num_players; i++) {
            for (int j = 0; j < BINGO_SIZE; j++) {
                for (int k = 0; k < BINGO_SIZE; k++) {
                    if (players[i].card[j][k] == called_numbers[called_count - 1]) {
                        players[i].marked[j][k] = true;
                    }
                }
            }
            print_card(players[i].card, players[i].marked);
            if (check_bingo(players[i].marked)) {
                printf("%s wins!\n", players[i].name);
                return;
            }
        }
    }
}