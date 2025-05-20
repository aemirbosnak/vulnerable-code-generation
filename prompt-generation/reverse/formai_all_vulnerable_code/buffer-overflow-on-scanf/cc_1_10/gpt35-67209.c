//FormAI DATASET v1.0 Category: Memory Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4
#define MAX_GUESSES 10

void initialize_board(int board[SIZE][SIZE]);
void print_board(int board[SIZE][SIZE], int reveal);
int get_guess(int board[SIZE][SIZE], int guesses[MAX_GUESSES][2], int count);
int check_guess(int board[SIZE][SIZE], int guess[2]);
int game_is_over(int board[SIZE][SIZE]);

int main(void) {
    int board[SIZE][SIZE];
    int guesses[MAX_GUESSES][2];
    int count_guesses = 0;
    int guess[2];
    int reveal = 0;
    int score = 0;
    int status;

    initialize_board(board);
    printf("Welcome to the Memory Game!\n\n");

    while(count_guesses < MAX_GUESSES && game_is_over(board) == 0) {
        printf("Guess #%d\n", count_guesses+1);
        print_board(board, reveal);
        printf("Enter row and column (space-separated): ");
        guess[0] = get_guess(board, guesses, count_guesses);
        guess[1] = get_guess(board, guesses, count_guesses);

        if (guess[0] == -1 || guess[1] == -1) {
            printf("Invalid guess, try again.\n\n");
            continue;
        }

        guesses[count_guesses][0] = guess[0];
        guesses[count_guesses][1] = guess[1];
        count_guesses++;

        status = check_guess(board, guess);
        if (status == 1) {
            score++;
            printf("Match found!\n");
            reveal = 1;
        } else {
            printf("No match found :(\n");
            reveal = 0;
        }
        printf("\n");
    }

    if (game_is_over(board) == 1) {
        printf("You win! Final score: %d/%d\n", score, MAX_GUESSES);
    } else {
        printf("You lose! Final score: %d/%d\n", score, MAX_GUESSES);
    }

    return 0;
}

void initialize_board(int board[SIZE][SIZE]) {
    int values[SIZE*SIZE/2];
    int index = 0;

    for (int i=0; i<SIZE*SIZE/2; i++) {
        values[i] = rand() % 10 + 1;
    }

    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            board[i][j] = values[index];
            index++;
            if (index == SIZE*SIZE/2) {
                index = 0;
            }
        }
    }

    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            int row = rand() % SIZE;
            int col = rand() % SIZE;
            int temp = board[i][j];
            board[i][j] = board[row][col];
            board[row][col] = temp;
        }
    }
}

void print_board(int board[SIZE][SIZE], int reveal) {
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            if (reveal == 1) {
                printf("%d ", board[i][j]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

int get_guess(int board[SIZE][SIZE], int guesses[MAX_GUESSES][2], int count) {
    int row, col;
    scanf("%d %d", &row, &col);

    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        return -1;
    }

    for (int i=0; i<count; i++) {
        if (row == guesses[i][0] && col == guesses[i][1]) {
            return -1;
        }
    }

    return board[row][col];
}

int check_guess(int board[SIZE][SIZE], int guess[2]) {
    int value = board[guess[0]][guess[1]];
    int count = 0;

    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            if (board[i][j] == value && (i != guess[0] || j != guess[1])) {
                count++;
            }
        }
    }

    if (count > 0) {
        return 1;
    } else {
        return 0;
    }
}

int game_is_over(int board[SIZE][SIZE]) {
    int count = 0;

    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            if (board[i][j] == 0) {
                count++;
            }
        }
    }

    if (count == SIZE*SIZE) {
        return 1;
    } else {
        return 0;
    }
}