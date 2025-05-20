//GPT-4o-mini DATASET v1.0 Category: Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define MAX_TRIES 10

void display_board(char board[SIZE][SIZE]) {
    printf("Current Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void initialize_board(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '.';
        }
    }
}

int is_guess_valid(int row, int col) {
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE);
}

void place_random_ship(char board[SIZE][SIZE], int ship_size) {
    int placed = 0;
    while (placed < ship_size) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        
        if (board[row][col] == '.') {
            board[row][col] = 'S'; // Place ship on board
            placed++;
        }
    }
}

int play_game() {
    char board[SIZE][SIZE];
    initialize_board(board);
    int ship_size = 3;
    place_random_ship(board, ship_size);

    int tries = 0;
    int hits = 0;
    while (tries < MAX_TRIES && hits < ship_size) {
        display_board(board);
        int guess_row, guess_col;

        printf("Enter your guess (row and column 0-%d, separated by space): ", SIZE - 1);
        scanf("%d %d", &guess_row, &guess_col);

        if (!is_guess_valid(guess_row, guess_col)) {
            printf("Invalid guess. Try again.\n");
            continue;
        }

        if (board[guess_row][guess_col] == 'S') {
            board[guess_row][guess_col] = 'X'; // Mark hit
            hits++;
            printf("Hit! You've found a ship!\n");
        } else if (board[guess_row][guess_col] == 'X' || board[guess_row][guess_col] == 'O') {
            printf("You've already guessed that spot. Try again.\n");
        } else {
            board[guess_row][guess_col] = 'O'; // Mark miss
            printf("Miss! No ship in that location.\n");
        }

        tries++;
    }

    if (hits == ship_size) {
        printf("Congratulations! You sank my battleship!\n");
    } else {
        printf("Game over! You've used all your tries.\n");
    }

    return 0;
}

int main() {
    srand(time(NULL));
    printf("Welcome to Battleship!\n");
    play_game();
    return 0;
}