//FormAI DATASET v1.0 Category: Table Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Function to display the game board
void display_board(char board[3][3]) {
  printf("\n");
  printf("%c | %c | %c\n", board[0][0], board[0][1], board[0][2]);   
  printf("%c | %c | %c\n", board[1][0], board[1][1], board[1][2]);    
  printf("%c | %c | %c\n", board[2][0], board[2][1], board[2][2]);     
}

// Function to check if game is over
int game_over(char board[3][3]) {
  // Check for a win in rows
  for(int i=0; i<3; i++) {
    if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      if(board[i][0] == 'X')
        return 1;
      else if(board[i][0] == 'O')
        return -1;
    }
  }
  // Check for a win in columns
  for(int j=0; j<3; j++) {
    if(board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
      if(board[0][j] == 'X')
        return 1;
      else if(board[0][j] == 'O')
        return -1;
    }
  }
  // Check for a win in diagonals
  if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    if(board[0][0] == 'X')
      return 1;
    else if(board[0][0] == 'O')
      return -1;
  }
  if(board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
    if(board[2][0] == 'X')
      return 1;
    else if(board[2][0] == 'O')
      return -1;
  }
  // Check if game is a draw
  for(int i=0; i<3; i++) {
    for(int j=0; j<3; j++) {
      if(board[i][j] == ' ')
        return 0;
    }
  }
  return 2;
}

int main() {
  // Initialize game board
  char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

  // Initialize players
  char player1 = 'X';
  char player2 = 'O';

  // Initialize turn counter
  int turn_counter = 0;

  // Play game
  while(1) {
    // Display board
    display_board(board);

    // Check if game is over
    int game_status = game_over(board);
    if(game_status == 1) {
      printf("\nPLAYER 1 WINS!\n");
      break;
    }
    if(game_status == -1) {
      printf("\nPLAYER 2 WINS!\n");
      break;
    }
    if(game_status == 2) {
      printf("\nGAME OVER. IT'S A DRAW!\n");
      break;
    }

    // Determine current player
    char current_player;
    if(turn_counter % 2 == 0) {
      current_player = player1;
    } else {
      current_player = player2;
    }

    // Get player move
    int row, col;
    printf("\nPLAYER %d: Enter row and column for your move: ", turn_counter % 2 + 1);
    scanf("%d %d", &row, &col);

    // Check if move is valid
    if(row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
      printf("\nINVALID MOVE, TRY AGAIN.\n");
      continue;
    }

    // Make move
    board[row][col] = current_player;

    // Increment turn counter
    turn_counter++;
  }

  printf("\nGAME OVER.\n");

  return 0;
}