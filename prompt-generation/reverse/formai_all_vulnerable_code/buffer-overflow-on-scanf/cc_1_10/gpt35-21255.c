//FormAI DATASET v1.0 Category: Table Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 3
#define COLS 3

char players[2] = {'X', 'O'};

void print_board(char board[ROWS][COLS]) {
  printf("\n");
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      printf(" %c ", board[i][j]);
      if (j != COLS - 1) printf("|");
    }
    printf("\n");
    if (i != ROWS - 1) printf("---|---|---\n");
  }
  printf("\n");
}

bool has_won(char board[ROWS][COLS], char player) {
  for (int i = 0; i < ROWS; ++i) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return true;
    }
  }
  
  for (int j = 0; j < ROWS; ++j) {
    if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
      return true;
    }
  }
  
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  }
  
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return true;
  }
  
  return false;
}

bool is_full(char board[ROWS][COLS]) {
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      if (board[i][j] == ' ') {
        return false;
      }
    }
  }
  return true;
}

void play(char board[ROWS][COLS], int num_players) {
  int player_turn = 0;
  bool has_won_game = false;
  
  while (!is_full(board) && !has_won_game) {
    printf("Player %d, it's your turn!\n", player_turn+1);
    print_board(board);
    
    int x, y;
    
    do {
      printf("Enter the x coordinate (1-3): ");
      scanf("%d", &x);
      printf("Enter the y coordinate (1-3): ");
      scanf("%d", &y);
    } while (board[x-1][y-1] != ' ');
    
    board[x-1][y-1] = players[player_turn];
    
    if (has_won(board, players[player_turn])) {
      has_won_game = true;
      printf("Player %d has won the game! Congratulations!\n", player_turn+1);
    }
    
    player_turn = (player_turn + 1) % num_players;
  }
  
  if (!has_won_game) {
    printf("The game ended in a draw!\n");
  }
  
  print_board(board);
}

int main() {
  char board[ROWS][COLS] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
  };
  
  int num_players;
  printf("Welcome to the Decentralized C Table Game!\n");
  printf("Enter the number of players (2 players required): ");
  scanf("%d", &num_players);
  
  if (num_players != 2) {
    printf("Error! Invalid number of players. Please enter 2 players only.\n");
    exit(0);
  }
  
  play(board, num_players);
  return 0;
}