//FormAI DATASET v1.0 Category: Checkers Game ; Style: artistic
#include <stdio.h>
#define BOARD_SIZE 8 // size of the board

// function prototypes
void setup_board(char board[][BOARD_SIZE]);
void print_board(char board[][BOARD_SIZE]);
void move_piece(char board[][BOARD_SIZE], int start_row, int start_col, int end_row, int end_col);
int is_valid_move(char board[][BOARD_SIZE], int start_row, int start_col, int end_row, int end_col);

int main() {
  char board[BOARD_SIZE][BOARD_SIZE];
  int start_row, start_col, end_row, end_col;

  setup_board(board); // initialize the board

  while(1) {
    print_board(board); // display the board
    printf("Enter the row and column number of the piece you want to move: ");
    scanf("%d%d", &start_row, &start_col);

    printf("Enter the row and column number of the square you want to move the piece to: ");
    scanf("%d%d", &end_row, &end_col);

    // check if the move is valid
    if(is_valid_move(board, start_row, start_col, end_row, end_col)) {
      move_piece(board, start_row, start_col, end_row, end_col);
    } else {
      printf("Invalid move. Try again.\n");
    }
  }

  return 0;
}

// initialize the board
void setup_board(char board[][BOARD_SIZE]) {
  int i, j;

  for(i = 0; i < BOARD_SIZE; i++) {
    for(j = 0; j < BOARD_SIZE; j++) {
      if((i+j) % 2 == 0) {
        board[i][j] = ' '; // empty square (with even row + col number)
      } else if(i < 3) {
        board[i][j] = 'w'; // white piece
      } else if(i > 4) {
        board[i][j] = 'b'; // black piece
      } else {
        board[i][j] = ' '; // empty square (with odd row + col number)
      }
    }
  }
}

// display the board
void print_board(char board[][BOARD_SIZE]) {
  int i, j;

  printf("\n");
  
  // print column numbers
  printf("  ");
  for(i = 0; i < BOARD_SIZE; i++) {
    printf(" %d ", i);
  }
  printf("\n");

  // print board with row numbers
  for(i = 0; i < BOARD_SIZE; i++) {
    printf("%d|", i);
    for(j = 0; j < BOARD_SIZE; j++) {
      printf(" %c |", board[i][j]);
    }
    printf("\n");
  }

  printf("\n");
}

// move the piece from start position to end position
void move_piece(char board[][BOARD_SIZE], int start_row, int start_col, int end_row, int end_col) {
  // swap the pieces
  board[end_row][end_col] = board[start_row][start_col];
  board[start_row][start_col] = ' ';
}

// check if the move is valid
int is_valid_move(char board[][BOARD_SIZE], int start_row, int start_col, int end_row, int end_col) {
  // check if the start and end positions are within the board
  if(start_row >= BOARD_SIZE || start_row < 0 || start_col >= BOARD_SIZE || start_col < 0 || end_row >= BOARD_SIZE || end_row < 0 || end_col >= BOARD_SIZE || end_col < 0) {
    return 0;
  }

  // check if the end position is empty
  if(board[end_row][end_col] != ' ') {
    return 0;
  }

  // check if the move is diagonal
  if(abs(start_row - end_row) != abs(start_col - end_col)) {
    return 0;
  }

  // check if the piece being moved is correct
  char piece = board[start_row][start_col];
  if(piece == ' ') {
    return 0;
  }
  if(piece == 'w' && end_row > start_row) {
    return 0;
  }
  if(piece == 'b' && end_row < start_row) {
    return 0;
  }

  // check if the move is one or two squares diagonally
  if(abs(start_row - end_row) == 1 && abs(start_col - end_col) == 1) {
    return 1;
  }
  if(abs(start_row - end_row) == 2 && abs(start_col - end_col) == 2) {
    // check if the piece to be captured is an enemy piece
    int middle_row = (start_row + end_row) / 2;
    int middle_col = (start_col + end_col) / 2;

    if(board[middle_row][middle_col] == 'w' && piece == 'b') {
      return 1;
    }
    if(board[middle_row][middle_col] == 'b' && piece == 'w') {
      return 1;
    }
  }

  return 0; // invalid move
}