//FormAI DATASET v1.0 Category: Table Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define PLAYER_1 'X'
#define PLAYER_2 'O'
#define EMPTY '-'

void print_board(char board[][COLS]) {
    printf("\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf(" %c ", board[i][j]);
            if(j < COLS-1) printf("|");
        }
        if(i < ROWS-1) printf("\n---|---|---\n");
    }
    printf("\n\n");
}

void reset_board(char board[][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = EMPTY;
        }
    }
}

int get_player_move(char board[][COLS], char player) {
    int row, col, index;
    while(1) {
        printf("Player %c, enter your move (1-9): ", player);
        scanf("%d", &index);
        row = (index-1) / ROWS;
        col = (index-1) % COLS;
        if(index < 1 || index > 9) {
            printf("Invalid move, try again!\n");
        } else if(board[row][col] != EMPTY) {
            printf("That spot is already taken, try again!\n");
        } else {
            board[row][col] = player;
            return 1;
        }
    }
}

char check_winner(char board[][COLS]) {
  for(int i=0; i<ROWS; i++) {
    if(board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      return board[i][0];
    }
  }

  for(int j=0; j<COLS; j++) {
    if(board[0][j] != EMPTY && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
      return board[0][j];
    }
  }

  if(board[0][0] != EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return board[0][0];
  }

  if(board[0][2] != EMPTY && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return board[0][2];
  }

  return EMPTY;
}

int main() {
    char board[ROWS][COLS];
    char winner = EMPTY;
    int player_turn = 1;

    reset_board(board);
    srand(time(NULL));

    printf("Welcome to Tic Tac Toe!\n\n");

    while(winner == EMPTY) {
        print_board(board);
        if(player_turn == 1) {
            if(get_player_move(board, PLAYER_1)) {
                player_turn = 2;
            }
        } else {
            // Random move for player 2
            int row = rand() % ROWS;
            int col = rand() % COLS;
            if(board[row][col] == EMPTY) {
                board[row][col] = PLAYER_2;
                player_turn = 1;
            }
        }
        winner = check_winner(board);
    }

    print_board(board);
    if(winner == PLAYER_1) {
        printf("\nPlayer %c wins!\n", PLAYER_1);
    } else {
        printf("\nPlayer %c wins!\n", PLAYER_2);
    }

    return 0;
}