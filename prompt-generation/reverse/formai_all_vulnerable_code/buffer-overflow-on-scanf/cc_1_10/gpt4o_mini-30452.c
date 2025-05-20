//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

char board[SIZE][SIZE];
char player = 'X';
char computer = 'O';

void initialize_board() {
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            board[i][j] = ' ';
}

void print_board() {
    printf("  0   1   2\n");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for(int j = 0; j < SIZE; j++) {
            printf("%c", board[i][j]);
            if (j < SIZE - 1) printf(" | ");
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf(" ---|---|---\n");
        }
    }
}

int check_winner() {
    for(int i = 0; i < SIZE; i++) {
        // Check Rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
        // Check Columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }
    // Check Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    return 0; // No winner
}

int is_board_full() {
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            if(board[i][j] == ' ')
                return 0; // There's at least one empty space
    return 1; // No empty space
}

void player_turn() {
    int x, y;
    while(1) {
        printf("Enter your move (row and column): ");
        scanf("%d %d", &x, &y);
        if(x >= 0 && x < SIZE && y >= 0 && y < SIZE && board[x][y] == ' ') {
            board[x][y] = player;
            break;
        } else {
            printf("Invalid move! Please try again.\n");
        }
    }
}

void computer_turn() {
    int x, y;
    // Generate random moves for the computer
    while(1) {
        x = rand() % SIZE;
        y = rand() % SIZE;
        if(board[x][y] == ' ') {
            board[x][y] = computer;
            printf("Computer places %c at (%d, %d)\n", computer, x, y);
            break;
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    initialize_board();

    while(1) {
        print_board();

        if(check_winner() == player) {
            print_board();
            printf("Congratulations! You win!\n");
            break;
        }
        if(is_board_full()) {
            print_board();
            printf("It's a draw!\n");
            break;
        }
        
        player_turn();

        if(check_winner() == player) {
            print_board();
            printf("Congratulations! You win!\n");
            break;
        }
        if(is_board_full()) {
            print_board();
            printf("It's a draw!\n");
            break;
        }

        computer_turn();

        if(check_winner() == computer) {
            print_board();
            printf("Computer wins! Better luck next time.\n");
            break;
        }
        if(is_board_full()) {
            print_board();
            printf("It's a draw!\n");
            break;
        }
    }
    
    return 0;
}