//Falcon2-11B DATASET v1.0 Category: Space Invaders Game Clone ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_board(int board[][5]);
void print_winner(char* winner);

int main() {
    int board[5][5] = {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
    int player_choice;
    int computer_choice;
    char* winner;

    // Display initial board
    display_board(board);

    // Game loop
    while (1) {
        printf("Player's turn.\n");
        printf("Enter 1 to place a X, 2 to place an O.\n");
        scanf("%d", &player_choice);

        if (player_choice == 1) {
            board[0][0] = 1;
        } else if (player_choice == 2) {
            board[0][1] = 1;
        } else {
            printf("Invalid input.\n");
        }

        display_board(board);

        // Check for a winner
        if (check_winner(board)) {
            winner = "Player";
            break;
        }

        // Computer's turn
        srand(time(NULL));
        computer_choice = rand() % 2 + 1;

        board[1][computer_choice] = 1;

        display_board(board);

        // Check for a winner
        if (check_winner(board)) {
            winner = "Computer";
            break;
        }
    }

    // Print the winner
    print_winner(winner);

    return 0;
}

void display_board(int board[][5]) {
    printf("  1 | 2 | 3 | 4 | 5\n");
    printf("---+---+---+---+---\n");

    for (int i = 0; i < 5; i++) {
        printf("| %d | %d | %d | %d | %d |\n", board[i][0], board[i][1], board[i][2], board[i][3], board[i][4]);
    }

    printf("---+---+---+---+---\n");
}

void print_winner(char* winner) {
    printf("Game over! %s wins.\n", winner);
}

int check_winner(int board[][5]) {
    // Check rows
    for (int i = 0; i < 5; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][3] == board[i][4]) {
            return board[i][0];
        }
    }

    // Check columns
    for (int i = 0; i < 5; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == board[3][i] && board[3][i] == board[4][i]) {
            return board[0][i];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[3][3] == board[4][4]) {
        return board[0][0];
    } else if (board[0][4] == board[1][3] && board[1][3] == board[2][2] && board[2][2] == board[3][1] && board[3][1] == board[4][0]) {
        return board[0][4];
    }

    return 0;
}