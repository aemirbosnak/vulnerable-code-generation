//Falcon-180B DATASET v1.0 Category: Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a board
void print_board(char board[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check for a win condition
int check_win(char board[3][3]) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

// Function to play the game
void play_game(char board[3][3]) {
    int player = 1;
    int choice;
    while (1) {
        system("clear");
        print_board(board);
        printf("\nPlayer %d's turn.\n", player);
        printf("Enter your move (1-9): ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 9) {
            printf("Invalid move.\n");
            continue;
        }
        if (board[choice/3][choice%3]!= 'X' && board[choice/3][choice%3]!= 'O') {
            board[choice/3][choice%3] = (player == 1)? 'X' : 'O';
            if (check_win(board)) {
                printf("\n%s wins!\n", (player == 1)? "Player 1" : "Player 2");
                break;
            }
            player++;
        } else {
            printf("Invalid move.\n");
        }
    }
}

int main() {
    srand(time(NULL));
    char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    play_game(board);
    return 0;
}