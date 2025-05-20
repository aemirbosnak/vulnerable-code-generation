//FormAI DATASET v1.0 Category: Chess engine ; Style: funny
#include <stdio.h>
#define BOARD_SIZE 8

// Function to print chess board
void print_board(char board[][BOARD_SIZE]) {
  for(int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", BOARD_SIZE-i);
    for(int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
  printf("   a b c d e f g h\n");
}

// Function to move chess pieces
int move_piece(char board[][BOARD_SIZE], char piece[], char dest[]) {
  int start_row = BOARD_SIZE - (piece[1] - '0');
  int start_col = piece[0] - 'a';
  int dest_row = BOARD_SIZE - (dest[1] - '0');
  int dest_col = dest[0] - 'a';

  if(board[start_row][start_col] == ' ') {
    printf("There is no piece at that position!\n");
    return 0;
  }

  if(start_row == dest_row && start_col == dest_col) {
    printf("You're not moving anywhere!\n");
    return 0;
  }

  printf("Moving %c from %s to %s\n", board[start_row][start_col], piece, dest);
  board[dest_row][dest_col] = board[start_row][start_col];
  board[start_row][start_col] = ' ';
  return 1;
}

int main() {
  // Initialize board
  char board[BOARD_SIZE][BOARD_SIZE] = {
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
  };

  print_board(board);

  // Start game loop
  while(1) {
    char piece[3];
    char dest[3];

    printf("Enter piece to move (ex: e2): ");
    scanf("%s", piece);

    printf("Enter destination (ex: e4): ");
    scanf("%s", dest);

    int result = move_piece(board, piece, dest);
    if(result) {
      print_board(board);
    }
  }

  return 0;
}